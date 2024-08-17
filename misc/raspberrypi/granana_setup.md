# Grafana Setup for the Raspberry PI 4

## 1. Setup New Repositories
```bash
sudo mkdir -p /etc/apt/keyrings/
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee /etc/apt/sources.list.d/grafana.list

curl -s https://repos.influxdata.com/influxdata-archive_compat.key > influxdata-archive_compat.key
echo '393e8779c89ac8d958f81f942f9ad7fb82a25e133faddaf92e15b16e6ac9ce4c influxdata-archive_compat.key' | sha256sum -c && cat influxdata-archive_compat.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg > /dev/null
echo 'deb [signed-by=/etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg] https://repos.influxdata.com/debian stable main' | sudo tee /etc/apt/sources.list.d/influxdata.list
sudo apt update
```

## 2. Install Required Packages
```bash
sudo apt install grafana telegraf influxdb
sudo systemctl enable influxdb grafana-server telegraf
sudo systemctl start influxdb grafana-server telegraf
```

## 3. Configure InfluxDB
```bash
pi@raspberrypi:/etc/influxdb $ influx
Connected to http://localhost:8086 version 1.8.0
InfluxDB shell version: 1.8.0
> create database telegraf
> use telegraf
Using database telegraf
> create user telegrafuser with password 'Telegr@f' with all privileges
> grant all privileges on telegraf to telegrafuser
> create retention policy "4Weeks" on "telegraf" duration 4w replication 1 default
> exit
```

## 4. Configure Telegraf
```bash
pi@raspberrypi:~ $ sudo nano /etc/telegraf/telegraf.conf
```
```
[[outputs.influxdb]]
   urls = ["http://127.0.0.1:8086"]
   database = "telegraf"
   username = "telegrafuser"
   password = "Telegr@f"
```
```bash
pi@raspberrypi:~ $ sudo systemctl reload telegraf.service
pi@raspberrypi:~ $ sudo systemctl status telegraf.service
```

## 5. Add a Datasource for Grafana
> Open the following URL to get to grafana: `http://IP_RASPBERRYPI:3000`
> 
> The default credentials are `admin/admin`
>
> Click on `Add your first data source` and select `InfluxDB` as the type
>
> Enter the following values:
>
> **URL**: `http://IP_RASPBERRYPI:8086`
>
> **Auth**: All options turned **OFF**
>
> **Database**: `telegraf`
>
> **User**: `telegrafuser`
>
> **Password**: `Telegr@f`
>
> **HTTP Method**: `GET`

## 6. Add the Raspberry PI Dashboard
```bash
pi@raspberrypi:~ $ sudo usermod -a -G video telegraf
```
```bash
pi@raspberrypi:~ $ sudo nano /etc/telegraf/telegraf.d/raspberrypi.conf
```
```
[[inputs.net]]

[[inputs.netstat]]

[[inputs.file]]
   files = ["/sys/class/thermal/thermal_zone0/temp"]
   name_override = "cpu_temperature"
   data_format = "value"
   data_type = "integer"

[[inputs.exec]]
   commands = ["/opt/vc/bin/vcgencmd measure_temp"]
   name_override = "gpu_temperature"
   data_format = "grok"
   grok_patterns = ["%{NUMBER:value:float}"]
```
```
pi@raspberrypi:~ $ sudo systemctl reload telegraf.service
```
> Go to the main page and select the `Import` option
>
> Enter the following ID to get the Raspberry PI Dashboard: `10578`

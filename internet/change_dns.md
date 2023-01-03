# Change DNS server with NetworkManager

- change to the root user: `sudo -i`
- Open the file `/etc/NetworkManager/system-connections/ACCESS_POINT_NAME.nmconnection`
- under the [ipv4] section add:
```
dns=8.8.8.8;8.8.4.4;
ignore-auto-dns=true
```
- these are the settings for Google's DNS servers

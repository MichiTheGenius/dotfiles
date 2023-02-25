# Setup a headless raspberry pi

## enable ssh for the pi
- create an empty file called `ssh` in the **boot** partition of the pi
- this enables the ssh server for connecting via ssh
```bash
touch boot/ssh
```

## setup wifi for the pi
- copy the existing `wpa_supplicant.conf` file to the boot partition
- change the `psk` and `ssid` to your wifi password and ssid accordingly
```bash
cp ./wpa_supplicant.conf boot/
```


## add a new user
- create a ssh password
```bash
echo "YOUR-PASSWORD" | openssl passwd -6 -stdin
```
- create a file called `userconf` in the boot partition
    - it should contain your username followed by a colon (:) and then your created ssh password **from the openssl** command
- example:
```
john:$6$ExDkVmsi0PZ0C73c$hPQ6LCFpXt2pNGeTYhva9oAW6/SWq2.I8zi3jRp7K3CEQmVcy2OOXFImTQxfaVu5QMGqVZ9JltUGs5VGT5FQi/
```




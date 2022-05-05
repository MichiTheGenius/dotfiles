# Minimal KDE install on arch linux

## Install the `plasma-desktop` package for a minimal kde desktop without any applications.
```bash
sudo pacman -S plasma-desktop
```
## Install the `plasma-meta` meta-package for functions like audio or internet.
```bash
sudo pacman -S plasma-meta
```
## Install `sddm` as the login manager and enable it
```bash
sudo pacman -S sddm && sudo systemctl enable sddm
```
## Install `bluez` for bluetooth functionality and add user to `lp` group for bluetooth permissions
```bash
sudo pacman -S bluez bluez-utils
sudo systemctl enable bluetooth
usermod -aG lp NAMEOFUSER
```

## Update the mirrorlist of pacman to use the fastest mirrors
> install the `pacman-contrib` package
>
> it includes the `rankmirrors` command
```bash
rankmirrors /etc/pacman.d/mirrorlist
```
## reboot and enjoy!
```bash
sudo reboot
```
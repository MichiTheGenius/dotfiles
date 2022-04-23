# Minimal KDE install on arch linux

1. Install the `plasma-desktop` package for a minimal kde desktop without any applications.
```bash
sudo pacman -S plasma-desktop
```
2. Install the `plasma-meta` meta-package for functions like audio or internet.
```bash
sudo pacman -S plasma-meta
```
3. Install `sddm` as the login manager and enable it
```bash
sudo pacman -S sddm && sudo systemctl enable sddm
```
4. reboot and enjoy!
```bash
sudo reboot
```
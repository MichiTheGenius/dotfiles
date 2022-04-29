# Install arch linux

## Change your keyboard layout. For german it would be:
```shell
loadkeys de
```

---

## Enable wifi
> Enter the command `iwctl`
>
> Enter the command `device list` to see all available devices
>
> Enter `station NAMEOFDEVICE scan`
>
> Enter `station NAMEOFDEVICE get-networks` to list all available networks
>
> Enter `station NAMEOFDEVICE connect SSID`
>
> Enter the password when prompted and `exit` iwctl

---

## Set your clock to use ntp
```shell
timedatectl set-ntp true
```
---

## Partition your disk with `cfdisk`
> Enter the command `cfdisk`
>
> For UEFI choose the `gpt` disk label. For legacy use `dos`
>
> make a boot partition with a size of 500M
>
> (for a swap) make a swap partition with the size of 2GB
>
> make a root partition with the rest of the size

---

## Format your partitions

### The **boot** partition

> for UEFI
>   
```shell
mkfs.fat -F32 /dev/NAMEOFBOOTPARTITION
```

> for legacy
>
```shell
mkfs.ext4 /dev/NAMEOFBOOTPARTITION
```

### The optional **swap** partition
```shell
mkswap /dev/NAMEOFSWAPPARTITION
```

### The **root** partition
```shell
mkfs.ext4 /dev/NAMEOFROOTPARTITION
```

---

## Mounting the partitions
```shell
mount /dev/NAMEOFROOTPARTITION /mnt
(if using legacy bios) mount /dev/NAMEOFBOOTPARTITION /mnt/boot
(optional) swapon /dev/NAMEOFSWAPPARTITION
```
---

## Installing the system
```shell
pacstrap /mnt base base-devel linux linux-firmware vim iwd
```

---

## Generating the filesystem table
```shell
genfstab -U /mnt >> /mnt/etc/fstab
```

---

## Chroot into the system
```shell
arch-chroot /mnt /bin/bash
```

---

## Set timezone
```shell
ln -sf /usr/share/zoneinfo/REGION/CITY /etc/localtime
```

---

## Set locale
```shell
vim /etc/locale.gen
```
> uncomment your locale

```shell
locale-gen
```

---

## Set hostname
```shell
vim /etc/hostname
```
> enter a hostname and save the file

---

## Change the password of the root user
```shell
passwd
```

---

## Add a new normal user
```shell
useradd -m NAMEOFUSER
usermod -aG wheel NAMEOFUSER
EDITOR=vim visudo
passwd NAMEOFUSER
```
> Remove the comment from the line: **%wheel ALL=(ALL:ALL) ALL**
>
> This allows members of the wheel group to execute any command when using sudo

---

## Install the bootloader
> for UEFI
>

```shell
pacman -S efibootmgr dosfstools os-prober mtools grub
mkdir /boot/EFI
mount /dev/NAMEOFBOOTPARTITION /boot/EFI
grub-install --target=x86_64-efi --bootloader-id=grub_uefi --recheck
grub-mkconfig -o /boot/grub/grub.cfg
```

> for legacy
>

```shell
grub-install /dev/NAMEOFBOOTPARTITION
grub-mkconfig -o /boot/grub/grub.cfg
```

---

## Finishing touches
> Install and enable networkmanager for internet access at fresh boot

```shell
pacman -S networkmanager
systemctl enable NetworkManager
```

> exit the chroot environment with the `exit` command
>
> unmount everything with `umount -R /mnt`
>
> reboot the system with `reboot` and enjoy!

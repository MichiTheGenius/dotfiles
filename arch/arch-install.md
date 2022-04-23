# Install arch linux

## Change your keyboard layout. For german it would be:
```properties
loadkeys de
```

---

## Set your clock to use ntp
```properties
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
```properties
mkfs.fat -F32 /dev/NAMEOFBOOTPARTITION
```

> for legacy
>
```properties
mkfs.ext4 /dev/NAMEOFBOOTPARTITION
```

### The optional **swap** partition
```properties
mkswap /dev/NAMEOFSWAPPARTITION
```

### The **root** partition
```properties
mkfs.ext4 /dev/NAMEOFROOTPARTITION
```

---

## Mounting the partitions
```properties
mount /dev/NAMEOFROOTPARTITION /mnt
(is using legacy bios) mount /dev/NAMEOFBOOTPARTITION /mnt/boot
(optional) swapon /dev/NAMEOFSWAPPARTITION
```
---

## Installing the system
```properties
pacstrap /mnt base base-devel linux linux-firmware vim
```

---

## Generating the filesystem table
```properties
genfstab -U /mnt >> /mnt/etc/fstab
```

---

## Chroot into the system
```properties
arch-chroot /mnt /bin/properties
```

---

## Set timezone
```properties
ln -sf /usr/share/zoneinfo/REGION/CITY /etc/localtime
```

---

## Set locale
```properties
vim /etc/locale.gen
```
> uncomment your locale

```properties
locale-gen
```

---

## Set hostname
```properties
vim /etc/hostname
```
> enter a hostname and save the file

---

## Change the password of the root user
```properties
passwd
```

---

## Add a new normal user
```properties
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

```properties
pacman -S efibootmgr dosfstools os-prober mtools grub
mkdir /boot/EFI
mount /dev/NAMEOFBOOTPARTITION /boot/EFI
grub-install --target=x86_64-efi --bootloader-id=grub_uefi --recheck
grub-mkconfig -o /boot/grub/grub.cfg
```

> for legacy
>

```properties
grub-install /dev/NAMEOFBOOTPARTITION
grub-mkconfig -o /boot/grub/grub.cfg
```

---

## Finishing touches
> Install and enable networkmanager for internet access at fresh boot

```properties
pacman -S networkmanager
systemctl enable NetworkManager
```

> exit the chroot environment with the `exit` command
>
> unmount everything with `umount -R /mnt`
>
> reboot the system with `reboot`







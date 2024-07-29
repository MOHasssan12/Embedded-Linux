# initramfs + dualboot

we will use the initramfs to make boot manager 

remove lib from rootfs_static as it takes much space 

```
cd ~/rootfs
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
cd ..
gzip initramfs.cpio
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```

Copy uRamdisk you created earlier in this section to the boot partition on the microSD card
```
sudo cp uRamdisk ~/boot

```


```
setenv kernel_addr_r 0x60000000
setenv fdt_addr_r 0x65000000
setenv initramfs 0x66000000

fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initramfs uRamdisk

setenv bootargs "console=ttyAMA0 rdinit=/bin/sh"

bootz $kernel_addr_r $initramfs $fdt_addr_r
```

### System configuration and startup

first run the **/etc/init.d/rcS** then 

```
mkdir mnt/boot
mkdir mnt/rootfs1


mount -t ext4 /dev/mmcblk0p1 /mnt/boot
mount -t ext4 /dev/mmcblk0p2 /mnt/rootfs1


```
You can change the root 

```
chroot /mnt/rootfs1 
```

## Dual boot 

First you have to resize the sd card and add third partition ext4 to be rootfs2

then create your root filesystem in this partition 

we need to create a script to choose between roots and add it to the rootfs_static directory 

and add the running command of script in rcs 

```
source /bin/script
```

the script 

```

#!/bin/sh
echo "Select the root:"
read -r choice

case $choice in
    1)
        mkdir -p /mnt/rootfs_one
        mount -t ext4 /dev/mmcblk0p2 /mnt/rootfs_one
        chroot /mnt/rootfs_one
        ;;
    2)
        mkdir -p /mnt/rootfs_two
        mount -t ext4 /dev/mmcblk0p3 /mnt/rootfs_two
        chroot /mnt/rootfs_two
        ;;
    *)
        echo "Wrong selection"
        ;;
esac


```
edit bootargs so the init=/sbin/init  

```
setenv kernel_addr_r 0x60000000
setenv fdt_addr_r 0x65000000
setenv initramfs 0x66000000

fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initramfs uRamdisk

setenv bootargs "console=ttyAMA0 rdinit=/sbin/init"

bootz $kernel_addr_r $initramfs $fdt_addr_r

```


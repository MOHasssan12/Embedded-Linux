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
mkdir mnt/rootfs2

mount -t ext4 /dev/mmcblk0p1 /mnt/boot
mount -t ext4 /dev/mmcblk0p2 /mnt/rootfs1
mount -t ext4 /dev/mmcblk0p3 /mnt/rootfs2

```
You can change the root 

```
chroot /mnt/rootfs1 or chroot /mnt/rootfs2 
```
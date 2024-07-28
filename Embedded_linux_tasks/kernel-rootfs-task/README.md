# Mounting Root File System with SD card for ARM Cortex-A9 on Vexpress [ Qemu ]


## Downloading BusyBox

Clone the BusyBox repository from the official source:

```
git clone https://github.com/mirror/busybox.git

cd busybox/
```



### Configuring BusyBox

Use menuconfig to configure BusyBox according to your requirements:


```
make menuconfig
```

### Compiling BusyBox

Export the compiler and architecture variables:

```bash
export CROSS_COMPILE=Path/arm-cortexa9_neon-linux-musleabihf-
export ARCH=arm
```
Configure BusyBox for static build:

```
make menuconfig
```

Build BusyBox:

```
make
```
Generate the rootfs

```
make install
```
This will create folder named _install which has all binaries


## Creating the Root File System


Set up the root filesystem by copying BusyBox binaries:

```

# create directory rootfs
mkdir rootfs_static


cp -rp ./busybox/_install/ ./rootfs


sudo rsync -a ~/x-tools/arm-cortexa9_neon-linux-musleabihf/arm-cortexa9_neon-linux-musleabihf/sysroot/* ~/rootfs/

cd rootfs

sudo chown -R root:root *


mkdir -p ./dev ./etc ./sys ./etc

mkdir ./etc/init.d
touch ./etc/init.d/rcS
touch ./etc/inittab

```
in the inittab we must write our configurations as it the the first thing used by init process 

```
#When system startup,will execute "rcS" script
::sysinit:/etc/init.d/rcS
#Start"askfirst" shell on the console (Ask the user firslty to press any key) 
ttyAMA0::askfirst:-/bin/sh
#when restarting the init process,will execute "init" 
::restart:/sbin/init

```
then write the bash script in rcS 

```
#!/bin/sh
# mount a filesystem of type `proc` to /proc
mount -t proc nodev /proc
# mount a filesystem of type `sysfs` to /sys
mount -t sysfs nodev /sys
# mount devtmpfs if you forget to configure it in Kernel menuconfig
#there is two options uncomment one of them  
mount -t devtmpfs devtempfs /dev
```



---

```
cp -rp ~/rootfs_Static/* ~/rootfs
```

## Run qemu

```
qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd ~/sd.img
```

Set addresses of kernel_addr_r and fdt_addr_r and set bootargs 

```
setenv kernel_addr_r 0x60000000
setenv fdt_addr_r 0x65000000

setenv bootargs 'console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init' 

fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb


bootz $kernel_addr_r - $fdt_addr_r

```


now we are running our kernel 




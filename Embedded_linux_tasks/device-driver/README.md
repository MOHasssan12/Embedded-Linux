# Device Drivers

#### Linux Kernel Modules (LKM) Overview
Linux Kernel Modules (LKM) are essential components that extend the functionality of the Linux kernel. Modules allow you to add new features, such as device drivers, filesystems, and security modules, without the need to recompile the entire kernel.

#### Introduction to Linux and RTOS
Linux is a versatile operating system that handles tasks and provides an interface for users. Unlike Real-Time Operating Systems (RTOS), which are designed to handle tasks in a predictable manner and typically do not offer a user interface, Linux provides extensive user interaction capabilities and manages system resources efficiently.

- Linux: An operating system that manages hardware and software resources and provides a user interface for interaction.

- RTOS: An operating system designed for real-time task management, often without user interaction capabilities.

### Static vs. Dynamic Modules

There is two methodes to implement the modules:

#### Static Modules

- **Definition**: Modules compiled directly into the kernel during the build process.
- **Location**: Embedded in the zImage (the kernel image).
- **Advantages**:

    Essential drivers are always available in the kernel.
- **Disadvantages**:

    Increases the size of the kernel image.

    Can lead to longer kernel startup times.

#### Dynamic Modules

- **Definition**: Modules loaded into the kernel at runtime from the root filesystem.
- **Location**: Stored as .ko files (kernel object files).
- **Advantages**:

    Keeps the kernel image smaller.

    Modules can be loaded or unloaded without rebooting.

- **Disadvantages**:

    Missing modules from the root filesystem cannot be loaded.

    .ko files may be larger than static object files.

    Loading modules adds a slight delay during system boot.


### How to Reduce Kernel Startup Time:

    1) Use systemd: Systemd can run services in parallel, improving boot times compared to System V.
    2) Optimize Services: Run only essential services to reduce the kernel’s startup time.

### Commands for Managing Dynamic Modules:

-    Insert a Module: ```sudo insmod module.ko```
-    Remove a Module: ```sudo rmmod module```
-    Insert or Remove a Module: ``sudo modprobe module``
-    List Loaded Modules: `lsmod`

## Why Use Linux Kernel Modules?

Kernel modules provide a way to extend the Linux kernel’s functionality without recompiling the entire kernel. This includes:

- Security: Adding or enhancing security features.
- File Systems: Supporting new file systems.
- Device Drivers: Managing hardware devices.

## Kernel Module Syntax

1. Header Section

    **Includes**: Only kernel headers like <linux/module.h>, <linux/kernel.h>.
    Note: No user-space libraries (e.g., stdio.h) are included since modules operate in kernel space.

2. Code Section

   - **Functions**:
        Initialization: int mymodule_init(void) { /* initialization code */ }
        Cleanup: void mymodule_exit(void) { /* cleanup code */ }
   - **Macros**:
        Module Initialization: module_init(mymodule_init)
        Module Exit: module_exit(mymodule_exit)
   - **Logging**: Use printk() for logging kernel messages. Output appears in dmesg.


## Kernel Headers

Kernel headers are crucial for developing kernel modules. They provide the necessary definitions and interfaces used by the kernel and modules.

### Importance of Kernel Headers Compatibility

   - Consistency: Kernel headers must be compatible with the Linux kernel version you are building against. This ensures that the API and structures used by the kernel and modules are aligned.
   - Avoid Breakages: Using headers from a different kernel version can lead to incompatibilities and errors during compilation or runtime. Kernel APIs and internal structures may change between versions.
   - Development Environment: Always use the headers that match the kernel version running on your system. This can be verified using the command: `uname -r`
   - Kernel Headers Location:Typically located at /usr/src/linux-headers-$(uname -r)/include for the currently running kernel version. 

## Building Dynamic Modules

### Method 1: Using Kernel Makefile

1. Navigate to the directory of your kernel module.
2. Run:
```
 make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
```
### Method 2: Creating a Makefile

1. Create a Makefile in your module directory with the following content:

```
obj-m := mydriver.o

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

2. Run make in the module directory to build the module.


## License Issue

Ensure your module’s license matches the kernel’s license, usually GPL. Add this line to your module code:

```
MODULE_LICENSE("GPL");

```

**Note**: .ko files are not executable; they are kernel object files loaded into the kernel. The kernel handles the execution of the code in these files.

**Note**: the size of dynamic in Ram is larger than static.
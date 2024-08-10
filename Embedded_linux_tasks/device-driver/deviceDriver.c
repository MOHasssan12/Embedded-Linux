#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <stdio.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
dev_t mydevice_id;

static int lkn_init(void) {
  printf("hello from init \n");
  alloc_chrdev_region(&mydevice_id, 0, 1, "iti_driver");
  return 0;
}

static void lkn_exit(void) { printk("hello from exit\n"); }

module_init(lkn_init); // Register the initialization function
module_exit(lkn_exit); // Register the exit function

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("A simple example module");
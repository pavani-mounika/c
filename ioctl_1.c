#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include <linux/ioctl.h>


#define WR_VALUE _IOW('a','a',char*)
#define RD_VALUE _IOR('a','b',char*)
#define buf 400
char msg[buf];

dev_t dev = 0;
static struct class *dev_class;
static struct cdev manusree;



static int dvr_open(struct inode *inode, struct file *file);
static int dvr_release(struct inode *inode, struct file *file);
static long dvr_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .open           = dvr_open,
        .unlocked_ioctl = dvr_ioctl,
        .release        = dvr_release,
};

static int dvr_open(struct inode *inode, struct file *file)
{
        printk(KERN_INFO "Device File Opened...!!!\n");
        return 0;
}

static int etx_release(struct inode *inode, struct file *file)
{
        printk(KERN_INFO "Device File Closed...!!!\n");
        return 0;
}

static long dvr_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
         switch(cmd) {
                case WR_VALUE:
                        copy_from_user(&msg ,(char *) arg, sizeof(msg));
                        printk(KERN_INFO "string in write = %s\n", msg);
                        break;
                case RD_VALUE:
                        copy_to_user((char*) arg, &msg, sizeof(msg));
			printk(KERN_INFO"string to read=%s\n",arg);
                        break;
        }
        return 0;
}


static int __init dvr_init(void)
{
        /*Allocating Major number*/
        if((alloc_chrdev_region(&dev, 0, 1, "manusree")) <0){
                printk(KERN_INFO "Cannot allocate major number\n");
                return -1;
        }
        //printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

        /*Creating cdev structure*/
        cdev_init(&manusree,&fops);

        /*Adding character device to the system*/
        if((cdev_add(&manusree,dev,1)) < 0){
            printk(KERN_INFO "Cannot add the device to the system\n");
            goto r_class;
        }

        /*Creating struct class*/
        if((dev_class = class_create(THIS_MODULE,"manusree")) == NULL){
            printk(KERN_INFO "Cannot create the struct class\n");
            goto r_class;
        }

        /*Creating device*/
        if((device_create(dev_class,NULL,dev,NULL,"manusree")) == NULL){
            printk(KERN_INFO "Cannot create the Device 1\n");
            goto r_device;
        }
        printk(KERN_INFO "Device Driver Insert...Done!!!\n");
    return 0;

r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;
}

void __exit dvr_exit(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&manusree);
        unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "Device Driver Remove...Done!!!\n");
}

module_init(dvr_init);
module_exit(dvr_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EmbeTronicX <embetronicx@gmail.com or admin@embetronicx.com>");
MODULE_DESCRIPTION("A simple device driver");
MODULE_VERSION("1.5");

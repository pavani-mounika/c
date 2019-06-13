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


/*_IOR(int type, int number, data_type), used for an ioctl that reads data from the device driver. The driver will be allowed to return sizeof(data_type) bytes to the user

_IOW(int type, int number, data_type), similar to _IOR, but used to write data to the driver.*/

#define WR_VALUE _IOW('a','a',char *)
#define RD_VALUE _IOR('a','b',char *)
#define DVRNAME "srinivas"
#define MAX 40
char buf[MAX];

dev_t mydev;
static struct class *myclass;
struct cdev *cdev;

static int ioctl_open(struct inode *inode,struct file *file)
{
	printk("opened\n");
	return 0;
}

static int ioctl_release(struct inode *inode,struct file *file)
{
	printk("closed\n");
	return 0;
}

static int ioctl_ops(struct file *file,unsigned int cmd,unsigned long arg)
{
	switch(cmd){
		case WR_VALUE: copy_from_user(buf,(void __user *)arg,sizeof(arg));
				printk("write:%s\n",buf);
				break;
		case RD_VALUE: copy_to_user((void __user *)arg,buf,sizeof(buf));
				printk("read:%s\n",arg);
				break;
		}
	return 0;
}

static struct file_operations fops={
	.owner=THIS_MODULE,
	.open = ioctl_open,
	.unlocked_ioctl = ioctl_ops,
	.release = ioctl_release
};

static int __init ioctl_init(void)
{
	if(alloc_chrdev_region(mydev,0,1,DVRNAME)<0) // struct dev_t, minor no,count,name of driver	
	{
		printk("error in alloc\n");
		return 0;
	}
	cdev_init(&cdev,&fops);
	if(cdev_add(&cdev,mydev,1)<0)
	{
		printk("Error in cdev_add\n");
		return 0;
	}
	myclass=class_create(THIS_MODULE,"class");
	if(device_create(myclass,NULL,mydev,NULL,"srinivas")<0)
	{
		printk("error in device_class\n");
		return 0;
	}
	printk("inserted\n");
	return 0;
}

static void __exit ioctl_exit(void)
{
	printk("removed\n");
	device_destroy(myclass,mydev);
	class_destroy(myclass);
	cdev_del(&cdev);
	unregister_chrdev_region(mydev,1);
}

module_init(ioctl_init);
module_exit(ioctl_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SRINIVAS");
MODULE_DESCRIPTION("My device driver");
MODULE_VERSION("4.4.0");

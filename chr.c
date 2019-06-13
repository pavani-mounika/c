#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include<linux/errno.h>
#include<linux/device.h>
//#include<linux/current.h>

#define CHAR_DEV_NAME "lockdvr"
#define MAX_LENGTH 4000
#define SUCCESS 0
struct cdev *lock_cdev;
dev_t mydev;
int count=1;
static struct class *lock_class;
static char *char_device_buf;

static int char_dev_open(struct inode *inode,struct file  *file)
{
	printk(KERN_INFO "Open operation invoked \n");
	return SUCCESS;
}
static int char_dev_release(struct inode *inode, struct file *file)
{

	printk("This is release operation in driver...\n\n");
	return SUCCESS;
}
static int char_dev_write(struct file *file, const char *buf, size_t lbuf, loff_t *ppos)
{
	printk(KERN_INFO "This is write operation in driver...\n\n");
	int nbytes=copy_from_user(char_device_buf+*ppos,buf,sizeof(buf));		
	printk(KERN_INFO"string in write mode:%s\n",char_device_buf);
	*ppos+=nbytes;
 	return SUCCESS;
}
static int char_dev_read(struct file *file, char *buf, size_t lbuf, loff_t *ppos)	
{
	printk("This is read operation in driver");
	int nbytes = copy_to_user (buf, char_device_buf+ *ppos , sizeof(char_device_buf));
	printk("string in read::%s\n",buf);
	*ppos+=nbytes;
	return nbytes;
}
static struct file_operations char_dev_fops = {
	
	.owner = THIS_MODULE,
	.write = char_dev_write,
	.read = char_dev_read,
	.open = char_dev_open,
	.release = char_dev_release,
};

static int __init char_dev_init(void)
{
	printk("This is init operation in driver...\n\n");
	int ret;
	if(alloc_chrdev_region(&mydev,0,count,CHAR_DEV_NAME)<0)
	{
			return -1;
	}
	if(!(lock_cdev= cdev_alloc()))
	{
		unregister_chrdev_region(mydev,count);
		return -1;
	}
	cdev_init(lock_cdev,&char_dev_fops);	
	ret=cdev_add(lock_cdev,mydev,count);	
	if( ret < 0 ) {
		printk("Error registering device driver\n");
		cdev_del(lock_cdev);
		return ret;
		}
	lock_class=class_create(THIS_MODULE,"VIRTUAL");
	device_create(lock_class,NULL,mydev,NULL,"lock");
	char_device_buf=(char*)kmalloc(MAX_LENGTH,GFP_KERNEL);
	return 0;

}
static void __exit char_dev_exit(void)
{
	device_destroy(lock_class,mydev);
	class_destroy(lock_class);
	cdev_del(lock_cdev);
	printk("This is exit operation in driver...\n\n");
	unregister_chrdev_region(mydev,1);	
	printk(KERN_INFO "\n Driver unregistered \n");
	kfree(char_device_buf);
}



module_init(char_dev_init);
module_exit(char_dev_exit);



MODULE_AUTHOR("SREE");
MODULE_DESCRIPTION("Character Device Driver - Test");
MODULE_LICENSE("GPL");



























































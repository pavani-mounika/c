#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>
#include<asm/uaccess.h>
#include<linux/cdev.h>
#include<linux/device.h>

#define CHARDVR "manu"
#define MLEN 4000
static struct class *manu_class;

dev_t mydev;
struct cdev *cdev;
static char buf[MLEN];

static int char_open(struct inode *inode,struct file  *file)
{
	printk(KERN_INFO "Open operation invoked \n");
	return 0;
}

static int char_release(struct inode *inode, struct file *file)
{

	printk("This is release operation in driver...\n\n");
	return 0;
}

static int char_read(struct file *file, char *msg, size_t lbuf, loff_t *ppos)	
{
	printk("This is read operation in driver");
	int nbytes = copy_to_user (msg,buf+ *ppos , sizeof(buf));
	printk("string in read::%s\n",msg);
	*ppos+=nbytes;
	return nbytes;
}

static int char_write(struct file *file, const char *msg, size_t lbuf, loff_t *ppos)
{
	printk(KERN_INFO "This is write operation in driver...\n\n");
	int nbytes=copy_from_user(buf+*ppos,msg,sizeof(msg));		
	printk(KERN_INFO"string in write mode:%s\n",buf);
	*ppos+=nbytes;
 	return 0;
}

static struct file_operations fops = {
	
	.owner = THIS_MODULE,
	.write = char_write,
	.read = char_read,
	.open = char_open,
	.release = char_release,
};

static int __init char_init(void)
{
	printk("in init func\n");
	int ret;
	if(alloc_chrdev_region(&mydev,0,1,CHARDVR)<0)
	{
		printk("error in init\n");
		return -1;
	}
	if(!(cdev=cdev_alloc()))
	{
		printk("error in cdev\n");
		unregister_chrdev_region(mydev,1);
		return -1;
	}
	cdev_init(cdev,&fops);
	ret=cdev_add(cdev,mydev,1);
	if(ret<0)
	{
               printk("error in add\n");
               unregister_chrdev_region(mydev,1);
               return -1;
	}
	manu_class=class_create(THIS_MODULE,"manu_cls");
	device_create(manu_class,NULL,mydev,NULL,"dev_cls");
	return 0;
}

static void __exit char_exit(void)
{
	cdev_del(cdev);
	device_destroy(manu_class,mydev);
	class_destroy(manu_class);
	printk("in exit func\n");
        unregister_chrdev_region(mydev,1);
}

module_init(char_init);
module_exit(char_exit);

MODULE_AUTHOR("SREE");
MODULE_DESCRIPTION("Character Device Driver - Test");
MODULE_LICENSE("GPL");

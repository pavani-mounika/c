#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/sched.h>

#define MAXLEN 100
#define CHARDVR "sree_drv"

dev_t mydev;
struct cdev *manusree_cdev;
static struct class *chr_class;
static char buffer[MAXLEN];

static int chr_open(struct inode *inode,struct file *file)
{
	printk("in open function\n");
	return 0;
}

static int chr_release(struct inode *inode,struct file *file)
{
	printk("in release function\n");
	return 0;
}

static int chr_write(struct file *file,const char *buf,size_t lbuf,loff_t *ppos)
{
	int nbytes;
	nbytes = lbuf - copy_from_user(buffer+ *ppos,buf,sizeof(buf));
	printk("write:%s\n",buffer);
	*ppos += nbytes;
	return 0;
}	

static int chr_read(struct file *file,char *buf,size_t lbuf,loff_t *ppos)
{
	int nbytes;
	nbytes = lbuf - copy_to_user(buf,buffer+ *ppos,sizeof(buffer));
	printk("read:%s",buf);
	*ppos += nbytes;
	return 0;
}

static struct file_operations cofs={
	.owner = THIS_MODULE,
	.read = chr_read,
	.write = chr_write,
	.open = chr_open,
	.release = chr_release
};

static int __init chr_init(void)
{
	printk("in init function\n");
	int ret;
	ret = alloc_chrdev_region(&mydev,0,1,CHARDVR); //dev_t *dev,minor num(unsigned),count(unsigned),const char * name
	if(ret!=0)
	{
		printk("error in alloc\n");
		return 0;
	}
	manusree_cdev=cdev_alloc(); //contain info of char drv
	cdev_init(manusree_cdev,&cofs);
	cdev_add(manusree_cdev,mydev,1);
	chr_class = class_create(manusree_cdev,"VIRTUAL");
	device_create(chr_class,NULL,mydev,NULL,"manusree_drv");
}

static void __exit chr_exit(void)
{
	printk("in exit function\n");
	cdev_del(manusree_cdev);
	unregister_chrdev_region(mydev,1);
}

module_init(chr_init);
module_exit(chr_exit);

MODULE_AUTHOR("SRINIVAS");
MODULE_DESCRIPTION("DYN CHAR DRIVER");
MODULE_LICENSE("GPL");

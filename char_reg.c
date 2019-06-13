#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
#include<linux/slab.h>

#define MAJORNO 300
#define MINORNO 0
#define CHAR_NAME "manu_cdrv"
#define MAXLEN 4000
#define SUCESS 0

static char buffer[MAXLEN];
struct cdev *manu_cdev;
dev_t mydev;
int count=1,inuse=0;

static 	int chr_open(struct inode *inode,struct file *file)
{
	printk("in open function\n");
	if(inuse)
	{
		printk("busy cannot open\n");
	}
	inuse=1;
	printk("deice opened\n");
	return SUCESS;
}

static int chr_release(struct inode *inode,struct file *file)
{
	printk("in release function\n");
	inuse=1;
	return SUCESS;
}

static int chr_write(struct file *file,const char *buf,size_t lbuf,loff_t *ppos)
{
	int nbytes;
	printk("in write function\n");
	nbytes = lbuf - copy_from_user(buffer+ *ppos,buf,sizeof(buf)); //(void __user *to,const void *from,unsigned long n(size)
	*ppos += nbytes;
	printk("write:%s\n",buffer);
	return SUCESS;
}

static int chr_read(struct file *file,char *buf,size_t lbuf,loff_t *ppos)
{
	int nbytes;
	printk("in read function\n");
	nbytes = lbuf - copy_to_user(buf,buffer+ *ppos,sizeof(buffer));	// void *from,const void *from, long n(size)
	*ppos += nbytes;
	printk("read:%s\n",buffer);
	return SUCESS;
}

static struct file_operations chr_ops={
	.owner = THIS_MODULE,
	.read = chr_read,
	.write = chr_write,
	.open = chr_open,
	.release = chr_release
};	

static int __init char_init(void)
{
	int ret;
	printk("in init function of driver\n");
	mydev=MKDEV(MAJORNO,MINORNO);
	ret=register_chrdev_region(mydev,count,CHAR_NAME); //dev_t first, count(unsigned), char *name
	if(ret!=0)
	{
		printk("error register_chrdev_region\n");
		return SUCESS;
	}
	manu_cdev=cdev_alloc();	// cdev struct used for alloc cdev struct the char driver info present here
	cdev_init(manu_cdev,&chr_ops); // struct cdev and fops struct add
	cdev_add(manu_cdev,mydev,count); // struct cdev and dev_t and count
	
	return SUCESS;
}

static void __exit char_exit(void)
{
	printk("This is exit operation in driver...\n\n");
	
	 cdev_del(manu_cdev);	// struct cdev
	 unregister_chrdev_region(mydev,1); // mydev_t, count	
	 printk(KERN_INFO "\n Driver unregistered \n");
}

module_init(char_init);
module_exit(char_exit);

MODULE_AUTHOR("MANU");
MODULE_DESCRIPTION("BASIC CHAR DRIVER");
MODULE_LICENSE("GPL");

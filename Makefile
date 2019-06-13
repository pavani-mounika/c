#obj-m += char_reg.o
#obj-m += char_alloc.o
#obj-m += chr.o
#obj-m += ioctl.o
#obj-m += char.o
#obj-m +=ioctlnew.o
obj-m += ioctl1.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

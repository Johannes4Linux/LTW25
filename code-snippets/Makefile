# Kernel Header Makefile kompiliert i2c_hello.c automatisch zu i2c_hello.o file
obj-m += i2c_hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


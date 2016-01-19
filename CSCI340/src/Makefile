TARGET = num_pagefaults.ko

CURRENT = $(shell uname -r)
KDIR = /lib/modules/$(CURRENT)/build
PWD = $(shell pwd)

obj-m := num_pagefaults.o

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o num_pagefaults.ko .*.cmd .*.flags *.mod.c

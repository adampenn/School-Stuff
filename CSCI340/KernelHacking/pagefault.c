#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>

static int pagefault_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, linux_proc_banner,
		utsname()->sysname,
		utsname()->release,
		utsname()->pagefault);
	return 0;
}

static int pagefault_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, pagefault_proc_show, NULL);
}

static const struct file_operations pagefault_proc_fops = {
	.open		= pagefault_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_pagefault_init(void)
{
	proc_create("pagefault", 0, NULL, &pagefault_proc_fops);
	return 0;
}
fs_initcall(proc_pagefault_init);

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>
#include <linux/pagemap.h>

MODULE_LICENCE("GPL");

static int num_pagefaults_proc_show(struct seq_file *m, void *v)
{
	unsigned long longUns = (unsigned long)this_cpu_read(vm_event_states.event[PGFAULT]);
	seq_printf(m, "%lu\n", longUns);
	return 0;
}

static int num_pagefaults_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, num_pagefaults_proc_show, NULL);
}

static const struct file_operations num_pagefaults_proc_fops = {
	.open		= num_pagefaults_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_num_pagefaults_init(void)
{
	proc_create("num_pagefaults", 0, NULL, &num_pagefaults_proc_fops);
	return 0;
}
fs_initcall(proc_num_pagefaults_init);

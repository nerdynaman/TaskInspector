#include<linux/module.h>
#include<linux/cred.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/moduleparam.h>
#include<linux/pid.h>
#include<linux/cdev.h>
#include<linux/sched.h>
#include<linux/proc_fs.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
long pid = 1;
module_param(pid, long, 0);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("NAMAN Aggarwal");
MODULE_DESCRIPTION("creating a module to get details for a pid"); 
static int __init begin(void)
{
	struct task_struct *taskStructInfo = pid_task(find_vpid(pid), PIDTYPE_PID);
	if(taskStructInfo==NULL){
		printk(KERN_INFO "ERROR");
	}
	printk(KERN_INFO "PID: %d\n" "USER ID: %d\n" "PROCESS GROUP ID: %d\n""COMMAND PATH: %s\n",(int)taskStructInfo->pid,(int)taskStructInfo->cred->uid.val,(int)taskStructInfo->cred->gid.val,(char*)taskStructInfo->comm);
	return 0;
}
static void __exit out(void)
{
    printk(KERN_INFO "removing module\n");
}
module_init(begin);      
module_exit(out);   

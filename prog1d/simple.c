// Brian McIlwain
// Write a kernel module.
// [16] If you select this problem, you will need to demonstrate it prior to the assignment
// due date, though you may submit your code earlier for the purpose of determining extra 
// credit. You must demonstrate to receive the credit, however.
// If you have your own Linux device (or a LiveCD/LiveDVD on your laptop), you may write a
// simple kernel module (per the Chapter 2 Programming Projects: Part I--Creating Kernel 
// Modules), then demonstrate module insertion and removal, providing evidence via dmesg 
// output. Call the module simple.c. If you are able to write the kernel module from memory
// while I watch, and demonstrate its use, I will give you a fox sticker (+1).

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    return 0;
}

void simple_exit(void)
{
    printk(KERN_INFO "Removing Module\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

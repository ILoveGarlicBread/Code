#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

void dfs(struct task_struct *task) {
	struct task_struct *child; 
	struct list_head *list; 
	
	printk(KERN_INFO "Name: %-20s State: %ld\tProcess ID: %d\n", task->comm, task->stats, task->pid);
	
	list_for_each(list, &task->children) { //Loop over children
		child = list_entry(list, struct task_struct, sibling); //Get child
		dfs(child); 
	}
}

int entryPoint(void) {
	printk(KERN_INFO "Inserting ListTasksDFS\n");	
	
	printk(KERN_INFO "Started listing tasks\n");
	
	dfs(&init_task); 
	
	printk(KERN_INFO "Stopped listing tasks\n");
	return 0;
}

void exitPoint(void) {
	printk(KERN_INFO "Removing ListTasksDFS\n");
}

module_init(entryPoint);
module_exit(exitPoint);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("List tasks using DFS");
MODULE_AUTHOR("Youssef Hassan, 900132871");

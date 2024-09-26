#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/moduleparam.h>


// add module with: sudo inmod collatz.ko initial_value = <int>
#define PROC_NAME "collatz"
struct collatz_element {
    int value;
    struct list_head list; 
};

static LIST_HEAD(collatz_list);

static int initial_value = 0;
module_param(initial_value, int, 0);
MODULE_PARM_DESC(initial_value, "Initial value for the Collatz sequence");

// Module entry function
static int __init collatz_init(void)
{
    struct collatz_element *elem;
    int current_value;
    
    if (initial_value <= 0) {
        printk(KERN_INFO "Invalid initial value. Must be greater than 0.\n");
        return -EINVAL; 
    }

    printk(KERN_INFO "Loading collatz module...\n");
    printk(KERN_INFO "Generating Collatz sequence for initial value: %d\n", initial_value);

    // Initialize the first value of the sequence
    current_value = initial_value;

    while (current_value > 1) {
        // Allocate memory for the new element
        elem = kmalloc(sizeof(*elem), GFP_KERNEL);
        if (!elem) {
            printk(KERN_ERR "Memory allocation failed for Collatz element.\n");
            return -ENOMEM; // Out of memory error
        }

        // Set the value and add it to the list
        elem->value = current_value;
        INIT_LIST_HEAD(&elem->list);
        list_add_tail(&elem->list, &collatz_list);

        // Log the current value to the kernel log buffer
        printk(KERN_INFO "Collatz value: %d\n", current_value);

        // Collatz formula
        if (current_value % 2 == 0) {
            current_value /= 2;
        } else {
            current_value = 3 * current_value + 1;
        }
    }

    // Add the final value "1" to the list
    elem = kmalloc(sizeof(*elem), GFP_KERNEL);
    if (!elem) {
        printk(KERN_ERR "Memory allocation failed for Collatz element.\n");
        return -ENOMEM;
    }
    elem->value = 1;
    list_add_tail(&elem->list, &collatz_list);
    printk(KERN_INFO "Collatz value: %d\n", elem->value);

    return 0;
}

// Module exit function
static void __exit collatz_exit(void)
{
    struct collatz_element *elem, *tmp;

    printk(KERN_INFO "Unloading collatz module and freeing memory...\n");

    // Traverse the linked list and free the allocated memory
    list_for_each_entry_safe(elem, tmp, &collatz_list, list) {
        printk(KERN_INFO "Removing Collatz value: %d\n", elem->value);
        list_del(&elem->list); 
        kfree(elem); 
    }
}

module_init(collatz_init);
module_exit(collatz_exit);

MODULE_AUTHOR("Lam");
MODULE_DESCRIPTION("Generate the Collatz sequence.");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");

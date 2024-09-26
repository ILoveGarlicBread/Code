#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>

#define PROC_NAME "color_list"
struct color {
    char *name;
    int r, g, b; 
    struct list_head list; // Kernel's list_head structure
};

// Declare and initialize the head of the linked list
static LIST_HEAD(color_list);

// Module entry function
static int __init color_list_init(void)
{
    struct color *c1, *c2, *c3, *c4;
    struct color *ptr;
    int i = 0;

    printk(KERN_INFO "Loading color_list module...\n");

    // Allocate memory and initialize first color struct
    c1 = kmalloc(sizeof(*c1), GFP_KERNEL);
    c1->name = "Red";
    c1->r = 255; c1->g = 0; c1->b = 0;
    INIT_LIST_HEAD(&c1->list);
    list_add_tail(&c1->list, &color_list);

    // second color struct
    c2 = kmalloc(sizeof(*c2), GFP_KERNEL);
    c2->name = "Green";
    c2->r = 0; c2->g = 255; c2->b = 0;
    list_add_tail(&c2->list, &color_list);

    // third color struct
    c3 = kmalloc(sizeof(*c3), GFP_KERNEL);
    c3->name = "Blue";
    c3->r = 0; c3->g = 0; c3->b = 255;
    list_add_tail(&c3->list, &color_list);

    // fourth color struct
    c4 = kmalloc(sizeof(*c4), GFP_KERNEL);
    c4->name = "Yellow";
    c4->r = 255; c4->g = 255; c4->b = 0;
    list_add_tail(&c4->list, &color_list);

    // Traverse the linked list and print the color 
    list_for_each_entry(ptr, &color_list, list) {
        printk(KERN_INFO "Color %d: %s (R: %d, G: %d, B: %d)\n", i++, ptr->name, ptr->r, ptr->g, ptr->b);
    }

    return 0;
}

// Module exit function
static void __exit color_list_exit(void)
{
    struct color *ptr, *tmp;
    printk(KERN_INFO "Unloading color_list module and freeing memory...\n");

    // Traverse the linked list and free the allocated memory
    list_for_each_entry_safe(ptr, tmp, &color_list, list) {
        printk(KERN_INFO "Removing color: %s\n", ptr->name);
        list_del(&ptr->list); // Remove from the list
        kfree(ptr); // Free the allocated memory
    }
}

module_init(color_list_init);
module_exit(color_list_exit);

MODULE_AUTHOR("Lam");
MODULE_DESCRIPTION("module with a linked list of color structs.");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");

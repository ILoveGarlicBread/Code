#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

#define BUFFER_SIZE 128
#define PROC_NAME "pid_module"

/* the current pid */
static int current_pid;

static ssize_t proc_read(struct file *file, char *buf, size_t count,
                         loff_t *pos);
static ssize_t proc_write(struct file *file, const char __user *usr_buf,
                          size_t count, loff_t *pos);

static const struct proc_ops proc_ops = {
    .proc_read = proc_read,
    .proc_write = proc_write,
};

/* This function is called when the module is loaded. */
static int proc_init(void) {
  // creates the /proc/procfs entry
  proc_create(PROC_NAME, 0666, NULL, &proc_ops);
  printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
  return 0;
}

/* This function is called when the module is removed. */
static void proc_exit(void) {
  // removes the /proc/procfs entry
  remove_proc_entry(PROC_NAME, NULL);
  printk(KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count,
                         loff_t *pos) {
  int rv = 0;
  char buffer[BUFFER_SIZE];
  static int completed = 0;
  struct task_struct *tsk = NULL;
  if (completed) {
    completed = 0;
    return 0;
  }
  tsk = pid_task(find_vpid(current_pid), PIDTYPE_PID);
  if (tsk) {
    rv = snprintf(buffer, BUFFER_SIZE,
                  "command = [%s], pid = [%d], state = [%ld]\n", tsk->comm,
                  current_pid, tsk->stats);
  } else {
    printk(KERN_INFO "Invalid PID %d!", current_pid);
    return 0;
  }
  completed = 1;
  // copies the contents of kernel buffer to userspace usr_buf
  if (copy_to_user(usr_buf, buffer, rv)) {
    rv = -1;
  }
  return rv;
}

/* This function is called each time we write to the /proc file system. */
static ssize_t proc_write(struct file *file, const char __user *usr_buf,
                          size_t count, loff_t *pos) {
  char *k_mem;
  // allocate kernel memory
  k_mem = kmalloc(count, GFP_KERNEL);
  /* copies user space usr_buf to kernel buffer */
  copy_from_user(k_mem, usr_buf, count);
  // k_mem[count] = '\0';   // make sure k_mem is null-terminated
  kstrtoint(k_mem, 10, &current_pid);
  printk(KERN_INFO "Set current PID to %d", k_mem);
  kfree(k_mem);
  return count;
}

/* Macros for registering module entry and exit points. */
module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL"); // MIT is not allowed here, because this module calls
                       // pid_task(), which is GPL only
MODULE_DESCRIPTION("Report the task information when /proc/pid is read, after "
                   "PID is written to /proc/pid.");
MODULE_AUTHOR("Keith Null");

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/types.h>
#include <uapi/asm-generic/errno-base.h>
#include <linux/string.h>

SYSCALL_DEFINE2(sh_task_info, int, pid, char *, filename)
{
  if (pid > 32768 || pid <= 0)
    return -EINVAL;
  struct file *fl;
  struct task_struct *task;
  mm_segment_t memory_flag;
  int write_flag;
  long out;

 

  memory_flag = get_fs();

  set_fs(KERNEL_DS);

  char data[1000] = "";
  char file_name[250];

  out = strncpy_from_user(file_name, filename, sizeof(file_name));
 
  if (out < 0)
  {
    return -EFAULT;
  }
  if (out == sizeof(filename))
  {
    return -EFAULT;
  }
  
  fl = filp_open(file_name, O_WRONLY | O_CREAT, 0644);

  task = pid_task(find_vpid(pid), PIDTYPE_PID);
  
  char data1[100] = "";
  char data2[100] = "";
  char data3[100] = "";
  char data4[100] = "";
  char data5[100] = "";
  char data6[100] = "";
  char data7[100] = "";

  char num_data1[100];
  char num_data2[100];
  char num_data3[100];
  char num_data4[100];
  char num_data5[100];
  char num_data6[100];
  char num_data7[100];
  

  printk(KERN_INFO "Process Name: %s\nProcess ID: %ld\nProcess State: %ld\nProcess Priority: %ld\nProcess Static Priority: %ld\nProcess utime: %ld\nProcess Group: %ld\n", task->comm, (long)task->pid, (long)task->state, (long)task->prio, (long)task->static_prio, (long)task->utime, (long)task_pgrp_vnr(task));

  sprintf(num_data1, "%s\n", task->comm);
  sprintf(num_data2, "%ld\n", (long)task->pid);
  sprintf(num_data3, "%ld\n", (long)task->state);
  sprintf(num_data4, "%ld\n", (long)task->prio);
  sprintf(num_data5, "%ld\n", (long)task->static_prio);
  sprintf(num_data6, "%ld\n", (long)task->utime);
  sprintf(num_data7, "%ld\n", (long)task_pgrp_vnr(task));

  strcat(data1, "Process Name: ");
  strcat(data2, "Process ID: ");
  strcat(data3, "Process State: ");
  strcat(data4, "Process Priority: ");
  strcat(data5, "Process Static Priority: ");
  strcat(data6, "Process utime: ");
  strcat(data7, "Process Group: ");

  strcat(data1, num_data1);
  strcat(data2, num_data2);
  strcat(data3, num_data3);
  strcat(data4, num_data4);
  strcat(data5, num_data5);
  strcat(data6, num_data6);
  strcat(data7, num_data7);

  strcat(data, data1);
  strcat(data, data2);
  strcat(data, data3);
  strcat(data, data4);
  strcat(data, data5);
  strcat(data, data6);
  strcat(data, data7);

  write_flag = vfs_write(fl, data, strlen(data), &fl->f_pos);

  if (write_flag < 0)
  {
    return -EFAULT;
  }

  set_fs(memory_flag);

  filp_close(fl, NULL);
  return 0;
}

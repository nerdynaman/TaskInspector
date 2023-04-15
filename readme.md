## Task Inspector

we have created a module which use functions `pid_task`, `find_vpid` to find the pid and task struct of a given process further our module requires two function.
1) For initialisation we have used `init_module`
2) For exit we have used `cleanup_module`

 We have used `printk` to print the message on the kernel log. 
upon loading of module input has to be given in the form of process id and output is printed on the kernel log and upon deload of module the output is printed on the kernel log.

## Installation

```bash
make
sudo insmod task_inspector.ko pid={insert pid here}
# sudo rmmod task_inspector.ko # to unload the module
```

## Usage

```bash
dmesg
```

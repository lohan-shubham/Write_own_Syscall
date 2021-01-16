# Writing own Syscall 
>`Purpose:` Course Project at [IIITD](https://www.iiitd.ac.in/)
>
>[`Instructions:`](/instructions.pdf) (Credits- [Operating System](http://techtree.iiitd.edu.in/viewDescription/filename?=CSE231))

# Objective
```
You have to create your own system call in C, called sh task info(), which
takes argument as PID. It would need to search out the task struct() corresponding to the PID and print out all the fields corresponding to it and also
save it in a file. The file name also needs to be supplied as an argument to the
system call.
You also would require to handle errors in user inputs, such as incorrect arguments, through appropriate errno and function return values (e.g. 0 signaling
correct input, while 1 signaling incorrect input).
You are supposed to use Linux/kernel v5.9 distribution for the assignment,
i.e. the system call should be written for the said version. You would need
to first download the kernel version from the official repository of the Linux
distribution that you are using (e.g. Ubuntu) and compile and boot that up.
The system call should be written and tested for this version
```

# Work:
>- first download linux kernel 5.9.1 from [here](https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.1.tar.gz)
>
>- extract zip file and place diff.txt in linux folder.
>
>- then patch the diff file using this command
> 
>   ```sh
>   $ patch -Naur -p1 < diff.txt
>   ```
>  
>- then follow the instruction given in [this](https://medium.com/>anubhav-shrimal/adding-a-hello-world-system-call-to-linux-kernel-dad32875872) link from point 7
>- after restart to test the syscall run this command
>  
>   ```sh
>   $ make run
>   ```
>- run this command check whether syscall is working or not
>
>    ```sh
>    $ sudo dmesg
>    ```

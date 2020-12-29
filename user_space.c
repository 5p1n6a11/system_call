#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define __NR_hello 441

long hello_syscall(void)
{
    return syscall(__NR_hello);
}

int main(int argc, char *argv[])
{
    long retval;
    retval = hello_syscall();

    if (retval < 0) {
        perror("hello system call");
    } else {
        printf("success: hello system call\n");
    }

    return 0;
}


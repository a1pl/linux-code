.section .text
.global _start

_start:
    # execve("/bin/sh", argv, NULL)
    mov $59, %rax              # execve syscall number
    mov $filename, %rdi        # filename: "/bin/sh"
    mov $argv, %rsi            # argv array
    xor %rdx, %rdx             # envp = NULL
    syscall
    
    # exit(1) if execve fails
    mov $60, %rax              # exit syscall
    mov $1, %rdi               # exit code 1
    syscall

.section .rodata
filename:
    .string "/bin/sh"

script_path:
    .string "/sbin/init.sh"

argv:
    .quad filename             # argv[0] = "/bin/sh"
    .quad script_path          # argv[1] = "/sbin/init.sh"  
    .quad 0                    # argv[2] = NULL (terminator)

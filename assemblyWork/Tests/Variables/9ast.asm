section .text
    global _start            ;must be declared for linker (ld)

_start:                      ;tell linker entry point
    mov edx, 9               ;message length
    mov ecx, stars           ;message to write
    mov ebx, 1               ;file descriptor (stdout)
    mov eax, 4               ;system call (sys_write)
    int 80h                  ;call the kernel

    mov edx, 1               ;message length
    mov ecx, newln           ;message to write
    mov ebx, 1               ;file descriptor (stdout)
    mov eax, 4               ;system call (sys_write)
    int 80h                  ;call the kernel

    mov eax, 1               ;system call number (sys_exit)
    int 80h                  ;call kernel

section .data
    stars times 9 db '*'
    newln db 0x0a

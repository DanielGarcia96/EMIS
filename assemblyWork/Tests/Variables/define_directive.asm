section .text
    global _start            ;must be declared for linker (gcc)

_start:                      ;tell linker entry point
    mov edx, 1               ;message length
    mov ecx, choice          ;message to write
    mov ebx, 1               ;file descriptor (stdout)
    mov eax, 4               ;system call number (sys_write)
    int 0x80                 ;call kernel


    mov edx, 1               ;message length
    mov ecx, newln           ;message to write
    mov ebx, 1               ;file descriptor (stdout)
    mov eax, 4               ;system call number (sys_write)
    int 0x80                 ;call kernel

    mov eax, 1               ;system call number (sys_exit)
    mov ebx, 0               ;exit value
    int 80h

section .data
    choice db 'y'
    newln db 0x0a

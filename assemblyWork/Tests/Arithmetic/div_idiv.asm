section .text
    global _start         ;must be declared for using gcc

_start:                   ;tell linker entry point
    mov ax, '8'
    sub ax, '0'

    mov bl, '2'
    sub bl, '0'
    div bl
    add ax, '0'

    mov [res], ax
    mov ecx, msg
    mov edx, len
    mov ebx, 1  ;file descriptor (stdout)
    mov eax, 4  ;system call number (sys_write)
    int 0x80    ;call kernel

    mov ecx, res
    mov edx, 1
    mov ebx, 1  ;file descriptor (stdout)
    mov eax, 4  ;system call number (sys_write)
    int 0x80    ;call kernel

    mov eax, 4  ;system call number (sys_write)
    mov ebx, 1  ;file descriptor (stdout)
    mov ecx, newln
    mov edx, 1
    int 0x80    ;call kernel

    mov eax, 1  ;system call number (sys_exit)
    mov ebx, 0  ;exit value
    int 0x80

section .data
    msg db "The result is: "
    len equ $ - msg
    newln db 0xa

segment .bss
    res resb 1

%assign SYS_EXIT   1
%assign SYS_WRITE  4
%assign STDIN      0
%assign STDOUT     1
section .text
    global _start        ;must be declared for using gcc

_start:                  ;tell linker entry point
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg2
    mov edx, len2
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg3
    mov edx, len3
    int 0x80

    mov eax, SYS_EXIT     ;system call number (sys_exit)
    int 0x80              ;call kernel

section .data
    msg1 db 'Hello, programmers!', 0xa, 0xd
    len1 equ $ - msg1
   
    msg2 db 'Welcome to the world of,', 0xa, 0xd
    len2 equ $ - msg2

    msg3 db 'Linux assembly programming! ', 0xa
    len3 equ $ - msg3
segment .data
    msg db 'Hello world', 0x21, 0x0A
    lenmsg equ $ - msg

segment .bss

segment .text
    global _start

_start:

    mov eax, 4        ;System call to write
    mov ebx, 1        ;Write to STDOUT
    mov ecx, msg      ;Load message into call
    mov edx, lenmsg   ;Load message length into call
    int 80h           ;Call kernel

    mov eax, 1        ;System call to exit
    mov ebx, 0        ;Exit with value zero
    int 80h           ;Call kernel

section .data
    msg db "0010 + 0100 equals: "
    len equ $ - msg
    newln db 0xa

section .bss
    result resb 2

section .text
    global _start

_start:
    mov al, 0x2
    mov bl, 0x4
    mul bl
    mov [result], ax
    add [result], word '0'

    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, len
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 2
    int 0x80
 
    mov eax, 4
    mov ebx, 1
    mov ecx, newln
    mov edx, 1
    int 0x80

exit:
    mov eax, 1
    mov ebx, 0
    int 0x80

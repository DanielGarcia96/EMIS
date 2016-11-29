section .bss
    number resb 5

section .text
    global _start

_start:
    mov eax, 3
    mov ebx, 0
    mov ecx, number
    mov edx, 5
    int 0x80

    mov edx, 0
change_loop:
    inc byte [number+edx]
    inc edx
cmp edx, 4
jne change_loop

    mov eax, 4
    mov ebx, 1
    mov ecx, number
    mov edx, 5
    int 0x80

exit:
    mov eax, 1
    xor ebx, 0
    int 0x80

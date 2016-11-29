section .data
    msg db "Enter a long number: "
    len equ $ - msg
    newln db 0xa
    idx db 10

section .bss
    number resb 5

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, len
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, number
    mov edx, 5
    int 0x80

    xor eax, 0
    mov ebx, 10
    xor edx, 0
    mov ecx, 0

shift_loop:

    mov edx, [number+ecx]
    sub edx, '0'
    add eax, edx 
    mul ebx
    mov edx, 0
    inc ecx

cmp [number+ecx], byte 0xa
jne shift_loop

    add eax, 50
    xor edx, 0
ascii_loop:

    div ebx
    mov [number+ecx], edx
    xor edx, 0
    add byte [number+ecx], '0'
    dec ecx

cmp eax, 0
jle ascii_loop

    mov eax, 4
    mov ebx, 1
    mov ecx, number
    mov edx, 5
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

SYS_WRITE    equ 4
SYS_READ     equ 3
SYS_EXIT     equ 1
STDOUT       equ 1
STDIN        equ 0
EXIT_SUCCESS equ 0

section .data
    msg1 db "This program will display all operations performed on a single-digit number", 0x2e, 0xa
    len1 equ $ - msg1

    msg2 db "Enter the first number: "
    len2 equ $ - msg2

    msg3 db "Enter the second number: "
    len3 equ $ - msg3

    adds db "+"
    subs db "-"
    equals db "="
    newln db 0xa

section .bss
    num1   resw 1
    num2   resw 1
    addres resb 1
    subres resb 1

section .text
    global _start

_start:
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

    mov eax, SYS_READ
    mov ebx, STDIN
    mov ecx, num1
    mov edx, 2
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg3
    mov edx, len3
    int 0x80

    mov eax, SYS_READ
    mov ebx, STDIN
    mov ecx, num2
    mov edx, 2
    int 0x80

    mov eax, [num1]
    sub eax, '0'

    mov ebx, [num2]
    sub ebx, '0'

    add eax, ebx
    add eax, '0'
    mov [addres], eax
    
    mov eax, [num1]
    sub eax, '0'

    mov ebx, [num2]
    sub ebx, '0'

    sub eax, ebx
    add eax, '0'
    mov [subres], eax

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, num1
    mov edx, 2
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, adds
    mov edx, 1
    int 0x80
    
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, num2
    mov edx, 2
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, equals
    mov edx, 1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, addres
    mov edx, 1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, newln
    mov edx, 1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, num1
    mov edx, 2
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, subs
    mov edx, 1
    int 0x80
    
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, num2
    mov edx, 2
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, equals
    mov edx, 1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, subres
    mov edx, 1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, newln
    mov edx, 1
    int 0x80

exit:

    xor eax, ebx
    mov eax, SYS_EXIT
    mov ebx, EXIT_SUCCESS
    int 0x80

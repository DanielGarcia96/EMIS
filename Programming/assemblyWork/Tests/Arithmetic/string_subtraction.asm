SYS_WRITE equ 4
SYS_READ equ 3
STDIN equ 0
STDOUT equ 1

section .data
    msg db "Enter a number and this will spit back with 1 subtracted from it: "
    len equ $ - msg
    newln db 0xa
section .bss
    num resb 10
section .text
    global _start

_start:
    mov eax, SYS_WRITE                             ;Prompt the user for a number
    mov ebx, STDOUT
    mov ecx, msg
    mov edx, len
    int 0x80

    mov eax, SYS_READ                              ;Read the number
    mov ebx, STDIN
    mov ecx, num
    mov edx, 10
    int 0x80

    mov edx, 0                                     ;Find out how long the number is
    length_loop:
        inc edx
    cmp byte [num+edx], 0xa
    jne length_loop

    push edx                                       ;Push the length of the number onto the stack
    mov byte [num+edx], 0                          ;Get rid of the newline by turning it to null
    dec edx                                        ;Readjust the index so I can subtract
    
    sub_loop:
    cmp edx, -1                                    ;I've reached the end of the number, so exit the loop
    je sub_loop_exit
        cmp byte [num+edx], '0'
        je niner                                   ;If it's zero, I might have to continue the loop
        jne decrement                              ;Else I just decrement once and leave
        niner:
            cmp edx, 0                             ;If I'm at the highest order digit, there's nothing left but dec
            jne move_nine
            jmp sub_loop_exit                      
                move_nine:                         ;Otherwise, I move a '9' there and move on to the next digit
                    mov byte [num+edx], '9'        
                    dec edx
                    loop sub_loop
        decrement:
            dec byte [num+edx]
            dec edx
    sub_loop_exit:

    mov eax, SYS_WRITE                             ;Write out the new number
    mov ebx, STDOUT
    mov ecx, num
    pop edx
    int 0x80 

    mov eax, SYS_WRITE                             ;Write a newline to make it clean
    mov ebx, STDOUT
    mov ecx, newln
    mov edx, 1
    int 0x80

_exit:
    mov eax, 1                                     ;Exit with sucess status
    mov ebx, 0
    int 0x80

segment .data
    count dw 0
    value db 15

segment .text
    global _start

_start:
    inc word [count]
    dec byte [value]

    mov ebx, count
    inc word [ebx]
    
    mov esi, value
    dec byte [esi]

    mov eax, 1
    mov ebx, 0
    int 80h

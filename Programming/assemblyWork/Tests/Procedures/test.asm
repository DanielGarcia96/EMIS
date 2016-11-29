segment .data
    myvar: db "hello world", 0x0A, 0
    myvarL: equ $-myvar
    myvar2: db "super bad test", 0x0A, 0
    myvar2L: equ $-myvar2

segment .text
    global _start

_start:
    push myvarL ; store myvarL on the stack
    push myvar  ; store myvar on the stack
    call _hworld

    push myvar2L    ; store myvar2L on the stack
    push myvar2 ; store myvar2 on the stack
    call _hworld2

    mov eax, 1
    mov ebx, 0
    int 0x80

_hworld:
    push ebp    ; store the current value of ebp on the stack (hence +8)
    mov ebp, esp    ; store current esp in ebp

    mov eax, 4
    mov ebx, 1
    mov ecx, [ebp+8]    ; +4 is old ebp
    mov edx, [ebp+12]
    int 0x80

    mov esp, ebp    ; restore ebp to esp
    pop ebp     ; restore ebp
    ret

_hworld2:
    push ebp    ; store old ebp on the stack
    mov ebp, esp    ; store esp in ebp

    mov eax, 4
    mov ebx, 1
    mov ecx, [ebp +8]   ; +4 is old ebp
    mov edx, [ebp +12]
    int 0x80

    mov esp, ebp    ; restore ebp to esp
    pop ebp     ; restore ebp
    ret

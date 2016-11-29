section .text
    global _start        ;must be declared for linker (ld)
_start:                  ;tell linker entry point

    ;writing the name 'Zara Ali'
    mov edx, 9           ;message length
    mov ecx, name        ;message to write
    mov ebx, 1           ;file descriptor (stdout)
    mov eax, 4           ;system call number (sys_write)
    int 0x80             ;call kernel
  
    mov [name], dword 'Nuha'  ;Changed the name to Nuha Ali

    ;writing the name 'Nuha Ali'
    mov edx, 8           ;message length
    mov ecx, name        ;message to write
    mov ebx, 1           ;file descriptor (stdout)
    mov eax, 4           ;system call number (sys_write)
    int 0x80             ;call kernel

    ;write a newline
    mov edx, 1           ;message length
    mov ecx, newln       ;message to write
    mov ebx, 1           ;file descriptor (stdout)
    mov eax, 4           ;system call number (sys_write)
    int 0x80             ;call kernel

    mov eax, 1           ;system call number (sys_exit)
    mov ebx, 0           ;Exit value
    int 0x80

section .data
    name db 'Zara Ali '
    newln db 0x0a

section .text
   global _start    ;must be declared for linker (ld)

_start:            ;tells linker entry point
   mov  edx,len    ;message length
   mov  ecx,msg    ;message to write
   mov  ebx,0x01   ;file descriptor (stdout)
   or   ebx,0x00   ;curious what this does, should do nothing
   mov  eax,0x04   ;system call number (sys_write)
   int  0x80       ;call kernel


   mov  ebx,0x00      ;Have an exit code of 0
   mov  eax,0x01      ;system call number (sys_exit)
   int  0x80       ;call kernel


section .data
msg db 'Hello, world!', 0xa  ;our dear string
len equ $ - msg    ;length of our dear string

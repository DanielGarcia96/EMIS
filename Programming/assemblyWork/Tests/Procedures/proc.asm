section .data
   hello: db 'Hello world', 0x21, 0xa
   h_len: equ $-hello

section .bss
   
section .text

   global _start

hello_world:
   push ebp
   mov  ebp, esp

   mov  eax, [ebp + 8]
   mov  ebx, [ebp + 12]
   mov  ecx, [ebp + 16]
   mov  edx, [ebp + 20]
   int 0x80

   mov esp, ebp
   pop ebp
   ret

print_twelve:
   push ebp
   mov  ebp, esp

   mov eax, 0
   label1:
      inc eax
      push eax
      mov  eax, [ebp + 8]
      mov  ebx, [ebp + 12]
      mov  ecx, [ebp + 16]
      mov  edx, [ebp + 20]
      int 0x80

      pop eax
   cmp eax, 12
   jne label1

   mov esp, ebp
   pop ebp
   ret

exit:
   mov eax, 1
   xor ebx, ebx
   int 0x80

_start:
   push h_len
   push hello
   push 1
   push 4
   call print_twelve

   call exit

SYS_WRITE equ 4
SYS_READ equ 3
STDOUT    equ 1
STDIN     equ 0
section .data
   prompt1:    db 'Enter the first number: '
   prompt1len: equ $-prompt1
   prompt2:    db 'Enter the second number: '
   prompt2len: equ $-prompt2
   spc:   db ' '
   newln: db 0xa
   equal: db '='
   plus:  db '+'
   minus: db '-'

section .bss
   num1 resb 4
   num2 resb 4
   rslt resb 4

section .txt

   global _start

_start:
   ;call read_numbers

   mov byte [num1], '5'
   mov byte [num1+1], 0

   mov byte [num2], '4'
   mov byte [num2+1], 0
 
   push num2
   push num1
   call add_nums

   push eax
   push num2
   push plus
   push num1
   call print_result

   push num2
   push num1
   call sub_nums

   push eax
   push num2
   push minus
   push num1
   call print_result

   call exit

read_numbers:
   push ebp
   mov  ebp, esp

   push ebx

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, prompt1
   mov edx, prompt1len
   int 0x80

   ;sub dword esp, 16
   mov eax, SYS_READ
   mov ebx, STDIN
   mov ecx, num1
   mov ecx, 4
   int 0x80

   mov byte [num1+eax], 0

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, prompt2
   mov edx, prompt2len
   int 0x80

   mov eax, SYS_READ
   mov ebx, STDIN
   mov ecx, num2
   mov ecx, 4
   int 0x80

   mov byte [num2+eax], 0

   pop ebx

   mov esp, ebp
   pop ebp
   ret

;arg1 arg2 arg3 = arg4
print_result:
   push ebp
   mov  ebp, esp

   push ebx

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, [ebp+8]
   mov edx, 4
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, spc
   mov edx, 1
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, [ebp+12]
   mov edx, 1
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, spc
   mov edx, 1
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, [ebp+16]
   mov edx, 4
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, spc
   mov edx, 1
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, equal
   mov edx, 1
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, spc
   mov edx, 1
   int 0x80

   mov ecx, [ebp+20]
   add ecx, '0'
   mov [rslt], cl
   mov byte [rslt+1], 0

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, rslt
   mov edx, 4
   int 0x80

   mov eax, SYS_WRITE
   mov ebx, STDOUT
   mov ecx, newln
   mov edx, 1
   int 0x80

   pop ebx

   mov  esp, ebp
   pop  ebp
   ret

add_nums:
   push ebp
   mov ebp, esp

   mov edx, [ebp+8]
   mov ecx, [ebp+12]

   mov al, [edx]
   sub eax, '0'

   add eax, [ecx]
   sub eax, '0'

   mov  esp, ebp
   pop  ebp
   ret

sub_nums:
   push ebp
   mov ebp, esp

   push ebx

   mov edx, [ebp+8]
   mov ecx, [ebp+12]

   mov al, [edx]
   sub eax, '0'
   mov bl, [ecx]
   sub ebx, '0'

   sub eax, ebx

   push ebx

   mov  esp, ebp
   pop  ebp
   ret

exit:
   mov eax, 1
   xor ebx, ebx
   int 0x80

	.file	"testcalc.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"x=%d, y=%d, z=%d, result=%d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx  /* load argc from the main */
	andl	$-16, %esp     /* clear out the low order bits */
	pushl	-4(%ecx)       /* save argc argument */
	pushl	%ebp           /* save frame pointer */
	movl	%esp, %ebp     /* create new pointer */
	pushl	%ecx           /* save argv argument */
	subl	$36, %esp      /* reserve 36 bytes on stack for functions  */
	movl	$13, 8(%esp)   /* load z into calc */
	movl	$7, 4(%esp)    /* load y into calc */
	movl	$5, (%esp)     /* load x into calc */
	call	calc           /* call calc */
	movl	%eax, 20(%esp) /* mov calc result into printf */
	movl	$13, 16(%esp)  /* load z into printf */
	movl	$7, 12(%esp)   /* load y into printf */
	movl	$5, 8(%esp)    /* load x into printf */
	movl	$.LC0, 4(%esp) /* load format string into printf */
	movl	$1, (%esp)     /* load file descriptor into printf */
	call	__printf_chk   /* call printf */
	movl	$0, %eax       /* return 0 from printf */
	addl	$36, %esp      /* restore 36 bytes from stack */
	popl	%ecx           /* guard against unaligned stack pointer */
	popl	%ebp           /* restore frame pointer */
	leal	-4(%ecx), %esp /* guard against unaligned stack */
	ret                    /* end program */
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits

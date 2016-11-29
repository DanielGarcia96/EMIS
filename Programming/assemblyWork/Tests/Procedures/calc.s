	.file	"calc.c"
	.text
.globl calc
	.type	calc, @function
calc:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	movl	16(%ebp), %ecx
	leal	(%eax,%eax,2), %eax
	addl	8(%ebp), %eax
	leal	(%ecx,%ecx,8), %edx
	leal	(%ecx,%edx,2), %edx
	addl	%edx, %eax
	popl	%ebp
	ret
	.size	calc, .-calc
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits

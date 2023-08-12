	.file	"test.c"
	.text
	.globl	shift_left2_rightn
	.type	shift_left2_rightn, @function
shift_left2_rightn:
.LFB0:
	.cfi_startproc
	leal	0(,%rdi,4), %eax
	movl	%esi, %ecx
	sarl	%cl, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	shift_left2_rightn, .-shift_left2_rightn
	.ident	"GCC: (GNU) 7.3.1 20180303 (Red Hat 7.3.1-5)"
	.section	.note.GNU-stack,"",@progbits

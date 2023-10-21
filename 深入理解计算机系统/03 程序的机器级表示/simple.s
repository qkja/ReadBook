	.file	"simple.c"
	.intel_syntax noprefix
	.text
	.globl	simple
	.type	simple, @function
simple:
.LFB0:
	.cfi_startproc
	mov	eax, esi
	add	eax, DWORD PTR [rdi]
	mov	DWORD PTR [rdi], eax
	ret
	.cfi_endproc
.LFE0:
	.size	simple, .-simple
	.ident	"GCC: (GNU) 7.3.1 20180303 (Red Hat 7.3.1-5)"
	.section	.note.GNU-stack,"",@progbits

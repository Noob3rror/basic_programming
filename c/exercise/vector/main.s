	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC4:
	.ascii "vec1 x: %.2f, y: %.2f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
	leaq	-16(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	leaq	-64(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	call	vec2_add
	movsd	-8(%rbp), %xmm1
	movsd	-16(%rbp), %xmm0
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	movq	%xmm0, %rax
	movq	%rax, %rcx
	movq	%rcx, %xmm0
	movapd	%xmm1, %xmm2
	movq	%rdx, %r8
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	0
	.long	1074003968
	.align 8
.LC1:
	.long	0
	.long	1074528256
	.align 8
.LC2:
	.long	0
	.long	1074855936
	.align 8
.LC3:
	.long	-858993459
	.long	-1074475828
	.ident	"GCC: (Rev3, Built by MSYS2 project) 13.2.0"
	.def	vec2_add;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef

	.file	"test.cc"
	.text
	.p2align 4
	.globl	_Z5solvePiiS_i
	.type	_Z5solvePiiS_i, @function
_Z5solvePiiS_i:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	cmpl	%esi, %ecx
	jge	.L10
	movl	%esi, %r10d
	movq	%rdx, %r11
	movl	%ecx, %r8d
	xorl	%r9d, %r9d
	subl	%ecx, %r10d
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%r11, %rdx
	movl	%r9d, %eax
	testl	%ecx, %ecx
	jg	.L8
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L4:
	testl	%esi, %esi
	jne	.L7
	movslq	%eax, %rsi
	movl	(%rdi,%rsi,4), %r14d
	cmpl	%r14d, 4(%rdi,%rsi,4)
	jne	.L5
.L6:
	addl	$1, %eax
	addq	$4, %rdx
	cmpl	%eax, %r8d
	je	.L14
.L8:
	movl	(%rdx), %esi
	cmpl	$1, %esi
	jne	.L4
	movslq	%eax, %rsi
	movl	(%rdi,%rsi,4), %r14d
	cmpl	%r14d, 4(%rdi,%rsi,4)
	jg	.L6
.L5:
	addl	$1, %r9d
	addl	$1, %r8d
	cmpl	%r9d, %r10d
	jne	.L3
.L1:
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	.cfi_restore_state
	cmpl	$-1, %esi
	jne	.L6
	movslq	%eax, %rsi
	movl	(%rdi,%rsi,4), %r14d
	cmpl	%r14d, 4(%rdi,%rsi,4)
	jge	.L5
	addl	$1, %eax
	addq	$4, %rdx
	cmpl	%eax, %r8d
	jne	.L8
.L14:
	addl	$1, %r9d
	addl	$1, %ebx
	addl	$1, %r8d
	cmpl	%r9d, %r10d
	jne	.L3
	jmp	.L1
.L10:
	xorl	%ebx, %ebx
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z5solvePiiS_i, .-_Z5solvePiiS_i
	.ident	"GCC: (Ubuntu 13.2.0-4ubuntu3) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

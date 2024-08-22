	.file	"test.cc"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB9872:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	_ZSt3cin@GOTPCREL(%rip), %rdi
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	4(%rsp), %rsi
	call	_ZNSirsERi@PLT
	movslq	4(%rsp), %rsi
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	lzcntq	%rsi, %rsi
	call	_ZNSolsEi@PLT
	movb	$10, 3(%rsp)
	movq	%rax, %rdi
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	cmpq	$0, 16(%rdi,%rax)
	je	.L2
	leaq	3(%rsp), %rsi
	movl	$1, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.L3:
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L7
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L2:
	.cfi_restore_state
	movl	$10, %esi
	call	_ZNSo3putEc@PLT
	jmp	.L3
.L7:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE9872:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.0"
	.section	.note.GNU-stack,"",@progbits

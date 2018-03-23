lui	$28,%hi(__gnu_local_gp)
addiu	$28,$28,%lo(__gnu_local_gp)
nop
	.globl	i
	.data
	.align	2
	.type	i, @object
	.size	i, 4
i:
	.word	0

main:
addiu	$sp,$sp,-24
sw	$fp,20($sp)
sw	$31,16($sp)
move	$fp,$sp
nop
nop
lw	$2,%got(i)($28)
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j	$31
nop

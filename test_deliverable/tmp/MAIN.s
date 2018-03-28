	.globl main
	.text
nop

main:
addiu	$sp,$sp,-20
sw	$fp,16($sp)
sw	$31,12($sp)
move	$fp,$sp
nop
nop
li	$2, 0
move	$fp,$sp
lw	$31,12($sp)
lw	$fp,16($sp)
addiu	$sp,$sp,20
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,12($sp)
lw	$fp,16($sp)
addiu	$sp,$sp,20
j	$31
nop

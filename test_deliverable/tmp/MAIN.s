nop
	.globl function
	.text

function:
addiu	$sp,$sp,-32
sw	$fp,28($sp)
sw	$31,24($sp)
move	$fp,$sp
nop
nop
li	$2, 0
sw	$2, 16($fp)
lw	$2, 16($fp)
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j	$31
nop

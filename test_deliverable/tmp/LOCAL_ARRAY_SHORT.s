	.globl main
	.text
nop

main:
addiu	$sp,$sp,-40
sw	$fp,36($sp)
sw	$31,32($sp)
move	$fp,$sp
nop
nop
li	$2, 1
sw	$2, 28($fp)
li	$2, 1
move	$8, $2
lw	$2, 28($fp)
bne	$2, $8, not_start_0
nop
li	$2, 1
beq	$0, $0, not_end_1
nop
not_start_0:
move $2, $0
not_end_1:
beq	$2, $0, if_end_2
nop
nop
li	$2, 0
move	$fp,$sp
lw	$31,32($sp)
lw	$fp,36($sp)
addiu	$sp,$sp,40
j $31
nop
b else_if_end_3
if_end_2:
nop
else_if_end_3:
li	$2, 1
move	$fp,$sp
lw	$31,32($sp)
lw	$fp,36($sp)
addiu	$sp,$sp,40
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,32($sp)
lw	$fp,36($sp)
addiu	$sp,$sp,40
j	$31
nop

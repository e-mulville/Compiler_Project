	.globl main
	.text
nop

main:
addiu	$sp,$sp,-28
sw	$fp,24($sp)
sw	$31,20($sp)
move	$fp,$sp
nop
nop
li	$2, 5
sw	$2, 8($fp)
move	$2, $fp
addiu $2, $2, 8
sw	$2, 12($fp)
li	$2, 5
move	$8, $2
lw	$2, 12($fp)
lw	$2, ($2)
slt	$2, $2, $8
beq	$2, $0, if_end_0
nop
nop
li	$2, 1
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j $31
nop
b else_if_end_1
if_end_0:
li	$2, 5
move	$8, $2
lw	$2, 12($fp)
lw	$2, ($2)
bne	$2, $8, not_start_2
nop
li	$2, 1
beq	$0, $0, not_end_3
nop
not_start_2:
move $2, $0
not_end_3:
beq	$2, $0, if_end_4
nop
nop
li	$2, 0
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j $31
nop
b else_if_end_1
if_end_4:
else_if_end_1:
move	$2, $0
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j	$31
nop

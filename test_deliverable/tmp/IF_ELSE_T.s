nop
	.globl f
	.text

f:
addiu	$sp,$sp,-28
sw	$fp,24($sp)
sw	$31,20($sp)
move	$fp,$sp
nop
nop
li	$2, 1
move	$8, $2
li	$2, 1
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
li	$2, 0
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j $31
nop
beq	$0, $0, else_end_4
nop
if_end_2:
nop
li	$2, 1
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j $31
nop
else_end_4:
else_if_end_3:
move	$2, $0
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j	$31
nop

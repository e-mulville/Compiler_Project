nop
	.globl f
	.text

f:
addiu	$sp,$sp,-36
sw	$fp,32($sp)
sw	$31,28($sp)
move	$fp,$sp
nop
nop
li	$2, '5'
sb	$2, 16($fp)
move	$2, $fp
addiu	$2, $2, 16
sw	$2, 20($fp)
li	$2, '5'
move	$8, $2
lw	$2, 20($fp)
lb	$2, 0($2)
beq	$2, $8, not_start_0
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
li	$2, 1
move	$fp,$sp
lw	$31,28($sp)
lw	$fp,32($sp)
addiu	$sp,$sp,36
j $31
nop
b else_if_end_3
if_end_2:
li	$2, '5'
move	$8, $2
lw	$2, 20($fp)
lb	$2, 0($2)
bne	$2, $8, not_start_4
nop
li	$2, 1
beq	$0, $0, not_end_5
nop
not_start_4:
move $2, $0
not_end_5:
beq	$2, $0, if_end_6
nop
nop
li	$2, 0
move	$fp,$sp
lw	$31,28($sp)
lw	$fp,32($sp)
addiu	$sp,$sp,36
j $31
nop
b else_if_end_3
if_end_6:
else_if_end_3:
move	$2, $0
move	$fp,$sp
lw	$31,28($sp)
lw	$fp,32($sp)
addiu	$sp,$sp,36
j	$31
nop

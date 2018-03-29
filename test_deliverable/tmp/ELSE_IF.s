nop
	.globl f
	.text

f:
addiu	$sp,$sp,-32
sw	$fp,28($sp)
sw	$31,24($sp)
move	$fp,$sp
nop
nop
li	$2, 10
sw	$2, 16($fp)
li	$2, 1
move	$8, $2
lw	$2, 16($fp)
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
li	$2, 1
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j $31
nop
beq	$0, $0, else_end_4
nop
if_end_2:
li	$2, 10
move	$8, $2
lw	$2, 16($fp)
bne	$2, $8, not_start_5
nop
li	$2, 1
beq	$0, $0, not_end_6
nop
not_start_5:
move $2, $0
not_end_6:
beq	$2, $0, if_end_7
nop
nop
li	$2, 0
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j $31
nop
b else_if_end_3
if_end_7:
nop
li	$2, 1
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j $31
nop
else_end_4:
else_if_end_3:
move	$2, $0
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j	$31
nop

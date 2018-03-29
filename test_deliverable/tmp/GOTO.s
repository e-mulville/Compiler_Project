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
li	$2, 0
sw	$2, 16($fp)
start:
lw	$2, 16($fp)
addiu	$2, $2, 1
sw	$2, 16($fp)
li	$2, 5
move	$8, $2
lw	$2, 16($fp)
slt	$2, $2, $8
beq	$2, $0, if_end_0
nop
nop
j	start
b else_if_end_1
if_end_0:
nop
else_if_end_1:
li	$2, 5
move	$8, $2
lw	$2, 16($fp)
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
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j $31
nop
b else_if_end_5
if_end_4:
nop
else_if_end_5:
li	$2, 1
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

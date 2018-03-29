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
li	$2, 0
sw	$2, 20($fp)
li	$2, 10
sw	$2, 16($fp)
for_start_0:
li	$2, 0
move	$8, $2
lw	$2, 16($fp)
slt	$2, $8, $2
beq	$2, $0, for_end_1
nop
nop
lw	$2, 20($fp)
addiu	$2, $2, 1
sw	$2, 20($fp)
lw	$2, 16($fp)
addiu	$2, $2, -1
sw	$2, 16($fp)
beq	$0, $0, for_start_0
nop
for_end_1:
li	$2, 10
move	$8, $2
lw	$2, 20($fp)
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
lw	$2, 16($fp)
move	$fp,$sp
lw	$31,28($sp)
lw	$fp,32($sp)
addiu	$sp,$sp,36
j $31
nop
b else_if_end_5
if_end_4:
nop
else_if_end_5:
li	$2, 1
move	$fp,$sp
lw	$31,28($sp)
lw	$fp,32($sp)
addiu	$sp,$sp,36
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,28($sp)
lw	$fp,32($sp)
addiu	$sp,$sp,36
j	$31
nop

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
li	$2, 1
move	$8, $2
li	$2, 2
move	$9, $2
li	$2, 2
move	$10, $2
li	$2, 4
addu	$2, $2, $10
move	$10, $2
li	$2, 6
move	$11, $2
li	$2, 2
mult	$2, $11
mflo	$2
div	$2, $10
mflo	$2
mult	$2, $9
mflo	$2
subu	$2, $2, $8
sw	$2, 16($fp)
li	$2, 3
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
li	$2, 0
move	$fp,$sp
lw	$31,24($sp)
lw	$fp,28($sp)
addiu	$sp,$sp,32
j $31
nop
b else_if_end_3
if_end_2:
nop
else_if_end_3:
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

nop
	.globl f
	.text

f:
addiu	$sp,$sp,-44
sw	$fp,40($sp)
sw	$31,36($sp)
move	$fp,$sp
move	$2, $4
sw	$2, 44($fp)
move	$2, $5
sw	$2, 48($fp)
move	$2, $6
sw	$2, 52($fp)
nop
lw	$2, 52($fp)
move	$8, $2
lw	$2, 48($fp)
move	$9, $2
lw	$2, 44($fp)
addu	$2, $2, $9
addu	$2, $2, $8
sw	$2, 16($fp)
li	$2, 6
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
lw	$31,36($sp)
lw	$fp,40($sp)
addiu	$sp,$sp,44
j $31
nop
b else_if_end_3
if_end_2:
nop
else_if_end_3:
li	$2, 1
move	$fp,$sp
lw	$31,36($sp)
lw	$fp,40($sp)
addiu	$sp,$sp,44
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,36($sp)
lw	$fp,40($sp)
addiu	$sp,$sp,44
j	$31
nop

nop
	.globl f
	.text

f:
addiu	$sp,$sp,-52
sw	$fp,48($sp)
sw	$31,44($sp)
move	$fp,$sp
move	$2, $4
sw	$2, 52($fp)
move	$2, $5
sw	$2, 56($fp)
move	$2, $6
sw	$2, 60($fp)
move	$2, $7
sw	$2, 64($fp)
lw	$2, 84($fp)
sw	$2, 16($fp)
nop
lw	$2, 16($fp)
move	$9, $2
lw	$2, 64($fp)
move	$10, $2
lw	$2, 60($fp)
move	$11, $2
lw	$2, 56($fp)
move	$12, $2
lw	$2, 52($fp)
addu	$2, $2, $12
addu	$2, $2, $11
addu	$2, $2, $10
addu	$2, $2, $9
sw	$2, 16($fp)
li	$2, 15
move	$9, $2
lw	$2, 52($fp)
bne	$2, $9, not_start_0
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
lw	$31,44($sp)
lw	$fp,48($sp)
addiu	$sp,$sp,52
j $31
nop
b else_if_end_3
if_end_2:
nop
else_if_end_3:
li	$2, 1
move	$fp,$sp
lw	$31,44($sp)
lw	$fp,48($sp)
addiu	$sp,$sp,52
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,44($sp)
lw	$fp,48($sp)
addiu	$sp,$sp,52
j	$31
nop

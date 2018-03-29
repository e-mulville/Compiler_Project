nop
	.globl f
	.text

f:
addiu	$sp,$sp,-48
sw	$fp,44($sp)
sw	$31,40($sp)
move	$fp,$sp
nop
nop
li	$2, 1
sw	$2, 36($fp)
li	$2, 1
move	$8, $2
lw	$2, 36($fp)
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
lw	$31,40($sp)
lw	$fp,44($sp)
addiu	$sp,$sp,48
j $31
nop
b else_if_end_3
if_end_2:
nop
else_if_end_3:
li	$2, 1
move	$fp,$sp
lw	$31,40($sp)
lw	$fp,44($sp)
addiu	$sp,$sp,48
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,40($sp)
lw	$fp,44($sp)
addiu	$sp,$sp,48
j	$31
nop

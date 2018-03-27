nop
	.abicalls
	.data
	.align	2
	.type	i, @object
	.size	i, 1
i:
	.byte	48
	.text

main:
addiu	$sp,$sp,-24
sw	$fp,20($sp)
sw	$31,16($sp)
move	$fp,$sp
nop
nop
li	$2, '0'
move	$8, $2
lui	$2,%hi(i)
lb	$2,%lo(i)($2)
bne	$2, $8, not_start_0
nop
li $2, 1
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
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
beq	$0, $0, else_end_4
nop
if_end_2:
nop
nop
li	$2, 1
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
else_end_4:
else_if_end_3:
move	$2, $0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j	$31
nop

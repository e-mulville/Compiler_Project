nop

main:
addiu	$sp,$sp,-20
sw	$fp,16($sp)
sw	$31,12($sp)
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
lw	$31,12($sp)
lw	$fp,16($sp)
addiu	$sp,$sp,20
j $31
nop
b else_if_end_3
if_end_2:
nop
else_if_end_3:
li	$2, 1
move	$fp,$sp
lw	$31,12($sp)
lw	$fp,16($sp)
addiu	$sp,$sp,20
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,12($sp)
lw	$fp,16($sp)
addiu	$sp,$sp,20
j	$31
nop

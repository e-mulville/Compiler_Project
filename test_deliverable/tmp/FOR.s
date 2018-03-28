nop

main:
addiu	$sp,$sp,-28
sw	$fp,24($sp)
sw	$31,20($sp)
move	$fp,$sp
nop
nop
li	$2, 0
sw	$2, 12($fp)
li	$2, 10
sw	$2, 8($fp)
for_start_0:
li	$2, 0
move	$8, $2
lw	$2, 8($fp)
slt	$2, $8, $2
beq	$2, $0, for_end_1
nop
nop
lw	$2, 12($fp)
addiu	$2, $2, 1
sw	$2, 12($fp)
lw	$2, 8($fp)
addiu	$2, $2, -1
sw	$2, 8($fp)
beq	$0, $0, for_start_0
nop
for_end_1:
li	$2, 10
move	$8, $2
lw	$2, 12($fp)
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
lw	$2, 8($fp)
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j $31
nop
b else_if_end_5
if_end_4:
nop
else_if_end_5:
li	$2, 1
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,20($sp)
lw	$fp,24($sp)
addiu	$sp,$sp,28
j	$31
nop

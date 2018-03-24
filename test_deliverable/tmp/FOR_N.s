nop

main:
addiu	$sp,$sp,-24
sw	$fp,20($sp)
sw	$31,16($sp)
move	$fp,$sp
nop
nop
li	$2, 9
sw	$2, 8($fp)
li	$2, 0
move	$8, $2
lw	$2, 8($fp)
beq	$2, $8, not_start_0
nop
li $2, 1
beq	$0, $0, not_end_1
nop
not_start_0:
move $2, $0
not_end_1:
for_start_2:
li	$2, 0
move	$8, $2
lw	$2, 8($fp)
beq	$2, $8, not_start_4
nop
li $2, 1
beq	$0, $0, not_end_5
nop
not_start_4:
move $2, $0
not_end_5:
beq	$2, $0, for_end_3
nop
nop
li	$2, 1
move	$8, $2
lw	$2, 8($fp)
subu	$2, $2, $8
sw	$2, 8($fp)
beq	$0, $0, for_start_2
for_end_3:
lw	$2, 8($fp)
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j	$31
nop

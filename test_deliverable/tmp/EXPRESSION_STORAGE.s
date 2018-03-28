	.globl main
	.text
nop

main:
addiu	$sp,$sp,-24
sw	$fp,20($sp)
sw	$31,16($sp)
move	$fp,$sp
nop
nop
li	$2, 10
sw	$2, 8($fp)
lw	$2, 8($fp)
move	$8, $2
lw	$2, 8($fp)
move	$9, $2
lw	$2, 8($fp)
move	$10, $2
lw	$2, 8($fp)
move	$11, $2
lw	$2, 8($fp)
move	$12, $2
lw	$2, 8($fp)
move	$13, $2
lw	$2, 8($fp)
move	$14, $2
lw	$2, 8($fp)
move	$15, $2
lw	$2, 8($fp)
move	$16, $2
lw	$2, 8($fp)
move	$17, $2
lw	$2, 8($fp)
move	$18, $2
lw	$2, 8($fp)
move	$19, $2
lw	$2, 8($fp)
move	$20, $2
lw	$2, 8($fp)
move	$21, $2
lw	$2, 8($fp)
move	$22, $2
lw	$2, 8($fp)
move	$23, $2
lw	$2, 8($fp)
move	$24, $2
lw	$2, 8($fp)
move	$25, $2
lw	$2, 8($fp)
addu	$sp, $sp, -4
sw	$2, 8($sp)
lw	$2, 8($fp)
addu	$sp, $sp, -4
sw	$2, 8($sp)
lw	$2, 8($fp)
addu	$sp, $sp, -4
sw	$2, 8($sp)
lw	$2, 8($fp)
addu	$sp, $sp, -4
sw	$2, 8($sp)
lw	$2, 8($fp)
addu	$sp, $sp, -4
sw	$2, 8($sp)
lw	$2, 8($fp)
lw	$3,8($sp)
addu	$sp, $sp, 4
addu	$2, $2, $3
lw	$3,8($sp)
addu	$sp, $sp, 4
addu	$2, $2, $3
lw	$3,8($sp)
addu	$sp, $sp, 4
addu	$2, $2, $3
lw	$3,8($sp)
addu	$sp, $sp, 4
addu	$2, $2, $3
lw	$3,8($sp)
addu	$sp, $sp, 4
addu	$2, $2, $3
addu	$2, $2, $25
addu	$2, $2, $24
addu	$2, $2, $23
addu	$2, $2, $22
addu	$2, $2, $21
addu	$2, $2, $20
addu	$2, $2, $19
addu	$2, $2, $18
addu	$2, $2, $17
addu	$2, $2, $16
addu	$2, $2, $15
addu	$2, $2, $14
addu	$2, $2, $13
addu	$2, $2, $12
addu	$2, $2, $11
addu	$2, $2, $10
addu	$2, $2, $9
addu	$2, $2, $8
sw	$2, 8($fp)
li	$2, 240
move	$8, $2
lw	$2, 8($fp)
beq	$2, $8, not_start_0
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
li	$2, 1
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
b else_if_end_3
if_end_2:
li	$2, 240
move	$8, $2
lw	$2, 8($fp)
bne	$2, $8, not_start_4
nop
li	$2, 1
beq	$0, $0, not_end_5
nop
not_start_4:
move $2, $0
not_end_5:
beq	$2, $0, if_end_6
nop
nop
li	$2, 0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
b else_if_end_3
if_end_6:
else_if_end_3:
move	$2, $0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j	$31
nop

lui	$28,%hi(__gnu_local_gp)
addiu	$28,$28,%lo(__gnu_local_gp)
nop

f:
addiu	$sp,$sp,-24
sw	$fp,20($sp)
sw	$31,16($sp)
move	$fp,$sp
move	$2, $4
sw	$2, 24($fp)
nop
li	$2, 1
move	$8, $2
lw	$2, 24($fp)
subu	$2, $2, $8
sw	$2, 24($fp)
li	$2, 0
move	$8, $2
lw	$2, 24($fp)
slt	$2, $8, $2
beq	$2, $0, if_end_0
nop
addiu	$sp,$sp,-76
sw	$8, 4($sp)
sw	$9, 8($sp)
sw	$10, 12($sp)
sw	$11, 16($sp)
sw	$12, 20($sp)
sw	$13, 24($sp)
sw	$14, 28($sp)
sw	$15, 32($sp)
sw	$16, 36($sp)
sw	$17, 40($sp)
sw	$18, 44($sp)
sw	$19, 48($sp)
sw	$20, 52($sp)
sw	$21, 56($sp)
sw	$22, 60($sp)
sw	$23, 64($sp)
sw	$24, 68($sp)
sw	$25, 72($sp)
lw	$2, 24($fp)
move	$2, $5
jal	f
lw	$25, 72($sp)
lw	$24, 68($sp)
lw	$23, 64($sp)
lw	$22, 60($sp)
lw	$21, 56($sp)
lw	$20, 52($sp)
lw	$19, 48($sp)
lw	$18, 44($sp)
lw	$17, 40($sp)
lw	$16, 36($sp)
lw	$15, 32($sp)
lw	$14, 28($sp)
lw	$13, 24($sp)
lw	$12, 20($sp)
lw	$11, 16($sp)
lw	$10, 12($sp)
lw	$9, 8($sp)
lw	$8, 4($sp)
addiu	$sp,$sp, 76
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
beq	$0, $0, else_end_1
nop
if_end_0:
li	$2, 0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j $31
nop
else_end_1:
move	$2, $0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j	$31
nop

main:
addiu	$sp,$sp,-20
sw	$fp,16($sp)
sw	$31,12($sp)
move	$fp,$sp
nop
nop
addiu	$sp,$sp,-76
sw	$8, 4($sp)
sw	$9, 8($sp)
sw	$10, 12($sp)
sw	$11, 16($sp)
sw	$12, 20($sp)
sw	$13, 24($sp)
sw	$14, 28($sp)
sw	$15, 32($sp)
sw	$16, 36($sp)
sw	$17, 40($sp)
sw	$18, 44($sp)
sw	$19, 48($sp)
sw	$20, 52($sp)
sw	$21, 56($sp)
sw	$22, 60($sp)
sw	$23, 64($sp)
sw	$24, 68($sp)
sw	$25, 72($sp)
li	$2, 5
move	$2, $4
jal	f
lw	$25, 72($sp)
lw	$24, 68($sp)
lw	$23, 64($sp)
lw	$22, 60($sp)
lw	$21, 56($sp)
lw	$20, 52($sp)
lw	$19, 48($sp)
lw	$18, 44($sp)
lw	$17, 40($sp)
lw	$16, 36($sp)
lw	$15, 32($sp)
lw	$14, 28($sp)
lw	$13, 24($sp)
lw	$12, 20($sp)
lw	$11, 16($sp)
lw	$10, 12($sp)
lw	$9, 8($sp)
lw	$8, 4($sp)
addiu	$sp,$sp, 76
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

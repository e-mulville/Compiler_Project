lui	$28,%hi(__gnu_local_gp)
addiu	$28,$28,%lo(__gnu_local_gp)
nop

main:
addiu	$sp,$sp,-40
sw	$fp,36($sp)
sw	$31,32($sp)
move	$fp,$sp
nop
nop
li	$2, 1
la	$3,a
sw	$2,0($3)
li	$2, 1
move	$fp,$sp
lw	$31,32($sp)
lw	$fp,36($sp)
addiu	$sp,$sp,40
j $31
nop
move	$2, $0
move	$fp,$sp
lw	$31,32($sp)
lw	$fp,36($sp)
addiu	$sp,$sp,40
j	$31
nop

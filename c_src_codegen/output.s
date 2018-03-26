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
li	$2, 5
move	$3, $2
lw	$2, 8($fp)
and	$2, $2, $3
sw	$2, 8($fp)
move	$2, $0
move	$fp,$sp
lw	$31,16($sp)
lw	$fp,20($sp)
addiu	$sp,$sp,24
j	$31
nop

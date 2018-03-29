#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="../bin/c_compiler"
fi

have_compiler=0
if [[ ! -f ../c_src_codegen/bin/c_compiler ]] ; then
    >&2 echo "Fail : cannot find compiler at path ${compiler}."
    have_compiler=1
fi

if [[ ${have_compiler} -eq 0 ]] ; then
    rm -rf tmp
    input="test_cases"
    mkdir -p tmp


    for i in ${input}/*.c ; do
    # Compile using our compiler
        base=$(echo $i | sed -E -e "s|${input}/([^.]+)[.]c|\1|g");
        $compiler -S $i -o tmp/$base.s
 
    # Compile using our compiler
	name=$(basename $i)
        name1=$(echo $name | cut -f 1 -d '.')
        mips-linux-gnu-gcc -c drivers/$name1'_driver.c' -o tmp/$name1'_driver'.o
    done

    cd tmp
    
    tot=0
    passed=0
    for i in *.s ; do
        tot=$((tot+1))
        base=$(echo $i | sed -E -e "s|([^.]+)[.]s|\1|g");
        if [[ -s $i ]] ; then
            # Link the generated assembly and the driver
            # object into a MIPS executable
	    mips-linux-gnu-gcc -static $base.s $base'_driver'.o -o $base'.elf'

            # Run the executable under QEMU
            qemu-mips $base'.elf'
            
            # Check the result
	        result=$(echo $?)
	        if [[ $result -eq 0 ]]
	        then
	            echo "Test "$base" passed."
	            passed=$((passed+1))
	        else
	            echo "Test "$base" failed."
	        fi
	    else
	        echo "Test "$base" failed."
	    fi
    done
    
    echo "Passed "$passed" tests out of "$tot"."
fi

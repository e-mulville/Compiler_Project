#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="../c_src_codegen/bin/c_compiler"
fi

have_compiler=0
if [[ ! -f ../c_src_codegen/bin/c_compiler ]] ; then
    >&2 echo "Fail : cannot find compiler at path ${compiler}."
    have_compiler=1
fi

input_dir="test_cases"
driver_dir="test_cases/driver"

working="tmp"
mkdir -p ${working}

if [[ ${have_compiler} -eq 0 ]] ; then
    for i in ${driver_dir}/*.c ; do
        base=$(echo $i | sed -E -e "s|${driver_dir}/([^.]+)[.]c|\1|g");
    
        # Compile the reference C version
        mips-linux-gnu-gcc $i -c 
    done

    for i in ${input_dir}/*.c ; do
        base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");

        # Compile using our compiler
        $compiler -S ${working}/$base -o ${working}/$base
    done

    mv *.o tmp
fi

#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="c_src_codegen/bin/c_compiler"
fi

have_compiler=0
if [[ ! -f c_src_codegen/bin/c_compiler ]] ; then
    >&2 echo "Fail : cannot find compiler at path ${compiler}."
    have_compiler=1
fi

input_dir="c_codegen_testbench"

working="tmp/c_codegen"
mkdir -p ${working}

if [[ ${have_compiler} -eq 0 ]] ; then
    for i in ${input_dir}/*.c ; do
        base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
    
        # Compile the reference C version
        gcc $i -o $working/$base
    
        # Run the reference C version
        $working/$base
        REF_C_OUT=$?

        # Compile using our compiler
        $compiler -S ${working}/$base -o ${working}/$base-got
	
	# Run our C version
        $working/$base-got
        GOT_C_OUT=$?
    done
fi

#!/bin/bash
# Brian McIlwain
# Operating Systems
# A script for compiling and running code
# [16] Write a script utilizing the smartlog library which should accept the name of a source 
# file (with a .c or a .java extension) [2], then do the following: syntax-highlight the code [2], 
# compile the code [2], then on the condition the code compiled successfully, run it [2]. 
# Assume the source is such that the compilation and running process is simple (e.g. javac 
# Hello.java; java Hello or gcc hello.c -o hello; ./hello). Document each step of the script
# with the smartlog logging functions [4], and in particular print failure messages on 
# file-not-found, compilation, and run errors, or if the extension does not match [4]. 
# Call this examine.sh. As long as you meet the specifications, you are free to personalize your script.

# Get the logging plugin
source '/usr/lib/smartlog/smartlog.sh'

# filename parsing
fullname=$(basename "$1")
ext="${fullname##*.}"
filename="${fullname%.*}"
exe="${filename}"

# Input validation
if [[ $# != 1 ]]; then
    log "Program requires exactly one argument"; fail
    exit 1
fi

if [ ! -f $fullname ]; then
    count=`ls -1 *.flac 2>/dev/null | wc -l`

    if [ count != 0 ]; then
        log "File extension does not match"; fail
        exit 1
    fi

    log "File $1 not found"; fail
    exit 1
fi

# Compiling the code
if [[ $ext == "c" ]]; then
    log "Compiling c"
    echo
    `gcc ${fullname} -o ${exe}.out`
    exe="./${exe}.out"
    ok
elif [[ $ext == "cpp" ]]; then
    log "Compiling c++"
    echo
    `g++ ${fullname} -o ${exe}.out`
    exe="./${exe}.out"
    ok
elif [[ $ext == "java" ]]; then
    log "Compiling Java"
    echo
    `javac ${fullname}`
    exe="java $filename"
    ok
else
    log "File type not supported"; fail
    exit 1
fi

log "Running the program"
    echo
    # run it
    $exe
ok

exit 0

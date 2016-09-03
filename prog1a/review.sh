#!/bin/bash
# Brian McIlwain
# A script for reviewing notes and codes
# [16] As the course unfolds, the README.rst in each directory in notes/ will 
# have an ordered list of files you should read (see the example in shell/). It would be 
# useful to automate the process of reviewing them.
# Write a script which can, for all the codes mentioned in README.rst (in the order they are
# mentioned) do the following: print the code syntax-highlighted to stdout (see the manual 
# page for highlight), [2] number-line [2] the code/note, wait for the user to hit Enter [2], 
# then clear the screen [2]. The directory to use shall be taken in as a command-line argument
# (thus, the script should be runnable outside of the current directory) [2]; if no argument
# is given, it should act on the current directory if a README.rst exists in the current directory
# [2]. Use the commands file, highlight, nl, read, and clear. Document the script with comments
# [4]. Call this review.sh. As long as you meet the specifications, you are free to 
# personalize your script however you like.

# Get the logging plugin
source '/usr/lib/smartlog/smartlog.sh'

# file path parsing

# Input validation
if [[ $# == 1 ]]; then
    # File exists if specified?
    fullname="$1/README.rst"
    path="$1/"
    if [[ ! -f "${fullname}" ]]; then
        log "README not found at path $1"; fail
        exit 1
    fi
elif [[ $# == 0 ]]; then
    # Check for README in current directory
    fullname="README.rst"
    path="./"
    if [[ ! -f $fullname ]]; then
        log "No README found in current directory"; fail
        exit 1
    fi
else
    log "Program requires zero or one argument"; fail
    exit 1
fi

# RegEx find and isolate filenames, using back ticks to identify
filenames=$(grep -o '``.*``' README.rst | sed -e 's/\`//g')

while read -r file; do
    echo "File: $file"
    if [[ -f ${path}$file ]]; then
        pygmentize ${path}$file | nl
    else
        log "File: ${path}$file does not exist"
        fail
    fi
    echo
    echo "Press the [Enter] key to continue..."
    read input </dev/tty
    clear
done <<< "$filenames"

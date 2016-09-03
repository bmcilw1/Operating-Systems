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

source '/usr/lib/smartlog/smartlog.sh'

file="$1"

g++ $file

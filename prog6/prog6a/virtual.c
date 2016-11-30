// Brian McIlwain
// Virtual address space translation.
// Write a program which accepts either one or two command-line arguments, and outputs 
// different quantities depending on the number of command-line arguments: 
//  -if one argument is passed, it is assumed to be a hex address; then
//   assuming 32-bit architecture, prints the page number and offset for the byte at that address.
//  -if two arguments are passed, it is assumed to be the page number and
//   offset; and returns the virtual address.
// These are command-line arguments; hence they should be accepted when invoking the program program 
// (look in argv for them). Input hex addresses are formatted with a leading 0x like so: 0x42D2

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int PAGESIZE;

int main(int argc, char *argv[])
{
    int pg_num=0, offset=0;
    unsigned int hex=0;
    PAGESIZE = getpagesize();
//    printf("PAGESIZE: %i\n", PAGESIZE);
//    printf("PAGESIZE_HEX: %x\n", PAGESIZE);

    if (argc == 2) {
        hex = strtol(argv[1], NULL, 16);

//        printf("HEX: %x\n", hex);

        pg_num = hex / PAGESIZE;
        offset = hex % PAGESIZE;

        printf("Page number: %i\n", pg_num);
        printf("Offset: %i\n", offset);
    } else if (argc == 3) {
        pg_num = atoi(argv[1]);
        offset = atoi(argv[2]);
        
        hex = pg_num * PAGESIZE + offset;

        printf("Virtual address: 0x%x\n", hex);
    } else {
        printf("Usage: \n");
        printf("   ./prog_name page_number offset\n");
        printf("OR\n");
        printf("   ./prog_name hex_address\n");

        return 1;
    }

    return 0;
}

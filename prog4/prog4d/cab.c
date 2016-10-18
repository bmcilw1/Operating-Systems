// Brian McIlwain
// How system command options are enabled; how manual pages are written.
// [32] Command-line options can be accepted in a more fluid manner using the getopt 
// library. The getopt library allows for options to be given in any order, and in long or
// short form, using a simple minimum-length description in the code. See src/sum.c for an example.
// Also included is a manual page for the system command, which can be viewed with man -l 
// sum.1 (-l for local). Study the syntax to get a feel for how a manual page is 
// structured. You can read more about how to properly create manual pages on-line.
// Write a program cab.c which copies a segment of bytes from one file into another. It 
// should take the following options:
// -i or --input followed by a filename to read from. If not specified, it should read from stdin.
// -o or --output followed by a filename to write to. If not specified, it should write to stdout.
// -s or --start followed by a number in hex to start at. If this is not specified, it should start from 0.
// -e or --end followed by a number in hex to end at If this is not specified, it should end at the EOF of the input file.
// -n or --num which is a number of bytes to copy. This must not be used in conjunction with both of the above options.
// -v or --version and a help message displaying a brief summary of the options.
// The start and end values are inclusive (those bytes are copied). Also, write a manual 
// page for this program, giving its description, synopsis, option list, author information, and so forth. Call this cab.1.

int main(int agrc, char **argv) {

    return 0;
}

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

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>


// Print usage message.
void usage(char *name) {
  printf("cab version 0.1\n");
  printf("usage: %s [options]\n\n", name);
  printf("  options:\n");
  printf("    -i, --input\n");
  printf("        filename to read from (default stdin)\n\n");
  printf("    -o, --output  \n");
  printf("        filename to write to (default stdout)\n\n");
  printf("    -s, --start\n");
  printf("        hex bit number to start at (default 0)\n\n");
  printf("    -e, --end\n");
  printf("        hex bit number to end at (default input EOF)\n\n");
  printf("    -n, --num\n");
  printf("        number of bytes to copy. Cannot use with both -s -n simultaneously\n\n");
  printf("    -v, --version\n");
  printf("        show version and help message\n\n");
}


// Return sum from m to n in steps of j. Also print steps of the process, with
// detail depending on the value of the int verbosity.
void copy(char *i, char *o, int s, int e, int n) {
    printf("copy i: %s, o: %s, s: %i, e: %i, n: %i\n", i, o, s, e, n);
    char *cmd="", *a_of="", *a_if="", *a_cnt="", *a_seek="";

    // Set up args
    if (i != "") sprintf(a_if, "if=%s", i);
    if (o != "") sprintf(a_of, "of=%s", o);
    if (s >= 0) sprintf(a_seek, "skip=%i", s);
    if (n >= 0) sprintf(a_cnt, "count=%i", n);
    if (e >= 0) {
        if (s >= 0) sprintf(a_cnt, "count=%i", e-s);
        else sprintf(a_cnt, "count=%i", e);
    }

    sprintf(cmd, "dd ibs=1 status=noxfer %s %s %s %s", a_if, a_of, a_seek, a_cnt);
    printf("cmd: %s\n"cmd);
}


// Demonstrate getopt_long functionality.
int main(int argc, char **argv) {
  int n=-1, s=-1, e=-1;
  char *i="", *o="";
  int c, digit_optind = 0;

  // This struct contains the long options.
  // First  field:  input file
  // Second field:  output file
  // Third  field:  start position
  // Fourth field:  end position
  // Fifth  field:  number of bytes to copy
  // Sixth  field:  display help and version info
  static struct option long_options[] = {
      {"input",     0, 0, 'i'},
      {"output",    0, 0, 'o'},
      {"start",     0, 0, 's'},
      {"end",       0, 0, 'e'},
      {"num",       0, 0, 'n'},
      {"version",   0, 0, 'v'},
  };

  // Loop to parse arguments; breaks when no more can be parsed.
  while (1) {

    // Get the option.
    c = getopt_long(argc, argv, "i:o:s:e:n:v", long_options, NULL);

    // If option does not exist, break from while-loop.
    if (c == -1)
      break;

    switch (c) {

      case 'i':
        i = optarg;
        break;

      case 'o':
        o = optarg;
        break;

      case 's':
        s = strtol(optarg, NULL, 16);
        break;

      case 'e':
        e = strtol(optarg, NULL, 16);
        break;

      case 'n':
        n = atoi(optarg);
        break;

      default:
        usage(argv[0]);
	exit(EXIT_FAILURE);
    }
  }

  // If more CL arguments were passed than the option list allowed,
  // print usage and exit.
  if (optind < argc) {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  // Can't specify n and s and e
  if (n >= 0 && s >= 0 && e >= 0) {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  if (argc == 1) usage(argv[0]);
  else           copy(i, o, s, e, n);
  exit(EXIT_SUCCESS);

}

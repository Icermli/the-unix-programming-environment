/* readslow: keep reading, waiting for more */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 512 /* arbitrary */
char *progname;

void error(char *s1, char *s2);

int main (argc, argv)
    int argc;
    char *argv[];
{
    char buf[SIZE];
    int n, fd = 0;
    int seekend = 0;
    int t = 10;

    progname = argv[0];

    while (argc > 1 && argv[1][0] == '-') {
      switch (argv[1][1]) {
        case 'e':
          seekend = 1;
          break;
        default:
          t = atoi(&argv[1][1]);
          break;
      }
      argc--;
      argv++;
    }

    if (argc > 1 && (fd = open(argv[1], 0)) == -1) {error("can't open %s", argv[1]);}
    if (seekend == 1) {lseek(fd, 0L, 2);}

    for (;;) {
        while ((n = read(fd, buf, sizeof buf)) > 0)
           write(1, buf, n);
        sleep(t);
    }
}

void error(char *s1, char *s2) {
  extern int errno;
  extern const int sys_nerr;
  extern const char *const sys_errlist[];
  extern char *progname;

  if (progname) {fprintf(stderr, "%s: ", progname);}
  fprintf(stderr, s1, s2);
  if (errno > 0 && errno < sys_nerr) {
    fprintf(stderr, " (%s)", sys_errlist[errno]);
  }
  fprintf(stderr, "\n");
  exit(1);
}

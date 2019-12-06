/* p: print input in chunks (version 4) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spname.h"
#define PAGESIZE  22
char *progname; /* program name for error message */

void print(FILE *fp, int pagesize);
char ttyin();

int main(argc, argv)
    int argc;
    char *argv[];
{
  FILE *fp, *efopen();
  int i, pagesize = PAGESIZE;
  char *p, *getenv(), buf[BUFSIZ];

  progname = argv[0];
  if ((p = getenv("PAGESIZE")) != NULL) {pagesize = atoi(p);}
  if (argc > 1 && argv[1][0] == '-') {
    pagesize = atoi(&argv[1][1]);
    argc--;
    argv++;
  }
  if (argc == 1) {print(stdin, pagesize);}
  else {
    for (i = 1; i < argc; i++) {
      switch (spname(argv[i], buf)) {
        case -1:
          fp = efopen(argv[i], "r");
          break;
        case 1:
          fprintf(stderr, "\"%s\"? ", buf);
          if (ttyin() == 'n') {break;}
          argv[i] = buf;
        case 0:
          fp = efopen(argv[i], "r");
          print(fp, pagesize);
          fclose(fp);
      }
    }
  exit(0);
  }
}

FILE *efopen(char *file, char *mode) {
  FILE *fp, *fopen();
  extern char *progname;

  if ((fp = fopen(file, mode)) != NULL) {
    return fp;
  }
  fprintf(stderr, "%s: can't open file %s mode %s\n", progname, file, mode);
  exit(1);
}

void print(FILE *fp, int pagesize) {
  static int lines = 0;
  char buf[BUFSIZ];

  while (fgets(buf, sizeof buf, fp) != NULL) {
    if (++lines < pagesize) {
      fputs(buf, stdout);
    } else {
      buf[strlen(buf) - 1] = '\0';
      fputs(buf, stdout);
      fflush(stdout);
      ttyin();
      lines = 0;
    }
  }
}

char ttyin() {
  char buf[BUFSIZ];
  FILE *efopen();
  static FILE *tty = NULL;

  if (tty == NULL) {
    tty = efopen("/dev/tty", "r");
  }
  if (fgets(buf, BUFSIZ, tty) == NULL || buf[0] == 'q') {
    exit(0);
  } else {
    return buf[0];
  }
}

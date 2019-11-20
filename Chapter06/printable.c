#include <stdio.h>
#include <ctype.h>

int invert = 0;
int is_printable(FILE *fp)

int main(int argc, char *argv[]) {
  while (argc > 1 && argv[1][0] == '-') {
    switch (argv[1][1]) {
      case 'v':
        invert = 1;
        break;
      default:
        fprintf(stderr, "%s: unknown arg %s\n", argv[0], argv[1]);
        return 1;
    }
    argc--;
    argv++;
  }
  if (argc != 1) {
    for (int i = 1; i < argc; i++) {
      if (fp = fopen(argv[i], "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", argv[0], argv[i]);
        return 1;
      } else {
        if (is_printable(fp)) {
          printf("%s\n", argv[i]);
        }
        fclose(fp);
      }
    }
  }
  return 0;
}

int is_printable(FILE *fp) {
  int c;
  int val = 1;
  while ((c = getc(fp)) != EOF) {
    if (isascii(c) && (isprint(c) || c == '\n' || c == '\t' || c == ' ')) {

    } else {
      val = 0;
    }
  }
  return invert ? !val : val;
}

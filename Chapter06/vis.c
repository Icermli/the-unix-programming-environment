/* vis: make funny characters visible (version 1) */

#include <stdio.h>
#include <ctype.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF)
    if (isascii(c) &&
        (isprint(c) || c=='\n' || c=='\t' || c==' ')) {
          if (c == '\t') {
            printf("\\t");
          } else if (c == '\\') {
            printf("\\\\");
          } else {
            if (c == ' ') {
              putchar(' ');
              while ((c = getchar()) == ' ') {
                putchar(' ');
              }
            }
            if (c == '\n') {
              putchar('$');
            }
            putchar(c);
          }
    } else {
      printf("\\%03o", c);
    }

    return 0;
}

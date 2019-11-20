/* vis: make funny characters visible (version 2) */

#include <stdio.h>
#include <ctype.h>

#define	FOLD_LENGTH	80

int count_getchar();
void reset_count();
int count = 0;

int main()
{
  int c;

  while ((c = count_getchar()) != EOF)
    if (isascii(c) &&
        (isprint(c) || c=='\n' || c=='\t' || c==' ')) {
          if (c == '\t') {
            printf("\\t");
          } else if (c == '\\') {
            printf("\\\\");
          } else {
            if (c == ' ') {
              putchar(' ');
              while ((c = count_getchar()) == ' ') {
                putchar(' ');
              }
            }
            if (c == '\n') {
              putchar('$');
              reset_count();
            }
            putchar(c);
          }
    } else {
      printf("\\%03o", c);
    }
    if (FOLD_LENGTH == count) {
			printf(">\n");
			reset_count();
		}

    return 0;
}


int count_getchar()
{
	int c = getchar();
	count++;
	return c;
}

void reset_count()
{
	count = 0;
}

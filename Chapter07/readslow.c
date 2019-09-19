/* readslow: keep reading, waiting for more */
#include <stdlib.h>
#include <unistd.h>
#define SIZE 512 /* arbitrary */

int main (argc, argv)
    int argc;
    char *argv[];
{
    char buf[SIZE];
    int n;
    int t = 10;

    if (argc > 1 && argv[1][0] == '-') { t = atoi(&argv[1][1]); }

    for (;;) {
        while ((n = read(0, buf, sizeof buf)) > 0)
           write(1, buf, n);
        sleep(t);
    }
}

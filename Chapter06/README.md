## Exercise 6-1.
> We decide that tabs should be left alone, rather than made visible as `\011` or `pretended a triangle here` or `\t`, since our main use of `vis` is looking for truly anomalous characters. An alternate design is to identify every character of output unambiguously --- tabs, non-graphics, blanks at line ends, etc. Modify `vis` so that characters like tab, backslash, backspace, formfeed, etc., are printed in their conventional C representations `\t`, `\\`, `\b`, `\f`, etc., and so that blanks at the ends of lines are marked. Can you do this unambiguously? Compare your design with
```
$ sed -n 1
```

[vis.c](/vis.c) (Notice: not working properly on mac)

## Exercise 6-2.
> Modify `vis` so that it folds long lines at some reasonable length. How does this interact with the unambiguous output required in the previous exercise?

[vis1.c](/vis1.c) (Notice: not working properly on mac)

## Exercise 6-3.
> Change the `-s` argument so that `vis -sn` will print only strings of n or more consecutive printable characters, discarding non-printing characters and short sequence of printable ones. This is valuable for isolating the parts of non-text files such as executable programs. Some versions of the system provide a `strings` program that does this. Is it better to have a separate program or an argument to `vis`?

[vis2.c](/vis2.c)

## Exercise 6-4.
> The availability of the C source code is one of the strengths of the UNIX system --- the code illustrates elegant solutions to many programming problems. Comment on the tradeoff between readability of the C source and the occasional optimizations obtained from rewriting in assembly language.

C code is better in both ways, except assembly language is faster in some specified cases. Assembly language are prone to bugs.

## Exercise 6-5.
> Write a program `printable` that prints the name of each argument file that contains only printable characters; if the file contains any non-printable character, the name is not printed. `printable` is useful in situations like this:
```
$ pr `printable *` | lpr
```
Add the option `-v` to invert the sense of the test, as in `grep`. What should `printable` do if there are no filename arguments? What status should `printable` return?

[printable.c](/printable.c)

## Exercise 6-6.
> Does `p` act sanely if pagesize is not positive?

Only one line of content will be printed if pagesize is not positive.

## Exercise 6-7.
> What else could be done to `p`? Evaluate and implement (if appropriate) the ability to re-print parts of earlier input. (This is one extra feature that we enjoy.) Add a facility to permit printing less than a screenful of input after each pause. Add a facility to scan forward or backward for a line specified by number or content.

## Exercise 6-8.
> Use the file manipulation capabilities of the `exec` shell built-in (see `sh(1)`) to fix `ttyin's` call to `system`.

```
char ttyin() {
  char buf[BUFSIZ];
  char buff[BUFSIZ];
  FILE *efopen();
  static FILE *tty = NULL;

  if (tty == NULL) {
    tty = efopen("/dev/tty", "r");
  }
  for (;;) {
    if (fgets(buf, BUFSIZ, tty) == NULL || buf[0] == 'q') {
      exit(0);
    } else if (buf[0] == '!') {
      sprintf(buff, "exec %s", buf+1)
      system(buff);
      printf("!\n");
    } else {
      return buf[0];
    }
  }
}
```

## Exercise 6-9.
> If you forget to specify an input for `p`, it sits quietly waiting for input from the terminal. Is it worth detecting this probable error? If so, how? Hint: `isatty(3)`.

## Exercise 6-10.
> Given `pick`, is there a need for `rm -i`?

`rm -i` is convenient.

## Exercise 6-11.
> Modify `zap` so that any number of arguments can be supplied. As written, `zap` will normally echo the line corresponding to itself as one of the choices. Should it? If not, modify the program accordingly. Hint: `getpid(2)`.

It's better not to echo the line corresponding to itself.
[zap.c](/zap.c)

## Exercise 6-12.
> Build as `fgrep(1)` around `strindex`. Compare running times for complicated searches, say ten words in a document. Why does `fgrep` run faster?

## Exercise 6-13.
> Add the command `q` to `idiff`: the response `q<` will take all the rest of the `<` choices automatically; `q>` will take all the rest of the `>` choices.

## Exercise 6-14.
> Modify `idiff` so that any `diff` arguments are passed on to `diff`; `-b` and `-h` are likely candidates. Modify `idiff` so that a different editor can be specified, as in
```
$ idiff -e another-editor file1 file2
```
How do these two modifications interact?

## Exercise 6-15.
> Change `idiff` to use `popen` and `pclose` instead of a temporary file for the output of `diff`. What difference does it make in program speed and complexity?

## Exercise 6-16.
> `diff` has the property that if one of its arguments is a directory, it searches that directory for a file with the same as the other argument. But if you try the same thing with `idiff`, it fails in a strange way. Explain what happens, then fix it.

## Exercise 6-17.
> Modify `idiff` to search the environment for the name of the editor to be used. Modify 2, 3, etc., to use `PAGESIZE`.

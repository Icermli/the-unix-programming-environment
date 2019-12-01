## Exercise 9-1.
> Omitting a terminating command like `.AE` or `.DE` is usually a disaster. Write a program `mscheck` to detect errors in `ms` input (or your favorite package).

## Exercise 9-2.
> How did we format this chapter?

## Exercise 9-3.
> If your `eqn` deliminiter is a dollar sign, how do you get a dollar sign in the output? Hint: investigate quotes and the pre-defined words of `eqn`.

## Exercise 9-4.
> Why doesn't
```
$ `doctype filenames`
```
work? Modify `doctype` to run the resulting command, instead of printing it.

## Exercise 9-5.
> Is the overhead of the extra `cat` in `doctype` important? Rewrite `doctype` to avoid the extra process. Which version is simpler?

## Exercise 9-6.
> Is it better to use `doctype` or write a shell file containing the commands to format a specific document?

## Exercise 9-7.
> Experiment with various combinations of `grep`, `egrep`, `fgrep`, `sed`, `awk` and `sort` to create the fastest possible version of `doctype`.

## Exercise 9-8.
> Write a manual page for `doctype`. Write a version of the `man` command that looks in your own `man` directory for documentation on your personal programs.

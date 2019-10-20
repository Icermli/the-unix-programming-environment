## Exercise 5-1.
> If users prefer your version of `cal`, how do make it globally accessible? What has to be done to put it in `/usr/bin`?

## Exercise 5-2.
> Is it worth fixing `cal` so `cal` 83 prints the calendar for 1983? If so, how would you print the calendar for year 83?

## Exercise 5-3.
> Modify `cal` to accept more than one month, as in
```
$ cal oct nov
```
or perhaps a range of months:
```
$ cal oct - dec
```
If it's now December, and you ask for `cal jan`, should you get this year's January or next year's? When should you have stopped adding features to `cal`?

## Exercise 5-4.
> Why doesn't `which` reset `PATH` to `opath` before exiting?

## Exercise 5-5.
> Since the shell uses `esac` to terminate a `case`, and `fi` to terminate an `if`, why does it use `done` to terminate a `do`?

`od` is a shell script name.

## Exercise 5-6.
> Add an option `-a` to which so it prints all files in `PATH`, rather than quiting after the first. Hint: `match='exit 0'`.

## Exercise 5-7.
> Modify which so it knows about shell built-ins like exit.

## Exercise 5-8.
> Modify which to check for execute permissions on the files. Change it to print an error message when a file cannot be found.

## Exercise 5-9.
> Look at the implementation of true and false in `\bin` or `/usr/bin`. (How would you find our where they are?)

## Exercise 5-10.
> Change `watchfor` so that multiple arguments are treated as different people, rather than requiring the user to type 'joe|mary'.

## Exercise 5-11.
> Write a version of `watchwho` that uses `comm` instead of `awk` to compare the old and new data. Which version do you prefer?

## Exercise 5-12.
> Write a version of `watchwho` that stores the who output in shell variables instead of files. Which version do you prefer? Which version runs faster? Should `watchwho` and `checkmail` do & automatically?

## Exercise 5-13.
> What is the difference between the shell : do-nothing command and the `#` comment character? Are both needed?

## Exercise 5-14.
> The version of `nohup` above combines the standard error of the command with the standard output. Is this a good design? If not, how would you separate them cleanly?

## Exercise 5-15.
> Look up the times shell build-in, and add a line to your `.profile` so that when log off the shell prints out how much CPU time you have used.

## Exercise 5-16.
> Write a program that will find the next available user-id in `/etc/passwd`. If you are enthusiastic (and have permission), make it into a command that will add a new user to the system. What permissions does it need? How should it handle interrupts?

## Exercise 5-17.
> Why doesn't `overwrite` use signal code 0 in the `traps` so the files are removed when it exits? Hint: Try typing DEL while running the following program:
```
trap "echo exiting; exit 1" 0 2
sleep 10
```

## Exercise 5-18.
> Add an option `-v` to `replace` to print all changed lines on `/dev/tty` Strong hint: `s/$left/$right/g$vflag`.

## Exercise 5-19.
> Fix `replace` so it works regardless of the characters in the substitution strings.

## Exercise 5-20.
> Can `replace` be used to change the variable `i` to `index` everywhere in a program? How could you change things to make this work?

## Exercise 5-21.
> Is `replace` convenient and powerful enough to belong in `/usr/bin`? Is it preferable to simply typing the correct `sed` commands when needed? Why or why not?

## Exercise 5-22.
> (Hard)
```
$ overwrite file 'who | sort'
```
doesn't work. Explain why not, and fix it. Hint: see `eval` in `sh(1)`. How does your solution affect the interpretation of metacharacters in the command?

## Exercise 5-23.
> Modify `zap` to print out the `ps` header from the pipeline so that it is insensitive to changes in the format of `ps` output. How much does this complicate the program?

## Exercise 5-24.
> Try writing a `pick` that reads its arguments from the standard input if none are supplied on the command line. It should handle blanks properly. Does a `q` response work? If not, try the next exercise.

## Exercise 5-25.
> Although shell build-ins like `read` and `set` cannot be redirected, the shell itself can be temporarily redirected. Read the section of `sh(1)` that described `exec` and work out how to `read` from `/dev/tty` without calling a sub-shell. (It might help to read Chapter 7 first.)

## Exercise 5-26.
> (Much easier) Use `read` in your `.profile` to initialize `TERM` and whatever else depends on it, such as `tab` stops.

## Exercise 5-27.
> Add an option `-n` (notify) to `news` to report but not print the news items, and not touch `.news_time`. This might be placed in your `.profile`.

## Exercise 5-28.
> Compare our design and implementation of `news` to the similar command on your systems.

## Exercise 5-29.
> Write a command `version` that does two things:
```
$ version -5 file
```
reports the summary, modification date and person making the modification of the selected version in the history file.
```
$ version sep 20 file
```
reports which version number was current on September 20. This would typically be used in:
```
$ get `version sep 20 file`
```
(version can echo the history filename for convenience.)

## Exercise 5-30.
> Modify `get` and `put` so they manipulate the history file in a separate directory, rather than cluttering up the working directory with `.H` files.

## Exercise 5-31.
> Not all versions of a file are worth remembering once thins settle down. How can you arrange to delete versions from the middle of the history file?

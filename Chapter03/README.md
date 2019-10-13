## Exercise 3-1.
> What are the differences among the following three commands?
```
$ cat file | pr
$ pr <file
$ pr file
```
> (Over the years the redirection `<` has lost some ground to pipes; people seem to find `"cat file |"` more natural `"<file"`.)

1. standard out of `cat file` into standard in of `pr`

2. file content as the standard in of `pr`

3. file as argument as `pr`

## Exercise 3-2.
> Explain the output produced by
```
$ ls .*
```

`ls` any file or folder that start with `.`

## Exercise 3-3.
> Predict what each of the following `grep` commands will do, then verify your understanding.
```
$ grep \$                       $ grep \\
\$ match all lines              \\ match all lines contains \
$ grep \\$                      $ grep \\\\
match all lines with \$         match all lines contains \\
$ grep \\\$                     $ grep "\$"
match all lines with \$         match all lines
$ grep '\$'                     $ grep '"$'
match all lines with \$         match all lines with "$
$ grep '\'$'                    $ grep "$"
single quote is not closing     match all lines with $
```
> A file containing these commands themselves makes a good test case if you want to experiment.

## Exercise 3-4.
> How do you tell `grep` to search for a pattern beginning with a '-'? Why doesn't quoting the argument help? Hint: investigates the `-e` option.

Quoting `-` still parse the literal `-`, which will be constructed as options. Try
```
grep -e -... file
```

## Exercise 3-5.
> Consider
```
$ echo */*
```
> Does this produce all names in all directories? In what order do the names appear?

This will show all files in subfolders in alphabetical order.

## Exercise 3-6.
> (Trick question) How do you get a `/` into a filename (i.e., a `/` that doesn't separate components of the path)?

The answer is that you can't, unless your filesystem has a bug. See [this](https://stackoverflow.com/questions/9847288/is-it-possible-to-use-in-a-filename).

## Exercise 3-7.
> What happens with
```
$ cat x y >y
```
> and with
```
$ cat x >>x
```
> Think before rushing off to try them.

if `x` is not empty,

`cat x y >y` will loop to put content of `x` into `y`.

`cat x >>x` will also loop.

if `x` is empty,

`cat x y >y` will cause `y` to be empty file.

`cat x >>x` will cause `x` to be empty file.

## Exercise 3-8.
> If you type
```
$ rm *
```
> why can't `rm` warn you that you're about to delete all your files?

`*` is interpreted by shell, therefore, `rm` won't know they are all your files.

## Exercise 3-9.
> Look in `/bin` and `/user/bin` to see how many commands are actually shell files. Can you do it with one command? Hint: `file(1)`. How accurate are guesses based on file length?
```
$ (file /bin/*; file /usr/bin/*) | grep 'shell script' | wc -l
81
$ wc -c /usr/bin/* | sort -nr | tail -n 10
```

## Exercise 3-10.
> If the backslashes are omitted in
```
$ echo `echo \`date\``
```
> what happens?
```
$ echo `echo \`date\``
date
```

## Exercise 3-11.
> Try
```
$ `date`
```
> and explain the result.
```
$ `date`
-bash: Sun: command not found
```
`date` executed by shell then shell look for command `Sun`

## Exercise 3-12.
```
$ grep -l pattern filenames
```
> lists the filenames in which there was a match of pattern, but produces no other output. Try some variations on
```
$ command `grep -l pattern filenames`
```
```
$ wc -c `grep -l pattern filenames`
```

## Exercise 3-13.
> Why do we always include the current directory in `PATH`? Where should it be placed?
To be able to execute script in current folder. And it should be placed in beginning of `PATH`.

## Exercise 3-14.
> Compare the her-document version of 411 with the original. Which is easier to maintain? Which is a better basis for a general service?
The original one is easier to maintain because of no need to maintain a phone-book. Also original one is better for a general service.

## Exercise 3-15.
> If the `diff` loop were placed in a shell file, would you put the pick in the shell file? Why or why not?
No, `pick $*` already do a loop.

## Exercise 3-16.
> What happens if the last line of the loop above is
```
> done | pr | lpr &
```
> that is, ends with an ampersand? See if you can figure out, then try it.

## Exercise 3-17.
> How would you use `bundle` to send all the files in a directory and its subdirectories? Hint: shell files can be recursive.
```
$ cat rbundle
for i in $1/*
do
	cat $i || rbundle $i
	cat $i && bundle $i
done
```

## Exercise 3-18.
> Modify `bundle` so it includes with each file the information garnered from `ls -l`, particularly permissions and date of last change. Contracts the facilities of `bundle` with the archive program `ar(1)`.
```
for i
do
    echo "echo $i 1>&2"
    echo "echo \# `ls -l $i` >$i"
    echo "cat >>$i <<'End of $i'"
    cat $i
    echo "End of $i"
done
```

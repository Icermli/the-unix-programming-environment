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

## Exercise 3-5.
> Consider
```
$ echo */*
```
> Does this produce all names in all directories? In what order do the names appear?

## Exercise 3-6.
> (Trick question) How do you get a `/` into a filename (i.e., a `/` that doesn't separate components of the path)?

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

## Exercise 3-8.
> If you type
```
$ rm *
```
> why can't `rm` warn you that you're about to delete all your files?

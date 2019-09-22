## Exercise 2-1.
> What happens when you type `ctl-d` to `ed`? Compare this to the command
```
$ ed <file
```
Both cases will print '?'.

## Exercise 2-2.
> Given the information in this section, you should be able to understand roughly how the `ls` command operates. Hint: `cat . >foo; ls -f foo`.

Maybe look at the bytes of current directory `.`, then print the names?

## Exercise 2-3.
> (Harder) How does the `pwd` command operate?

## Exercise 2-4.
> `du` was written to monitor disc usage. Using it to find files in a directory hierarchy is at best a strange idiom, and perhaps inappropriate. As an alternative, look at the manual page for `find(1)`, and compare the two commands. In particular the command `du -a | grep ...` with the corresponding invocation if `find`. Which runs faster? Is it better to build a new tool or use a side effect of an old one?

## Exercise 2-5.
> Experiment with `chmod`. Try different simple modes, like 0 and 1. Be careful not to damage your login directory!

## Exercise 2-6.
> Why does `ls -l` report 4 links to `recipes`? Hint: try
```
$ ls -ld /usr/you
```

## Exercise 2-7.
> What is the difference between
```
$ mv junk junk1
```
and
```
$ cp junk junk1
$ rm junk
```
Hint: make a link to junk, then try it.

## Exercise 2-8.
> `cp` doesn't copy subdirectories, it just copies files at the first level of a hierarchy. What does it do if one of the argument files is a directory? Is this kind or even sensible? Discuss the relative merits of three possibilities: an option to `cp` to descend directories, a separate command `rcp` (recursive copy) to do the job, or just having `cp` copy a directory recursively when it finds one. See Chapter 7 for help on providing this facility. What other programs would profit from the ability to traverse the directory tree? 

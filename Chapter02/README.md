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

Maybe it works like this(caution: this may be totally wrong)...

1. Every time you `cd` to some folder, `pwd` record current path to `PWD` variable

2. When you type `pwd`, then it print $PWD.

Here is what i find in the `pwd` source code

Determine the basename of the current directory, where DOT_SB is the result of lstat'ing "." and prepend that to the file name in `*FILE_NAME`. Find the directory entry in `..` that matches the dev/i-node of DOT_SB. Upon success, update `*DOT_SB` with stat information of `..`, chdir to `..`, and prepend "/basename" to FILE_NAME. Otherwise, exit with a diagnostic. PARENT_HEIGHT is the number of levels `..` is above the starting directory. The first time this function is called (from the initial directory), PARENT_HEIGHT is 1.  This is solely for diagnostics. Exit nonzero upon error.

## Exercise 2-4.
> `du` was written to monitor disc usage. Using it to find files in a directory hierarchy is at best a strange idiom, and perhaps inappropriate. As an alternative, look at the manual page for `find(1)`, and compare the two commands. In particular the command `du -a | grep ...` with the corresponding invocation if `find`. Which runs faster? Is it better to build a new tool or use a side effect of an old one?

`find` runs a little bit faster if the search folder does not contain so many files. If you search from near root directory, there may be a big difference in running efficiency.

## Exercise 2-5.
> Experiment with `chmod`. Try different simple modes, like 0 and 1. Be careful not to damage your login directory!
```
chmod 400 ~/.ssh/<somekey>
```

## Exercise 2-6.
> Why does `ls -l` report 4 links to `recipes`? Hint: try
```
$ ls -ld /usr/you
```
There are four files inside the `recipes` folder.

2 links to `cookies` and `pie` files inside `recipes`

1 link to current dir `.`

1 link to upper dir `..`

## Exercise 2-7.
> What is the difference between
```
$ mv junk junk1 # junk1 and junk are one file with different name
```
and
```
$ cp junk junk1 # junk1 and junk are different file with same content
$ rm junk
```
> Hint: make a link to junk, then try it.

## Exercise 2-8.
> `cp` doesn't copy subdirectories, it just copies files at the first level of a hierarchy. What does it do if one of the argument files is a directory? Is this kind or even sensible? Discuss the relative merits of three possibilities: an option to `cp` to descend directories, a separate command `rcp` (recursive copy) to do the job, or just having `cp` copy a directory recursively when it finds one. See Chapter 7 for help on providing this facility. What other programs would profit from the ability to traverse the directory tree?

If the first argument is a dir, it will complain and won't copy.

If the first argument is a file and the second is a dir, it will copy the file into the dir.

I shall come back to second question when i get to Chapter 7...

## Exercise 2-9.
> Find out about the other files in `/dev` by reading Section 4 of the manual. What is the difference between `/dev/mt0` and `/dev/rmt0`? Comment on the potential advantages of having subdirectories in `/dev` for discs, tapes, etc.

`/dev/rmt0` is to deal with foreign tapes.

Advantages: easy to find different types of devices.

## Exercise 2-10.
> Tapes written on non-UNIX systems often have different block sizes, such as 800 bytes --- ten 80-character card images --- but the tape device `/dev/mt0` expects 512-byte blocks. Look up the `dd` command (`dd(1)`) to see how to read such a tape.

Through `dd bs=512` both input and output block size is set to 512 bytes.

## Exercise 2-11.
> Why isn't `/dev/tty` just a link to your login terminal? What would happen if it were mode `rw--w--w-` like your login terminal?

Others login to the machine won't have a terminal to use.

Other users will not be able to read their terminal name.

## Exercise 2-12.
> How does `write(1)` work? Hint: see `utmp(5)`.

Use `utmp` to find user id `ut_name[8]` and send to their login terminal `ut_line[8]`.

## Exercise 2-13.
> How can you tell if a user has been active at the terminal recently?

May consider check `ut_time` of `utmp` to see user login time.

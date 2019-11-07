## Exercise 7-1.
> Add a `-n` argument to `readslow` so the default sleep time can be changed to `n` seconds. Some systems provide an option `-f` ("forever") for `tail` that combines the functions of `tail` with those of `readslow`. Comment on this design.

## Exercise 7-2.
> What happens to `readslow` if the file being read is truncated? How would you fix it? Hint: read about `fstat` in Section 7.3.

## Exercise 7-3.
> Modify `readslow` to handle a filename argument if one is present. Add the option `-e`:
```
$ readslow -e
```
causes `readslow` to seek to the end of the input before beginning to read. What does `lseek` do on a pipe?

## Exercise 7-4.
> Rewrite `efopen` from Chapter 6 to call `error`.

## Exercise 7-5.
> How much can you improve on the heuristic for the selecting the best match in `spname`? For example, it is foolish to treat a regular file as if it were a directory; this can happen with the current version.

## Exercise 7-6.
> The name `tx` matches whichever of `tc` happens to come last in the directory, for any single character `c`, can you invent a better distance measure? implement it and see how well it works with real users.

## Exercise 7-7.
> `mindist` reads the directory one entry at a time. Does `p` run perceptibly faster if directory reading is done in bigger chunks.

## Exercise 7-8.
> Modify `spname` to return a name that is a prefix of the desired name if no closer match can be found. How should ties be broken if there are several names that all match the prefix?

## Exercise 7-9.
> What other programs could profit from `spname`? Design a standalone program that would apply correction to its arguments before passing them along to another program, as in
```
$ fix prog filenames...
```
Can you write a version of `cd` that uses `spname`? How would you install it?

## Exercise 7-10.
> Modify `checkmail` to identify the sender of the mail as part of the "You have mail" message. Hint: `sscanf`, `lseek`.

## Exercise 7-11.
> Modify `checkmail` so that it does not change to the mail directory before it enters its loop. Does this have a measurable effect on its performance? (Harder) Can you write a version of `checkmail` that only needs one process to notify all users?

## Exercise 7-12.
> write a program `watchfile` that monitors a file and prints the file from the beginning each time it changes. When would you use it?

## Exercise 7-13.
> `sv` is quite rigid in its error handling. Modify it to continue even if it can't process some file.

## Exercise 7-14.
> Make `sv` recursive: if one of the source file is a directory, that directory and its files are processed in the same manner. Make `cp` recursive. Discuss whether `cp` and `sv` ought to be the same program, so that `cp -v` doesn't do the copy if the target is newer.

## Exercise 7-15.
> Write the program `random`:
```
$ random filename
```
produces one line chosen at random from the file. Given a file people of names, `random` can be used in a program called `scapegoat`, which is valuable for allocating blame:
```
$ cat scapegoat
echo "It's all `random people`'s fault!"
$ scapegoat
It's all Ken's fault!
$
```
Make sure that random is fair regardless of the distribution of line lengths.

## Exercise 7-16.
> There's other information in the inode as well, in particular, disc addresses where the file blocks are located. Examine the file <sys/ino.h>, then write a program `icat` that will read files specified by inode number and disc device. (It will work only if the disc in question is readable, of course.) Under what circumstances is `icat` useful?

## Exercise 7-17.
> Modify `watchfile` (Exercise 7-12) so it has the same property as `waitfile`: if there is no `command`, it copies the file; otherwise it does the command. Could `watchfile` and `waitfile` share source code? Hint: `argv[0]`.

## Exercise 7-18.
> Can you infer how `sleep` is implemented? Hint: `pause(2)`. Under what circumstances, if any, could `sleep` and `alarm` interfere with each other?

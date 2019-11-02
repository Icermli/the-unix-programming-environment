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

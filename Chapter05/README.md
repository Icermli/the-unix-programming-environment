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

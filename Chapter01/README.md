## Exercise 1-1.
> Explain what happens with
```
$ date\@
-bash: date@: command not found
```

## Exercise 1-2.
> Most shells (though not the 7th Edition shell) interpret # as introducing a comment, and ignore all text from the # to the end of the line. Given this, explain the following transcript, assuming your erase character is also #:
```
$ date
Thu Sep 19 17:35:11 HKT 2019
$ #date

$ \#date
-bash: #date: command not found
$ \\#date
-bash: \#date: command not found
```

## Exercise 1-3.
> Try
```
$ ls /usr/games
```
> and do whatever comes naturally. Things might be more fun outside of normal working hours.
```
ls: /usr/games: No such file or directory (¯―¯٥)
```

## Exercise 1-4.
> What are the differences among these commands?
```
$ ls junk                         $ echo junk
to be or not to be                junk
$ ls /                            $ echo /
Applications  cores               /
$ ls                              $ echo
README.md                         
$ ls *                            $ echo *
README.md                         README.md
$ ls '*'                          $ echo '*'
ls: *: No such file or directory  *
```

## Exercise 1-5.
> Explain why
```
$ ls >ls.outside
```
> causes `ls.out` to be included in the list of names.
Redirection `>` will first be evaluated, therefore by the time `ls` runs the output file has been created already. See [this link](https://askubuntu.com/questions/728382/why-does-ls-ls-out-cause-ls-out-to-be-included-in-list-of-names) for details.

## Exercise 1-6.
> Explain the output from
```
$ wc temp >temp
```
> If you misspell a command name, as in
```
$ woh >temp
```
> what happens?

After first command, `temp` will be like        0       0       0 temp

For misspell command,
```
$ woh >temp
-bash: woh: command not found
```
and `temp` will be empty file.

## Exercise 1-7.
> Explain the differences between
```
$ who | sort # this will direct the output of who to input of sort
$ who >sort # this will create a file called 'sort' and write the output of who to it. 
```

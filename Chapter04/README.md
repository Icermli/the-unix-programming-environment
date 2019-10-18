## Exercise 4-1.
> Look up tagged regular expressions `(\(` and `\))` in Appendix 1 or `ed(1)`, and use `grep` to search for palindromes --- words spelled the same backwards as forwards. Hint: write a different pattern for each length of word.

```
$ grep -i '^\(.\)\(.\)\(.\)\3\2\1$' /usr/share/dict/words
degged
hallah
kakkak
redder
retter
tebbet
terret
```

## Exercise 4-2.
> The structure of `grep` is to read a single line, check for a match, then loop. How would `grep` be affected if regular expressions could match newlines?

Some matched lines may appear multiple times.

## Exercise 4-3.
> Use the tools in this section to write a simple spelling checker, using `/usr/dict/words`. What are its shortcomings, and how would you address them?

```
cat $* |
tr A-Z a-z |
tr -sc a-z '\012' |
sort -u >/tmp/inputwords
grep -iw -f /tmp/inputwords /usr/share/dict/words >/tmp/outputwords
grep -wv -f /tmp/outputwords /tmp/inputwords  
rm -f /tmp/inputwords /tmp/outputwords
```

## Exercise 4-4.
> Write a word-counting program in your favorite programming language and compare its size, speed and maintainability with the word-counting pipeline. How easily can you convert it into a spelling checker.

C++: [code](/wc.app)
real	0m0.007s
user	0m0.003s
sys	0m0.002s

shell: [code](/wc)
real	0m0.015s
user	0m0.011s
sys	0m0.016s

## Exercise 4-5.
> Modify `older` and `newer` so they don't include the argument file in their output. Change them so the files are listed in the opposite order.

```
# newer f: list files newer than f
ls -tr | sed "1,/^$1\$/d"
# older f: list files older than f
ls -t | sed "1,/^$1\$/d"
```

## Exercise 4-6.
> Use `sed` to make the `bundle` robust. Hint: in here documents, the end-making word is recognized only when it matches the line exactly.

```
# bundle: group files into distribution packages

echo '# To unbundle, sh this file'
for i
do
    echo "echo $i 1<&2"
    # echo "cat >$i <<'End of $i'"
    # cat $i
    echo "cat >fake$i <<'End of $i'"
    sed "s/End of $i/Fake End of $i/g" $i
    echo "End of $i"
    echo "sed \"s/Fake End of $i/End of $i/g\" fake$i >$i"
    echo "rm -f fake$i"
done
```

## Exercise 4-7.
> How many `awk` programs can you write that copy input to output as `cat` does? Which is the shortest?

```
awk '{print}' file
```

## Exercise 4-8.
> Our test of `prpages` suggests alternate implementations. Experiment to see which is fastest.

```
sed -n '$=' $* |
awk '{n+=int(($1+55)/56)}
     END        {print n}'
```

## Exercise 4-9.
> The output from `wordfreq` includes text formatting commands like `.CM`, which is used to print words in this font. How would you get rid of such non-words? How would you use `tr` to make `wordfreq` work properly regardless of the case of its input? Compare the implementation and performance of `wordfreq` to the pipeline from Section 4.2 and to this one:
```
sed 's/[ ->][ ->]*/\
/g' $* | sort | uniq -c | sort -nr
```

awk version:
real	0m0.010s
user	0m0.004s
sys	0m0.004s

sed version:
real	0m0.012s
user	0m0.009s
sys	0m0.010s

## Exercise 4-10.
> Modify `fold` so that it will fold lines at blanks or tabs rather than spliting a word. Make it robust for long words.

## Exercise 4-11.
> Modify `calendar` so it knows about weekends: on Friday, "tomorrow" includes Saturday, Sunday and Monday. Modify `calendar` to handle leap years. Should `calendar` know about holidays? How would you arrange it?

## Exercise 4-12.
> Should `calendar` know about dates inside a line, not just at the beginning? How about dates expressed in other formats, like 10/1/83?

## Exercise 4-13.
> Why doesn't `calendar` use `getname` instead of `$NAME`?

## Exercise 4-14.
> Write a personal version of `rm` that moves files to a temporary directory rather than deleting them, with an `at` command to clean out the directory while you are sleeping.

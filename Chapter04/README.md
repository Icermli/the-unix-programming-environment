## Exercise 4-1.
> Look up tagged regular expressions `(\(` and `\))` in Appendix 1 or `ed(1)`, and use `grep` to search for palindromes --- words spelled the same backwards as forwards. Hint: write a different pattern for each length of word.

## Exercise 4-2.
> The structure of `grep` is to read a single line, check for a match, then loop. How would `grep` be affected if regular expressions could match newlines?

## Exercise 4-3.
> Use the tools in this section to write a simple spelling checker, using `/usr/dict/words`. What are its shortcomings, and how would you address them?

## Exercise 4-4.
> Write a word-counting program in your favorite programming language and compare its size, speed and maintainability with the word-counting pipeline. How easily can you convert it into a spelling checker.

## Exercise 4-5.
> Modify `older` and `newer` so they don't include the argument file in their output. Change them so the files are listed in the opposite order.

## Exercise 4-6.
> Use `sed` to make the `bundle` robust. Hint: in here documents, the end-making word is recognized only when it matches the line exactly.

## Exercise 4-7.
> How many `awk` programs can you write that copy input to output as `cat` does? Which is the shortest?

## Exercise 4-8.
> Our test of `prpages` suggests alternate implementations. Experiment to see which is fastest.

## Exercise 4-9.
> The output from `wordfreq` includes text formatting commands like `.CM`, which is used to print words in this font. How would you get rid of such non-words? How would you use `tr` to make `wordfreq` work properly regardless of the case of its input? Compare the implementation and performance of `wordfreq` to the pipeline from Section 4.2 and to this one:
```
sed 's/[ ->][ ->]*/\
/g' $* | sort | uniq -c | sort -nr
```

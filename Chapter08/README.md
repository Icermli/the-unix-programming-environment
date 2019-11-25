## Exercise 8-1.
> Examine the structure of the `y.tab.c` file. (It's about 300 lines long for hoc1.)

## Exercise 8-2.
> Add the operators % (modulus or remainder) and unary + to hoc1. suggestion: look at `frexp(3)`.

## Exercise 8-3.
> Add a facility for remembering the most recent value computed, so that it does not have to be retyped in a sequence of related computations. One solution is to make it one of the variables, for instance 'p' for 'previous.'

## Exercise 8-4.
> Modify `hoc` so that a semicolon can be used as an expression terminator equivalent to a newline.

## Exercise 8-5.
> As `hoc3` stands, it's legal to say
```
  PI = 3
```
Is this a good idea? How would you change `hoc3` to prohibit assignment to "constants"?

## Exercise 8-6.
> Add the built-in function `atan2(y,x)`, which returns the angle whose tangent is `y/x`. Add the built-in `rand()`, which returns a floating point random variable uniformly distributed on the interval (0,1). How do you have to change the grammar to allow for built-ins with different numbers of arguments?

## Exercise 8-7.
> How would you add a facility to execute commands from within `hoc`, similar to ! feature of the UNIX programs?

## Exercise 8-8.
> Revise the code in `math.c` to use a table instead of the set of essentially identical functions that we presented.

## Exercise 8-9.
> Compare the sizes of the two versions of `hoc3`. Hint: see `size(1)`.

## Exercise 8-10.
> Make the sizes of `stack` and `prog` dynamics, so that `hoc4` never runs out of space if memory can be obtained by calling `malloc`.

## Exercise 8-11.
> Modify `hoc4` to use a switch on the type of operation in `execute` instead of calling functions. How do the versions compare in lines of source code and execution speed? How are they likely to compare in case of maintenance and growth.

## Exercise 8-12.
> Modify `hoc5` to print the machine it generate it generates in a readable form for debugging.

## Exercise 8-13.
> Add the assignment operators of C, such as `+=, *=`, etc., and the increment and decrement operators `++` and `--`. Modify `&&` and `||` so they guanrantee left-to-right evalution and early termination, as in C.

## Exercise 8-14.
> Add a `for` statement like that of C to `hoc5`. Add `break` and `continue`.

## Exercise 8-15.
> How would you modify the grammar or the lexical analyzer (or both) of `hoc5` to make it more forgiving about the placement of newlines? How would you add semicolon as a synonym for newline? How would you add a comment convention? What syntax would you use?

## Exercise 8-16.
> Add interrupt handling to `hoc5`, so that a runaway computation can be stopped without losing the state of variables already computed.

## Exercise 8-17.
> It is a nuisance to have to create a program in a file, run it, then edit the file to make a trivial change. How would you modify `hoc5`, so provide an edit command that would cause you to be placed in an editor with a copy of your `hoc` program already read in? Hint: consider a `text` opcode.

## Exercise 8-18.
> Modify `hoc6` to permit named formal parameters in subroutines as an alternative to `$1`, etc.

## Exercise 8-19.
> As it stands, all variables are global except for parameters. Most of the mechanism for adding local variables maintained on the stack is already present. One approach is to have an `auto` declaration that makes space on the stack for variables listed; variables not so named are

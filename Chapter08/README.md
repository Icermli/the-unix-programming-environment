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

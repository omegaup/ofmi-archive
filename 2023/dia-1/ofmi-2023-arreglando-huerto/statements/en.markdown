In your backyard, you have a garden of size $n$ and you want a specific number of items of different vegetables in it. Everything was going great until a vegetarian snake started stealing your vegetables. Now, some sections of the garden have fewer vegetables than they should, and others somehow have more!

You have two arrays of non-negative integers $A$ and $B$ of length $n$, which represent the current state of the garden and the state you want it to be in, respectively. Each element of an array describes how many vegetables there are or should be in that section of the garden.

Given that the sections of the garden are very close to each other, each time you add or take vegetables from a section, you also modify the number of vegetables from an adjacent section. If you decide to subtract $x$ vegetables to any section of the garden $A[i]$, you'll also have to add $x$ vegetables, either to $A[i-1]$ or to $A[i+1]$.

After each operation, the number of vegetables in each section of the garden $A$ must remain non-negative.

The goal is to make $A$ equal to $B$, meaning each element of $A$ must be equal to the element of $B$ in the same position.

# Implementation

You must implement the function `arregla(A, B)` , which must call the function `mueve(indice, cantidad, direccion)` until `A` becomes equal to `B`.

# Your function, `arregla`

`bool arregla(int n, int A[], int B[])`

## Description

Your submission must implement this function. The program evaluator will look for it in your code and call the function with the following parameters:

## Parameters

- `n`, the number of elements on `A` and `B`.
- `A` and `B`, which represent two integer arrays, both with the same number of elements.

Within this function, you must call the given function `mueve(indice, cantidad, direccion)` to subtract `cantidad` from `A[indice]` and add `cantidad` to `A[indice+direccion]` until the elements on `A` are equal to those on `B`.

The program evaluator has its own copies of `A` and `B`, different from the parameters of `A` and `B` that your function received. This means that, if you modify `A` and `B`, the arrays within the evaluator won't change; and when you call `mueve(indice, cantidad, direccion)`, your arrays `A` and `B` won't change either.

## Return

Your function must return a boolean, which represents if it was possible or not to make both arrays the same.

# The program evaluator function, `mueve`

`bool mueve(int indice, int cantidad, int direccion);`

## Description

The program evaluator will provide you with this function. Call it to subtract `cantidad` from `A[indice]` and add `cantidad` to `A[indice+direccion]`

The function returns `true` if `A` is equal to `B` after doing the operation, and `false` if they're different.

You shouldn't implement this function, you should just call it.

Note: Remember that by calling this function, the arrays `A` and `B` that were passed on to you function as parameters aren't modified.

## Parameters

- `indice`: It's the index of the element you're subtracting from. If you send an index smaller to $0$ or bigger than $n - 1$, the function returns `false` and does nothing.

- `cantidad`: It's the number being subtracted from `A[indice]` and added to `A[indice+direccion]`. Consider that `cantidad` can be negative.

- `direccion`: Its value can only be $1$ or $-1$; if you send another value, the function returns `false` and does nothing. `indice+direccion` must be greater than or equal to $0$ and less than or equal to $n - 1$; if this doesn't happen, the function returns `false` and does nothing.

## Return

A boolean that indicates if `A` is equal to `B` after doing the operation.

## Example

||input
Function called
||output
Returned value
||description
Description
||input
arregla(4, [1, 2, 0, 1], [0, 1, 3, 0])
||output

- ||description
  This is the initial call to your procedure, `arregla`.
  ||input
  mueve(0, 1, 1)
  ||output
  false
  ||description
  We subtract $1$ from the element $A[0]$ and add $1$ to the element $A[1]$. The new value of $A$ is `[0, 3, 0, 1]`. The function returns `false`because $A$ is not equal to $B$.
  ||input
  mueve(1, 2, 1)
  ||output
  false
  ||description
  We subtract $2$ from the element $A[1]$ and add $2$ to the element $A[2]$. The new value of A is `[0, 1, 2, 1]`. The function returns `false`because $A$ is not equal to $B$.
  ||input
  mueve(3, 1, -1)
  ||output
  true
  ||description
  We subtract $1$ from the element $A[3]$ and add $1$ to the element $A[2]$.
  The new value of A is `[0, 1, 3, 0]`.
  As $A$ equals $B$, the function returns `true`.
  ||end

# Limits

- $1 \leq n \leq 10^4$
- $0 \leq A_i, B_i \leq 10^5$

# Subtasks

- **Subtask 1 group (18 points):**
  - The initial elements of $A$ are in descending order, meaning $A[i] \geq A[i+1]$, and those of $B$ are in ascending order, $B[i] \leq B[i+1]$ for all $i$.
  - It is certain that there is always a solution.
  - $n \leq 10^4$
- **Subtask 2 group (37 points):**
  - $n \leq 10^3$
- **Subtask 3 group (45 points):**
  - $n \leq 10^4$
  - Additionally, you must use the smallest number of calls possible to function `mueve`.

# Experimentation

{{libinteractive:download}}

The test evaluator receives the file `sample.in` with the values $n$ on the first line, the array $A$ on the second line and the array $B$ on the third line. For the previous example case, `sample.in` would look the following way:

```
4
1 2 0 1
0 1 3 0
```

_IMPORTANT:_ The test evaluator and the final program evaluator that are used to grade your solution are different. The testing evaluator has the debugging of your solution and can implement some functions differently.

---

![](arreglando.jpeg 'Chasing the snake.')

After fixing your garden, you were very tired, and to rest, you decided to figure out how you became so tired in the first place.

It turns out that by moving from one side to the other this happened, sometimes forgetting the vegetables you were going to plant and other times chasing Nicholas, the vegetarian serpent who stole them. And given that your garden is of $1$ unit in its height and infinitely large, you can only move forward and backward.

You have the register of the movements you made (because you are THAT organized) and you want to know how many meters you have traversed at any given moment and how many times you have changed directions.

# Implementation

You must implement the functions `adelante(x)`, `atras(y)`, `avanzado()` and `vueltas()`. These procedures are described below.

# Your function, `adelante`

`void adelante(int x);`

## Description

Your submission must implement this function. The program evaluator will look for it in your code and call it with the following parameters:

- `x` represents the number of meters you moved forward.

# Your function, `atras`

`void atras(int y);`

## Description

Your code must implement this function. The evaluator will look for it in your code and call it with the following parameters:

- `y` represents the number of meters you moved backward.

# Your function, `avanzado`

`int avanzado();`

## Return

Your submission must implement this function. This function must return an integer that represents the distance in meters that you have moved from the start of the course to the point you're located in.

# Your function, `vueltas`

`int vueltas();`

## Return

Your submission must implement this function. This function
must return how many times you have turned, meaning how many times you've changed direction. It is considered that you changed direction when you moved forward and then backward or when you moved backward and then forward.

# Example

||input
Called function
||output
Returned value
||description
Description
||input
adelante(4)
||output

- ||description
  You moved $4$ meters forward.
  ||input
  atras(1)
  ||output
- ||description
  You moved $1$ meter backward. Since you were previously moving forward, you had to change directions.
  ||input
  vueltas()
  ||output
  1
  ||input
  adelante(2)
  ||output
- ||description
  Since you're moving backward, you have to change directions again to then move $2$ meters forward.
  ||input
  vueltas()
  ||output
  2
  ||input
  avanzado()
  ||output
  5
  ||end

# Limits

- Your functions will be called, at the most, $N$ times.
- $1 \leq N, x, y \leq 10^4$

# Subtasks

- **Subtask 1 (20 points):**
  - Your function `atras` will never be called.
- **Subtask 2 (20 points):**
  - Your function `avanzado` will be called exactly once after all the `adelante` and `atras`.
  - The function `vueltas` will never be called.
- **Subtask 3 (20 points):**
  - The function `adelante` will never be called after having made a call to `atras`.
- **Subtask 4 (40 points):**
  - No additional considerations.

# Experimentation

{{libinteractive:download}}

The testing evaluator will receive the file `sample.in` with a value of $N$, which is the number of events. In the following $N$ lines, you will see a description of each of the next events in the following way:

- `1 x`: where $x$ is a positive integer, and this means the evaluator will call `adelante(x)`.
- `2 y`: where $y$ is a positive integer, and this means the evaluator will call `atras(y)`.
- `3`: this means the evaluator will make a call to `avanzado`.
- `4`: this means the evaluator will make a call to `vueltas`.

For the previous example case, `sample.in` would look the following way:

```
6
1 4
2 1
4
1 2
4
3
```

_IMPORTANT:_ The testing evaluator and the final evaluator which will be used to grade your solution are different. The testing evaluator has the debugging of your code and can implement some of its functions differently.

---

![](recorriendo.jpeg 'Nicholas, the vegeratian snake.')

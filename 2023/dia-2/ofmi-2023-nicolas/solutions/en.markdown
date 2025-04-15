Nicholas is a snake, but he's not a normal one; he's a vegetarian snake. He is the only one of this kind in the world.

You have seen him a couple of times stealing vegetables from your garden and when you told your friends, they didn't believe you, so you want to take a photo of him for them to get to know Nicholas.

The snake has a length of $L$ meters and moves at $X$ mps (meters per second).

The garden is represented by a row of boxes, where each box measures $1$ meter.

When Nicholas starts moving, this is determined as the time $0$, his tail is in box number $0$ and his head in box $L - 1$, and he always moves in a straight line forward.

In each following second (starting from second 1), you point the camera to box $y$ and take a photo that captures everything in the meter $y$.

# Problem

Your task is to calculate Nicholas' length ($L$) and the speed he's moving at ($X$), using the information given by these photos.

# Implementation

You must implement the function `nicolas()`. This procedure can call the functions `foto(y)` and `reporta(X, L)`. All these procedures are described below.

# Your function, `nicolas`

`void nicolas();`

## Description

You must implement this function. The program evaluator will look for it in your code and call it initially.

You can call the function `foto(y)` the necessary times to obtain information about Nicholas.

You must call the function `reporta(X, L)` exactly once to report the values of $X$ and $L$.

# The program evaluator function, `foto`

`bool foto(int y);`

## Description

The evaluator implements this function. Call it through the parameter `y`, which represents the box in which you want to take the photo.

## Return

This function returns `true` if in box $y$, you can find a part of Nicholas at the moment in which you took the photo. And it returns `false` on the contrary.

Remember that the next time you call`foto` it will be in the 1st second, the next time will be taken as the 2nd second, and so on.

# The program evaluator function, `reporta`

`void reporta(int X, int L);`

## Description

The program evaluator has implemented this function. Call it **exactly once** with parameters `X` and `L`, which represent Nicholas' velocity and length.

Once you call this function, your program's execution will end and it will check if the values you sent are correct.

# Example

||input
Called function
||output
Returned value
||description
Description
||input
nicolas()
||output

- ||description
  The program evaluator calls the function `nicolas()`. Nicholas's velocity is of 3mps y and he has a length of 2m. Remember these are unknown values for your program.
  ||input
  foto(2)
  ||output
  false
  ||description
  During second 1, Nicholas takes up the boxes $[3, 4]$. So he doesn't appear on the photo of the second meter.
  ||input
  foto(7)
  ||output
  true
  ||description
  During second 2, Nicholas takes up the boxes $[6, 7]$.
  ||input
  reporta(3, 2)
  ||output
  ||descriptionyou must call debes llamar `reporta()` so that the evaluator can check your solution.
  ||end

# Limits

- $1 \leq X, L \leq 1,000$

# Subtasks

- **Subtask 1 (12 points):**

  - $L = 1$
  - You can call `foto` as many times as you want.

- **Subtask 2 (12 points):**

  - $X = 1$
  - You can call `foto` as many times as you want.

- **Subtask 3 (26 points):**

  - You can call `foto` as many times as you want.

- **Subtask 4 (50 points):**
  - Your score depends on how many times you call `foto`
    - (10 points) If the number of calls is between $1,011$ and $1,020$
    - (25 points) If the number of calls is between $1,001$ and $1,010$
    - (50 points) If the number of calls is less or equal to $\leq 1,000$

# Experimentation

{{libinteractive:download}}

The test evaluator receives the file `sample.in` with the values of $X$ and $L$. For the previous example case, `sample.in` would look the following way:

```
3 2
```

_IMPORTANT:_ The test evaluator and the final evaluator that are used to grade your solution are different. The test evaluator has the debugging of your solution and can implement some of its functions differently.

---

![](nicolas.jpeg 'Nicholas, the vegetarian snake.')

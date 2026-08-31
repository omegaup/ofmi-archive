# Traversing the garden - Solution

## Subtask 1 (the subject is not moving backward)

Given that the subject never moves backward, the function `vueltas` must always return $0$. Thus, we must only make sure to have a correct calculation of the position we're located in at every moment (`curr_pos`). Every iteration of `adelante(x)` adds $x$ to that position.

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2 (the function, vueltas, is not called)

To solve this subtask, you must also add the function `atras(y)`, which must subtract $y$ from the current position.

<details><summary>Solution to the subtask 2</summary>

{{sub2.cpp}}

</details>

## Subtask 3 (one turn at the most)

For this subtask, the only turn that we have to do is when we call the function `atras` for the first time. From this moment onward, we must answer the function `vueltas` using the value of $1$.

<details><summary>Solution to the subtask 3</summary>

{{sub3.cpp}}

</details>

## Subtask 4 (solution)

To solve the complete problem, we need to see the moment in which the subject takes a turn. This happens when there is a change of direction. This being when you call `atras` and the last displacement was forward, or when you call `adelante` and the last displacement was backward. It is enough to store a variable that indicates the current direction we are following (it could be -1 for going backward and 1 for going forward, for example). If the direction changes, we add 1 unit to our number of turns, or `giros`.

<details><summary>Solution</summary>

{{solution.cpp}}

</details>

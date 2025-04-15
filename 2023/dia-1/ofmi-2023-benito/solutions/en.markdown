# Benito the Bunny - Solution

## Subtask 1. ($1 \leq n \leq 3$)

Given that the possible values of $n$ are very small, we can solve these cases by hand. The matrix of size $1\times 1$ is simply 1. While for the one of size $n=3$ it can be one of the following two forms:

```
1 1 1        2 2 2
1 2 1        2 1 2
1 1 1        2 2 2
```

Thus, we can make a code that checks if one of these cases is happening.

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2. (Spiral-shaped matrix)

Being a spiral, we can look for the biggest number in the matrix and print it as an answer. We can also analyze the smaller cases and observe that, given a matrix of size $n$, either growing from the outside to the inside or from the inside to the outside, the answer will be $(n + 1) / 2$.

<details><summary>Solution to the subtask 2</summary>

{{sub2.cpp}}

</details>

## Subtask 3. (Matrices spiraling from the outside to the inside)

Focusing on only one type of spiral allows us to analyze which patterns or structures they must have. For this case, we could run a simulation and build the matrix from the outside to the inside, but even when doing it by hand, we can observe that the number of a box depends on how close it is to a bound of the matrix.

For example, for the $7\times 7$ matrix,

```
1 1 1 1 1 1 1
1 2 2 2 2 2 1
1 2 3 3 3 2 1
1 2 3 4 X 2 1
1 2 3 3 3 2 1
1 2 2 2 2 2 1
1 1 1 1 1 1 1
```

The missing number `X` is at a 5-unit distance from the left bound, a 3-unit distance from the right bound, and a 4-unit distance from the upper and lower bounds. Effectively, the corresponding number of this position is 3.

As homework, you could demonstrate that this will always be fulfilled for the matrices spiraling from the outside to the inside. The important thing is that given a position $(x, y)$, the number that should be present in the $n\times n$ matrix can be calculated with the following function:

```g++
int distancia(int x, int y, int n) {
  return std::min(std::min(x + 1, y + 1), std::min(n - x, n - y));
}
```

With a double `for`, we can check if the matrix spirals from the outside to the inside or not.

<details><summary>Solution to the subtask 3</summary>

{{sub3.cpp}}

</details>

## Subtask 4. (Matrices spiraling from the outside to the inside)

For this subtask, was can make the same observations as in subtask 3, but the distance toward the closest bound won't indicate the number of the box. Instead, this value will tell us how much we would need to subtract from $(n + 1) / 2$ to have the correct number on that position.

<details><summary>Solution to the subtask 4</summary>

{{sub4.cpp}}

</details>

## Subtask 5.

We can join the solutions of the last two subtasks to achieve a general solution.

<details><summary>Full solution</summary>

{{solution.cpp}}

</details>

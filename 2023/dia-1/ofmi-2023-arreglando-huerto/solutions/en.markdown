# Fixing the garden - Solution

## Subtask 1 group. (Ordered elements)

The key of this subtask is to see that, given that there is always a solution, $A_i \geq B_i$ is always achieved. For this reason, we can always move from left to right. In other words, we start from the first element of $A$, subtract the necessary to make it equal to the first one of $B$, and pass it on to the right. We do the same with the second element, and so on.

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2.

The first thing we must do starting from this subtask it knowing if it's possible to make both arrays the same. This results in the garden being fixable if and only if the sum of the elements of $A$ is equal to the one of $B$.

A simple demonstration takes us to an algorithm to solve subtask 2. We can execute a first iteration in which we pass all elements of $A$ from left to right, accumulating all the sum of $A$ in the first box. That way, we can run the same algorithm from the past subtask to accommodate all the necessary elements, now from left to right.

<details><summary>Solution to the subtask 2</summary>

{{sub2.cpp}}

</details>

## Subtask 3.

The last algorithm gives us the answer in $2n$ calls. To reduce this number, we can ensure that within each pair of adjacent boxes, we only have one possible movement (either to the left or to the right).

We start with an array of size $n$, looking for the first index $j$ from left to right so that $\sum_{i=0}^{j} A_i \geq \sum_{i=0}^{j} B_i$. Then, what we must do is pass elements from left to right starting from $j$. Once that's done, all elements of $[0, j]$ will be fixed. Then we apply the same algorithm for the remaining subarray ($[j + 1, n]$).

<details><summary>Solution</summary>

{{solution.cpp}}

</details>

# Zombies versus plants - Solution

## Subtask 1 ($d = 1$).

For this subtask, we must observe that each one of the $n$ zombies will be attacked exactly an equal number of times to its life points; so for each zombie with $a_i$ life points, we will need $a_i - 1$ shields.

Thus, the solution is to iterate on the $n$ zombies and print the accumulated sum of $a_i - 1$.

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2 ($n = 1$).

For this subtask, we must find a way of knowing how many shields we will use now with only one zombie that has $a$ life points. There are two ways to do this: the first one is simulating shot after shot.

<details><summary>Solution to the simulation for subtask 2</summary>

{{sub2.cpp}}

</details>

The other way is by realizing we will occupy exactly $(a - 1) / d$ shields.

## Subtask 3

This subtask is achieved by combining subtask 1 with the simulation for subtask 2. Instead of adding $a_i - 1$ (the shields we would use if $d = 1$), we simulate shot after shot and count the shields zombie by zombie.

## Subtask 4

To obtain the full score, you need to know that the $i$-th zombie will make you spend $(a_i - 1) / d$ shields. Thus, the complete solution is to iterate on the $n$ zombies and print the accumulated sum of $(a_i - 1) / d$.

<details><summary>Solution</summary>

{{solution.cpp}}

</details>

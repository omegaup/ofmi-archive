# The Tour of the Eras- Solution

## Subtask 1. ($N = 1$)

In this subtask, there is a certainty that there will only be one animal buying $D$ mushrooms, which won't be considered a reseller (given that $D < L$). Then, in this case, we only need to see how many mushrooms can be sold to it after separating the $R$ mushrooms for the general sale.

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2. ($D_i < L$)

This subtask is a generalization of the last one; after having separated the $R$ mushrooms, we try to sell each animal the maximum possible number of these access items. Now we need to traverse the list using a `for` statement.

<details><summary>Solution to the subtask 2</summary>

{{sub2.cpp}}

</details>

## Subtask 3. (Enough mushrooms)

In this subtask, there are enough mushrooms for all animals, so we don't have to worry about saving mushrooms for the general sale period. However, now we have to take care of not overselling mushrooms to the reselling snakes. This can be verified with an `if (D[i] > L)` while we traverse the list using a `for` statement.

<details><summary>Solution to the subtask 3</summary>

{{sub3.cpp}}

</details>

## Subtask 4.

The goal of the previous subtasks is to be able to solve the original problem by parts, starting with what instructions we need to place to be able to sell mushrooms to the animals if these run out, or how to sell to the animals if they ask for a number of items over the permitted limit. In the general solution, we have to consider both cases, so we can join the previous solutions into only one to cover all the points for an ideal solution.

<details><summary>Full solution</summary>

{{solution.cpp}}

</details>

# Find the lettuce - Solution

## Subtask 1 (The garden has not been invaded by the URG)

Given that the URG has not taken over boxes in the garden and that the guinea pigs can only move to the left, right, up, or down with each passing second, the minimum quantity of seconds between each guinea pig and the lettuce will be the absolute value of the position $(i, j)$ of each guinea pig minus the position $(x, y)$ of the lettuce. Considering the previous information, if the seconds each guinea pig
takes to get to the lettuce are recorded in a list, you can order the arrivals in ascendent order, to then traverse the array through a while statement until either there is no more lettuce to eat, or all the guinea pigs have arrived. And finally, you print which guinea pigs are eating lettuce and which are not.

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2 (Solution)

To solve the complete problem, it is important to note that given that the URG has already invaded the garden, it is necessary to implement an algorithm to find the number of seconds a guinea pig takes to get to the lettuce. Thus, you can construct a BFS starting from the lettuce to all the boxes in the garden, which will give us a minimum number of seconds to move to every box in the garden. Through a conditional statement, you can then add the minimum number of seconds in the boxes where there are guinea pigs to the list, and apply the same algorithm on _Subtask 1_ to find out which guinea pigs are eating and which aren't.

<details><summary>Solution</summary>

{{solution.cpp}}

</details>

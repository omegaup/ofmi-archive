# Mich the Explorer - Solution

## Subtask 1 (n = 1)

For subtask 1, as N equals 1, the room is a line and you have to get to the East to get towards the gate, so it is enough to count how many tiles before the last one point to another direction.

![](330462831_1192585168065821_2065832953943047226_n.jpg)

<details><summary>Solution to the subtask 1</summary>

{{sub1.cpp}}

</details>

## Subtask 2 (arriving without modifications)

For subtask 2, it is enough to follow the way indicated by the tiles and corroborate if you can get to the gate or not.

![](329394651_574786484541860_126123251104163130_n.jpg)

<details><summary>Solution to the subtask 2</summary>

{{sub2.cpp}}

</details>

## Subtask 3

For the general case, we must first note if arriving without modifications would be the best possible solution. If this is not the case, we should mark all the tiles we can arrive at without needing a coin as visited (which are the green ones in the figure). After that, we can arrive at any tile that is adjacent to one of them by spending a coin. Even so, we can follow the path marked by the board from each of them, showing all the reachable tiles by spending one coin (which are the yellow ones in the figure). We can repeat this process, now from following the possible paths of all the adjacent tiles to a yellow space, which are the reachable tiles with two coins (the blue tiles in the figure), and so on until you reach the gate.

![](329091306_2272586872926551_7313266498286252245_n.jpg '  Tile paths that can be formed with each quantity of coins')

<details><summary>Solution</summary>

{{solution.cpp}}

</details>

Some observations that help understand the solutions are:

- The gate is always reachable, as I have enough coins to modify in the worst-case scenario, all the tiles from one path toward the gate.
- I can always find a path that spends the least possible amount of gold coins without cycles, as the cycle can be cut; if coins were spent on the cycle, that is because after the cycle you needed to pass through a certain tile with a specific direction; in such case, you can use the coin after the cycle.
- The prior observation allows us to implement the algorithm in a way that we mark the tiles as visited and we don't process them again so that the number of operations is described by the maximum (N\*M) tiles we process, multiplied by a factor 4 by accounting the maximum of 4 neighbors that each tile has (depending of the implementation, there can be a bigger factor, so there is still a good amount of time left considering the time limit given by the problem).

This algorithm is a modification of the classical algorithm of Breadth First Search, also known as BFS. You can practice more about this subject with the following practice problems:

- https://omegaup.com/arena/problem/Volcan/
- https://omegaup.com/arena/problem/Intersecciones/
- https://omegaup.com/arena/problem/L-OMI-Super-Agente/

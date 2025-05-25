Mich is a great explorer. Today he is determined to find the legendary Jade Carrot, a relic that, as the old tales say, will bring prosperity to the crops of delicious vegetables. To accomplish this, he has entered the Cuytlán ruins, an old and prosperous agricultural civilization, but the last part to reach the Jade Carrot is a trap.

The trap consists of a rectangular room where the floor is covered by square tiles, where each tile shows an arrow pointing toward one of the four directions (North, South, East, or West) going to another tile or to the wall inside the room. Mich can jump between adjacent tiles, but if he's on a tile and jumps in a direction that is different from the one it's pointing to, the gate to the Jade Carrot will close and he will only have the option to go back through the way he came from, but without the long-awaited, mythical carrot.

Fortunately, there is an alternative, as through his trajectory Mich can drop a gold coin over the tile in which he's in, changing the direction to any of the four possible ones. Our explorer was expecting something of the sort, so he carries enough gold coins to make this change of direction at the necessary times. However, he would like to spend the least amount of them possible to celebrate big when he returns from his adventure.

Considering Mich starts in the lower left corner of the room, and the gate is located in the upper right corner, help Mich reach the gate by spending the least possible amount of gold coins.

# Input

In the first line, two numbers $N$ and $M$, which represent the width and height of the room.

In the following $N$ lines, $M$ numbers that indicate the direction to which each tile points: `0` for North, `1` for East, `2` for South, and `3` for West.

# Output

In the first line, a number is printed, which represents the smallest quantity of gold coins that Mich needs.

In the following $N$ lines, $M$ numbers that indicate the direction toward which each tile points in Mich's trajectory are shown. Remember that the given trajectory utilizes the minimum possible amount of gold coins. Use `0` for North, `1` for East, `2` for South, and `3` for West. In case there is more than one valid solution, you can print any of them.

# Examples

||examplefile
sample
||description
Initially, you cannot go from the lower left corner to the upper right corner, so you must at least make a modification necessarily. As you can observe in the following output, only one modification was made, and this represents the minimum possible number of changes.

Note that the other possible modification also achieves the outcome the problem is asking for, so both are accepted.

```
1 1 2

0 1 0
```

||examplefile
sampleNoMinPath
||end

# Limits

- $1 \leq N, M \leq 500$

# Subtasks

- **Subtask 1 (5 points):**.
  - It is certain that $N = 1$.
- **Subtask 2 (10 points):**.
  - You must determine if it is possible to arrive at the gate without making modifications. In the first line, you must print $0$ if that is possible or $-1$ on the contrary. It is not necessary to print the room. In case you need to change tiles and you print the correct quantity of tiles you need to change and the modified board, you'll get the points for this subtask.
- **Subtask 3 (85 points):**
  - No additional considerations.

---

![](explorador.jpeg 'Mich the explorer.')

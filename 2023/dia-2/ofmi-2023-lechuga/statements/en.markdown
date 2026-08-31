Some farmer guinea pigs have planted one giant lettuce in one of the boxes within their rectangular garden, which has the dimensions of $N \times M$ boxes. In addition to it, every guinea pig has its house in one of these spaces. However, the United Rat Gang (URG) has taken over some boxes; to avoid problems, the guinea pigs have decided not to step over there.

The guinea pigs are hungry, so they've decided to get out of their houses to eat the giant lettuce. Only one guinea pig lives in each house. In the 0th second, all the guinea pigs are located inside their houses. After that, in each of the following seconds, all the guinea pigs can move to an adjacent box, either to the left, to the right, upwards, or downwards. Once a guinea pig gets to the giant lettuce, it awaits a second, and after that, it starts eating a unit of the giant lettuce over each passing second.

In case there are being multiple guinea pigs in the box of the giant lettuce and there does not happen to be enough lettuce for all of them in the same time lapse, the guinea pigs will get organized to prioritize feeding the guinea pigs that have not eaten yet at a given moment. Plus, it's possible that when any guinea pig arrives at the giant lettuce it won't be able to get food, as its guinea pig friends will have finished the giant lettuce by then. Además, es posible que cuando llegue cualquier cobaya a la gran lechuga. Assuming that the guinea pigs move optimally, meaning they will always try to get to the giant lettuce in the smallest time possible, ¿how many guinea pigs will not eat at least a unit of the giant lettuce?

# Input

In the first line, you will receive two integers separated by a space, $N$ and $M$, which represent the number of rows and columns of the garden, respectively.

In the following lines, you will see a matrix of $N \times M$ integers separated by a space that represents the initial configuration of the garden.

- Free boxes are represented with a 0.
- URG boxes are represented with a -1.
- Houses are represented with a 1.
- The giant lettuce is represented with a number $S \geq 2$ (Where $S$ is the number of units in the giant lettuce).

# Output

Print the number of guinea pigs that are not able to eat lettuce.

# Example

||examplefile
sample
||examplefile
sample1
||examplefile
sample2
||end

# Limits

- $2 \leq N, M \leq 1,000$
- $2 \leq S \leq 10^6$

# Subtasks

- **Subtask 1 (25 points):**
  - The matrix doesn't contain $-1$.
- **Subtask 2 (75 points):**
  - No additional considerations.

---

![](lechuga.jpeg 'Farmer guinea pigs.')

Benito is the world's most famous bunny due to his successful career as a singer.

After ending his most recent tour _Un saltito sin ti_ , Benito is determined to return to his burrow with the objective of eating the biggest carrot in his garden.

However, fame has taken a toll on him, which is why Benito only eats carrots that have grown in a spiral-shaped garden; if this doesn't happen, Benito turns angry and becomes a bad bunny.

A garden is determined to be spiral-shaped if:

1. It is a square-shaped matrix of $n \times n$ with an odd $n$ value.

2. One of the following conditions is achieved:

   - A spiral is formed from the outside to the inside. This means that the outside bounds of the square are formed exclusively by $1$ $mm$ carrots, while the bounds of the square inside it contain $2$ $mm$ carrots, and so on until you get to the interior with the square of $1 \times 1$ with the biggest type of carrot.

   - A spiral is formed from the inside to the outside. This means that the outside bounds of the square are of the biggest size possible for this matrix of $n \times n$ and this diminishes slowly until the interior with the square of $1 \times 1$ with a carrot of $1$ $mm$.

![](huertoEspiral.png 'An example of a spiral-shaped garden going from the inside to the outside.')

The program must be capable of identifying if the matrix is a spiral or not.

You must print the size of the biggest carrot there is in Benito's garden.

# Input

In the first line, there is the integer $n$, which represents the size of the matrix.

In each one of the following $n$ lines, there will be $n$ separate integers, which are separated by a space that represents the size of the carrots in millimeters.

# Output

Print the size of the biggest carrot in the spiral-shaped garden.

In case the garden is not spiral-shaped, print -1.

# Examples

||examplefile
sample
||examplefile
sample1
||examplefile
sample2
||end

# Limits

- $1 \leq n \leq 800$. $n$ has an odd value.

# Subtasks

- **Subtask 1 (10 points):**
  - $1 \leq n \leq 3$.
- **Subtask 2 (10 points):**
  - It is a certainty that matrices are always spiral-shaped.
- **Subtask 3 (20 points):**
  - Only matrices that are not spiral-shaped and those in spirals from the outside to the inside.
- **Subtask 4 (20 points):**
  - Only matrices that are not spiral-shaped and those in spirals from the inside to the outside.
- **Subtask 5 (40 points):**
  - No additional considerations.

---

![](benito.jpeg "Benito, the world's most famous bunny.")

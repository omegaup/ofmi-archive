A year ago, you decided to start growing your own garden, with the objective of growing fresh and healthy fruits and vegetables. You know it's important to include these foods in your diet to maintain a healthy lifestyle.

What you didn't know, is that a line of $n$ zombies is moving towards your garden with the intention of destroying your crops. Each zombie has a different number of life points. So to protect your garden, you have a gun that affects $d$ points of damage.

Your strategy is to attack the closest zombie until it dies. Each shot takes $d$ points from its life. However, each time a zombie survives your shot, it attacks you and destroys one of your protection shields. Thus, you must have enough protection shields to stay safe from the infection.

# Problem

You must calculate the minimum number of necessary shields to protect yourself from the zombies and save your crops.

# Input

The first line contains two integers $n$ and $d$, which represent the number of zombies and the points of damage from your gun, respectively.

The next line contains an array of $n$ integers, where the $i$-th number represents the life points of the zombie in position $i$.

# Output

You must print the minimum number of necessary shields to accomplish your mission.

# Examples

||examplefile
sample
||description
There are 5 zombies and your gun makes 3 points of damage.

- You attack the first zombie (which has 2 points of life) and kill it.
- You attack the second zombie (which has 5 points of life).
- The second zombie attacks you.
- You attack the second zombie (with 2 points of life) and kill it.
- You attack the third zombie (which has 8 points of life).
- The third zombie attacks you.
- You attack the third zombie (with 5 points of life).
- The third zombie attacks you again.
- You attack the third zombie (with 2 points of life) and you kill it.
- You attack the fourth zombie (which has 2 points of life) and you kill it.
- You attack the fifth zombie (with 4 points of life) and you kill it.
- The fifth zombie attacks you.
- You attack the fifth zombie (which has 1 point of life) and you kill it.

In total, you needed 4 shields to defend yourself.
||end

# Limits

- $1 \leq n \leq 10^5$
- $1 \leq d, a_i \leq 10^9$

# Subtasks

- **Subtask 1 (5 points):**
  - $d = 1$ (your gun makes only 1 point of damage)
- **Subtask 2 (5 points):**
  - $n = 1$ (there is only one zombie)
- **Subtask 3 (20 points):**
  - $1 \leq n \leq 100$, $1 \leq d, a_i \leq 100$ (There are, at a maximum, 100 zombies, and your gun makes, at the most, 100 points of damage)
- **Subtask 4 (70 points):**
  - No additional considerations.

---

![](zombies.jpeg 'The zombies approaching your garden.')

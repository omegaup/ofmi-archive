Tyler Sweet has just announced her world tour for all her herbivore fans, The Tour of The Eras, and asked the webpage Ticket Monster to manage the mushroom sales (Hongus Boletus) which serve as an access to enter the concert so that the sales would not collapse during the presale period.

She also wanted some mushrooms to be sold during the presale, in order to give more animals the opportunity to get a mushroom, worried specifically about reseller snakes taking over the event. 

Ticket Monster told Tyler they could manage it all, but they messed up badly, and aside from collapsing the sales, they finished distributing the mushrooms during the presale period.

Tyler is very mad about this, so she has hired you to make a better code than Ticket Monster's. To prove yourself, she asks you to only handle the mushroom sales in the city of Aguascalientes.

You have been told to make a program that processes $N$ animals that arrived at a virtual line, and you have to manage their demands in the order that they arrived. They also told you there is a total of $B$ mushrooms, but you want there to be at least $R$ remaining mushrooms after the presale period. In order to not give many mushrooms to the snakes, you won't sell more than $L$ mushrooms per animal.

# Input

In the first line, you will receive four integers: $N$, $B$, $R$,  and $L$.

In the following line, you will see $N$ integers, separated by a space. These represent the tickets $D_i$ that the $i$-the aminal in the line ordered.

# Output

Print $N$ integers that represent the number of tickets that you sold to the $i$-th person.

# Example

||examplefile
sample
||end

# Limits

- $1 \leq N \leq 10^5$
- $0 \leq R \leq B \leq 10^5$
- $0 \leq L, D_i \leq 1000$

# Subtask

- **Subtask 1 (10 points):**
  - $N = 1$, $L \gt D_i$ for all $i$
- **Subtask 2 (15 points):**
  - $L \gt D_i$ for all $i$
- **Subtask 3 (15 points):**
  - It is a certainty you'll always have enough mushrooms. $(B - R \gt \sum D_i)$
- **Subtask 4 (60 points):**
  - No additional considerations.

---

![](ticketmonster.jpeg 'Fans in the great Tour of The Eras.')

Tapia tiene una colección de $N$ chocolates, cada uno con un cierto nivel de deliciosidad. Tapia quiere llenar $M$ bolsas con los chocolates de su colección para regalarlos a sus amigos.

Juanito le va a ayudar a Tapia a llenar las bolsas. Tapia abre una bolsa y le dice a Juanito que le vaya pasando chocolates. Juanito le va pasando los chocolates uno por uno a Tapia. Tapia toma el chocolate y decide si lo guarda en la bolsa o no. Si decide guardarlo, lo pone en la bolsa y continúa. Si no, cierra esa bolsa, abre una nueva, pone el chocolate en la nueva bolsa y continúa. Todos los chocolates deben ser guardados en alguna bolsa y cada bolsa debe tener al menos $K$ chocolates.

Al final, Tapia quiere conservar algunos chocolates para él. De cada bolsa, Tapia va a tomar los $K$ chocolates **menos** deliciosos y los va a guardar para él (para dejarles los más sabrosos a sus amigos).

# Problema

Dado $N$, $K$ y la deliciosidad de cada chocolate, tu tarea es ayudar a Tapia a encontrar la mejor forma de llenar las bolsas para que la suma de las deliciosidades de los chocolates con los que se quede Tapia sea la **menor posible**.

# Entrada

En la primera línea tres enteros $N$, $M$ y $K$, que representan la cantidad de chocolates, la cantidad de bolsas y la cantidad de chocolates que Tapia se va a quedar por cada bolsa, respectivamente.

En la siguiente línea $N$ enteros separados por espacios $A_i$ que representan la deliciosidad de cada chocolate, en el orden en que Juanito se los va a pasar a Tapia.

# Salida

Deberás imprimir $M-1$ enteros separados por espacios $p_1$, $p_2$ ..., $p_{m-1}$ que representan la mejor partición de chocolates, en donde:

- La bolsa $1$ contiene los chocolates desde el índice $1$ hasta el $p_1$
- La bolsa $2$ contiene los chocolates desde el índice $p_1 + 1$ hasta el $p_2$.
- ...
- La bolsa $M$ contiene los chocolates desde el índice $p_{M-1} + 1$ hasta el $N$-ésimo.

Si hay más de una solución óptima, puedes imprimir cualquiera de ellas.

# Ejemplo

||examplefile
sub3.sample
||description
Tenemos $N = 9$ chocolates, $M = 3$ bolsas por llenar y Tapia se va a quedar con $K = 2$ chocolates de cada bolsa. Podemos minimizar la suma de chocolates que se va a quedar de la siguiente forma:

- Tapia llena la bolsa $1$ con los chocolates $[1, 2]$ (del índice $1$ al $2$).
- Tapia cierra la bolsa $1$ y abre una nueva.
- Tapia llena la bolsa $2$ con los chocolates $[5, 1, 3]$ (del índice $3$ al $5$).
- Tapia cierra la bolsa $2$ y abre una nueva.
- La bolsa $3$ contiene los chocolates $[2, 5, 2, 4]$ (del índice $6$ al $9$).

Tapia se queda con los chocolates de deliciosidad $[1, 2]$ de la bolsa $1$, $[1, 3]$ de la bolsa $2$ y $[2, 2]$ de la bolsa $3$. La suma de los chocolates que se va a quedar es $11$.

No hay una forma de llenar las bolsas para que la suma sea menor. Por lo tanto, imprimimios `2 5` como respuesta, el índice del último chocolate de la bolsa $1$ y el índice del último chocolate de la bolsa $2$.
||end

# Límites

- $2 \leq N \leq 10^5$
- $1 \leq M, K, M*K \leq N$
- $1 \leq A_i \leq 10^9$

# Subtareas

- **Subtarea 1 (8 puntos):**
  - $N \leq 1000$, $M = 2$.
- **Subtarea 2 (12 puntos):**
  - $N \leq 1000$, $M = 3$.
- **Subtarea 3 (35 puntos):**
  - $N \leq 300$.
- **Subtarea 4 (9 puntos):**
  - $K = 1$.
- **Subtarea 5 (36 puntos):**
  - Sin consideraciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![Chocolates](chocolates.jpg 'Chocolates.')

En Yucatán se les dice turix o turixes a las libélulas. Los turixes quieren ir a presenciar la próxima OFMI y para ello tienen que viajar grandes distancias. Para volar, necesitan energía, la cual obtienen de su alimento favorito: los pretzels.

Hay un turix que vuela durante $t$ segundos y en cada segundo $i$ vuela a una altura $H_i$.

Volar a cierta altura $j$ requiere de cierta cantidad de pretzels $P_j$.

# Problema

Dada la lista de alturas a las que vuela el turix y la cantidad de pretzels necesarios para cada altura, tu tarea es calcular la cantidad de pretzels que necesitará en total.

# Entrada

En la primera línea vendrán dos enteros $t$ y $h$, que representan el número de segundos que vuela el turix y la máxima altura que sabemos que el turix podría alcanzar.

En la segunda línea vendrán $t$ enteros, donde el $i$-ésimo número $H_i$ representa la altura a la que voló en el segundo $i$.

En la tercera línea vendrán $h$ enteros, donde el $j$-ésimo número $P_j$ representa la cantidad de pretzels que requiere el turix para volar a una altura $j$.

# Salida

Un único entero que representa la cantidad total de pretzels que necesita el turix.

# Ejemplo

||examplefile
sub3-sample
||description
El turix estuvo en el aire $10$ segundos.

- En el segundo $1$ voló a una altura de $2$, por lo que necesitó $5$ pretzels.
- En el segundo $2$ voló a una altura de $3$, por lo que necesitó $2$ pretzels.
- En el segundo $3$ voló a una altura de $3$, por lo que necesitó $2$ pretzels.
- En el segundo $4$ voló a una altura de $4$, por lo que necesitó $5$ pretzels.
- En el segundo $5$ voló a una altura de $2$, por lo que necesitó $5$ pretzels.
- En el segundo $6$ voló a una altura de $3$, por lo que necesitó $2$ pretzels.
- En el segundo $7$ voló a una altura de $1$, por lo que necesitó $3$ pretzels.
- En el segundo $8$ voló a una altura de $1$, por lo que necesitó $3$ pretzels.
- En el segundo $9$ voló a una altura de $2$, por lo que necesitó $5$ pretzels.
- En el segundo $10$ voló a una altura de $1$, por lo que necesitó $3$ pretzels.

En total, el turix necesitó $5 + 2 + 2 + 5 + 5 + 2 + 3 + 3 + 5 + 3 = 35$ pretzels.

||end

# Límites

- $1 \leq t, h \leq 10^5$.
- $1 \leq H_i \leq h$ para toda $1 \leq i \leq t$.
- $1 \leq P_j \leq 1,000$ para toda $1 \leq j \leq h$.

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $P_j = 1$ para toda $1 \leq j \leq h$.
- **Subtarea 2 (10 puntos):**
  - $t = 1$.
- **Subtarea 3 (80 puntos):**
  - Sin restricciones adicionales.

**Nota:** Las subtareas no estarán agrupadas.

---

![](turix.jpeg 'El turix comiendo pretzels.')

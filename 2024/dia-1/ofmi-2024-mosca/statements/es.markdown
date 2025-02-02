En el reino de las mosquitas, las mosquitas juegan "mosca, mosca, ¡abeja!", un juego que antecede al conocido "pato, pato, ¡ganso!". Andrea es la mosquita más sociable y tiene muchísimas amigas. Para jugar con ella, sus $n$ amigas se forman en una fila.

Andrea te entregó una lista de a quiénes les va a decir mosca y a quiénes abeja; sin embargo, Andrea te dio la lista de manera reducida para no escribir mucho. Ella escribió una lista de $m$ números positivos de la siguiente manera:

- Primero, escribió el número de amigas a las que les va a decir mosca al inicio de la fila.
- Después, continúa con el número de amigas siguientes en la fila a las que les va a decir abeja.
- Después, continúa con el número de amigas siguientes en la fila a las que les va a decir mosca.
- Después, el número de amigas siguientes en la fila a las que les va a decir abeja, y así alternadamente hasta que los números de la lista sumen un total de $n$ amigas.

Por ejemplo, si la fila se ve así: _[mosca, mosca, abeja, abeja, abeja, mosca, abeja, abeja, abeja]_,
entonces la lista de Andrea se verá así: _[2 3 1 3]_.

Andrea está interesada en saber qué le va a tocar a $q$ de sus amigas. Tú sabrás en qué lugar se formaron en la fila, entonces, para cada una de ellas, ayúdale a saber si les tocará mosca o abeja.

# Problema

Dados $n$ y $m$, el número de amigas de Andrea y el tamaño de la lista reducida, así como la lista reducida de la fila, deberás ayudarle a Andrea a saber qué le toca a $q$ de sus amigas.

# Entrada

En la primera línea, dos enteros $n$ y $m$: el número de amigas de Andrea y el tamaño de la lista reducida que te dio.

En la segunda línea, vendrán $m$ enteros $p_i$, separados por espacio, que representan la lista reducida de amigas a las que les va a decir mosca o abeja.

En la tercera línea, vendrá un único entero $q$: el número de amigas que están interesadas en saber qué les tocó.

En las siguientes $q$ líneas vendrá un entero $a_i$ que representa la posición en la fila de esa amiga. Andrea te garantiza que te dirá las posiciones de sus amigas en orden no decreciente.

# Salida

Deberás imprimir $q$ líneas, en donde la $i$-ésima línea es `"Mosca"` (sin comillas) si la amiga $q_i$ le tocó mosca, o `"Abeja"` (sin comillas) si le tocó abeja.

# Ejemplo

||examplefile
2_sub2.sample
||description
Andrea tiene $9$ amigas y la lista reducida que te dio significa que ella asignó a sus amigas de la siguiente manera:

- A las primeras dos amigas en la fila, les tocó mosca.
- A las siguientes tres amigas, les tocó abeja.
- A la siguiente le tocó mosca.
- A las últimas tres amigas les tocó abeja.

Por lo tanto, la fila de amigas se vería como _[mosca, mosca, abeja, abeja, abeja, mosca, abeja, abeja, abeja]_.

De las cuatro amigas de las que Andrea quiere saber qué les tocó, tenemos lo siguiente:

- A la amiga $2$ le tocó mosca.
- A la amiga $4$ le tocó abeja.
- A la amiga $6$ le tocó mosca.
- A la amiga $8$ le tocó abeja.

||end

# Límites

- $1 \leq n \leq 10^9$.
- $1 \leq m \leq min(n, 2 \times 10^5)$.
- $1 \leq p_i \leq n$.
- $\sum\_{i=1}^{m} p_i = n$; es decir, la suma de todos los números de la lista reducida será exactamente $n$.
- $1 \leq q \leq 2 \times 10^5$.
- $1 \leq a_i \leq n$.
- $a_i \leq a_j$ para toda $1 \leq i < j \leq q$; es decir, las amigas están ordenadas de manera no decreciente.

# Subtareas

- **Subtarea 1 (15 puntos):**
  - $m = 2$.
- **Subtarea 2 (26 puntos):**
  - $1 \leq n \leq 2 \times 10^5$.
- **Subtarea 3 (24 puntos):**
  - $1 \leq q \leq 300$.
- **Subtarea 4 (35 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![](mosca.jpeg 'Mosquitas jugando "mosca, mosca, ¡abeja!".')

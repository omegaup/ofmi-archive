En un almacén hay $n$ cubetas de varios tamaños numeradas del $1$ al $n$, donde la $i$-ésima cubeta tiene un tamaño $T_i$. Una cubeta $i$ de tamaño $T_i$ se puede apilar dentro de otra cubeta $j$ de tamaño $T_j$ si y solo si $T_i = T_j - 1$, es decir, si la cubeta $i$ es exactamente una unidad más pequeña que la cubeta $j$.

El dueño del almacén te ha pedido ayuda para organizar las cubetas en el menor número de pilas posible, donde cada pila consiste en una o más cubetas apiladas verticalmente siguiendo la regla del párrafo anterior.

![Ilustración del caso de ejemplo](ejemplo-cubetas.png)

# Problema

Dado $n$ y la lista de tamaños de las $n$ cubetas, ayuda al dueño del almacén a determinar el número mínimo de pilas necesarias para acomodar todas las cubetas.

# Entrada

En la primera línea un entero $n$, representando el número de cubetas en el almacén.

En la segunda línea vendrán $n$ enteros $T_1, T_2, \dots, T_n$, representando los tamaños de las cubetas.

# Salida

Un único entero representando el mínimo número de pilas necesarias para acomodar todas las cubetas del almacén.

# Ejemplo

||examplefile
sub3.sample
||description
Se pueden formar dos pilas, la primera de ellas se hace con las cubetas de tamaño $1$, $2$, $3$, $4$.

La segunda pila se forma con las cubetas de tamaño $2$ y $3$ que sobran.
||examplefile
sub2.sample
||description
Ninguna cubeta se puede apilar porque la diferencia entre sus tamaños es más de una unidad.
||end

# Límites

- $1 \leq n \leq 2 \times 10^5$.
- $1 \leq T_i \leq 10^9$.

# Subtareas

- **Subtarea 1 (11 puntos):**
  - $1 \leq T_i \leq 3$.
- **Subtarea 2 (21 puntos):**
  - $T_i \neq T_j$ para toda $1 \leq i < j \leq n$, es decir, todos los tamaños de las cubetas son diferentes.
- **Subtarea 3 (25 puntos):**
  - $1 \leq T_i \leq 10^6$.
- **Subtarea 4 (43 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

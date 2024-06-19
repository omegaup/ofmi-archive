Has comprado un bello libro de mandalas. El libro tiene $n$ páginas, donde la página $i$ presenta un mandala distinto que te toma $A_i$ minutos colorear. Quieres colorear gran parte del libro en el menor tiempo posible de tal forma que no hayan más de $k$ páginas consecutivas sin colorear.

# Problema

Dado el número de páginas del libro, el tiempo que te toma colorear cada página y el máximo número de páginas consecutivas que puedes dejar sin colorear, determina el mínimo tiempo que te tomará colorear el libro de mandalas de tal forma que no hayan más de $k$ páginas consecutivas sin colorear.

# Entrada

En la primera línea se encuentran dos enteros $n$ y $k$, la cantidad de páginas del libro y el máximo numero de páginas consecutivas que se puede dejar sin colorear, respectivamente.

En la siguiente línea se encuentran $n$ enteros $A_i$ separados por espacio, el tiempo que te toma colorear la página $i$.

# Salida

Debes imprimir un único entero, el mínimo tiempo posible que te tomará colorear el libro de mandalas de tal forma que no hayan más de $k$ páginas consecutivas sin colorear.

# Ejemplo

||examplefile
sub2.sample
||description
Únicamente necesitas colorear la página $2$ para cumplir que no hayan más de $k=2$ páginas consecutivas sin colorear.
||examplefile
sub2.sample2
||end

# Límites

- $1 \leq n \leq 2 * 10^5$
- $1 \leq k \leq n$
- $1 \leq A_i \leq 10^9$

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $A_i = A_j$ para todo $i, j$ (te tomará el mismo tiempo colorear cada página).
- **Subtarea 2 (18 puntos):**
  - $n \leq 20$.
- **Subtarea 3 (14 puntos):**
  - $k = 1$.
- **Subtarea 4 (30 puntos):**
  - $k \leq 100$.
- **Subtarea 5 (28 puntos):**
  - Sin consideraciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![Megalibro de mandalas](megalibro.jpg 'Megalibro de mandalas.')

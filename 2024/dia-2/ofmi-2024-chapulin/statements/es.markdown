Charly, el Chapulín que brinca sin fin, salta todos los días desde su casa a la escuela por una banqueta cuadriculada de ancho $1$. Como Charly siempre salta en línea recta, inventó un juego para no aburrirse de hacer lo mismo todos los días.

En la banqueta hay $n$ cuadros, numerados de izquierda a derecha de $1$ a $n$. Charly puede escoger cualquier cuadro de la banqueta para empezar a jugar. Luego escoge un número $s$ que marcará el tamaño de sus saltos. Además, Charly siempre saltará hacia adelante, porque no quiere llegar tarde a clase. Es decir, si Charly se encuentra en el cuadro numerado con $x$, saltará al cuadro numerado con $x+s$. Además de los saltos de tamaño $s$, en cualquier momento puede realizar **un solo turbo salto** con tamaño de a lo más $t$. Inmediatamente después de hacer el turbo salto, Charly debe continuar dando saltos de tamaño $s$.

Como parte del juego, Charly le asigna un valor a cada uno de los cuadros de la banqueta que forman su camino. Es decir, al $i$-ésimo cuadro le asigna un valor $A_i$. Para ganar el juego, Charly debe maximizar la suma de los valores de cada cuadro que pise en el trayecto de su casa a la escuela. El juego terminará cuando llegue a la escuela, es decir, cuando su salto rebase el último cuadro de la banqueta.

# Problema

Dado un arreglo $A$ de $n$ enteros $A_1, A_2, ..., A_{n-1}, A_n$ que representan los valores que Charly le asignó a los cuadros de la banqueta, el tamaño de salto $s$ y el tamaño máximo $t$ que puede saltar con el turbo salto, debes determinar la suma máxima de los valores en el arreglo por los que Charly puede saltar.

# Entrada

En la primera línea se proporcionan tres enteros $n$, $s$ y $t$, que representan el tamaño del arreglo $A$, el tamaño del salto $s$ y el tamaño máximo del turbo salto $t$.

En la segunda línea se incluyen $n$ enteros, donde el $i$-ésimo entero representa el valor $A_i$ del arreglo.

# Salida

Un único entero que represente la suma máxima de los valores por los que Charly puede saltar en el arreglo.

# Ejemplo

||examplefile
sub1.sample
||description
El turbo salto no ayuda, ya que tiene un tamaño de $0$. Si comenzamos a saltar desde la primera posición del arreglo, sumaremos $3 + 2 + 4 = 9$, que es lo máximo que se puede obtener.
||examplefile
sub3.sample
||description
Con el turbo salto disponible para alcanzar cualquier otra casilla del arreglo, podemos comenzar en la segunda posición ($4$), usar el turbo salto de tamaño $1$ para llegar a la tercera posición ($2$), y seguir haciendo saltos de tamaño $2$, sumando $4 + 2 + 4 = 10$.
||end

# Límites

- $1 \leq s \leq n \leq 10^5$.
- $0 \leq A_i \leq 1,000$.
- $0 \leq t \leq N$.

# Subtareas

- **Subtarea 1 (9 puntos):**
  - $t = 0$.
- **Subtarea 2 (13 puntos):**
  - $t = N$.
  - $A_i = A_{i+1}$ para toda $1 \leq i < n$, es decir, todos los valores del arreglo son iguales.
- **Subtarea 3 (15 puntos):**
  - $1 \leq n \leq 100$.
  - $t = n$.
- **Subtarea 4 (19 puntos):**
  - $1 \leq n \leq 5,000$.
  - $t = n$.
- **Subtarea 5 (21 puntos):**
  - $t = n$.
- **Subtarea 6 (23 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![](chapulin.jpeg 'Charly, el Chapulín que brinca sin fin.')

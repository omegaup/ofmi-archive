Durante su estancia en los Países Bajos, las competidoras de la OFMI tuvieron la oportunidad de conocer a otro mexicano que está representando a México, el famoso piloto de carreras, Peco Chérez.

Para su sorpresa, resulta que Peco es un gran fan de la OFMI y se sabe de memoria el orden en que obtuvieron puntos todas las competidoras de la EGOI. Ahora, ellas quieren mostrar el mismo interés por la carrera de Peco.

Saben que el Gran Premio Holandés de la Fórmula 0 tiene $N$ coches numerados del $1$ al $N$. Los coches corren sobre una recta de longitud infinita. Cada coche empieza en una posición $X_i$ de la recta, que indica a cuántos kilómetros se encuentra el coche de la línea de salida, y avanza a $V_i$ kilómetros por hora.

La carrera puede durar mucho tiempo y las competidoras de la OFMI no pueden ver toda la carrera ya que tienen que participar en la EGOI, por lo que únicamente verán la transmisión de los momentos clave de la carrera; esto es, cada vez que un coche adelante a otro.

Ayuda a reportar los primeros $M$ momentos clave en el que un coche adelanta a otro, en el orden en que ocurrieron.

# Problema

Dado un número $N$ de coches, la posición inicial $X_i$ y la velocidad $V_i$ de cada coche, deberás mostrar los primeros $M$ momentos clave en el orden en que ocurrieron. En caso de que dos o más o momentos clave ocurran al mismo tiempo, deberás reportar primero el que ocurre en la posición de menor valor.

# Entrada

En la primera línea vendrán dos enteros $N$ y $M$ que representan la cantidad de coches y el número de momentos clave que deberás reportar.

En las siguientes $N$ líneas vendrán dos enteros $X_i$ y $V_i$ que representan la posición inicial y la velocidad del coche $i$, respectivamente.

# Salida

Deberás imprimir $M$ líneas, los primeros $M$ momentos clave en el orden que ocurrieron. Cada línea deberá contener dos enteros separados por espacio $i$ y $j$ que representan que el coche $i$ alcanzó al coche $j$. Si dos o más momentos clave ocurren al mismo tiempo, reporta primero el que ocurra en la posición de menor valor.

# Ejemplo

||examplefile
sub3.sample
||description
Hay $4$ coches en la carrera.

El coche $1$ empieza en el kilómetro $0$ y tiene velocidad de $2$ kilómetros por hora.

El coche $2$ empieza en el kilómetro $2$ y tiene velocidad de $1$ kilómetro por hora.

El coche $3$ empieza en el kilómetro $3$ y tiene velocidad de $8$ kilómetros por hora.

El coche $4$ empieza en el kilómetro $6$ y tiene velocidad de $3$ kilómetros por hora.

El primer momento clave ocurre cuando el coche $3$ alcanza al coche $4$.

El segundo momento clave ocurre cuando el coche $1$ alcanza al coche $2$.

||end

# Límites

- $2 \leq N \leq 10^5$.
- $1 \leq M \leq 10^4$.
- $0 \leq X_i \leq 10^9$. Todas las posiciones son distintas.
- $1 \leq V_i \leq 10^9$.
- Se te asegura que en ningún momento tres coches se encuentran en la misma posición.
- Se te asegura que no se te pedirán más momentos clave de los que hay.

# Subtareas

- **Subtarea 1 (12 puntos):**
  - $M = 1$.
- **Subtarea 2 (23 puntos):**
  - Todos los coches tienen la misma velocidad, excepto uno.
- **Subtarea 3 (25 puntos):**
  - $N \leq 1,000$.
- **Subtarea 4 (40 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![Peco](race.jpg 'Peco Chérez.')

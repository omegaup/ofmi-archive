Jessie y Tiro al Blanco se enteraron de que en los juegos Panamericanos existe la categoría de adiestramiento ecuestre y quieren participar.

Durante la competencia, tendrán que realizar una rutina con música ante los jueces, será como un baile. Cada rutina tiene una dificultad representada por un entero $k_i$.

El problema es que no son los únicos que desean participar y todos deben escoger una rutina diferente.

Los jueces tienen una lista de $N$ rutinas y de cada rutina se conoce su dificultad $k_i$. Cuando los equipos llegan al registro, siempre escogen la rutina con mayor dificultad posible. Sin embargo, Jessie y Tiro al Blanco quieren que sea un reto para ellos, por lo que solo escogerán una rutina con una dificultad mayor a $0$.

# Problema

Dadas las dificultades de las rutinas y la posición en la que Jessie y Tiro al Blanco llegaron al registro, deberás decirles a Jessie y Tiro al Blanco la dificultad de la rutina que escogerán o que solo quedan rutinas demasiado sencillas.

# Entrada

En la primera línea dos enteros $N$ y $M$, que representan el número de rutinas y la posición en la que Jessie y Tiro al Blanco llegaron al registro, respectivamente.

En la segunda línea $N$ enteros separados por espacio, que representan la dificultad $k_i$ de la $i$-ésima rutina.

# Salida

Deberás imprimir la dificultad de la rutina que Jessie y Tiro al Blanco escogerán, o la palabra “sencillo” **(en minúsculas)** si no quedan rutinas con dificultad mayor a $0$.

# Ejemplo

||examplefile
sample-sub1
||description
Jessie y Tiro al Blanco son los primeros en el registro, por lo que escogerán la rutina con dificultad $8$, que es la rutina de mayor dificultad.
||examplefile
sample2-sub5
||description
Jessie y Tiro al Blanco son el tercer equipo en el registro.
El primer equipo escogerá la rutina con dificultad $7$.
El segundo equipo escogerá la rutina con dificultad $5$.
Por lo tanto, Jessie y Tiro al Blanco escogerán la rutina con dificultad $2$, que es, entre las rutinas que aún quedan disponibles, la de mayor dificultad.
||examplefile
sample3-sub4
||description
Jessie y Tiro al Blanco son el cuarto equipo en el registro.
Los equipos anteriores ya habrán escogido las rutinas con dificultad $8$, $5$ y $0$, en ese orden.
La rutina más difícil que queda cuando Jessie y Tiro al Blanco llegan al registro es la de dificultad $-1$, pero ellos no eligen rutinas de dificultad menor o igual a 0.
||end

# Límites

- $1 \leq N \leq 3*10^5$
- $1 \leq M \leq N$
- $-10^9 \leq k_i \leq 10^9$, para $1\leq i \leq N$

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $M = 1$ (Jessie y Tiro al Blanco siempre serán el primer equipo en el registro)
- **Subtarea 2 (20 puntos):**
  - $1 \leq N \leq 1000$
- **Subtarea 3 (10 puntos):**
  - $0 \leq k_i \leq 1$ (La dificultad de las rutinas es 0 o 1), para $1\leq i \leq N$
- **Subtarea 4 (20 puntos):**
  - $-100 \leq k_i \leq 100$ (La dificultad de las rutinas está entre -100 y 100), para $1\leq i \leq N$
- **Subtarea 5 (40 puntos):**
  - Sin restricciones adicionales.

Las casos de prueba de las subtareas no estarán agrupados. Sin embargo, los casos estarán agrupados por pares: uno que sí tenga solución con otro que no; por lo que si siempre imprimes 'sencillo' no obtendrás puntos.

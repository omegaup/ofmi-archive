Para llegar a los Juegos Panamericanos en Santiago 2023 los personajes de Disney tendrán que tomar el tren y como quieren llegar a tiempo te han pedido que analices los tiempos de los trenes para que les puedas contestar unas preguntas que tienen.

La línea de tren que tomarán cuenta con $N+1$ estaciones. Entre cada dos estaciones consecutivas existe una conexión. En total existen $N$ conexiones dónde la $i$-ésima conexión conecta la estación $i$ con la estación $i+1$. Los trenes se tardan $t_i$ minutos en atravesar la $i$-ésima conexión.

El recorrido de un tren consiste en salir de la estación sur $1$, ir estación por estación hasta la estación norte $N+1$, y después regresar, una por una, a la estación $1$. Es decir, el recorrido pasa por las estaciones $1$ &rarr; $2$ &rarr; $3$ &rarr; ... &rarr; $N-1$ &rarr; $N$ &rarr; $N+1$ &rarr; $N$ &rarr; $N-1$ &rarr; ... &rarr; $3$ &rarr; $2$ &rarr; $1$. Cada estación, excepto por la estación $N+1$, tiene 2 lados: el lado donde se puede tomar el tren que va hacia el norte, o el lado donde se puede tomar el tren que va hacia el sur.

Se asegura que un tren sale cada $k$ minutos de la estación $1$.

Los personajes de Disney te van a hacer $Q$ consultas que podrán ser de 2 tipos:

- Tipo `a`: Llegas a la estación $e$ en alguno de sus lados, y escuchas a alguien decir que el último tren de ese lado pasó hace $d$ minutos. ¿Cuánto tiempo falta para que pase el siguiente tren de ese mismo lado?
- Tipo `b`: Llegas a la estación $e$ en alguno de sus lados, y después de $d$ minutos ves pasar un tren del otro lado. ¿cuánto tiempo tienes que esperar en total para que llegue el tren de tu lado?

# Problema

Dados $N$, el número de conexiones entre las estaciones de tren; $k$, la periodicidad con que los trenes salen de la estación $1$; y los tiempos $t_i$ que le toma a un tren atravesar la $i$-ésima conexión, deberás responder a $Q$ consultas de alguno de los dos tipos antes descritos.

# Entrada

En la primera línea dos enteros separados por un espacio, $N$ y $k$, que representan el número de conexiones y cada cuántos minutos sale un tren de la estación $1$, respectivamente.

En la segunda línea vendrán $N$ enteros $t_i$ separados por espacio y cada uno representa los minutos que le toma a un tren atravesar la conexión entre la estación $i$ y la estación $i+1$.

En la tercera línea vendrá el entero $Q$, el número de consultas.

Cada una de las siguientes $Q$ líneas describe una consulta en el siguiente formato:

- `a` $e_i$ $l$ $d_i$: Indicando que es una consulta de tipo `a`, $e_i$ es la estación a la que llegas, $l$ el lado en el que llegas representado con un único caracter, `N` es norte y `S` es sur, y $d_i$ indica hace cuántos minutos pasó el último tren del lado $l$.
- `b` $e_i$ $l$ $d_i$: Indicando que es una consulta de tipo `b`, $e_i$ es la estación a la que llegas, $l$ el lado en el que llegas representado con un único caracter, `N` es norte y `S` es sur, y $d_i$ indica cuántos minutos tuviste que esperar para ver pasar un tren del lado opuesto a $l$.

# Salida

Deberás imprimir $Q$ líneas, cada una con un entero indicando el tiempo de espera para cada consulta.

# Ejemplo

||examplefile
sub2.sample
||description
Hay $6$ estaciones y los trenes salen de la estación $1$ cada $7$ minutos.

Para la consulta $1$, llegas a la estación $3$ del lado norte. El último tren del lado norte pasó hace $2$ minutos. El siguiente tren del lado norte pasará en $5$ minutos.

Para la consulta $2$, llegas a la estación $3$ de lado norte. Después de $1$ minuto ves pasar un tren del lado sur. En total tendrás que esperar $6$ minutos para que llegue el siguiente tren del lado norte.

Para la consulta $3$, llegas a la estación $3$ del lado sur. Después de $1$ minuto ves pasar un tren del lado norte. En total tendrás que esperar $3$ minutos para que llegue el siguiente tren del lado sur.

Para la consulta $4$, llegas a la estación $5$ del lado sur. El último tren del lado sur pasó hace $6$ minutos. El siguiente tren del lado sur pasará en $1$ minuto.

Para la consulta $5$, llegas a la estación $2$ del lado norte. Después de $3$ minutos ves pasar un tren del lado sur. En total tendrás que esperar $5$ minutos para que llegue el siguiente tren del lado norte.

||end

# Límites

- $1 \leq N \leq 2*10^5$
- $1 \leq k \leq 10^9$
- $1 \leq Q \leq 10^5$
- $1 \leq t_i \leq 10^9$, para $1\leq i \leq N$.
- $1 \leq e_i \leq N$, para $1\leq i \leq Q$.
- $0 \leq d_i \leq k$. Además, si la operación es de tipo `a`, tendremos $0 < d_i$, para $1\leq i \leq Q$.

# Subtareas

Definamos a $T$ como la suma del tiempo que toma atravesar todas las conexiones. Es decir, $T = t_1 + t_2 + t_3 + ... + t_N$.

- **Subtarea 1 (10 puntos):**
  - Solo habrá consultas de tipo `a`.
- **Subtarea 2 (15 puntos):**
  - $N, k, Q \leq 100$
  - $T \leq 1000$
- **Subtarea 3 (18 puntos):**
  - $N \leq 100$
  - $k, Q \leq 1000$
  - $T \leq 10^6$
  - $T / k \leq 1000$
- **Subtarea 4 (17 puntos):**
  - $k, Q \leq 1000$
  - $T \leq 10^6$
  - $T / k \leq 1000$
- **Subtarea 5 (40 puntos):**
  - Sin restricciones adicionales

Las subtareas están agrupadas.

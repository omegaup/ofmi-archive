En los últimos años se ha observado una rápida propagación de la Enfermedad del Buey Extremadamente Verde (EGOI por sus siglas en inglés), esta enfermedad hace a las vacas peligrosas para los excursionistas. Después de varios incidentes se decidió que necesitamos separar las áreas donde las vacas pastan de la parte de los Alpes donde la gente quiere ir a excursionar.

Te dan un mapa de los Alpes. En el mapa hay $n$ áreas. Cada una puede estar poblada por vacas, ser un área de excursión o una área sin usar. Algunos pares de áreas están conectados por senderos bidireccionales. Todos los senderos tienen una longitud no negativa (en términos de teoría de grafos, el mapa es un grafo no dirigido con aristas con peso).

Puedes construir muros en algunas de las áreas. Una vez que construyes un muro en un área, ésta será inaccesible para los excursionistas y para las vacas, esto quiere decir que no podrán caminar a través de esa área.

Tu tarea es escoger el conjunto de áreas donde se construirán los muros. Este conjunto de áreas debe satisfacer las siguientes condiciones:

- Debe consistir únicamente de áreas sin usar.
- Debe separar áreas pobladas por vacas de áreas de excursión. Esto significa que una vaca ya no debe poder caminar por senderos de un área poblada por vacas a un área de excursión (sin atravesar un área que tenga un muro).
- **No** debe separar ningún área de excursión de otras áreas de excursión. Esto significa que un excursionista debe poder caminar por senderos de cualquier área de excursión a cualquier otra área de excursión (sin atravesar un área que tenga un muro).

Si hay más de una forma de alcanzar el objetivo anterior, nos importará la facilidad de mantenimiento de los muros. Los muros obtendrán mantenimiento por equipos
especiales. Hay un equipo especial basado en cada área de excursión.

Para cualquier área definimos su _lejanía_ como la longitud mínima de un camino de senderos entre y algún área de excursión (La longitud del camino es la suma de las longitudes de sus senderos. Nota que estos caminos **pueden** atravesar muros y áreas pobladas por vacas -- el equipo de mantenimiento de muros tiene todas las habilidades y equipo necesario para lograrlo).

La _lejanía_ de un conjunto de áreas es entonces la lejanía **máxima** de cualquier área del conjunto.

Entre todos los conjuntos de áreas con muros que tengan las propiedades requeridas, encuentra el área con la **mínima lejanía posible**. Si hay muchos conjuntos que cumplan, puedes regresar cualquiera de ellos.

Nota que el número de áreas no importa. Particularmente **no** es necesario usar la mínima cantidad de muros.

# Entrada

La primera línea de entrada tiene dos enteros separados por un espacio $n$ y $m$: el número de áreas y senderos, respectivamente. Las áreas están numeradas de $1$ a $n$.

La segunda línea tiene $n$ enteros separados por un espacio $t_1,...,t_n$, donde $t_i$ es $-1$ si la $i$-ésima área es un área poblada por vacas, $0$ si no está usada y $1$ si es un área de excursión.

Las siguientes $m$ líneas describen los senderos. La $j$-ésima línea contiene tres enteros separados por un espacio $a_j$, $b_j$ y $l_j$, indicando que existe un sendero entre las áreas $a_j$ y $b_j$ de longitud $l_j$.

Se garantiza que:

- existe a lo más un sendero entre dos áreas,
- es posible caminar entre dos áreas usando cero o más senderos,
- existe al menos un área poblada por vacas,
- existe al menos un área de excursión.

# Salida

Si es imposible construir muros satisfaciendo los requerimientos, imprime ​$-1$​.

De lo contrario, la primera línea de la salida debe tener un entero $k$: el número de muros que quieres construir. La segunda línea debe tener $k$ enteros: los números de las áreas en donde quieres construir los muros (Estos números deben ser números distintos entre $1$ y $n$ inclusive. No tienen que estar en ningún orden particular).

La salida será aceptada si es un conjunto válido de muros con la mínima lejanía.

# Ejemplo

||examplefile
sample
||description
En el primer ejemplo, la mínima lejanía posible es $2$, se logra poniendo muros en las áreas 4, 5 y 6. Nota que no podrías poner muros en las áreas 4, 2 y 6, aunque esto tendría una mínima lejanía de $1$, porque sería imposible viajar entre el área de excursión 1 y el área de excursión 3 sin atravesar un muro.
||examplefile
sample2
||description
En el segundo ejemplo, la lejanía del área 2 es $1000$, la lejanía del área 3 es $30$, ya que se puede alcanzar por el camino 1–5–4–3. (Recuerda que los equipos de mantenimiento pueden atravesar muros y áreas pobladas por vacas). Entonces debemos poner muros en las áreas 5 y 3 (no en la 2) y la mínima lejanía posible será $30$.
||examplefile
sample3
||end

En todas las figuras, el azul se usa para áreas de excursión, el rojo para las áreas pobladas por vacas y el naranja para muros.

![](sample.png)

<figcaption align = "center"><i>Ejemplo 1</i></figcaption>

![](sample2.png)

<figcaption align = "center"><i>Ejemplo 2</i></figcaption>

# Límites

- $2 \leq n \leq 3 · 10^5$
- $n - 1 \leq m \leq 3 · 10^5$
- $1 \leq a_j \leq b_j \leq n$
- $0 \leq l_j \leq 10^9$

# Subtareas

- Subtarea 1 (7 puntos): $n \leq 10$
- Subtarea 2 (22 puntos): todas las longitudes $l_j = 0$.
- Subtarea 3 (16 puntos): hay exactamente un área de excursión.
- Subtarea 4 (11 puntos): hay exactamente $n - 1$ senderos (en términos de teoría de grafos, el grafo es un árbol).
- Subtarea 5 (8 puntos): $n, m \leq 2000$ y todas las longitudes $l_j = 1$.
- Subtarea 6 (36 puntos): no hay consideraciones adicionales.

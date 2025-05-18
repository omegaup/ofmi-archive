Michititlán, ciudad de los gatos miautemáticos, es un lugar cosmopolita donde nacen algunas de las ideas más prrrofundas sobre la filosofía y las matemáticas felinas.

A estos gatos les gustan los números enteros, así que Michititlán tiene una forma de cuadrícula con calles paralelas al eje $x$ y otras paralelas al eje $y$. Para cada entero $Z$, hay una calle vertical en $x = Z$ y una horizontal en $y = Z$. Para compartir direcciones, los gatos habitantes de Michititlán usan pares de números enteros, que representan intersecciones entre una calle vertical y una horizontal.

Cada día una humana, llamada Mitzi, viene de un poblado humano cercano a hacer una repartición de platillos personalizados entre los habitantes de Michititlán. Como los platillos son personalizados, Mitzi sabe la importancia de entregar los platillos en el orden correcto.

Para saber dicho orden, Mitzi tiene una lista de coordenadas que representan las casas de los habitantes, escrita en el orden en que Mitzi tiene que hacer las entregas. Para facilitarse la vida, los michis han creado un sistema de repartición que le permite a Mitzi darle su platillo al $i$-ésimo michi de la lista, que vive en las coordenadas $(X_i, Y_i)$, simplemente con estar en la misma calle vertical (cuya coordenada en $x$ sea $X_i$) o en la misma calle horizontal (cuya coordenada $y$ sea $Y_i$).

Mitzi comienza su jornada siempre en la coordenada $(0, 0)$, y después sigue alguna ruta que le permita entregar los platillos personalizados a todos los habitantes de Michititlán en el orden correcto. Una vez que ha entregado todos los platillos, Mitzi se detiene a descansar.

Como puedes imaginar, Mitzi prefiere recorrer un camino que le permita hacer su trabajo recorriendo la menor distancia total posible, así que le ha pedido a la Organización Felina de Michis Inteligentes (OFMI) que le digan cuál es dicha distancia.

# Problema

Dado $n$ y una lista con las coordenadas de las casas de los habitantes de Michititlán, en el orden en que deben entregarse los platillos, encuentra la distancia mínima que Mitzi necesita recorrer para completar las entregas.

# Entrada

En la primera línea un entero $n$, representando el número de platillos personalizados que se tienen que repartir.

Después vendrán $n$ líneas. En la $i$-ésima línea vendrán dos enteros $X_i$ y $Y_i$, representando la ubicación de la casa del $i$-ésimo habitante de Michititlán. Estas coordenadas están en el orden en el que se tienen que entregar sus respectivos platillos personalizados.

# Salida

Un solo entero representando la mínima distancia total que Mitzi tiene que recorrer para entregar todos los platillos personalizados a los habitantes de Michititlán.

# Ejemplo

||examplefile
sub2.sample
||description
Mitzi comienza su jornada en las coordenadas $(0, 0)$. De ahí hace lo siguiente:

- Va a la coordenada $(8, 0)$, recorriendo una distancia de $8$ en el eje $x$, para alimentar al michi en las coordenadas $(8, 3)$.
- Va a la coordenada $(7, 0)$, recorriendo una distancia de $1$ en el eje $x$, para alimentar al michi en las coordenadas $(7, -7)$.
- Va a la coordenada $(7, 1)$, recorriendo una distancia de $1$ en el eje $y$, para alimentar al michi en las coordenadas $(8, 1)$.
- Se queda en la coordenada $(7, 1)$, por lo que no recorre ninguna distancia, ya que desde ahí puede alimentar al michi en las coordenadas $(-2, 1)$.
- Va a la coordenada $(6, 1)$, recorriendo una distancia de $1$ en el eje $x$, para alimentar al michi en las coordenadas $(6, -5)$.

Con esto, Mitzi termina de alimentar a todos los habitantes de Michititlán habiendo recorrido una distancia total de $8 + 1 + 1 + 1 = 11$.
||examplefile
sub1.sample
||description
De nuevo, Mitzi comienza en las coordenadas $(0, 0)$ y hace el siguiente recorrido:

- Va a la coordenada $(0, 2)$, recorriendo una distancia de $2$ en el eje $y$, para alimentar al michi en las coordenadas $(15, 2)$.
- Va a la coordenada $(0, -3)$, recorriendo una distancia de $5$ en el eje $y$, para alimentar al michi en las coordenadas $(15, -3)$.
- Va a la coordenada $(0, 2)$, recorriendo una distancia de $5$ en el eje $y$, para alimentar de nuevo al michi en las coordenadas $(15, 2)$.

Mitzi completa sus entregas recorriendo una distancia total de $2 + 5 + 5 = 12$.
||end

# Límites

- $1 \leq n \leq 2 \times 10^4$
- $−1,000 \leq X_i, Y_i \leq 1,000$

# Subtareas

- **Subtarea 1 (15 puntos):**
  - $X_i = X_j$ para toda $1 \leq i < j \leq n$.
- **Subtarea 2 (20 puntos):**
  - $1 \leq n \leq 20$.
- **Subtarea 3 (25 puntos):**
  - $1 \leq n \leq 200$.
- **Subtarea 4 (25 puntos):**
  - $1 \leq n \leq 2,000$.
- **Subtarea 5 (15 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

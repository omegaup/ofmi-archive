Tapia decidió ir a una feria en Cholula, donde está la pirámide con la base más grande del mundo. En esta feria hay una ruleta de la suerte conformada por $n$ segmentos, marcados por `P`'s y `S`'s, donde:

- `P` representa un _premio_.
- `S` representa un _sigue intentando_.

![Representación de la ruleta](ruleta.png)

Podemos numerar los segmentos de la ruleta del $1$ al $n$ en sentido horario, comenzando desde algún segmento arbitrario. De tal manera, podemos representar la ruleta como una cadena de caracteres $R_1, R_2, ... , R_n$, donde el carácter $R_n$ es seguido por el $R_1$, formando un círculo.

Ixchel, la dueña de la ruleta, permite a Tapia girar la ruleta; una vez que se detiene, Tapia puede elegir moverla en sentido horario o antihorario, recolectando los segmentos en esa dirección uno por uno. Cada segmento puede recolectarse una sola vez y se acumula a su cuenta de _premios_ y _sigue intentandos_.

Sin embargo, Ixchel le advirtió a Tapia que si acumula $k$ _sigue intentandos_, perderá el juego y todos los _premios_ que había acumulado.

Como Tapia no se detendrá porque cree que obtendrá todos los _premios_, te pide tu ayuda para saber cuál sería la mayor cantidad de _premios_ que podría obtener si tiene la mejor de las suertes al girar la ruleta.

Se dice que Tapia tiene la mejor de las suertes si la ruleta se detiene en una posición que, eligiendo sabiamente hacia dónde moverla y cuándo parar, le permita obtener la mayor cantidad de _premios_ posible.

# Problema

Dada una cadena $R$ de $n$ caracteres $R_1, R_2, ... , R_n$ que representan el estado del segmento en la ruleta y $k$, la cantidad límite de _sigue intentandos_, debes determinar cuál sería la mayor cantidad de _premios_ que Tapia podría obtener si tiene la mejor de las suertes al girar la ruleta y elige sabiamente cuándo retirarse del juego.

# Entrada

La primera línea contiene dos enteros, $n$ y $k$, separados por un espacio, representando la cantidad de segmentos y la cantidad de _sigue intentando_ con las que Tapia pierde el juego.

En la segunda línea se incluye una cadena de $n$ caracteres, donde el $i$-ésimo caracter representa el valor $R_i$ del $i$-ésimo segmento de la ruleta. Los segmentos de la ruleta $R_i$ solo contendrán caracteres `'P'` y `'S'`.

# Salida

Un solo entero representando la mayor cantidad de _premios_ que Tapia podría obtener si tiene la mejor de las suertes al girar la ruleta y elige sabiamente cuándo retirarse del juego.

# Ejemplo

||examplefile
sub1.sample1
||description
En la mejor de las suertes, si la ruleta cae en la posición $8$ y Tapia decide moverla en sentido horario hacia la derecha hasta la posición $2$ obtendría $3$ _premios_ y $1$ _sigue intentando_. Así mismo, si hubiera decidido moverla en sentido antihorario hacia la izquierda hasta la posición $5$ obtendría el mismo resultado.

En cualquier de los dos casos, si decide moverse más, perdería porque acumularía $2$ _sigue intentandos_.
||examplefile
sub1.sample2
||description
En la mejor de las suertes, si la ruleta cae en la posición $4$ y Tapia decide moverla en sentido antihorario hacia la izquierda hasta la posición $9$, obtendría $6$ _premios_ y $2$ _sigue intentandos_.

Si decide moverse más, perdería porque acumularía $3$ _sigue intentandos_.
||end

# Límites

- $1 \leq k \leq n \leq 10^6$.

# Subtareas

- **Subtarea 1 (21 puntos):**
  - $1 \leq n \leq 1,000$.
- **Subtarea 2 (13 puntos):**
  - $k = 1$.
- **Subtarea 3 (27 puntos):**
  - $k = 2$.
- **Subtarea 4 (39 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

[1]: data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABAQMAAAAl21bKAAAAA1BMVEUAAACnej3aAAAAAXRSTlMAQObYZgAAAApJREFUCNdjYAAAAAIAAeIhvDMAAAAASUVORK5CYII=

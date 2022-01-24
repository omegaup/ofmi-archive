# Peones - Solución

Para analizar la solución del problema peones, vamos a tomar en cuenta unas cuantas observaciones que serán útiles para entender mejor las formas en las que están condicionadas los movimientos de los peones. Después, vamos a tomar en cuenta unos cuantos casos en las que la configuración inicial del tablero, provoca que el peón blanco **NO** pueda llegar a la casilla de destino. Una vez comprendido esto, será más fácil entender la lógica del cómo identificar cuando se puede y cuando no, alcanzar la posición final. Después de ello se explicará cómo obtener la menor cantidad de movimientos para alcanzar dicha posición (en caso de ser posible).

## Observaciones importantes

Recordemos los movimientos válidos que tenemos para los peones del tablero:

- **Movimiento de tipo 1:** Si la casilla de enfrente está libre (no hay ningún peón), se puede mover el peón únicamente una posición hacia delante.
- **Movimiento de tipo 2:** Una posición en diagonal (hacia delante, ya sea izquierda o derecha) cuando pueden capturar a un peón enemigo. Cuando esto sucede, el peón enemigo se descarta del tablero.

Dado el movimiento de los peones, nos centraremos brevemente en cómo estos 2 tipos de movimientos, le ayudarían al peón blanco a alcanzar la posición de destino:

1. Lo primero a notar es que sin importar el movimiento que realice el peón blanco, **este siempre se moverá una fila hacia adelante**. La diferencia está en que si el peón blanco realiza un movimiento de tipo 1 (moverse una casilla hacia enfrente en caso de que no haya un peón negro bloqueando el paso), entonces sólo se moverá una fila hacia adelante pero se mantendrá en la misma columna. Si el peón blanco realiza un movimiento de tipo 2 (moverse en diagonal para capturar un peón negro, en caso de ser posible), entonces se moverá una fila hacia adelante y además cambiará de columna, ya sea a la que tiene inmediatamente a la izquierda o a la que tiene inmediatamente a la derecha. Aunado a esto, podemos concluir que el peón blanco **jamás se podrá mover una o más filas hacia atrás** ya que no hay ningún movimiento que le permita hacer esto.

2. La segunda observación es que para cambiar de columna, el peón blanco **necesita capturar un peón negro que esté en esa columna**. Dado que los peones negros no pueden capturarse entre ellos por ser del mismo bando, **un peón negro sólo podrá moverse dentro de su columna inicial** hacia enfrente (recuerda que los peones negros se mueven en dirección opuesta a la dirección a la que se está moviendo el peón blanco). El único caso en donde un peón negro podría cambiar de columna, sería si captura al peón blanco, lo cual evitaría que el peón blanco llegara a su posición final.

3. Por último, dado que hay exactamente un peón negro en cada columna y no más, el peón blanco **sólo podrá cambiarse a cada columna una vez**, ya que si el peón blanco quisiera llegar a una columna mediante la captura de un peón negro, cambiarse a otra columna, y volver a la columna en la que estaba, esta columna ya no tendría un peón negro que capturar, por lo que el peón blanco no podría regresar a la columna anterior. Esto aplica para todas las columnas excepto para la **columna inicial**, para la cual, el peón blanco podría realizar un cambio de columna y luego utilizar el peón negro de la columna inicial para regresar.

La siguiente imagen ilustra esta última observación más claramente (la casilla azul es la posición final deseada para el peón blanco):

![](imgs/observacion_columna_inicial.png)

## Casos en los que el peón blanco NO puede alcanzar su posición final

- **Si aun considerando que el peón blanco realice puros movimientos de tipo 2 (en diagonal), no es posible llegar a la columna de destino antes de que la posición final quede atrás del peón blanco:**
  En el siguiente caso, podemos observar que sin importar la configuración inicial de los peones negros, no será posible llegar a la posición final. La idea detrás de **sólo considerar movimientos en diagonal**, es porque esta sería la forma más rápida (en la menor cantidad de movimientos para el peón blanco) de llegar a su columna destino, y si a pesar de sólo realizar movimientos en diagonal, no es posible llegar a la posición final deseada, entonces tampoco será posible si intentamos llegar con una combinación de movimientos de tipo 1 (hacia enfrente) y 2 (en diagonal), esto por la observación 1.

![](imgs/imposible_1.png)

- **Si antes de llegar a la columna destino, el peón negro de la siguiente columna está por detrás de la casilla más cercana para ser capturado por el peón blanco:**
  En esta situación, la casilla de destino sí es alcanzable por el peón blanco en el caso de que los peones negros pudieran ser acomodados de manera que el peón blanco pueda capturar todos los peones negros que yacen entre la columna inicial y la columna destino. Sin embargo, esto es imposible ya que el peón negro de la columna **e** se encuentra muy adelantado, haciendo que el peón blanco no pueda llegar a capturarlo. Esta idea aplica para todos los peones negros que se encuentran entre la columna inicial y la columna destino. Si incluso con la forma más rápida (en la menor cantidad de movimientos para el peón blanco) de llegar a una columna, ya no es posible capturar el peón negro de la siguiente columna porque este se encuentre en una posición adelantada, entonces será imposible llegar a la posición final deseada, pues el peón blanco se quedará atorado en una columna intermedia.

![](imgs/imposible_2.png)

## Solución greedy

Tomando en cuenta los 2 casos en los que el peón blanco no podría alcanzar la casilla de destino, se pueden incorporar estas 2 validaciones previas a la solución greedy.

Retomando el segundo caso con el cual no se podría llegar a la posición final deseada (los peones negros se encuentran en posiciones adelantadas), se puede observar que en este sentido, cada uno de los peones negros tiene una **fila máxima** en la que pueden ser capturados, ya que de lo contrario, sería imposible llegar a la posición final deseada.

Tomemos en cuenta el siguiente caso de entrada:

![](imgs/input_1.png)

Por el momento sólo vamos a enfocarnos en el peón negro de la columna destino para el peón blanco, en este caso, el peón negro de la columna **g**. Si nos damos cuenta, la casilla destino está en la fila número 7, mientras que el peón negro de esa columna está en la fila 8. Ahora, este peón es uno de los peones que debe ser capturado por el peón blanco, de lo contrario el peón blanco no sería capaz de llegar a la columna destino. La pregunta es, ¿en qué filas de la columna **g** el peón negro podría ser capturado por el peón blanco, y que a su vez el peón blanco todavía pueda llegar a la casilla de destino después de la captura? Sin importar lo que se vaya a hacer con el resto de los peones negros, al menos sabemos que el peón negro de la columna **g** tiene que estar en cualquiera de estas filas al momento de ser capturado (señaladas en verde):

![](imgs/input_2.png)

En este momento, no importa si es que el peón blanco sería capaz de capturar al peón negro de **g** en cualquiera de esas casillas, lo único importante es que **tiene** que ser capturado en alguna de ellas, de lo contrario, llegar a la casilla destino sería imposible. En este caso, la única fila en donde el peón negro de **g** no puede ser capturado sin impedir que el peón blanco llegue a la casilla destino, es en la fila 8, la fila en donde se encuentra inicialmente. Por ello, sabemos que **cuando menos** el peón negro de **g** tiene que avanzar una fila hacia adelante, y además sabemos que este movimiento, al ser forzado para que exista una solución, debe ser parte de la solución óptima que minimiza el número total de movimientos realizados por los peones.

![](imgs/input_3.png)

A la fila con índice más grande (numeradas de abajo hacia arriba) de entre todas las filas en las que puede estar un peón negro al momento de ser capturado por el peón blanco, y que aún así el peón blanco pueda llegar a la posición final deseada, es a lo que llamaremos **fila máxima de captura** para cada peón negro entre las columnas de inicio y destino. Visto de otra manera, el peón negro no puede estar más atrás de su fila máxima de captura, así que si de manera inicial, se encuentra más atrás que dicha fila, se tiene que mover hacia enfrente tantas veces como sea necesario para alcanzar la fila máxima.

Así pues, para el peón negro de **g**, su fila máxima de captura sería la fila 7, por lo que podemos moverlo un paso hacia enfrente, confiando en que este movimiento es **forzado** para que exista una solución y por tanto, debe formar parte de la solución óptima.

Ahora, ¿qué pasaría con el peón negro de **f**? ¿cuál sería su **fila máxima de captura**? Bueno, para esto hay que analizar cuál es la fila máxima a la que puede llegar el peón blanco, al momento de pasar de la columna **e** a la columna **f** y aún así ser capaz de capturar al peón de **g**. Con esto en mente, podemos darnos cuenta que el peón de **f** puede ser capturado en cualquiera de estas filas (señaladas en verde), y el peón blanco aún así sería capaz de capturar al peón de **g** en el futuro.

![](imgs/input_4.png)

Esto es así, porque en el caso de que el peón blanco capturara al peón negro de **f** en las filas 7 u 8, el peón de **g** ya estaría demasiado adelantado para ser capturado por el peón blanco, imposibilitando así que el peón blanco pueda llegar a la posición final deseada. Por ende, de entre todas las filas en las que el peón negro de **f** puede ser capturado, la **fila máxima de captura** sería la 6. En este caso, como la fila inicial del peón de **f** es la 8, entonces tenemos que moverlo 2 pasos hacia enfrente para poder asegurarnos de que exista una solución.

![](imgs/input_5.png)

¿Y qué pasa con el peón de la columna **e**? ¿cuál es su **fila máxima de captura**? En este punto, es fácil darnos cuenta que el mismo criterio va a aplicar para todos los peones negros que se encuentren entre la columna inicial y la columna destino. Ya que en este caso, el peón de **e** tiene que colocarse en una fila tal, que cuando el péon blanco lo capture, aún así pueda capturar al peón de **f**. Así pues, al propagar este resultado desde el peón de la columna destino hasta el peón de la columna inicial, podemos darnos cuenta que las **filas máximas de captura** de los peones negros seguirán una secuencia **creciente** (como en forma de escalera).

Así luciría el tablero después de hacer el acomodo de los peones negros a sus respectivas filas máximas de captura.

![](imgs/input_6.png)

En el caso en el que un peón negro ya se encuentre dentro de su **fila máxima de captura**, no se moverá de lugar, y así tambien con los peones negros que se encuentren **por delante** de su **fila máxima de captura**, ya que al tener una posición adelantada, lo que nos conviene es mantenerlos lo más atrás posible para reducir el número de pasos hacia adelante que darán los peones negros de columnas subsecuentes para ser acomodados de manera creciente. Ejemplo:

![](imgs/input_7.png)

Les compartimos varias implementaciones de esta solución:

<details><summary>Primera solución greedy</summary>

{{solution.cpp}}

</details>

<details><summary>Segunda solución greedy</summary>

{{solutionC.cpp}}

</details>

### Caso en el que es imposible acomodoar a los peones negros

Ahora, ¿qué pasa cuando al estar procesando la **fila máxima de captura** de algún peón negro, esta tiene un valor de 1 o incluso se sale del tablero? En este caso, no existe una solución posible en la que el peón blanco pueda capturar los peones negros que se encuentran entre las columnas inicial y de destino y aún así ser capaz de llegar a la posición final deseada, por lo que en el momento que esto suceda, se puede detener el algoritmo de reacomodo de peones negros y devolver **-1**. Como en el caso siguiente:

![](imgs/imposible_3.png)

### Mover el Peón Blanco

Una vez acomodados los peones negros, el algoritmo para definir la cantidad de movimientos que se agregarán a la solución óptima, por parte del peón blanco, es sencillo:

Mientras no hayas llegado a la posición final y sigas teniendo movimientos válidos:

- Si puedas capturar, realiza un movimiento de tipo 2.
- Si no puedes capturar, pero puedes avanzar hacia enfrente, realiza un movimiento de tipo 1.

Si al final de la secuencia de movimientos, no estás en la posición final, entonces la configuración inicial del tablero no tenía una solución posible. Si estás en la posición final deseada, la respuesta será la suma de los movimientos realizados para acomodar los peones negros en sus filas máximas de captura más los movimientos realizados por el peón blanco.

### Excepciones

Hay 2 casos que deben ser tratados con cuidado para obtener todos los puntos:

1. **La casilla de destino se encuentra en la misma columna que la casilla de inicio:**
   En este caso, se tiene que realizar un movimiento parecido al descrito en la observación 3. Como el peón blanco inicia en la misma columna que la posición final deseada, este tiene que pasarse a la columna **b** capturando el peón negro de dicha columna y tiene que regresar a la columna **a** capturando el peón negro de la columna inicial. Esto en caso de que el peón negro de la columna **a** impida el paso directo del peón blanco a la casilla de destino. En este caso, basta con adelantar el peón negro de **b** a una fila más adelante que el peón negro de **a** y mover el peón blanco de acuerdo a lo descrito en la sección anterior.

2. **El peón de la columna a no permite al peón blanco capturar el peón negro de b**:

Como en el siguiente ejemplo:

![](imgs/excepcion_2.png)

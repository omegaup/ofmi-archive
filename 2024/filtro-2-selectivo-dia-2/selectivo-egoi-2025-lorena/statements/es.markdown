Lorena se encontró con Tapia en una feria en Cholula, donde está la pirámide con la base más grande del mundo. Tapia jugaba en una ruleta con $n$ segmentos, donde el segmento $i$ tiene escrito un entero positivo $A_i$.

Los segmentos están numerados del $0$ al $n - 1$ en sentido horario, comenzando desde el que apunta la flecha superior de la ruleta. Así, la ruleta puede representarse con una secuencia circular de enteros $A_0, A_1, \dots, A_{n - 1}$, donde $A_{n - 1}$ está seguido por $A_0$.

![Ejemplo de cómo se numera la ruleta](ruleta.png)

Lorena no alcanzó a ver los números, pero Tapia le contó que los enteros estaban **ordenados estrictamente de forma creciente**, es decir, para todo $1 \leq i < n$ se cumple $A_{i - 1} < A_i$.

Ixchel, la dueña de la ruleta, les propuso un juego: vendará los ojos de Lorena y permitirá que Tapia elija un entero positivo $x$, que puede o no estar en la ruleta. Tapia le dice ese número en secreto a Ixchel. Luego, Ixchel gira la ruleta, de modo que el segmento $0$ (al que apunta la flecha) podría no ser el mismo de antes.

Ixchel reta a nuestres amigues: _"Si Lorena logra decir en qué segmento está el número que Tapia eligió, o si responde correctamente que **no** está en la ruleta, ¡ganarán una cajita misteriosa!"_

![Ilustración de Lorena y la ruleta](lorena-y-la-ruleta.png)

Para lograrlo, Lorena puede preguntarle a Tapia qué número está en cualquier segmento del $0$ al $n - 1$, siempre considerando la nueva orientación tras el giro.

Tapia puede responder, pero Ixchel les pone un límite de preguntas. Si lo exceden, no ganarán la cajita misteriosa. Como a ti te gustan mucho de esas, decides ayudar a Lorena a encontrar el número $x$.

# Problema

Este problema es interactivo. Al igual que Lorena, tú no conocerás los números que hay en los segmentos. Dados $x$ y $n$, tu tarea es ayudar a Lorena a encontrar en qué segmento se encuentra $x$. Para saber qué número está escrito en algún segmento, puedes llamar a la función `pregunta`.

# Implementación

Deberás implementar la función `encuentra(x, n)`, que recibe el entero $x$ que Lorena tiene que encontrar y el número de segmentos en la ruleta $n$. Tu función debe regresar en qué segmento (indexado desde $0$) se encuentra $x$. Esta función puede llamar a `pregunta(posicion)`.

## Tu función `encuentra`

`int encuentra(int x, int n)`

### Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los siguientes parámetros:

### Parámetros

- `x`: el entero que está buscando Lorena en la ruleta.
- `n`: el número de segmentos en la ruleta.

Dentro de esta función, deberás llamar a `pregunta(posicion)` para saber qué entero se encuentra en el segmento con índice `posicion` de la ruleta.

### Regresa

Tu función debe regresar el índice del segmento (indexado en $0$) en el que se encuentra el entero $x$.

Si $x$ no se encuentra en ninguno de los segmentos de la ruleta, tu función debe regresar `-1`.

# Función del evaluador `pregunta`

`int pregunta(int posicion)`

### Descripción

El evaluador te proveerá con esta función. Llama a esta función para saber qué número está en el segmento con índice `posicion` en la ruleta. No tienes que implementar esta función, solo llamarla.

### Parámetros

- `posicion`: el índice del segmento en el que quieres saber qué entero está escrito.

### Regresa

El entero que se encuentra en la posición especificada del arreglo.

Si el valor de `posicion` es menor que $0$ o mayor o igual que $n$, es decir, si el índice por el que preguntas está fuera del arreglo, esta función regresa `-1`.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||input
encuentra(5, 4)
||output
—
||description
El evaluador llama a tu función `encuentra`.
||input
pregunta(0)
||output
8
||description
Preguntas por el número que se encuentra en el primer segmento de la ruleta. El evaluador te responde con el número $8$.
||input
pregunta(1)
||output
20
||description
Preguntas por el número que se encuentra en el segundo segmento. El evaluador te responde con el número $20$.
||input
pregunta(2)
||output
1
||description
Preguntas por el número que se encuentra en el tercer segmento. El evaluador te responde con el número $1$.
||input
pregunta(3)
||output
5
||description
Preguntas por el número que se encuentra en el cuarto y último segmento. El evaluador te responde con el número $5$. Con esto ya recorriste todos los segmentos de la ruleta y puedes saber que el arreglo es `[8, 20, 1, 5]`.

El $5$ es el número que estás buscando, entonces tu función debe regresar $3$ que es la posición en la que se encuentra.
||input
encuentra(10, 4)
||output
—
||description
El evaluador llama a tu función `encuentra`.
||input
pregunta(0)
||output
8
||description
Preguntas por el número que se encuentra en el primer segmento de la ruleta. El evaluador te responde con el número $8$.
||input
pregunta(1)
||output
20
||description
Preguntas por el número que se encuentra en el segundo segmento. El evaluador te responde con el número $20$.

El número que buscas tendría que ir después de $8$, pero antes de $20$, por lo que sabes que el $10$ no se encuentra en la ruleta. Tu función `encuentra` debe regresar `-1`.
||end

# Límites

- $1 \leq n \leq 10^4$.
- $1 \leq x, A_i \leq 10^9$.
- No hay números repetidos en el arreglo.

Se te evaluará según el número de llamadas que hagas a `pregunta`.

# Subtareas

- **Subtarea 1 (8 puntos):**
  - Puedes hacer hasta $10,000$ llamadas a `pregunta`.
- **Subtarea 2 (19 puntos):**
  - Puedes hacer hasta $60$ llamadas a `pregunta`.
  - Ixchel no gira la ruleta; los segmentos se quedan en su orden original.
- **Subtarea 3 (38 puntos):**
  - Puedes hacer hasta $60$ llamadas a `pregunta`.
- **Subtarea 4 (35 puntos):**
  - Puedes hacer hasta $16$ llamadas a `pregunta`.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`, donde la primera línea contiene dos enteros $n$ y $x$, el número de segmentos en la ruleta y el entero que Lorena quiere encontrar. Estos serán los parámetros que se le pasan a tu función `encuentra`.

La segunda línea contiene $n$ enteros $A_0, A_1, \dots, A_{n-1}$, representando los enteros escritos en los segmentos de la ruleta **después** de que Ixchel la gira. Recuerda que tu función `encuentra` no tendrá acceso a los valores de esta secuencia.

La tercera línea contiene un solo entero que representa el número de llamadas que puedes hacer a `pregunta`.

**IMPORTANTE:** El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de manera distinta.

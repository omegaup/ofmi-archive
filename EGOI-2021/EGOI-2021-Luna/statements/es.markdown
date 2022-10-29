A Luna se le ha ocurrido una idea. Formó a sus $2n$ amigos en una larga fila y les dio a cada uno un número entero entre $1$ y $n$ inclusive. Cada número se usa exactamente dos veces. Cada par de amigos que comparten el mismo número forman una pareja.

Luna quiere enviar a cada una de las $n$ parejas a una cita. Sin embargo, hacerlo no es tan sencillo. Para poder enviar una pareja a una cita, los dos amigos que forman la pareja deben estar uno junto al otro en la fila; es decir, no puede haber ninguna otra persona entre ellos.

Hay dos posibles acciones que Luna puede realizar:
- Intercambiar cualesquiera dos amigos que se encuentren uno junto a otro en la fila.
- Si una pareja se encuentra ya junta en la línea, Luna puede enviarlos a una cita. Esto quita la pareja de la fila. Los amigos que continuan en la fila se desplazan para llenar el espacio de la fila.

Estas acciones se pueden realizar en cualquier orden. Por ejemplo, ella puede realizar algunos intercambios primero, luego enviar algunas parejas de amigos a citas y después volver a realizar intercambios.

Tu tarea es encontrar el mínimo número de acciones necesarias para enviar a todos sus amigos a una cita.

# Entrada

La primera línea de la entrada contiene un solo entero $n$.

La segunda línea de la entrada contiene $2n$ enteros separados por un espacio $a_i$ - la secuencia de números asignados a los amigos en la fila.

# Salida

La primera y única línea de salida contiene el mínimo número de acciones que Luna debe realizar para enviar a cada pareja a una cita.

# Ejemplo

||examplefile
sample
||description
En el primer ejemplo, Luna podría empezar por intercambiar el tercero y cuarto amigo. Después del intercambio, la fila se vería así: 3 1 1 2 2 3.

Luego, ella puede enviar la pareja con el número 1 a una cita y la pareja con el número 2 a una cita (en cualquier orden). Una vez que lo hace, los dos amigos con el número 3 ahora están el uno junto al otro en la fila y ahora Luna puede enviarlos a una cita también.

Al final, esta solución realiza 4 acciones: un intercambio y tres citas.
||examplefile
sample2
||end

# Límites

- $1 \leq a_i \leq n$
- $1 \leq n \leq 500000$

# Subtareas

- Subtarea 1 (7 puntos): Para cada pareja, no hay ninguna persona entre ellos en la fila. Además, $1 \leq n \leq 100$.
- Subtarea 2 (8 puntos): Para cada pareja, hay a lo más una persona entre la pareja en la fila. Además, $1 \leq n \leq 100$.
- Subtarea 3 (11 puntos): Los primeros $n$ amigos de la fila tienen asignados enteros distintos desde $1$ a $n$, no necesariamente en orden. Además, $1 \leq n \leq 3000$.
- Subtarea 4 (16 puntos): Los primeros $n$ amigos de la fila tienen asignados enteros distintos desde $1$ a $n$, no necesariamente en orden. Además, $1 \leq n \leq 500000$.
- Subtarea 5 (22 puntos): $1 \leq n \leq 3000$.
- Subtarea 6 (36 puntos): $1 \leq n \leq 500000$.
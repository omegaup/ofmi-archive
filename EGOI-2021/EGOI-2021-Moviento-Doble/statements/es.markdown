Alice y Bob están jugando un juego y Claire les ayuda. Hay $n$ piedras numeradas del $1$ al $n$. El juego consiste de tres fases.

En la primera fase, Alice y Bob alternan movimientos. Alice mueve primero. En cada movimiento, un jugador declara su intención de tomar una piedra, pero en lugar de decir cuál exactamente, nombran dos opciones. Es posible que las dos opciones sean la misma. También es posible nombrar piedras que fueron nombradas previamente.

Ninguna piedra se toma durante la primera fase, los jugadores solo declaran sus intenciones para la segunda fase. La primera fase termina cuando se hayan hecho $n + 1$ declaraciones.

Este es un ejemplo de la primera fase para $n = 3$:

1. Alice: "Voy a tomar la piedra 1 o la piedra 3"
2. Bob: "Voy a tomar la piedra 2 o la piedra 2"
3. Alice: "Voy a tomar la piedra 3 o la piedra 2"
4. Bob: "Voy a tomar la piedra 1 o la piedra 3"


En la segunda fase, para cada una de las $n + 1$ declaraciones, Claire elige una de las dos opciones diciendo "primero" o "segundo". Llamaremos a cada secuencia de elecciones hechas por Claire un _escenario_. Nota que existen exactamente $2 · 2 · 2 ... 2 = 2^{n + 1}$ escenarios posibles (incluso si, en alguna declaración, la dos opciones son la misma piedra, consideramos que la "primera" o la "segunda" opción resultan en distintos escenarios).

Este es uno de los 16 escenarios que Claire podría escoger en el ejemplo anterior:

1. "Primero": Alice tomará la piedra 1
2. "Primero": Bob tomará la piedra 2
3. "Segundo": Alice tomará la piedra 2
4. "Primero": Bob tomará la piedra 1

Finalmente, en la tercera fase, Alice y Bob empiezan a tomar piedras de acuerdo a las decisiones de Claire. Pierde el primer jugador que no pueda hacer el movimiento requerido (porque la piedra ya fue tomada). Nota que como hay $n$ piedras y $n + 1$ movimientos, uno de los jugadores eventualmente debe perder.

En el ejemplo anterior, Alice empieza tomando la piedra 1. Bob toma la piedra 2. Alice quiere tomar la piedra 2, pero ya ha sido tomada, así que Alice pierde y Bob gana el juego.

Se te da el número $n$ y el estado del juego en algún punto durante la primera fase: un secuencia $k$ de declaraciones que ya se han hecho. Estas declaraciones pueden ser completamente arbitrarias.

Desde este punto, Alicia y Bob jugarán de manera óptima como se describe en el parrafo siguiente.

Sin importar cómo juegen Alice y Bob, es igualmente probable que Claire elija cada uno de los $2^{n+1}$ escenarios posibles. Alice y Bob saben esto por lo que al jugar optimamente están intentando minimizar el número de escenarios en los que van perder.

Asume que Alice y Bob van a jugar el resto del juego como se definió arriba. Calcula el número de escenarios en los que gana el juego cada jugador.

# Entrada 

La primera línea de entrada contiene los números $n$ y $k$ — el número de piedras y el número de declaraciones que ya se han hecho.

Las siguientes $k$ líneas, describen las declaraciones en el orden en que se hicieron. Cada línea contiene 2 números eneros separados por espacio: los números de las piedras declaradas (ambos entre $1$ y $n$ inclusive y no necesariamente distintas).

Nota que cuando $k < n + 1$ el siguiente jugador en hacer una declaración depende de la paridad de $k$.

# Salida

Imprime una sola línea con dos enteros: el número de escenarios en los que gana Alice y el número de escenarios en los que gana Bob. Asumiendo que los dos jugadores juegan el resto del juego como se definió en la redacción.

Nota que la suma de los dos números que escribas debe ser igual a $2^{n + 1}$.

# Ejemplo

||examplefile
sample
||description
El primer ejemplo corresponde al ejemplo de la redacción. No hay mas declaraciones por hacer así que solo debemos ver en cuántos escenarios gana Alice y en cuántos gana Bob. Alice gana si Claire escoge la piedra en su primer movimiento y la piedra en su segundo movimiento, y pierde en todos los demas escenarios.
||examplefile
sample2
||description
En el segundo ejemplo, Si Alice empieza declarando "​1 1​" , Bob continuará "​2 2​", y sin importar lo que declare Alice en el tercer movimiento, ella perderá, ya que Claire escogerá la piedra en el primer movimiento y la piedra en el segundo. Ya no habrá piedras disponibles para el tercer movimiento de Alice. Sin embargo, este no es el primer movimiento óptimo para Alice: Ella debería empezar declarando "​1 2​". Entonces, sin importar lo que Bob haga en el segundo movimiento y lo que Alice haga en el tercero, cada uno ganará en de los escenarios.
||end

# Límites

- $1 \leq n \leq 35$
- $0 \leq k \leq n + 1$

# Subtareas

- Subtarea 1 (15 puntos):: $N \leq 4$
- Subtarea 1 (34 puntos):: $N \leq 10$
- Subtarea 1 (20 puntos):: $N \leq 25$
- Subtarea 1 (10 puntos):: $k = 0$
- (21 puntos): No hay consideraciones adicionales.
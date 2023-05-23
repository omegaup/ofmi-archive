En la escuela se está organizando una votación para Karel como presidente.

La votación ocurre en una mesa redonda con $n$ participantes. Inicialmente, cada participante da su voto (sí o no).

Después, se harán otras $m$ rondas de votación. Para la $k$-ésima votación, cada persona votará de la siguiente manera:

- Si en la votación anterior la persona de su derecha votó que no, entonces la persona mantendrá su voto de la ronda pasada.
- Si en la votación anterior la persona de su derecha votó que sí, entonces la persona cambiará su voto de la ronda pasada (de no a sí, o de sí a no).

Tu tarea es saber cuál será el voto de cada participante al final de las $m$ rondas.

# Implementación

Deberás implementar la función `votacion(n, m, A)` y llamar a la función `resultados(R)`. Estos procedimientos son descritos a continuación.

# Tu función `votacion`

`void votacion(int n, int m, int A[]);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el número de participantes.
- `m`: el número de rondas de votación.
- `A`: el arreglo que representa el voto inicial de cada persona. $A_i = 0$ significa "no" y $A_i = 1$ significa "sí". La $n$-ésima persona del arreglo (índice $n-1$) tiene a su derecha a la primera persona (índice $0$).

Tu función deberá llamar a la función `resultados` con la $R$ que representa el arreglo de votos finales, desde la primera hasta la $n$-ésima persona.

# Función del evaluador `resultados`

`void resultados(int n, int R[])`

## Descripción

El evaluador tiene implementada esta función. Deberás llamar a esta función exactamente una vez con el arreglo $R$ que representa el voto final de cada uno de los $n$ participantes.

Esta función no retorna nada, únicamente es para reportar la solución.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
votacion(5, 2, [0, 0, 1, 0, 0])
||output

- ||description
  El evaluador llama a tu función `votacion` con $n = 5$, $m = 2$ y $A = [0, 0, 1, 0, 0]$.
  ||input
  resultados(5, [1, 0, 1, 0, 0])
  ||output
- ||description
  Tenemos 5 participantes y dos rondas.
- Inicialmente, $A_0 = [0, 0, 1, 0, 0]$
- Después la ronda 1, $A_1 = [0, 1, 1, 0, 0]$
- Después de la ronda 2, $A_2 = [1, 0, 1, 0, 0]$
  Por lo que mandas a llamar `resultados(5, [1, 0, 1, 0, 0])`
  ||end

# Límites

- $2 \leq n \leq 10^6$
- $1 \leq m \leq 10^9$

# Subtareas

- **Subtarea 1 (25 puntos):**
  - $n, m \leq 1,000$
- **Subtarea 2 (25 puntos):**
  - $n \leq 20$
- **Subtarea 3 (10 puntos):**
  - $n$ es potencia de dos y además, $A_{n-1} = 1$ y $A_i = 0$ para todo $0 \leq i < n - 1$
- **Subtarea 4 (40 puntos):**
  - Sin consideraciones adicionales.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea los enteros $n$ y $m$ separados por un espacio. En la segunda línea los $n$ enteros separados por espacio.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
5 2
0 0 1 0 0
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

Una familia de $n$ perritos se ha decidido reunir en algún punto de la avenida Reforma.

Cada perrito se encuentra inicialmente posicionado en cierto punto $x_i$ (medido en metros) de la avenida y se sabe que puede correr a una velocidad máxima de $v_i$ metros por segundo, tanto para enfrente como para atrás y no necesariamente deben avanzar a máxima velocidad.

Tu trabajo es calcular cuál es el menor tiempo posible para que todos los perritos lleguen a un mismo punto de encuentro.

# Implementación

Deberás implementar la función `reunion(n, X, V)`. Este procedimiento es descrito a continuación.

# Tu función `reunion`

`double reunion(int n, int X[], int V[]);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el número de perritos.
- `X`: el arreglo de tamaño $n$, en donde $X_{i-1}$ representa la posición del $i$-ésima perrito.
- `V`: el arreglo de tamaño $n$, en donde $V_{i-1}$ representa la velocidad del $i$-ésima perrito.

## Regresa

Esta función debe regresar un flotante, que represente el menor tiempo posible (en segundos) para que todos los perritos lleguen a un mismo punto de encuentro.

Nota: Sea $r$ tu respuesta y $s$ la repuesta oficial del evaluador, se considerará correcta si $|r - s| / max(1, s) \leq 10^{-6}$.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
reunion(3, [28, 4, 12], [2, 4, 2])
||output
4.0
||description
Tu función `reunion` es llamada por el evaluador. Hay 3 perritos:

- El primer en el metro 28 y con velocidad máxima de 2m/s
- El segundo en el metro 4 y con velocidad máxima de 4m/s
- El tercer en el metro 12 y con velocidad máxima de 2m/s

Todos los perritos pueden llegar al metro 20 en 4 segundos yendo a máxima velocidad.
||end

# Límites

- $1 \leq n \leq 50,000$
- $1 \leq X_i, V_i \leq 10^9$

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $n = 2$
- **Subtarea 2 (15 puntos):**
  - $n = 3$
- **Subtarea 3 (10 puntos):**
  - $V_i = V_j$ para toda $0 \leq i, j \leq n-1$
- **Subtarea 4 (15 puntos):**
  - $n \leq 1,000$
- **Subtarea 5 (50 puntos):**
  - Sin consideraciones adicionales.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea el entero $n$. En la segunda línea los $n$ enteros separados por espacio que representan el arreglo $X$. En la tercera línea, los $n$ enteros separados por espacio que representan el arreglo $V$.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
3
28 4 12
2 4 2
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

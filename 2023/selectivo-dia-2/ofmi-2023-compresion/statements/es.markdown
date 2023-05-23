Tienes un arreglo de $n$ enteros positivos. Puedes decidir aplicar o no aplicar la siguiente operación exactamente una vez:

- Dados dos enteros $[a, b]$, hacer todos los números menores a $a$ igual a $a$; de igual manera, hacer todos los números mayores a $b$ igual a $b$.

Después de esta operación quieres terminar con a lo más $m$ valores distintos.

Tú tarea es encontrar el mejor $a$ y $b$ tal que cambie la menor cantidad de elementos y logre comprimir el arreglo a no más de $m$ enteros distintos.

# Implementación

Deberás implementar la función `compresion(n, m, A)` y llamar a la función `aplasta(a, b)`. Esto procedimientos son descritos a continuación.

# Tu función `compresion`

`int compresion(int n, int m, int A[]);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el tamaño del arreglo.
- `m`: el número máximo de enteros distintos que quieres tener.
- `A`: el arreglo.

Tu función deberá llamar a la función `aplasta` con la $a$ y $b$ óptima si decides aplicarla.

## Regresa

Esta función debe regresar un entero, el mínimo número de elementos que se deben cambiar.

# Función del evaluador `aplasta`

`void aplasta(int a, int b)`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función con los parámetros $a$ y $b$ que representan la operación óptima (en caso que hayas decidido aplicarla).

Esta función no regresa nada, únicamente es para reportar los valores que elegiste.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
compresion(6, 2, [4, 3, 4, 5, 6, 5])
||output

- ||description
  El evaluador llama a tu función `compresion`. Quieres que al final hayan a lo más dos elementos distintos en el arreglo.
  ||input
  aplasta(4, 5)
  ||output
- ||description
  Llamas a la función `aplasta` para reportar que elegiste $a = 4$ y $b = 5$.
  Después de esto el arreglo quedaría $[4, 4, 4, 5, 5, 5]$
  ||input
- ||output
  2
  ||description
  Con la operación comprimiste 2 elementos y lograste que quedaran únicamente 2 elementos distintos ($4$ y $5$).
  Por lo que tu función `compresion` devuelve 2.
  ||end

# Límites

- $1 \leq m \leq n \leq 3*10^5$
- $0 \leq A_i \leq 10^9$

# Subtareas

- **Subtarea 1 (15 puntos):**
  - $m = 1$
- **Subtarea 2 (15 puntos):**
  - Todos los valores de $A$ son distintos
- **Subtarea 3 (20 puntos):**
  - $n \leq 1000$
- **Subtarea 4 (50 puntos):**
  - Sin consideraciones adicionales.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea los enteros $n$ y $m$ separados por un espacio. En la segunda línea los $n$ enteros separados por espacio.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
6 2
4 3 4 5 6 5
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

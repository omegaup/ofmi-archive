Tienes un arreglo $A$ de $n$ enteros.

Puedes hacerle la siguiente pregunta al maldoso Tapia. Dados dos índices distintos $(i, j)$:

1. Tapia escribe el valor de $x:= A_i$ y $y := A_j$ en ese momento.
2. Tapia reemplaza ahora $A_i := x + y$ y $A_j := x - y$.
3. Tapia te da el nuevo valor de $A_j$.

Quieres saber el valor inicial del arreglo $A$ haciéndole preguntas a Tapia.

# Implementación

Deberás implementar las función `maldoso(n)` y llamar a las funciones `pregunta(i, j)` y `respuesta(A)`. Esto procedimientos son descritos a continuación.

# Tu función `maldoso`

`void maldoso(int n);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el tamaño del arreglo.

Tu función deberá llamar a `respuesta` con el arreglo inicial y podrá llamar a la función `pregunta` para obtener información.

# Función del evaluador `pregunta`

`long pregunta(int i, int j)`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función con los parámetros $i \neq j$, $0 \leq i, j \leq n-1$ que representan los índices de la pregunta que le harás a Tapia.

Recuerda que esta función hace que Tapia modifique el arreglo.

## Regresa

Esta función regresa el valor nuevo de $A_j$.

# Función del evaluador `respuesta`

`bool respuesta(int n, int A[])`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función exactamente una vez con el arreglo inicial de $n$ enteros $A$.

## Regresa

Esta función regresa verdadero si el arreglo corresponde al arreglo inicial, falso si no.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
maldoso(3)
||output
||description
Originalmente, el arreglo inicial desconocido $A$ es $[3, 1, 2]$.
El evaluador manda a llamar a tu función `maldoso` con $n = 3$.
||input
pregunta(0, 1)
||output
2
||description
Mandas a llamar a `pregunta` con $i = 0$, $j = 1$.

1. Tapia define $x := A[0] = 3$ y $y := A[1] = 1$
2. Tapia cambia $A[0] := x + y = 4$ y $A[1] := x - y = 2$
3. El nuevo arreglo es $A = [4, 2, 2]$. Tapia devuelve $A[1] = 2$.
   ||input
   pregunta(2, 0)
   ||output
   -2
   ||description
   Después de esta pregunta, el arreglo nuevo queda $A = [-2, 2, 6]$
   ||input
   respuesta([3, 1, 2])
   ||output
   true
   ||description
   Decides llamar a respuesta con el arreglo $[3, 1, 2]$ y obtienes respuesta correcta.
   ||end

# Límites

- $2 \leq n \leq 10^4$
- $-10^9 \leq A_i \leq 10^9$

# Subtareas

- **Subtarea 1 (20 puntos):**
  - $n = 2$
  - El número máximo de llamadas a `pregunta` que puedes hacer es $n$.
- **Subtarea 2 (20 puntos):**
  - $n = 3$
  - El número máximo de llamadas a `pregunta` que puedes hacer es $n$.
- **Subtarea 3 (15 puntos):**
  - No hay número máximo de llamadas a `pregunta`.
- **Subtarea 4 (45 puntos):**
  - El número máximo de llamadas a `pregunta` que puedes hacer es $n$.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea el entero $n$. En la segunda línea los $n$ enteros separados por espacio.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
3
3 1 2
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

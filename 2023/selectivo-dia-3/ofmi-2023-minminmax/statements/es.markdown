Tienes un arreglo $A$ de tamaño $n$. Quieres formar $m$ subarreglos no vacíos consecutivos tal que minimices el mínimo de los máximos de cada subarreglo.

# Implementación

Deberás implementar la función `minMinMax(n, m A)`. Este procedimiento es descrito a continuación.

# Tu función `minMinMax`

`int minMinMax(int n, int m, int A[]);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el tamaño del arreglo.
- `m`: el número de subarreglos consecutivos que quieres formar.
- `A`: el arreglo.

## Regresa

Esta función debe regresar un entero, el mínimo número que se puede obtener si divides el arreglo en $m$ subarreglos contiguos y tomas el mínimo de los máximos de los subarreglos.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
minMinMax(5, 2, [9 8 7 6 5])
||output
5
||description
Podemos particionar el arreglo en los siguientes dos subarreglos [9, 8, 7, 6] y [5]. Tomando el máximo en cada subarreglo tenemos {9, 5}. El menor de ellos es 5.
||end

# Límites

- $1 \leq m \leq n \leq 10^5$
- $-10^9 \leq a_i \leq 10^9$

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea los enteros $n$ y $m$ separados por un espacio. En la segunda línea los $n$ enteros separados por espacio.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
5 2
9 8 7 6 5
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

Se dice que un entero es capicúa si se lee igual de izquierda a derecha que de derecha a izquierda. Ejemplos: 161, 2992, 3003, 91019, 5005, 292, 2882, 2442, 9102019.

Dado un rango $[A, B]$ queremos encontrar la cantidad de subrangos $[a, b] (A \leq a \leq b \leq B)$ tales que el número de capicúas contenidos en ese rango es par. Estos subrangos los llamaremos subrangos bonitos.

# Implementación

Deberás implementar la función `int subrangosBonitos(long long A, long long B)`. Esta función recibe como parámetros `A` y `B` que representan el rango $[A, B]$. Debe regresar la cantidad de subrangos bonitos que hay dentro del rango $[A, B]$ módulo $1000000007$.

# Ejemplos

||examplefile
sample
||description
[8, 9], [8, 10], [9, 11], [9, 12], [10, 10], [12, 12] son los subrangos con una cantidad par de capicúas.
||end

# Subtareas

- Subtarea 1 (10 puntos). $1 \leq A \leq B \leq 1000$
- Subtarea 2 (30 puntos). $1 \leq A \leq B \leq 1000000$
- Subtarea 3 (60 puntos). $1 \leq A \leq B \leq 10^{12}$

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` que contiene el rango $[A, B]$ a probar. Este archivo será usado para generar los parámetros de la función `subrangosBonitos` y mandarla a llamar.

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

_Nota: a las cobayas les gustan las capicúas_

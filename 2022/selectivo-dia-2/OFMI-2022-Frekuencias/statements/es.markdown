Juanito conoce a muchas cobayas y quiere saber más sobre los diferentes colores que pueden tener. Así que puso a todas las cobayas que conoce en una fila y les asignó un caracter que corresponde al color de cada cobaya.

Definimos la Frekuencia de una lista de colores como la diferencia entre la frecuencia del color más frecuente y la frecuencia del color menos frecuente.

Por ejemplo, la frekuencia de `abacaba` es $4-1=3$, pues el color `a` se repite 4 veces y el color `c` 1 vez.

El problema es, dada una lista de los colores de las cobayas, encontrar la mayor frekuencia entre todos los posibles subrangos de la lista.

# Implementación

Deberás implementar la función `int frekuencia(int N, char C[])`, que recibe el tamaño del arreglo de carácteres $N$ y la lista de caracteres $C$ que representa los colores de las cobayas.

Tu función debe regresar la mayor frekuencia posible entre todos los subrangos.

# Ejemplos

||examplefile
sample
||description
`abacaba` es el subrango de mayor frekuencia
||end

# Límites

- $1 \leq N \leq 100,000$ (Sí, Juanito conoce a muchas cobayas).
- La lista contendrá únicamente letras minúsculas del alfabeto inglés (cualquier carácter del abecedario de la `a` a la `z` sin incluir `ñ` o letras con acentos).

# Subtareas

- (25 puntos): $1 \leq N \lt 100$.
- (45 puntos): La lista solo contendrá caracteres `a` y `b`.
- (35 puntos): Sin consideraciones adicionales.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`, donde la primera línea debe ser el tamaño de la string y en la segunda línea una string, que serán los parámetros de la función `frekuencia`.

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

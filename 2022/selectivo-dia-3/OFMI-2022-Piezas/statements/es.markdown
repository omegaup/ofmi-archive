A Andrea le gusta jugar con letras hechas de fomi para armar su palabra favorita.

Ella se dio cuenta que puede voltear algunas piezas para usarlas como otra letra. Por ejemplo, puede voltear la `q` y volverla `p`, y viceversa. Específicamente, ella puede intercambiar: `p`<->`q`, `b`<->`d` y `s`<->`z`.

Dado ciertas letras de fomi que tiene, quiere saber la mayor cantidad de veces que puede formar su palabra favorita $s$.

# Implementación

Deberás implementar la función `int palabraFavorita(int n, char s[], int m, char piezas[])`. Esta función recibe como parámetros $n$, el tamaño de la cadena $s$, la cadena $s$ que es la palabra favorita de Andrea, $m$ que es el tamaño de el arreglo de $piezas$, el arreglo $piezas$ con el que cuenta Andrea. Deberás devolver la cantidad de veces que se puede formar la palabra favorita con las piezas disponibles.

# Ejemplos

||examplefile
sample
||description
La palabra favorita de Andrea es `siu`, podemos tomar de las piezas `i`, `s`, `i`, `z`, `u` y `u`, voltear la `z` para transformarla en `s` y así formar dos veces `siu`.
||end

# Subtareas

- (20 puntos): $1 \leq n, m \leq 100,000$. La palabra favorita de Andrea no contendrá las letras `p`, `q`, `b`, `d`, `s` ni `z`.
- (10 puntos): $1 \leq n, m \leq 10$
- (70 puntos): $1 \leq n, m \leq 100,000$

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` que en la primera línea `s` y en la segunda línea `piezas`. Este archivo será usado para generar los parámetros de la función `palabraFavorita` y mandarla a llamar.

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

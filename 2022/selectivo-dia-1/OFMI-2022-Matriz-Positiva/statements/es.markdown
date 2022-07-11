Tienes una matriz de enteros a la cual quieres aplicar cualquier número de veces alguna de las siguientes operaciones:

- Tomar una fila completa de la matriz y cambiar el signo de cada una de sus entradas.
- Tomar una columna completa de la matriz y cambiar el signo de cada una de sus entradas.

Tu objetivo es lograr que la suma de cada fila y de cada columna en la matriz sea semipositiva; es decir, mayor o igual a 0.

# Implementación

Deberás implementar la función `void matrizSumaSemipositiva(int N, int M, int matriz[][100])` que recibe como parámetros $N$, $M$ que indican que el tamaño de la matriz es de $N \times M$ y una matriz de tamaño $N \times 100$.

**Nota**: La matriz tendrá tamaño `N`x`100` por cuestiones técnicas, pero realmente sólo tendrán valores las primeras $M$ columnas.

Para cambiar de signo una fila de la matriz, tu función deberá llamar a la función `void cambiaFila(int fila)` que recibe el índice $(0 \leq fila < N)$ de la fila a cambiar.

Para cambiar de signo una columna de la matriz, tu función deberá llamar a la función `void cambiaColumna(int columna)` que recibe el índice $(0 \leq columna < M)$ de la columna a cambiar.

# Ejemplos

||examplefile
sample
||description
Aplicando la operación `cambiarColumna(1)` tendremos la matriz [[-2, 3, 4], [3, 5, 2]] cuyas filas y columnas suman positivo.
||end

# Límites

- Todos los números de la matriz están entre -100 y 100

# Subtareas

- (10 puntos): $N = 1$, $1 \leq M \leq 100$
- (30 puntos): $1 \leq N, M \leq 10$
- (40 puntos): $1 \leq N, M < 100$.
- (20 puntos): $N, M = 100$. Además, no puedes cambiar la misma fila o columna más de una vez.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` que contiene en la primera línea los enteros $N$ y $M$, y en las siguientes líneas la matriz. Este archivo será usado para mandar los parámetros de la función `matrizSumaSemipositiva`.

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

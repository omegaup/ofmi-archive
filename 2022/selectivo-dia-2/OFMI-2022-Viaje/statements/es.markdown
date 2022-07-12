La cobaya de Tapia se llama Boni y quiere ir a visitar a su amiga Facia. El lugar donde viven las cobayas está muy bien organizado y puede ser representado por una matriz.

Para moverse dentro de la ciudad de las cobayas hay que considerar lo siguiente:

- Boni puede dar 1 paso a cualquiera de las casillas [ortogonalmente adyacentes](https://omegaup.com/docs/Glosario-OFMI.pdf) a su posición actual.
- Boni puede dar 1 paso a cualquier casilla que tenga el mismo número que el que tiene su posición actual.
- Boni no puede llegar a una casilla que tenga un $-1$.

# Problema

Ayuda a Boni a llegar en la menor cantidad de pasos a donde se encuentra Facia. En caso de que Boni no pueda llegar con Facia, debes regresar $-1$.

# Implementación

Deberás implementar la función
`int viajeCobayas(int N, int M, int matriz[][200], int r1, int c1, int r2, int c2)`,
que recibe como parámetros $N$ y $M$ que representan el tamaño de la matriz, la matriz, la posición inicial de Boni $(r1, c1)$ y la posición de Facia $(r2, c2)$.

Tu función debe regresar la menor cantidad de pasos a donde se encuentra Facia, o $-1$ si es imposible.

La casilla en la posición $(0,0)$ es la casilla en la esquina superior izquierda.

**Nota**: La matriz tendrá tamaño $N\times200$ por cuestiones técnicas, pero realmente sólo tendrán valores las primeras $M$ columnas.

# Ejemplos

||examplefile
sample
||description
Se puede tomar cualquiera de los siguientes caminos:

- (0,0)->(1,1)->(1,2)->(2,2)
- (0,0)->(1,1)->(2,1)->(2,2)
  ||end

# Limites

- $N,M \leq 200$
- $1 \leq a_{i,j} \leq 40000$ o $a_{i,j} = -1$

# Subtareas

- (10 puntos): Todos las casillas tienen números diferentes y ninguno es negativo
- (20 puntos): $N, M \leq 5$
- (40 puntos): Todos las casillas tienen números diferentes y varios negativos
- (30 puntos): Sin consideraciones adicionales

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`

Con dos enteros, $N$ y $M$, seguido de $N$ lineas con $M$ valores indicando la matriz,
una linea con dos números $r1$ y $c1$, y al final otra linea con $r2$ y $c2$, los cuales serán los parámetros de la función `viajeCobayas`.

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes.
El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

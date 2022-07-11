Tienes un arreglo de $n$ enteros, en una operacion puedes cambiar el valor de cualquier elemento del arreglo a cualquier otro valor entero.

Se dice que hay una caída en la posicion $i$ del arreglo ($i \lt n - 1$) si se cumple que $A_i \gt A_{i + 1}$.

Tu tarea es realizar a lo más $k$ operaciones para que el arreglo tenga la menor cantidad de caídas.

# Implementación

Deberás implementar la función `int waves(int n, int k, int A[])`, que recibe el tamaño del arreglo $n$, la cantidad máxima de operaciones con las que cuentas $k$, y el arreglo de enteros $A$.

La función debe regresar la mínima cantidad de caídas en el arreglo después de realizar a lo más $k$ operaciones.

# Ejemplos

||examplefile
sample
||description
Usando las operaciones en el $5$ y el $2$ se obtiene el arreglo $\left[3, 4, 4, 4, 4, 4\right]$ el cual tiene $0$ caídas.
||end

# Límites

- $1 \leq k \leq n \leq 100$
- $-10^9 \leq A_i \leq 10^9$.

# Subtareas

- (35 puntos): $n \leq 20$.
- (65 puntos): Sin consideraciones adicionales.

# Experimentación

{{libinteractive:download}}

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

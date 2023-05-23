Tienes un grafo con $n$ vértices numerados de $1$ a $n$ y $m$ aristas. Cada arista es del tipo 1 o del tipo 2.

Quieres asignarle un número real a cada vértice de tal forma que:

- Para cada arista del tipo 1, la suma de los vértices que conecta debe ser 1.
- Para cada arista del tipo 2, la suma de los vértices que conecta debe ser 2.

Tu tarea es encontrar alguna asignación de vértices tal que cumpla con los requerimientos de aristas y minimice la suma del valor absoluto de los vértices.

Nota: La tolerancia de los requerimientos y la suma de los valores absolutos será de $10^{-6}$

# Implementación

Deberás implementar las función `unoDos(n, m, U, V, T)` y llamar a la función `asigna(v, x)`. Esto procedimientos son descritos a continuación.

# Tu función `unoDos`

`bool unoDos(int n, int m, int U[], int V[], int T[]);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el número de vértices.
- `m`: el número de aristas.
- `U`, `V`: arreglos que representan las aristas del grafo. La $i$-ésima arista conecta los vértices $U[i-1]$ con $V[i-1]$, con $1\leq i \leq m$.
- `T`: el arreglo que representa el tipo de arista. La $i$-ésima arista es de tipo $T[i-1]$, con $1\leq i \leq m$.

Si es posible conseguir la asignación, tu función deberá llamar a la función `asigna` para cada vértice con el valor que corresponde.

## Regresa

Esta función debe regresar `true` si es posible hacer dicha asignación, o `false` si no hay ninguna solución.

# Función del evaluador `asigna`

`bool asigna(int v, double x)`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función con los parámetros $v$ y $x$ que representan el vértice y el número real asignado, respectivamente.

Esta función regresa verdadero si la asignación sigue cumpliendo los requerimientos.

Regresa falso si la asignación es inválida (algún requerimiento no se cumplió) o si ya le habías asignado algún valor anteriormente a ese vértice. Esto se tomará como error y el evaluador no te dará puntos.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
unoDos(5, 4, [2, 4, 3, 2], [4, 5, 4, 3], [2, 1, 2, 1])
||output

- ||description
  El evaluador llama a tu función `unoDos`. Hay 5 vértices y 4 aristas.

- La primera arista es de tipo 2 y conecta los vértices 2 y 4.
- La segunda arista es de tipo 1 y conecta los vértices 4 y 5.
- La tercera arista es de tipo 2 y conecta los vértices 3 y 4.
- La cuarta arista es de tipo 1 y conecta los vértices 2 y 3.

||input
asigna(1, 0)
||output
true
||description
Le asignamos valor 0 al vértice 1.
||input
asigna(2, 0.5)
||output
true
||description
Le asignamos valor 0.5 al vértice 2.
||input
asigna(3, 0.5)
||output
true
||description
Le asignamos valor 0.5 al vértice 3. Así, se cumple el requerimiento la cuarta arista.
||input
asigna(4, 1.5)
||output
true
||description
Le asignamos valor 1.5 al vértice 4. Así, se cumplen los requerimientos de la primera y tercera arista.
||input
asigna(5, -0.5)
||output
true
||description
Le asignamos valor -0.5 al vértice 5. Así, se cumple el requerimiento de la segunda arista.
||input

- ||output
  true
  ||description
  Se lograron cumplir todos los requerimientos de las aristas, por lo que tu función `unoDos` debe regresar verdadero.
  Además, la suma de los valores absolutos fue de 3.
  ||end

# Límites

- $1 \leq n \leq 10^5$
- $0 \leq m \leq 2*10^5$
- $1 \leq U_i, V_i \leq n$
- $T_i \in \{1, 2\}$

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $n \leq 5$
  - $m \leq 14$
- **Subtarea 2 (5 puntos):**
  - $T_i = 1$ para toda $0 \leq i \leq n-1$
  - El evaluador no tomará en cuenta la suma del valor absoluto de los vértices. Es decir, solo importa que encuentres asignación correcta.
- **Subtarea 3 (15 puntos):**
  - El evaluador no tomará en cuenta la suma del valor absoluto de los vértices. Es decir, solo importa que encuentres asignación correcta.
- **Subtarea 4 (20 puntos):**
  - Cada vértice tendrá a lo más dos aristas incidentes.
  - El grafo no tendrá ciclos.
- **Subtarea 5 (50 puntos):**
  - Sin consideraciones adicionales.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea los enteros $n$ y $m$. En las siguientes $m$ líneas vendrán tres enteros separados por espacios, que representan los enteros $U_{i}$, $V_{i}$ y $T_{i}$, respectivamente.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
5 4
2 4 2
4 5 1
3 4 2
2 3 1
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

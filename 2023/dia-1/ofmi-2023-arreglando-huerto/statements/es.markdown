En tu jardín tienes un huerto de tamaño $n$ y quieres una cantidad específica de cada vegetal. Todo estaba perfecto hasta que una serpiente vegetariana empezó a robarte los vegetales. Ahora algunas secciones del huerto tienen menos vegetales de los que deberían y otras, de alguna forma tienen más.

Tienes dos arreglos de enteros no negativos $A$ y $B$ de longitud $n$, que representan el estado actual del huerto y como quieres que esté el huerto, respectivamente. Cada elemento de un arreglo dice cuántos vegetales hay o debería haber en esa sección del huerto.

Como las secciones del huerto están muy cerca las unas de las otras, cada vez que pones o quitas vegetales en una sección, también modificas la cantidad de vegetales de una sección adyacente. Si decides restar $x$ vegetales a cualquier sección del huerto $A[i]$, también tendrás que sumar $x$ vegetales ya sea a $A[i-1]$ o a $A[i+1]$.

Después de cada operación, la cantidad de vegetales en cada sección del huerto $A$ debe permanecer no negativa.

El objetivo es hacer que $A$ sea igual a $B$, es decir, que cada elemento de $A$ sea igual al elemento de $B$ en la misma posición.

# Implementación

Deberás implementar la función `arregla(A, B)` que mande a llamar la función `mueve(indice, cantidad, direccion)` hasta que `A` sea igual a `B`

# Tu función `arregla`

`bool arregla(int n, int A[], int B[])`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

## Parámetros

- `n` el número de elementos que tienen `A` y `B`.
- `A`, `B` representan 2 arreglos de enteros, ambos arreglos tienen la misma cantidad de elementos.

Dentro de esta función, deberás llamar a la función proporcionada `mueve(indice, cantidad, direccion)` para restar `cantidad` a `A[indice]` y sumar `cantidad` a `A[indice+direccion]` hasta que los elementos en `A` sean iguales a `B`.

El evaluador tiene sus propias copias de `A` y `B`, diferentes de los parámetros `A` y `B` que recibió tu función. Es decir, si modificas `A` y `B`, los arreglos del evaluador no van a cambiar; y cuando llames a `mueve(indice, cantidad, direccion)`, tus arreglos `A` y `B` no van a cambiar.

## Regresa

Tu función debe regresar un booleano, que representa si fue posible o no hacer que los dos arreglos fueran iguales.

# Función del evaluador `mueve`

`bool mueve(int indice, int cantidad, int direccion);`

## Descripción

El evaluador te proveerá con esta función. Llama esta función para restar `cantidad` a `A[indice]` y sumar `cantidad` a `A[indice+direccion]`

La función regresa `true` si `A` es igual a `B` después de realizar la operación, `false` si son diferentes.

No deberás implementar esta función, solo llamarla.

Nota: Recuerda que al llamar a esta función, los arreglos `A` y `B` que se pasaron a tu función como parámetros no se modifican.

## Parámetros

- `indice`: Es el índice del elemento al que se le va a restar. Si mandas un índice menor a $0$ o mayor a $n - 1$, la función regresa `false` y no hace nada.

- `cantidad`: Es la cantidad que se va a restar a `A[indice]` y sumar a `A[indice+direccion]`. Nota que `cantidad` puede ser negativa.

- `direccion`: Solo puede ser $1$ o $-1$, si se manda otro valor, la función regresa `false` y no hace nada. `indice+direccion` debe ser mayor o igual a $0$ y menor o igual a $n - 1$, si no se cumple, la función regresa `false` y no hace nada.

## Regresa

Un booleano que indica si `A` es igual a `B` después de realizar la operación.

## Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
arregla(4, [1, 2, 0, 1], [0, 1, 3, 0])
||output

- ||description
  Esta será la llamada inicial a tu procedimiento `arregla`.
  ||input
  mueve(0, 1, 1)
  ||output
  false
  ||description
  Restamos $1$ al elemento $A[0]$ y sumamos $1$ al elemento $A[1]$.
  El nuevo valor de $A$ es `[0, 3, 0, 1]`
  Como $A$ no es igual a $B$, la función regresa `false`
  ||input
  mueve(1, 2, 1)
  ||output
  false
  ||description
  Restamos $2$ al elemento $A[1]$ y sumamos $2$ al elemento $A[2]$.
  El nuevo valor de A es `[0, 1, 2, 1]`
  Como $A$ no es igual a $B$, la función regresa `false`
  ||input
  mueve(3, 1, -1)
  ||output
  true
  ||description
  Restamos $1$ al elemento $A[3]$ y sumamos $1$ al elemento $A[2]$.
  El nuevo valor de A es `[0, 1, 3, 0]`
  Como $A$ es igual a $B$, la función regresa `true`
  ||end

# Límites

- $1 \leq n \leq 10^4$
- $0 \leq A_i, B_i \leq 10^5$

# Subtareas

- **Subtarea 1 (18 puntos) agrupados:**
  - Los elementos iniciales de $A$ están en orden descendente, es decir, $A[i] \geq A[i+1]$ y los de $B$ en orden ascendente, $B[i] \leq B[i+1]$ para todo $i$.
  - Se asegura que siempre hay solución.
  - $n \leq 10^4$
- **Subtarea 2 (37 puntos) agrupados:**
  - $n \leq 10^3$
- **Subtarea 3 (45 puntos) agrupados:**
  - $n \leq 10^4$
  - Además, debes usar la mínima cantidad de llamadas a la función `mueve` posible.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $n$ en la primera línea, el arreglo $A$ en la segunda línea y el arreglo $B$ en la tercera línea. Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
4
1 2 0 1
0 1 3 0
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

---

![](arreglando.jpeg 'Persiguiendo a Nicolás.')

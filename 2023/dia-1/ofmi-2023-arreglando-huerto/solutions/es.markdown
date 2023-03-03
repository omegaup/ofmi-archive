# Arreglando el huerto - Solución

## Subtarea 1. (Elementos ordenados)

La clave de esta subtarea es ver que, dado que siempre hay solución, en todo momento se cumple que $A_i \gte B_i$. Por esta razón, podemos mover siempre de izquierda a derecha. En otras palabras, comenzamos desde el primer elemento de $A$, le quitamos lo necesario para igualarlo al primero de $B$ y lo pasamos a la derecha. Hacemos lo mismo con el segundo elemento, y así sucesivamente.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2.

Lo primero que debemos hacer a partir de esta subtarea es saber si es posible hacer que los dos arreglos sean iguales. Resulta que se se puede arreglar si y solo si la suma de los elementos de $A$ es igual a la de $B$.

Una demostración sencilla nos lleva a un algoritmo para solucionar la subtarea 2. Podemos hacer una iteración primera en donde vamos pasando todos los elementos de $A$ de derecha a izquierda, acumulando toda la suma de $A$ en la primera casilla. Así podemos correr tal cual el algoritmo de la subtarea anterior para ir acomodando los necesarios ahora de izquierda a derecha.

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3.

El algoritmo anterior nos da la respuesta en ~$2n$ llamadas. Para reducir este número de llamadas podemos hacer que entre cada par de casillas adyacentes solo haya un movimiento (ya sea a la izquierda o a la derecha).

Empecemos con un arreglo de tamaño $n$, busquemos de izquierda a derecha el primer índice $j$ tal que $\sum_{i=0}^{j} A_i \gte \sum_{i=0}^{j} B_i$. Entonces, lo que hay que hacer es hacer pasar elementos de derecha a izquierda a partir de $j$. Una vez hecho, todos los elementos de $[0, j]$ estarán bien arreglados. Entonces aplicamos el mismo algoritmo para el subarreglo que quedó (de $[j + 1, n]$).

<details><summary>Solución</summary>

{{solution.cpp}}

</details>

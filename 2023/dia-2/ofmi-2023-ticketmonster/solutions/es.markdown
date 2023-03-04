# La gira de las épocas - Solución

## Subtarea 1. ($N = 1$)

En esta subtarea se asegura que habrá solo un animal comprando $D$ hongos y no se considerará revendedor (puesto que $D < L$), entonces, en este caso solamente hay que ver cuántos hongos se le pueden vender después de separar los $R$ hongos para la venta general.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2. ($D_i < L$)

Esta subtarea es una generalización de la anterior, después de haber separado los $R$ hongos, tratamos de venderle a cada animal la mayor cantidad posible de hongos. Ahora debemos de recorrer la lista con un `for`.

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3. (Suficientes hongos)

En esta subtarea, hay suficientes hongos para todos los animales, por lo que no hay que preocuparnos por reservar hongos para la venta general. Sin embargo, ahora hay que cuidar no venderle de mas a las serpientes revendedoras. Esto se puede verificar con un `if (D[i] > L)` mientras recorremos la lista con un `for`.

<details><summary>Solución subtarea 3</summary>

{{sub3.cpp}}

</details>

## Subtarea 4.

La intención de las subtareas anteriores es que puedan resolver en partes el problema original: qué instrucciones hay que poner para poder venderle a los animales si se llegan a acabar los hongos, o cómo venderle a los animales si piden más del límite. En la solución general, hay que considerar ambos casos, aquí podríamos fusionar las soluciones anteriores en una sola para tener todos los puntos.

<details><summary>Solución completa</summary>

{{solution.cpp}}

</details>

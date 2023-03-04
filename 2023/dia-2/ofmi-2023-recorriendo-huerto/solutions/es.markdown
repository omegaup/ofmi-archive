# Recorriendo el huerto - Solución

## Subtarea 1 (no se avanza hacia atrás)

Dado que nunca se avanza hacia atrás, la función `vueltas` debe regresar $0$ siempre. Entonces, solo debemos tener bien calculado la posición en donde nos encontramos en cada momento (`curr_pos`). Cada `adelante(x)` suma $x$ a la posición.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2 (no se llama a la función vueltas)

Para resolver esta subtarea es agregar además la función `atras(y)` que debería restar $y$ a la posición actual.

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3 (máximo una vuelta)

Para esta subtarea, la única vuelta que se va a dar es cuando se llame por primera vez a la función `atras`. A partir de este momento, se debe contestar a `vueltas` con $1$.

<details><summary>Solución subtarea 3</summary>

{{sub3.cpp}}

</details>

## Subtarea 4 (solución)

Para resolver el problema completo hay que ver en qué momento se da una vuelta. Esto sucede en cuanto se cambia de dirección. Esto es, cuando se llama a un `atras` y el último desplazamiento fue hacia adelante, o cuando se llama a `adelante` y el último desplazamiento fue hacia atrás. Basta con guardar una variable que nos indique la dirección actual en la que estamos (podría ser -1 atras y 1 adelante). Si la dirección cambia, sumamos uno a nuestra cantidad de `giros`.

<details><summary>Solución</summary>

{{solution.cpp}}

</details>

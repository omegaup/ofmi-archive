# El conejo Benito - Solución

## Subtarea 1. ($1 \leq n \leq 3$)

Como el valor de $n$ es muy chiquita, podemos hacer los casos a mano. La matriz de tamaño $1\times 1$ es simplemente 1. Mientras que para la de tamaño $n=3$ puede ser una de las siguientes dos formas:

```
1 1 1        2 2 2
1 2 1        2 1 2
1 1 1        2 2 2
```

Entonces podemos hacer un código que cheque si es uno de estos casos.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2. (La matriz es espiral)

Al ser espiral, podemos buscar el número más grande de la matriz e imprimirla como respuesta. También podemos analizar los casos chiquitos y observar que, dada una matriz espiral de tamaño $n$, ya sea que crezca de adentro hacia afuera o de afuera hacia adentro, la respuesta será $(n + 1) / 2$.

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3. (Matrices de afuera hacia adentro)

El enfocarnos en un solo tipo de espiral nos permite analizar que patrones o estructura deben tener. Para este caso, podríamos hacer una simulación e ir construyendo la matriz de afuera hacia adentro, pero inclusive al hacerlo a mano, podemos observar que el número de una casilla depende de qué tan cerca de algún extremo de la matriz este.

Por ejemplo, para la matriz de $7\times 7$,

```
1 1 1 1 1 1 1
1 2 2 2 2 2 1
1 2 3 3 3 2 1
1 2 3 4 X 2 1
1 2 3 3 3 2 1
1 2 2 2 2 2 1
1 1 1 1 1 1 1
```

El número faltante `X` esta a distancia 5 del extremo de la izquierda, 3 de la derecha, y 4 de los extremos de arriba y abajo. Y en efecto, el número correspondiente de esta posición es el 3.

Les dejamos de tarea demostrar que esto siempre se cumplirá para las matrices espirales de adentro hacia afuera. Lo importante es que dada una posición $(x, y)$, el número que debe tener en la matriz de $n\times n$ se puede calcular con la siguiente función:

```g++
int distancia(int x, int y, int n) {
  return std::min(std::min(x + 1, y + 1), std::min(n - x, n - y));
}
```

Con un doble `for` podemos checar si es una matriz espiral de adentro hacia afuera o no.

<details><summary>Solución subtarea 3</summary>

{{sub3.cpp}}

</details>

## Subtarea 4. (Matrices de adentro hacia afuera)

Para esta subtarea podemos hacer las mismas observaciones que en la subtarea 3, solo que la distancia hacia el extremo más cercano no nos indica el número de la casilla, nos indica cuánto habría que restarle a $(n + 1) / 2$ para tener el número correcto de dicha posición.

<details><summary>Solución subtarea 4</summary>

{{sub4.cpp}}

</details>

## Subtarea 5.

Podemos unir las soluciones de las últimas dos subtareas para tener la solución general.

<details><summary>Solución completa</summary>

{{solution.cpp}}

</details>

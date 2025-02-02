Este problema nos da dos arreglos:

1. Uno de $T$ enteros, donde cada valor representa la altura que se vuela en ese segundo.
2. Uno de $H$ enteros, donde cada valor representa el costo de volar una altura $h$.

A partir de ahorra, nos referiremos al segundo arreglo como arreglo de costos.

Para resolver el problema, tenemos que hacer lo siguiente: por cada altura, tenemos que obtener cual es su costo y sumarlo al costo total.

## Subtarea 1

El costo de cada altura es 1, por lo que cada segundo consumiremos un pretzel.
Por lo tanto, la respuesta es $1 \times T$ = $T$, donde $T$ es la cantidad total de segundos.

<details><summary>Solución de la primera subtarea</summary>

{{sub1.cpp}}

</details>

## Subtarea 2

Debido a que solamente volaremos por un segundo, solo nos van a dar una altura $h$.

Observacion clave: el arreglo de costos asocia cada altura con su respectivo costo.
Esto es asi, porque cada indice o posición $i$ del arreglo representa una altura $h_i$.

Solo tenemos que consultar el valor en la posición $h$ del arreglo de costos.

<details><summary>Solución de la segunda subtarea</summary>

{{sub2.cpp}}

</details>

# Solución

Hay dos formas de sacar 100 puntos en este problema, dependiendo de en qué nos decidamos enfocar.

### Solución A: Alturas

- Creamos un arreglo de costos que vaya hasta $H_m + 1$, donde $H_m$ es la maxima altura que nos dan en la entrada.

  - Para saber el costo de una altura $h$, es suficiente con consultar la posición $h$ de este arreglo.

- Recorremos el arreglo de alturas, y por cada una obtenemos su costo consultando el arreglo de costos y lo sumamos al costo total.

<details><summary>Solución asociando cada altura con su costo</summary>

{{solution.cpp}}

</details>

### Solución B: Costos

- Crear una cubeta de alturas, donde mantendremos en cada posición $i$ cuántas veces aparece la altura $i$ a la que vuela el Turix.

  - Esta cubeta debe ser lo suficientemente grande como para indexar todas las alturas.

- Recorremos el arreglo de costos. Recordemos que cada posición de este arreglo esta asociada a una altura.

- A nuestro costo total, le sumamos $C_i \times F_i$, donde:

  - $C_i$ representa el costo de la altura actual.

  - $F_i$ representa la cantidad de veces que aparece la altura actual.

<details><summary>Solución guardando las alturas en una cubeta</summary>

{{solutionB.cpp}}

</details>

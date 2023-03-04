# Mich explorador - Solución

## Subtarea 1 (n = 1)

Para la subtarea 1, como N es 1, la habitación es una línea y hay que ir hacia el Este hasta llegar a la meta,
así que basta contar cuántas casillas antes de la última apuntan hacia otro lado.

![](330462831_1192585168065821_2065832953943047226_n.jpg)

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2 (llegar sin modificaciones)

Para la subtarea 2 basta seguir el camino que indican las baldosas y comprobar si se llega a la meta.

![](329394651_574786484541860_126123251104163130_n.jpg)

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3

Para el caso general, primero notemos que si se llega sin cambios ésto sería lo mejor. Si no es así,
marquemos como visitadas todas las casillas a las que podemos llegar sin gastar moneda (en la figura son las verdes), después
gastando una moneda podemos llegar a cualquier casilla que sea vecina de alguna de éstas, más aún,
podemos seguir el camino que marca el tablero desde cada una de ellas, éstas serán todas las
casillas alcanzables gastando una moneda (en la figura las amarillas), podemos repetir este proceso:
ahora desde todos los vecinos de alguna casilla amarilla seguimos el camino marcado y todas esas son
casillas alcanzables con dos monedas (en la figura las azules) y así sucesivamente hasta alcanzar
la casilla meta.

![](329091306_2272586872926551_7313266498286252245_n.jpg 'Casillas alcanzables con cada cantidad de monedas.')

<details><summary>Solución</summary>

{{solution.cpp}}

</details>

Algunas observaciones que ayudan a entender la solución son:

- La meta siempre es alcanzable, pues tengo suficientes monedas para modificar, en el peor
  caso, todas las casillas de algún camino a la meta.
- Siempre puedo encontrar un camino que gaste la mínima cantidad de monedas de oro y que
  no tenga ciclos, pues el ciclo se puede recortar; si en el ciclo se gastaban monedas
  es porque después del ciclo se necesitaba pasar por cierta casilla con cierta dirección, en
  tal caso se puede gastar la moneda después del ciclo.
- La observación anterior nos permite implementar el algoritmo de tal forma que vamos marcando
  como visitadas las casillas y no las volvemos a procesar, por lo que la cantidad de operaciones
  queda acotada por el máximo (N\*M) de casillas que procesamos, multiplicado por un factor
  4 por los máximo 4 vecinos que tiene cada casilla (dependiendo de la implementación puede haber
  un factor mayor, aún así hay buen colchón para el tiempo que nos da el problema).

Este algortimo es una modificación del algoritmo clásico de búsqueda en amplitud, también
conocido como BFS, puedes practicar más este tema con los siguientes problemas:

- https://omegaup.com/arena/problem/Volcan/
- https://omegaup.com/arena/problem/Intersecciones/
- https://omegaup.com/arena/problem/L-OMI-Super-Agente/

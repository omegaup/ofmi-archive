# Michmo Boll - Solución

## Subtarea 1. (Tiro horizontal)

En esta subtarea la pendiente con la que Michmo tira la micro-papa es 0, por lo que es un tiro horizontal. Su tiro sólo será válido si tira desde una posición con un valor de $P$ entre 0 y $M$ para que este dentro de la mesa.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2. (Nunca falla el tiro)

En este caso no tenemos que preocuparnos por checar si el tiro es válido o no, sólo enfocarnos en regresar la micro-papa con éxito.

Hay que tener cuidado de la pendiente con la que regresamos la micro-papa. No siempre se puede regresar con la misma pendiente de Michmo, ya que no hay garantía que haya pasado por su zona, y aunque lo haya hecho, cuando la micro-papa llega a la columna $N$ se redondea su valor y posiblemente baja un poco, en algunos casos lo suficiente para no tocar la zona de Michmo de regreso.

Hay varias estrategias para determinar qué pendiente sería un tiro válido, la que optamos en nuestras soluciones fue elegir alguna esquina o punto fijo de la zona de Michmo, y cálcular la pendiente de la siguiente forma:

> Si el punto fijo que elegimos es $(x, y)$ y la micro-papa la devolvemos desde $(N, p)$, entonces la pendiente debe ser (p - y) / (N - x)

Podemos dirigir la micro-papa al punto $(0, 0)$ y nuestra llamada para hacer un tiro válido sería `devolver(p, p, N)`.

La siguiente solución manda la micro-papa a $(0, 1)$, por eso llama con los parámetros `devolver(p, p - 1, N)`.

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3. (Dentro de la mesa)

En esta subtarea hay que observar que, para que Michmo tenga un tiro válido, al momento de pasar por la red ($x = N/2$), la micro-papa debe pasar sí o sí entre 0 y $M$, de caso contrario, nunca entrará a tu zona personal. Después de haber determinado si fue un tiro válido o no, podemos usar el algoritmo de la subtarea anterior para regresar la micro-papa con éxito.

<details><summary>Solución subtarea 3</summary>

{{sub3.cpp}}

</details>

## Subtarea 4.

En la subtarea 3 analizamos uno de los posibles casos en los que podríamos recibir la micro-papa. Los casos que quedan son si Michmo hace su lanzamiento desde $(0, P)$ con $P > M$ o con $P < 0$.

- Si $P > M$, basta con checar si pasa por los segmentos que conectan $(N/2, 0)$ con $(N/2, M)$ y $(N/2, M)$ con $(N, M)$.
- Si $P < 0$, basta con checar si pasa por los segmentos que conectan $(N/2, 0)$ con $(N/2, M)$ y $(N/2, 0)$ con $(N, 0)$.

Hay varias formas de checar si la micro-papa pasa por esos segmentos, para la solución de este problema, aprovechamos que las rectas son horizontales. Para checar si la micro-papa pasa por el segmento que conecta $(N/2, M)$ con $(N, M)$, podemos observar que debe ser de la forma $(x, M)$. Entonces, si la pendiente es $m = A / B$, el valor de $x$ se puede calcular de la siguiente forma:

```
M = m * x + P
M - P = m * x
(M - P) / m = x
```

Y así, solo hay que checar que $(M - P) / m$ está entre $N / 2$ y $N$.

De manera similar, se puede probar que la micro-papa pasa entre $(N/2, 0)$ y $(N, 0)$ si $-P / m$ está entre $N / 2$ y $N$.

<details><summary>Solución completa</summary>

{{solutionB.cpp}}

</details>

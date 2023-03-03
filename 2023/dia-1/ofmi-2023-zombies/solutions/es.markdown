# Zombies contra plantas - Solución

## Subtarea 1 ($d = 1$).

Para esta subtarea, debemos observar que cada uno de los $n$ zombies lo atacaremos exactamente el número de veces de su vida; por lo que por cada zombie con $a_i$ de vida, necesitaremos $a_i - 1$ escudos.

Por lo tanto, la solución es iterar sobre los $n$ zombies e imprimir la suma acumulada de $a_i - 1$.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2 ($n = 1$).

Para esta subtarea, debemos encontrar la forma de saber ahora cuántos escudos ocuparemos con un solo zombie de vida $a$. Hay dos formas de hacerlo, la primera es simulando disparo tras disparo.

<details><summary>Solución subtarea 2 simulado</summary>

{{sub2.cpp}}

</details>

La otra manera es darse cuenta que exactamente ocuparemos $(a - 1) / d$ escudos.

## Subtarea 3

Esta subtarea se logra combinando la subtarea 1 con la subtarea 2 simulada. En lugar de sumar $a_i - 1$ (los escudos que ocuparíamos si $d = 1$), simulamos disparo tras disparo y contamos los escudos zombie por zombie.

## Subtarea 4

Para obtener el puntaje completo, se necesita saber que el $i$-ésimo zombie nos hará gastar $(a_i - 1) / d$ escudos. Por lo tanto, la solución completa es iterar sobre los $n$ zombies e imprimir la suma acumulada de $(a_i - 1) / d$.

<details><summary>Solución</summary>

{{solution.cpp}}

</details>

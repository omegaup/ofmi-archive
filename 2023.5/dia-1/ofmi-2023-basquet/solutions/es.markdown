Este problema nos pide seleccionar, de entre $5$ números diferentes, $3$ cuya suma sea igual a $100$.

Si nombramos a los $5$ números de la entrada como $a, b, c, d$ y $e$, tenemos $10$ maneras diferentes de seleccionar la suma de tres de ellos:

- $a + b + c$
- $a + b + d$
- $a + b + e$
- $a + c + d$
- $a + c + e$
- $a + d + e$
- $b + c + d$
- $b + c + e$
- $b + d + e$
- $c + d + e$

Entonces, una forma de resolver el problema es calcular estas $10$ sumas y verificar si alguna de ellas es igual a $100$. El siguiente código implementa dicha idea.

<details><summary>Solución verificando las 10 sumas diferentes</summary>

{{solution.cpp}}

</details>

Una alternativa para resolver este problema es, en lugar de guardar los cinco números de la entrada como cinco variables distintas, guardarlos a todos en un arreglo, `playeras`, de tamaño $5$.

Si guardamos los números en las playeras de esa forma, encontrar $3$ de ellos que sumen $100$ equivale a encontrar $3$ índices distintos, $i, j, k$, uno para cada playera a elegir, que cumplan que `playeras[i] + playeras[j] + playeras[k] = 100`. Esto se puede lograr usando tres _fors_ anidados para iterar sobre todas las ternas $i, j, k$ posibles. El siguiente código implementa dicha solución.

<details><summary>Solución guardando los valores en un arreglo</summary>

{{solutionB.cpp}}

</details>

Nota que ambas soluciones prueban todas las formas posibles de seleccionar $3$ números distintos de entre los $5$ que son dados en la entrada, pero la primera solución guarda los números en $5$ variables diferentes mientras que la segunda solución los guarda en un arreglo.

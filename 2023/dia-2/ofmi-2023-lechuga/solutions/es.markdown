# Encuentra la lechuga - Solución

## Subtarea 1 (El huerto no ha sido invadido por la PRU)

Dado que la PRU no sé ha apoderado de casillas en el huerto y que las cobayas solamente se pueden mover a la izquierda, derecha, arriba o abajo por cada segundo que pase, la cantidad mínima de segundos entre cada cobaya y la lechuga será el valor absoluto de la posición $(i, j)$ de cada cobaya menos la posición $(x, y)$ de la lechuga. Notando lo anterior, si se guardan los segundos en que se tarda cada cobaya al llegar a la lechuga en una lista, se pueden ordenar las llegadas de manera ascendente, para entonces por medio de un while recorrer el arreglo hasta que, o bien ya no haya más lechuga que comer, o bien todas las cobayas hayan llegado. Y finalmente imprimir cuáles cobayas comerán y cuáles no.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2 (Solución)

Para resolver el problema completo basta notar que dado que la PRU ya ha invadido el huerto, entonces para encontrar los segundos que tarda una cobaya para llegar a la lechuga, es necesario usar el algoritmo BFS empezando de la lechuga a todas las casillas del huerto, lo cual nos dará la cantidad mínima de segundos a cada casilla del huerto. Por medio de un condicional se agrega la cantidad mínima de segundos en las casillas donde haya cobayas a una lista y aplicamos el mismo algoritmo de la _Subtarea 1_ para encontrar cuáles cobayas comerán y cuáles no.

<details><summary>Solución</summary>

{{solution.cpp}}

</details>

Las cobayas agricultoras han plantado una gran lechuga en una de las casillas de su huerto rectangular de $N \times M$ casillas, además, cada cobaya tiene su casita en uno de estos espacios. Sin embargo, la Pandilla de Ratas Unidas (PRU) se ha apoderado de algunas casillas; para evitar problemas las cobayas han decidido no pasar por allí.

Las cobayas están hambrientas por lo que han decidido salir de sus casitas para comer la gran lechuga, en cada casita vive solamente una cobaya. En el segundo $0$, todas las cobayas se encuentran dentro de sus casitas. Posteriormente, en cada segundo las cobayas se pueden mover una casilla, ya sea a la izquierda, a la derecha, arriba o abajo. Una vez que una cobaya llega a la gran lechuga, después de un segundo empieza a comer una unidad de la gran lechuga por cada segundo que pase.

En caso de que hayan múltiples cobayas en la casilla de la gran lechuga y no alcance lechuga para todas en el mismo lapso de tiempo, al momento de comer, las cobayas se organizarán para darle prioridad a las cobayas que no hayan comido aún. Además, es posible que cuando llegue cualquier cobaya a la gran lechuga ya no alcance a comer, pues sus amigas cobayas ya se habrán terminado la gran lechuga. Suponiendo que las cobayas se mueven de forma óptima, es decir, siempre buscarán llegar en el menor tiempo posible a la gran lechuga, ¿cuántas cobayas no comerán por lo menos una unidad de la gran lechuga?

# Entrada

En la primera línea dos enteros separados por un espacio, $N$ y $M$, que representan la cantidad de filas y columnas del huerto, respectivamente.

En las siguientes líneas, una matriz de $N \times M$ enteros separados por un espacio que representan la configuración inicial del huerto.

- Las casillas libres se representan con un 0.
- Las casillas de la PRU se representan con un -1.
- Las casitas se representan con un 1.
- La gran lechuga se representa con un número $S \geq 2$ (Donde $S$ es la cantidad de unidades que tiene la gran lechuga).

# Salida

Imprime el número de cobayas que no alcanzan a comer lechuga.

# Ejemplo

||examplefile
sample
||examplefile
sample1
||examplefile
sample2
||end

# Límites

- $2 \leq N, M \leq 1,000$
- $2 \leq S \leq 10^6$

# Subtareas

- **Subtarea 1 (25 puntos) agrupados:**
  - La matriz no contiene $-1$.
- **Subtarea 2 (75 puntos) agrupados:**
  - Sin consideraciones adicionales.

---

![](lechuga.jpeg 'Cobayas agricultoras.')

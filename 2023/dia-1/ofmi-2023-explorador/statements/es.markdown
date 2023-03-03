Mich es un gran explorador. El día de hoy se ha propuesto encontrar la legendaria Zanahoria de Jade, una reliquia que según las leyendas traerá prosperidad a las cosechas de ricas verduras. Para lograrlo se ha adentrado en las ruinas de Cuytlán, una antigua civilización agrícola y próspera, pero el tramo final para alcanzar la Zanahoria de Jade es una trampa.

La trampa consta de una habitación rectangular donde el piso está recubierto con baldosas cuadradas, donde cada baldosa muestra una flecha apuntando en una de las cuatro direcciones Norte, Sur, Este u Oeste hacia otra baldosa o hacia la pared de la habitación. Mich puede saltar entre baldosas contiguas, pero si está en una baldosa y salta en una dirección distinta a la que apunta, la salida se cerrará y solo le quedará volver por donde vino, sin la anhelada zanahoria mítica.

Afortunadamente hay una alternativa, ya que en su trayecto Mich puede dejar caer una moneda de oro sobre la baldosa en la que se encuentra, esto le permitirá cambiar la dirección a la que apunta a cualquiera de las cuatro posibles. Nuestro explorador ya prevenía algo como esto así que carga con suficientes monedas de oro para hacer este cambio de dirección las veces necesarias. Aun así le gustaría gastar la menor cantidad posible, para poder celebrar al máximo regresando de su aventura.

Considerando que Mich inicia en la esquina inferior izquierda de la habitación, y la salida se encuentra en la esquina superior derecha, ayuda a Mich a alcanzar la salida gastando la menor cantidad de monedas de oro posible.

# Entrada

En la primera línea dos números $N$ y $M$, el largo y ancho de la habitación.

En las siguientes $N$ líneas, $M$ números que indican la dirección a la que apunta cada baldosa: `0` para Norte, `1` para Este, `2` para Sur y `3` para Oeste.

# Salida

En la primera línea imprime un número, la menor cantidad de monedas de oro que necesita Mich.

En las siguientes $N$ líneas, $M$ números que indican la dirección a la que apunta cada baldosa al final del recorrido de Mich, recuerda que el recorrido es tal que gasta la mínima cantidad de monedas de oro. Usa `0` para Norte, `1` para Este, `2` para Sur y `3` para Oeste. En caso de existir más de una solución válida, puedes imprimir cualquiera.

# Ejemplos

||examplefile
sample
||description
Inicialmente no se puede ir de la esquina inferior izquierda a la superior derecha, por lo que al menos será necesario hacer una modificación. Como se puede observar en la salida solo se hizo una modificación y es por esto que es lo mínimo posible.

Nota que la siguiente modificación también cumple con lo que pide el problema, por lo que ambas son aceptadas

```
1 1 2

0 1 0
```

||examplefile
sampleNoMinPath
||end

# Límites

- $1 \leq N, M \leq 500$

# Subtareas

- **Subtarea 1 (5 puntos) agrupados:**.
  - Se cumple que $N = 1$.
- **Subtarea 2 (10 puntos) agrupados:**.
  - Debes determinar si es posible llegar sin hacer modificaciones. En la primera línea debes imprimir $0$ de ser posible o $-1$ en caso contrario. No es necesario que imprimas la habitación. En caso de que se deban cambiar baldosas e imprimes la cantidad correcta de baldosas a cambiar y el tablero modificado, se te darán los puntos de esta subtarea.
- **Subtarea 3 (85 puntos):**
  - Sin consideraciones adicionales.

---

![](explorador.jpeg 'Mich explorador.')

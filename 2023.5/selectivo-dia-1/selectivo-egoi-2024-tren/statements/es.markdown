¡La delegación mexicana, lista para su participación en la EGOI 2024, ha aterrizado en Ámsterdam! Para transportarse a Eindhoven, sede de la EGOI, deben abordar un tren.

Este importantísimo día, en la estación de trenes de Ámsterdam solo hay delegaciones de partipantes de la EGOI. Cada hora sale un tren con dirección a Eindhoven y cada tren tiene capacidad para transportar a lo más a $C$ delegaciones.

Para cada una de las siguientes $N$ horas, numeradas de $1$ a $N$, se conoce cuántas delegaciones llegan a la estación de trenes durante dicha hora. Es decir, para cada hora $i$, $1 \leq i \leq N$, se conoce el valor $A_i$: el número de delegaciones que llegan a la estación durante la hora $i$. Cuando un tren llega a la estación, al final de la $i$-ésima hora, abordan $C$ delegaciones que en ese momento se encuentren en la estación. Si en la estación hay menos de $C$ delegaciones, todas ellas abordan el tren. Si no hubiera delegaciones en la estación, el tren parte vacío. Además, si una delegación no alcanza a subir al tren, permanecerá en la estación hasta que logre abordar un tren.

La delegación mexicana no ha decidido en qué momento llegar a la estación. Como son muy amables, han acordado que si llegan a la estación en la hora $i$ dejarán que primero aborden todos las delegaciones que llegaron en horas anterios y también las que llegaron en la hora $i$. Acordaron además que solo están dispuestas a esperar en la estación hasta la $N$-ésima hora. Les gustaría entonces saber, para cada hora $i$, cuántas horas deberían esperar para abordar el tren en caso de llegar a la estación en la $i$-ésima hora o si no sería posible abordar el tren a lo más en la hora $N$.

# Problema

Dado $N$, el número de horas, y la cantidad de delegaciones que llegan a la estación durante cada hora, deberás indicar, para cada hora $i$, $1 \leq i \leq N$, cuántas horas debería esperar la delegación mexicana para abordar suponiendo que llegaran a la estación en la hora $i$. Si para una determinada hora de llegada la delegación mexicana debería esperar en la estación hasta después de la hora $N$, deberás imprimir `-1`.

# Entrada

En la primera línea dos enteros $N$ y $C$, el número de horas y la capacidad de los trenes, respectivamente.

En la segunda línea $N$ enteros $A_i$ separados por un espacio, donde el $i$-ésimo entero indica la cantidad de delegaciones que llegan a la estación en la $i$-ésima hora.

# Salida

Deberás imprimir $N$ enteros separados por espacio. El $i$-esimo entero representa la cantidad de horas que la delegación mexicana tienen que esperar en la estación para tomar un viaje si suponemos que las chicas llegan en la hora $i$, o `-1` en caso de que sea imposible tomar un viaje.

# Ejemplo

||examplefile
sub2.sample
||description

Se tiene información para $5$ horas, y los trenes tienen capacidad para transportar a $4$ delegaciones.

- Si la delegación mexicana llega en la hora $1$, dejarán viajar primero a las $8$ delegaciones que llegaron también en la hora $1$. Dada la capacidad del tren, $4$ de ellas abordan en la hora $1$ y las otras $4$ en la hora $2$. La delegación mexicana aborda en la hora $3$, por lo que esperaron $2$ horas.

- Si la delegación mexicana llega en la hora $2$, entonces dejarán viajar primero a las $8$ delegaciones que llegaron en la hora $1$ y las $3$ delegaciones que llegaron en la hora $2$. $4$ de ellas abordan en el la hora $1$, otras $4$ en la hora $2$, y en la hora $3$ pueden abordar las $3$ delegaciones faltantes y también la delegación mexicana. La delegación mexicana aborda en la hora $3$, por lo que esperaron $1$ hora.

- Si la delegación mexicana llega en la hora $3$, entonces viajarán en la hora $5$. Por lo que esperaron $2$ horas.

- Si llegan en la hora $4$, no alcanzarán a abordar.

- Si llegan en la hora $5$, tampoco alzanzan a abordar.
  ||end

# Límites

- $1 \leq N \leq 10^5$
- $1 \leq C \leq 10^9$
- $0 \leq A_i \leq 10^9$

# Subtareas

- **Subtarea 1 (8 puntos):**
  - $N = 1$.
- **Subtarea 2 (22 puntos):**
  - $N, C, A_i \leq 1,000$.
- **Subtarea 3 (23 puntos):**
  - $C = 1$.
  - $A_i \leq 1,000$.
- **Subtarea 4 (47 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![Tren expreso](trenexpres.jpg 'Tren expreso.')

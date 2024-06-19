En el día de paseo de la EGOI se organizó una visita al museo de la ciudad. Las $N$ competidoras se formaron en una fila para entrar al museo. Sin embargo, muchas de ellas no estaban conformes con su posición en la fila y decidieron intercambiar lugares con otras competidoras.

Cada competidora tiene exactamente dos pulparindos que puede usar para intercambiar su lugar con la persona que está **justo detrás** de ella. Esto es, la persona en la posición $i < n$ puede darle uno de sus pulparindos a la persona en la posición $i+1$ e intercambiar su lugar con ella. Una competidora solo puede dar los pulparindos que tenía al inicio, no puede dar los que haya recibido de otras personas, pues saben que no se regala lo que te regalan.

# Problema

Dado $n$ y la posición deseada de cada competidora, determina la mínima cantidad de pulparindos necesarios para que todas las competidoras estén en la posición deseada. Si no es posible, imprime `-1`.

# Entrada

En la primera línea un entero $N$ que representa la cantidad de competidoras.

En las siguiente línea vendrán $N$ enteros separados por espacios $p_i$ que representa que la competidora en la posición inicial $i$ desea estar en la posición $p_i$.

# Salida

La mínima cantidad de pulparindos necesarios. En caso de que no se pueda, imprimir `-1`.

# Ejemplo

||examplefile
sub2.sample
||description
La fila inicialmente se encuentra ordenada $[2, 1, 5, 3, 4]$.

La competidora que quiere estar en la posición $2$ puede usar un pulparindo para intercambiar lugar. El orden ahora es $[1, 2, 5, 3, 4]$.

La competidora que quiere estar en la posición $5$ puede usar un pulparindo para intercambiar lugar. El orden ahora es $[1, 2, 3, 5, 4]$.

La misma competidora puede usar su segundo pulparindo para intercambiar lugar. El orden ahora es $[1, 2, 3, 4, 5]$.

Todas las competidoras están en la posición deseada y se necesitaron $3$ pulparindos.
||examplefile
sub3.sample
||description
La fila inicialmente se encuentra ordenada $[2, 5, 1, 3, 4]$.

No hay manera que la competidora que quiere estar en la posición $5$ pueda llegar a su posición final con los dos pulparindos que tiene. Por lo que es imposible obtener el arreglo final.
||end

# Límites

- $1 \leq N \leq 10^5$
- $1 \leq p_i \leq n$. Todas las $p_i$ son distintas.

# Subtareas

- **Subtarea 1 (6 puntos):**
  - $N \leq 3$
- **Subtarea 2 (41 puntos):**
  - $N \leq 1000$
- **Subtarea 3 (53 puntos):**
  - Sin consideraciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![Museo](museo.jpg 'Museo.')

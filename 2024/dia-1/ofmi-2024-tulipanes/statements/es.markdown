En la tierra más allá del arcoíris existe un campo hermosísimo lleno de tulipanes de varios colores, acomodados en una cuadrícula de $n$ filas y $m$ columnas de tulipanes, habiendo un tulipán en cada posición.

Este tipo de tulipanes ha causado el surgimiento de un tipo muy especial de abejitas tulipanésticas que solo se alimentan de estos tulipanes.

El campo de tulipanes donde las abejitas tulipanésticas irán en busca de polen está representado por una matriz $C$ de $n$ filas y $m$ columnas, donde $C_{i,j}$ es el color del tulipán en la $i$-ésima fila y la $j$-ésima columna. Basándose en esta información, la colmena identifica el color de tulipán más abundante y determina una [submatriz](https://omegaup.com/docs/Glosario-OFMI.pdf) del campo que abarcará todas los tulipanes de ese color para extraer el polen.

Para la recolección, se asignará una abejita a cada tulipán dentro de la submatriz, asegurándose de que cada tulipán sea visitado por exactamente una abejita y que ésta recolecte el polen del tulipán asignado. El polen recolectado de tulipanes que no correspondan al color más abundante será desechado.

El objetivo de las abejitas es encontrar la submatriz que minimice la cantidad de polen desechado mientras recolectan todo el polen de los tulipanes del color más abundante. Si existen varios colores con la misma abundancia máxima, elegirán aquel cuya submatriz genere el menor desecho de polen. En caso de que dos submatrices generen la misma cantidad de desecho, pueden escoger cualquiera de ellas.

La encargada de formar la comitiva de abejitas tulipanésticas ha escuchado de un grupo de sabias en la tierra más acá del arcoíris, así que ha decidido pedirles ayuda. Por supuesto, tú eres una de las sabias.

# Problema

Dados $n$, $m$ y una matriz $C$ de $n$ filas y $m$ columnas, donde $C_{i,j}$ representa el color del tulipán en la fila $i$ y la columna $j$, determina la mínima cantidad de tulipanes cuyo polen será desechado.

Debes ayudar a las abejitas a elegir una submatriz que contenga todos los tulipanes del color más abundante, minimizando la cantidad de tulipanes de otros colores dentro del área seleccionada.

Si hay varios colores que sean los más abundantes, debes elegir el que genere el menor desecho de polen. En caso de que existan múltiples submatrices que minimicen el polen desechado, cualquiera que elijas es válida.

# Entrada

En la primera línea dos enteros $n$ y $m$ que representan la cantidad de filas y columnas respectivamente en el campo de tulipanes.

En cada una de las siguientes $n$ líneas vendrán $m$ enteros separados por espacios, donde cada entero $C_{i, j}$ representa el color del tulipán en la fila $i$ y columna $j$.

# Salida

Deberás imprimir un solo entero, el mínimo número de tulipanes cuyo polen será desechado.

# Ejemplo

||examplefile
sub2.sample
||description
El color de tulipanes más abundante es el $1$.

Si las abejitas van por la submatriz delimitada por $(1, 2)$ (primera fila, segunda columna) y $(4, 7)$ (cuarta fila, última columna) recolectarían polen de todos los tulipanes de ese color y únicamente habría $8$ tulipanes cuyo polen se tirará.
||examplefile
sub4.sample
||description
Los colores más abundantes son tanto el $1$ como el $3$, entonces podemos elegir cualquiera para recolectar.

Si las abejitas van por el color $3$ y recolectan polen de la submatriz delimitada por $(1, 1)$ y $(3, 2)$ habrán recolectado polen de todos los tulipanes de color $3$ sin que ninguna abejita recolecte polen que se tirará.
||end

# Límites

- $1 \leq n, m \leq 1,000$.
- $1 \leq C_{i, j} \leq 10^6$

# Subtareas

- **Subtarea 1 (17 puntos):**
  - Se te asegura que ningún color aparecerá más de $2$ veces.
  - $1 \leq n, m \leq 10$.
- **Subtarea 2 (18 puntos):**
  - Se te asegura que el color $1$ es el único color más abundante.
- **Subtarea 3 (30 puntos):**
  - $n = 1$.
- **Subtarea 4 (35 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![](tulipanes.jpeg 'Abejitas tulipanésticas en busca de polen.')

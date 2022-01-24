Andrea Parker es una estudiante de preparatoria que constantemente se ve involucrada en salvar al mundo de terribles amenazas. Después de un largo tiempo de paz y sin señales aparentes de villanos, Andrea Parker consigue un trabajo los fines de semana para ganar un poco de dinero extra. Su trabajo consiste en pasear las adorables cobayas de sus vecinos. Dada la popularidad de Andrea Parker en la ciudad, se ha hecho de muchas amistades en los últimos meses, por lo que para facilitarse el trabajo decide pedirles ayuda.

Se deben pasear una cantidad $N$ de cobayas, cada cobaya tiene un tamaño $T_i$.

Andrea decide distribuir las $N$ cobayas entre sus $K$ amistades (así es, Andrea no paseará ninguna cobaya). La distribución será de tal forma que cada una de sus $K$ amistades pasee un grupo de cobayas.

En cada grupo debe haber al menos una cobaya y cada cobaya solo puede estar en un grupo.

El ‘costo’ de pasear cada grupo de cobayas se determina por el $T_i$ más grande del grupo, menos el $T_i$ más pequeño del grupo.

# Problema

Ayuda a Andrea Parker a distribuir las cobayas tal forma que la suma de los costos de los $K$ grupos sea la menor posible.

# Entrada

- En la primera línea dos enteros separados por un espacio, $N$ y $K$ que representan la cantidad de cobayas que hay que pasear y la cantidad de amistades que tiene Andrea, respectivamente.

- En la segunda línea $N$ enteros separados por un espacio que representan los tamaños $T_i$ de cada cobaya.

# Salida

Un número entero, la menor suma de los costos de los grupos que puede ser formada.

# Ejemplo

||examplefile
sample
||description
La mejor forma de distribuir las cobayas entre sus dos amistades es en un grupo con {3, 1, 3} y otro con {6, 8}. Con esta distribución el costo total de pasear a los grupos de cobayas será de (3 - 1) + (8 - 6) = 4.
||end

# Límites

- $1 \leq K \leq N \leq 100,000$
- $1 \leq T_i \leq 10^9$

# Subtareas

- **(20 puntos):** $K = 2$
- **(20 puntos):** $K = 3$
- **(20 puntos):** $1 \leq N \leq 20$
- **(40 puntos):** No hay consideraciones adicionales.

---

![](cobaya.jpeg)

<figcaption align = "center"><i>Las cobayas son delicadas, por lo que hay que tener especial cuidado si las vas a sacar a pasear.</i></figcaption>

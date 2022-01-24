Karel ha decidido hacer una subasta de uno de sus trajes de Spiderman y las cobayas (que acaban de ver la película) quieren ganar el traje. Pero a Karel le molesta un poco el ruido que hacen las cobayas, así que te pidió que lleves a cabo la subasta y le digas cuál cobaya fue la que ganó.

Las cobayas harán pujas una por una durante la subasta, una puja es la oferta de dinero que hace un participante en una subasta. Para que la puja de una cobaya sea válida debe ser mayor o igual a la suma de las últimas dos pujas válidas. La última puja válida es la ganadora.

# Problema

Dadas las pujas de las cobayas en el orden en que las hicieron, determina el índice de la cobaya ganadora.

Nota: Al inicio de la subasta, considera la mejor y segunda mejor puja válida como 0.

# Entrada

- En la primera línea el entero $N$, el número de cobayas en la subasta.

- En la segunda línea $N$ enteros separados por un espacio: $a_1$, $a_2$, $\ldots$, $a_N$. Cada $a_i$ representa la puja de la cobaya en la $i$-ésima posición.

# Salida

El índice de la cobaya que ganó la subasta. Dicho de otra forma, el índice de la última puja válida.

# Ejemplo

||examplefile
sample
||description
La cobaya 5 hizo la última puja válida, pues la cobaya que pujó 7 no alcanzó a rebasar 3 + 5.
||end

# Límites

- $1 \leq N \leq 100,000$
- $1 \leq a_i \leq 10^9$

# Subtareas

- **(15 puntos):** $N \leq 3$
- **(25 puntos):** Se te asegura que si la puja es mayor a la última puja válida, entonces también es mayor o igual a la suma de las últimas dos pujas válidas.
- **(60 puntos):** No hay consideraciones adicionales.

---

![Spidercobaya](spidercobaya.jpg)

<figcaption align = "center"><i>Imagen confidencial filtrada de la posible identidad de la cobaya ganadora.</i></figcaption>

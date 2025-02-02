Inés, la ciempiés que camina al revés, compró unos bonitos zapatos cafés para reemplazar algunos de sus zapatos rotos.

Una característica muy interesante y bonita de las ciempiés como Inés es que sus pies son de varios tamaños, y los pies del mismo lado (derecho o izquierdo) van creciendo de adelante hacia atrás.

Otra característica muy fascinante de las ciempiés como Inés es que en sus pies izquierdos solamente usan zapatos de talla par, y en sus pies derechos solamente usan zapatos de talla impar.

Por lo anterior, antes de ponerse zapatos nuevos Inés siempre los acomoda en una fila donde primero coloca los zapatos de talla par de forma no decreciente, y enseguida hace lo mismo con los zapatos de tamaño impar.

Una fila está ordenada de forma no decreciente si cada elemento es mayor o igual al anterior. Por ejemplo, el arreglo [1, 2, 4, 5, 5, 9, 17] está ordenado de forma no decreciente, mientras que el arreglo [1, 2, 1, 5, 5, 9, 8] no lo está.

Al estar demasiado emocionada con sus nuevos zapatos como para concentrarse en acomodarlos, Inés ha pedido que alguien le ayude con esta tarea, ofreciendo a cambio algo a lo que llama "puntos para el examen de la OFMI".

# Problema

Dada una lista de $n$ números, representando las tallas de los zapatos que compró Inés, haz un programa que imprima la lista con los mismos números, pero que aparezcan primero de izquierda a derecha las tallas pares de forma no decreciente, y después las impares de forma no decreciente.

# Entrada

En la primera línea un entero $n$, la cantidad de zapatos por acomodar.

En la segunda línea $n$ enteros, donde el $i$-ésimo número $A_i$ representa la talla del $i$-ésimo zapato.

# Salida

Deberás imprimir $n$ enteros separados por espacios, las tallas de los zapatos acomodados de la forma que se pide.

# Ejemplo

||examplefile
sub3-sample
||end

# Límites

- $1 \leq n \leq 2 \times 10^5$.
- $1 \leq A_i \leq 10^9$.

# Subtareas

- **Subtarea 1 (20 puntos):**
  - $A_i$ es par para toda $1 \leq i \leq n$.
  - $1 \leq n \leq 1,000$.
  - $1 \leq A_i \leq 1,000$.
- **Subtarea 2 (20 puntos):**
  - $A_i \leq A_j$ para toda $1 \leq i < j \leq n$.
  - $1 \leq n \leq 1,000$.
  - $1 \leq A_i \leq 1,000$.
- **Subtarea 3 (40 puntos):**
  - $1 \leq n \leq 1,000$.
  - $1 \leq A_i \leq 1,000$.
- **Subtarea 4 (20 puntos):**
  - Sin restricciones adicionales.

**Nota:** Las subtareas no estarán agrupadas.

---

![](ines.jpeg 'Inés, la ciempiés que camina al revés.')

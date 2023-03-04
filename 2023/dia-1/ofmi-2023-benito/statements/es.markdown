Benito es el conejo más famoso del mundo debido a su exitosa carrera como cantante.

Tras acabar su más reciente gira _Un saltito sin ti_ , Benito se dispone para regresar a su madriguera con el objetivo de comer la zanahoria más grande de su huerto.

Sin embargo, la fama le cobró factura, por lo que Benito únicamente come zanahorias que hayan crecido en un huerto con forma de espiral; de otra forma Benito se enoja y se vuelve un conejo malo.

Se dice que un huerto tiene forma de espiral si:

1. Es una matriz cuadrada, de $n \times n$ con $n$ impar

2. Se cumplan alguna de las siguientes condiciones:

   - Es espiral de afuera hacia adentro. Esto es, el borde del cuadrado exterior de la matriz está compuesto exclusivamente por zanahorias de $1$ $mm$, mientras que el borde del cuadrado contenido dentro de este, contiene zanahorias de $2$ $mm$, y así sucesivamente hasta que solo llegar al cuadrado interior de $1 \times 1$ con el tamaño más grande de zanahoria.

   - Es espiral de adentro hacia afuera. Esto es, El borde del cuadrado exterior de la matriz, es del máximo tamaño posible para esa matriz de $n \times n$ y así va llegando hasta el interior con el cuadrado de $1 \times 1$ con zanahoria de $1$ $mm$.

![](huertoEspiral.png 'Ejemplo de huerto en espiral de adentro hacia afuera')

El programa debe ser capaz de identificar si la matriz es espiral o no.

Deberás imprimir el tamaño de la zanahoria más grande que haya en el huerto de Benito.

# Entrada

En la primera línea el entero $n$, que representa el tamaño de la matriz.

En cada una de las siguientes $n$ líneas vendrán $n$ enteros separados por un espacio que representa el tamaño de las zanahorias en milímetros.

# Salida

Imprime el tamaño de la zanahoria más grande en el huerto con forma de espiral.

En caso de que el huerto no tenga forma de espiral, imprime -1.

# Ejemplos

||examplefile
sample
||examplefile
sample1
||examplefile
sample2
||end

# Límites

- $1 \leq n \leq 800$. $n$ es impar.

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $1 \leq n \leq 3$.
- **Subtarea 2 (10 puntos):**
  - Se te asegura que la matriz siempre es espiral.
- **Subtarea 3 (20 puntos):**
  - Solo habrá matrices no espirales y espirales de afuera hacia adentro.
- **Subtarea 4 (20 puntos):**
  - Solo habrá matrices no espirales y espirales de adentro hacia afuera.
- **Subtarea 5 (40 puntos):**
  - Sin consideraciones adicionales.

---

![](benito.jpeg 'Benito, el conejo más famoso del mundo.')

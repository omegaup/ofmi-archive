En la escuela se te pidió exponer acerca de la evolución en procesamiento y memoria de las computadoras.

Has conseguido la información de $n$ computadoras y planeas hacer una presentación en donde presentes la mayor cantidad de computadoras, de tal forma que cada computadora que presentes deba ser estrictamente mejor tanto en procesamiento como en memoria. Además, la profesora te ha dicho que obligatoriamente debes comenzar exponiendo acerca de la computadora OFMI, cuyo procesamiento es de $p$ GHz (gigahertz) y tiene $m$ GB (gigabytes) de memoria.

Tu tarea es seleccionar la mayor cantidad de computadoras que puedas presentar.

# Implementación

Deberás implementar las función `computadoras(n, p, m, P, M)` y llamar a las función `presenta(identificador)`. Estos procedimientos son descritos a continuación.

# Tu función `computadoras`

`void computadoras(int n, int p, int m, int P[], int M[]);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el número de computadoras de las cuales tienes información (sin incluir la computadora OFMI).
- `p`: el procesamiento de la computadora OFMI.
- `m`: la memoria de la computadora OFMI.
- `P`: Un arreglo de $n$ enteros donde el $P_{i-1}$ es el procesamiento de la $i$-ésima computadora.
- `M`: Un arreglo de $n$ enteros donde el $M_{i-1}$ es la memoria de la $i$-ésima computadora.

Tu función deberá llamar a `presenta` la mayor cantidad de veces, en el orden en que vas a presentar cada computadora.

# Función del evaluador `presenta`

`bool presenta(int identificador)`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función con el identificador de la computadora a presentar, $0 \leq identificador \leq n$.
Deberás presentar la mayor cantidad de computadoras en orden de procesamiento y memoria crecientes.

**Nota**: Recuerda que siempre debes empezar presentando la computadora OFMI (representada con el identificador 0).

## Regresa

Esta función regresa verdadero si la computadora presentada cumple con que tenga mayor procesamiento y memoria que la última presentada. En caso contrario, o que no exista el identificador, regresara falso y obtendrás respuesta incorrecta.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
computadoras(5, 11, 9, [18, 23, 9, 3, 14], [18, 22, 11, 5, 16])
||output

- ||description
  El evaluador manda a llamar a tu función `computadoras`. Hay 5 computadoras, además de la computadora OFMI.
  ||input
  presenta(0)
  ||output
  true
  ||description
  La maestra te pide que empieces exponiendo con la computadora OFMI de 11 GHz y 9 GB. Tu función llama a `presenta`.
  ||input
  presenta(5)
  ||output
  true
  ||description
  Después expones acerca de la quinta computador, con 14 GHz y 16 GB.
  ||input
  presenta(1)
  ||output
  true
  ||description
  Después expones acerca de la primera computadora, con 18 GHz y 18 GB.
  ||input
  presenta(2)
  ||output
  true
  ||description
  Finalmente, expones acerca de la segunda computadora, con 23 GHz y 22 GB.
  Cuatro es la máxima cantidad de computadoras que puedes exponer.
  ||end

# Límites

- $1 \leq n \leq 5000$
- $1 \leq p, m \leq 10^6$
- $1 \leq P_i, M_i \leq 10^6$

Nota: Los casos están agrupados.

# Subtareas

- **Subtarea 1 (15 puntos):**
  - $n \leq 10$
- **Subtarea 2 (25 puntos):**
  - Todos los valores de $P_i$ son distintos entre sí.
  - $p$ es menor que cualquier $P_i$.
  - $m$ es menor que cualquier $M_i$.
- **Subtarea 3 (40 puntos):**
  - Todos los valores de $P_i$ son distintos entre sí. $p$ también es distinto a todo $P_i$
- **Subtarea 4 (20 puntos):**
  - Sin consideraciones adicionales.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea el enteros $n$. En la segunda línea los enteros $p$ y $m$. En cada una de las siguientes $n$ líneas vendrá una pareja de enteros $P_i$ y $M_i$.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
5
11 9
18 18
23 22
9 11
3 5
14 16
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

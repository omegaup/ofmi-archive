Randy es un entrenador de $N$ cobayas, las cuales saltan muy ordenadamente.

Randy logró entrenarlas para que cada cobaya salte de manera constante cada cierto tiempo. La primera salta cada $a_1$ segundos, la segunda salta cada $a_2$ segundos, la tercera salta cada $a_3$ segundos, así hasta la $N$-ésima cobaya, que salta cada $a_N$ segundos.

Las cobayas son veloces, y no demoran mucho en saltar. Cada cobaya se tarda a lo más $16$ segundos en saltar.

Cada año, la OFMI organiza un concurso de cobayas saltarinas, en la que Randy quiere inscribir a sus cobayas. Para poder participar le solicitan a Randy calcular las siguientes $Q$ cantidades:

- La menor cantidad $s_1$ de segundos que el equipo de $N$ cobayas saltarinas demora en realizar al menos $X$ saltos en total.
- La menor cantidad $s_2$ de segundos que el equipo de $N$ cobayas saltarinas demora en realizar al menos $2X$ saltos en total.
- ...
- La menor cantidad $s_Q$ de segundos que el equipo de $N$ cobayas saltarinas demora en realizar al menos $QX$ saltos en total.

Después de calcular los valores de $s_1, s_2, ..., s_Q$, Randy debe reportar la suma de estos bajo el módulo $10^9+7$ ($s_1 + s_2 + ... + s_Q$ mód $10^9 +7$).

En un principio, ninguna cobaya ha saltado. La $i$-ésima cobaya dará su primer salto en el segundo $a_i$.

# Problema

Ayuda a Randy a calcular los valores $s_1, s_2, ..., s_Q$ y su suma bajo el módulo $10^9+7$ para que sus cobayas puedan participar en la OFMI.

# Entrada

- En la primera línea un entero $N$ que representa la cantidad de cobayas que tiene Randy.

- En la siguiente línea, $N$ enteros separados por un espacio $a_1, a_2, ..., a_N$, representando el tiempo que tarda cada cobaya en volver a saltar.

- En la siguiente línea dos enteros, $Q$ y $X$, representando el número de categorias y el número de saltos que se describió, respectivamente.

# Salida

Deberas imprimir la suma de $s_1 + s_2 + ... + s_Q$ módulo $10^9 +7$.

# Ejemplo

||examplefile
sample
||description
En este caso de ejemplo tenemos que $Q$ = 3 y $X$ = 4. Por tanto, las preguntas a contestar serán:
4, 8 y 12.

Ya que queremos 4 saltos, vemos que con 4 segundos es suficiente, pues con 4 segundos brinca 2 veces la primera cobaya, 1 vez la segunda, y 1 vez la tercera. Por lo que brincan 4 veces. Con 3 segundos, esto ya no es posible.

Ya que queremos 8 saltos, vemos que con 8 segundos es suficiente, pues con 8 segundos brinca 4 veces la primera cobaya, 2 veces la segunda, 2 veces la tercera, y una vez la cuarta. Por lo que brincan 4 + 2 + 2 + 1 = 9 veces. Con 7 segundos, esto ya no es posible.

Ya que queremos 12 saltos, vemos que con 12 segundos es suficiente, pues con 12 segundos brinca 6 veces la primera cobaya, 4 veces la segunda, 3 veces la tercera, 1 vez la cuarta, y 1 vez la quinta. Por lo que brincan 6 + 4 + 3 + 1 + 1 = 15 veces. Con 11 segundos, esto ya no es posible.

Ya que nos piden la suma de las respuestas módulo $10^9+7$, la respuesta será $(4 + 8 + 12) \mod (10^9 + 7) = 24$.
||examplefile
sample2

||end

# Límites

- $1 \leq N \leq 10^5$
- $1 \leq Q \leq 10^6$
- $1 \leq X \leq 10^9$
- $1 \leq a_i \leq 16$ para toda cobaya, esto es, ninguna cobaya pasa más de 16 segundos sin saltar.

# Subtareas

- **(10 puntos):** $N \leq 100$, $Q \leq 1,000$, $X \leq 50$
- **(20 puntos):** $X = 1$
- **(20 puntos):** $N \leq 100$, $Q \leq 10,000$
- **(30 puntos):** $Q \leq 10,000$
- **(20 puntos):** No hay consideraciones adicionales.

# Consideraciones

Cada subtarea tiene todos sus casos agrupados.

# Nota

Se dice que _"$r$ es igual a $x$ bajo el módulo $y$"_ si _"$r$ es el residuo de dividir $x$ entre $y$"_.

---

![Dos cobayas de Randy](saltarinas.jpeg)

<figcaption align = "center"><i>Las cobayas de Randy.</i></figcaption>

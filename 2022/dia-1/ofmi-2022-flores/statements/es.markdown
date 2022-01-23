En tu camino hacia la EGOI 2022, descubres que el puente que lleva al edificio de la competencia quedó totalmente destruido. Lastimosamente, ese puente era la única manera de llegar ahí y tienes que encontrar otra manera de llegar rápido, ya que la competencia está por iniciar. Observando a tu alrededor, descubres que existe otro camino para llegar hacia el edificio, y está compuesto por múltiples flores gigantes cuadradas las cuales puedes saltar con facilidad.

Las flores todavía no han crecido totalmente, y si fuera aún peor, estas lo hacen extremadamente lento. Algunas de ellas, incluso tienen un límite de crecimiento y no pueden exceder de cierta longitud. Existe la posibilidad donde nunca puedas cruzar hacia el otro lado.

En tu camino hacia las flores, te encuentras un mapa cartesiano con las coordenadas del tallo de cada flor. Te puedes mover en las ocho direcciones. También, con tus altas capacidades de observación, notas que todas flores crecen a un ritmo constante y todas se expanden desde el centro del tallo. En un principio, ninguna flor ha crecido.

# Problema

Dadas las coordenadas en metros de cada uno de los tallos de las flores, y la coordenada de entrada y salida, debes determinar cuál es la minima cantidad de minutos para llegar de la entrada a la salida pisando en todo momento alguna flor (incluyendo en la entrada y en la salida).

Considera que en cada minuto todas las flores crecen $M$ metros hacia las cuatro direcciones salvo aquellas que hayan alcanzado su límite de crecimiento. El crecimiento de las flores es instantáneo al cambiar de minuto; es decir, no hay números decimales.

Para poder cruzar de una flor a otra, estas tienen que estar **totalmente** conectadas. Dos flores están totalmente conectadas si comparten al menos una esquina o un lado.

Desde el minuto cero se puede pisar el tallo de la flor.

# Entrada

- En la primera línea, dos números enteros $N$, $M$, que simbolizan el número de flores a cruzar, y el crecimiento en metros por minuto de cada flor, respectivamente.

- En la segunda línea, dos números que simbolizan las coordenadas de la entrada del puente.

- En la tercera línea, dos números que representan las coordenadas de la salida del puente.

- En las siguientes $N$ líneas vendrán dos números por línea que simbolizan las coordenadas $(x_i, y_i)$ de cada tallo.

- Por último, seguirán $N$ líneas con la longitud máxima de la planta $L_i$. Si $L_i = -1$ significa que esta flor no tiene límite de crecimiento.

# Salida

Un entero con la mínima cantidad de minutos que se necesita para poder cruzar hacia el edificio de la competencia. Si es imposible llegar al otro lado, imprime $-1$.

# Ejemplo

||examplefile
sample
||end

Observa con atención las imágenes para que veas cómo crecen las flores cada minuto.
![](flores_0.png)
![](flores_1.png)
![](flores_2.png)
![](flores_3.png)

# Límites

- $1 \leq N \leq 1,000$
- $0 \leq M \leq 100,000$
- Las coordenadas de la entrada, salida, y los tallos de las flores estarán entre $-100,000$ y $100,000$, inclusive.
- $-1 \leq L_i \leq 200,000$

# Subtareas

- **(10 puntos) no agrupados:** $N \leq 10$, además, las coordenadas de la entrada, salida, y los tallos de las flores estarán entre $0$ y $100$, inclusive.
- **(30 puntos) no agrupados:** El eje Y de la entrada, salida y flores será siempre $0$.
- **(20 puntos) agrupados**: Las flores no tendrán límite de crecimiento; es decir, $L_i = -1$.
- **(40 puntos) agrupados**: No hay consideraciones adicionales.

---

![](cobayas.jpeg)

<figcaption align = "center"><i>Se sospecha que el incidente del puente se debió a exceso de peso por tantas cobayas en él.</i></figcaption>

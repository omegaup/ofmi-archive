El Dr. Tapia era un científico brillante que buscaba la evolución de la raza humana. Desafortunadamente, un experimento para regenerar extremidades humanas salió mal y el Dr. Tapia terminó convirtiéndose en una poderosa cobaya. Desde entonces, su plan malvado es convertir a toda las personas en cobayas.

Spider-Juan quiere evitar a toda costa el plan de Dr. Tapia y lo ha seguido hasta la torre OFMI.

La torre OFMI es un edificio grande que tiene $n$ pisos con $m$ ventanas cada piso en forma de cuadrícula. Spider-Juan y Dr. Tapia se encuentran trepando y saltando entre las ventanas por el exterior del edificio en una peligrosa persecusión. Además, ambos pueden subir al techo del edificio desde el piso de hasta arriba, y desde el techo pueden bajar a cualquier ventana del último piso con un solo salto.

Cada que Spider-Juan se mueve un paso hacia alguna ventana o el techo de la torre, el Dr. Tapia se mueve un paso también. Sus movimientos son alternados.

# Problema

Dado el tamaño de la torre y las posiciones iniciales de ambos, ayuda a Spider-Juan a atrapar al Dr. Tapia.

La ventana de la esquina superior izquierda es la $(1, 1)$ y la ventana de la esquina inferior derecha es la $(n, m)$. El techo se representa como $(0, 0)$.

![Descripción gráfica de la torre OFMI](ejemplo_torre.png)

<figcaption align = "center"><i>Descripción gráfica de la torre OFMI.</i></figcaption>

# Implementación

Deberás implementar la función `juega(n, m, i_juan, j_juan, i_tapia, j_tapia)` que mande a llamar la función `mueve(i, j)` para mover a Spider-Juan hasta atrapar al Dr. Tapia. Estos procedimientos son descritos a continuación.

# Tu función `juega`

`void juega(int n, int m, int i_juan, int j_juan, int i_tapia, int j_tapia);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`, `m` representan el alto (filas) y ancho (columnas) de la torre, respectivamente.
- `i_juan` es la fila inicial de Spider-Juan. $0 \leq \texttt{i_juan} \leq n$.
- `j_juan` es la columna inicial de Spider-Juan. $0 \leq \texttt{j_juan} \leq m$.
- `i_tapia` es la fila inicial de Dr. Tapia. $0 \leq \texttt{i_tapia} \leq n$.
- `j_tapia` es la columna incial del Dr. Tapia. $0 \leq \texttt{j_tapia} \leq m$.

Dentro de esta función, deberás llamar a la función proporcionada `mueve(i, j)` para mover continuemente a Spider-Juan y saber hacia dónde se mueve Dr. Tapia. Nota que Spider-Juan se mueve primero.

# Función del evaluador `mueve`

`int mueve(int i_juan_nueva, int j_juan_nueva);`

## Descripción

El evaluador te proveerá con esta función. Llama a esta función cada que quieras mover a Spider-Juan hasta que hayas atrapado al Dr. Tapia.

## Parámetros

Llama a esta función con los parámetros de la nueva posición a la que se moverá Spider-Juan.

- (`i_juan_nueva`, `j_juan_nueva`) es la posición nueva a la que se mueve Spider-Juan. Deberás enviarle $(0,0)$ si se mueve al techo.

## Regresa

Al llamarla, esta función te regresará el movimiento del Dr. Tapia después de que Spider-Juan se haya movido, de la siguiente manera:

- si el Dr. Tapia no estaba en el techo regresa:
  - `1` si se mueve arriba.
  - `2` si se mueve abajo.
  - `3` si se mueve a la derecha.
  - `4` si se mueve a la izquierda.
- si el Dr. Tapia se encontraba en el techo, entonces su movimiento será bajar a la fila $1$ y la función regresa un número `j_tapia_nueva` entre $1$ y $m$ que representa la columna a la que se movió.
- regresa `0` si Spider-Juan atrapó en este movimiento al Dr. Tapia.
- regresa `-1` si el movimiento de Spider-Juan fue inválido.

![Movimiento normal](mov_normal.png)
![Movimiento desde el techo](mov_techo.png)
![Movimiento desde la base](mov_normal_2.png)

<figcaption align = "center"><i>Ejemplos de cómo Spider-Juan puede moverse en la torre OFMI.</i></figcaption>

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
juega(3, 3, 1, 1, 3, 2)
||output

- ||description
  Esta será la llamada inicial a tu procedimiento `juega`. La torre es de tamaño $3*3$, Spider-Juan empieza en la posición $(1, 1)$ y el Dr. Tapia en la posición $(3, 2)$.
  ||input
  mueve(2, 1)
  ||output
  3
  ||description
  Se manda a llamar `mueve`. Spider-Juan entonces se mueve a $(2, 1)$.

La función regresa $3$, que significa que el Dr. Tapia se mueve a la derecha. Por lo que ahora está en $(3, 3)$
||input
mueve(2, 2)
||output
1
||description
Spider-Juan se mueve a $(2, 2)$.

La función regresa $1$, que significa que el Dr. Tapia se mueve hacia arriba. Por lo que ahora está en $(2, 3)$
||input
mueve(2, 3)
||output
0
||description
Con esta llamada Spider-Juan se mueve a $(2, 3)$ y atrapa al Dr. Tapia. Así, la función regresa $0$ y con eso debes terminar ejecución.
||end

# Evaluación

Tu programa tendrá 0 puntos en el caso que algún movimiento de Spider-Juan sea inválido o jamás hayas logrado atrapar al Dr. Tapia. De lo contrario, tu puntuación dependerá de las siguientes subtareas.

# Subtareas

- **(20 puntos) no agrupados:**

  - $3 \leq n, m \leq 10$
  - Tu programa obtendrá todos los puntos de la subtarea si logras atrapar al Dr. Tapia.
  - El Dr. Tapia no se mueve óptimamente.

- **(40 puntos) agrupados:**

  - $10 < n, m \leq 1,000$
  - Tu programa obtendrá todos los puntos de la subtarea si logras atrapar al Dr. Tapia

- **(40 puntos) agrupados:**
  - $1,000 < n, m \leq 100,000$
  - Tu programa obtendrá todos los puntos de acuerdo al número de movimientos que haga Spider-Juan. Mientras menos movimientos, más puntos tendrás.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $n$, $m$ en la primera línea, $\texttt{i_juan}$, $\texttt{j_juan}$ en la segunda línea e $\texttt{i_tapia}$, $\texttt{j_tapia}$ en la tercera línea.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
3 3
1 1
3 2
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

---

![](https://c.tenor.com/XjNWme8fph0AAAAC/peachandgoma-peachmad.gif)

<figcaption align = "center"><i>Persecusión de Spider-Juan y Dr. Tapia representada con gatitos.</i></figcaption>

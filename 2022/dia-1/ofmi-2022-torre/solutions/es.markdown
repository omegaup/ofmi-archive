# Torre OFMI - Solución

## Primera observación

Vamos a ver una de las condiciones más importantes para que Spider-Juan pueda atrapar a Dr. Tapia. Observemos que, si la cantidad de pasos que Spider-Juan tiene que hacer para llegar con el Dr. Tapia es _par_, Spider-Juan nunca podrá alcanzar al Dr. Tapia por más cerca que este.

![Ejemplo de distancia par](cobaya_par_2.png)
![Ejemplo de distancia par](cobaya_par_1.png)

<figcaption align = "center"><i>Ejemplo de posiciones en donde Spider-Juan nunca podrá alcanzar a Dr. Tapia.</i></figcaption>

Esto es más fácil de ver si coloreamos de ajedrez (alternamos blanco y negro las posiciones); Si Dr. Tapia y Spider-Juan están en posiciones con el mismo color, Spider-Juan nunca podrá atrapar a Dr. Tapia.

![Coloreo de ajedrez](ajedrez.png)
![Coloreo de ajedrez](ajedrez_2.png)

<figcaption align = "center"><i>Coloreando de ajedrez las posiciones.</i></figcaption>

Para saber la distancia entre Spider-Juan y Dr. Tapia cuando ambos no estén en el techo, usaremos la [distancia manhattan](https://es.wikipedia.org/wiki/Geometr%C3%ADa_del_taxista):

```cpp
  int distancia_torre(int i_juan, int j_juan, int i_tapia, int j_tapia) {
      return std::abs(i_juan - i_tapia) + std::abs(j_juan - j_tapia);
  }
```

En caso de que la distancia entre Spider-Juan y Dr. Tapia sea par, el objetivo de Spider-Juan primero será cambiar la paridad, lo puede lograr subiendo al techo y bajando a otra columna.

## Subtarea 1

En esta subtarea, podemos aprovecharnos que Dr. Tapia no va a tomar la estrategia óptima y que sólo importa atraparlo. Eso sí, debemos checar la paridad de la distancia entre Spider-Juan y Dr. Tapia para que sea posible atrapar a la malvada cobaya. Por los movimientos aleatorios que hace Dr. Tapia, eventualmente podríamos atraparlo sin checar la paridad, pero habría que esperar mucho tiempo para que esto suceda y tendríamos _[TLE](https://www.instagram.com/p/CY2O6-BPDvA/)_.

- Si la distancia es par, debemos mover a Spider-Juan al techo. Si ya esta en el techo, podemos elegir la columna que más se acerque al Dr. Tapia.

```cpp
int columna_techo_Juan() {
    // Juan esta en (0, 0)
    if (distancia_torre(1, j_tapia, i_tapia, j_tapia) % 2 != 0) {
      // Hay que cambiar la paridad
      if (j_tapia != M) {
        i_juan = 1;
        j_juan = j_tapia + 1;
      } else {
        i_juan = 1;
        j_juan = j_tapia - 1;
      }
    } else {
      // Si podemos usar la columna
      i_juan = 1;
      j_juan = j_tapia;
    }
}
```

- Si la distancia es impar, podemos mover a Spider-Juan a la posición que más lo acerque al Dr. Tapia.

Esta estrategia no funcionaría si Dr. Tapia se mueve estratégicamente, pero al moverse de vez en cuando aleatoriamente, Spider-Juan podrá atraparlo.

<details><summary>Solución para la subtarea 1 (20 puntos)</summary>

{{subtask1_perseguir_greedy.cpp}}

</details>

## Subtarea 2

En esta subtarea el Dr. Tapia siempre se va a mover de forma estratégica, por lo que el plan planteado para la subtarea anterior no funcionaría en la mayoría de los casos.

Analicemos el siguiente caso particular en el que Spider-Juan puede atrapar al Dr. Tapia, independientemente de la estrategia que la cobaya llegue a tomar.

> Si Dr. Tapia y Spider-Juan cumplen que, la distancia entre estos es impar, y que `abs(j_juan - j_tapia) <= i_tapia - i_juan + 1`, entonces Spider-Juan puede mantener dicha desigualdad por el resto de la persecución hasta atrapar al Dr. Tapia.

En la siguiente imagen podemos ver de forma más visual, dado una posición fija de Spider-Juan, en qué posiciones Dr. Tapia podría ser acorralado:

![Zona acorralable](region_acorralable.png)

Si Dr. Tapia esta en alguna de las posiciones coloreadas, veamos como Spider-Juan puede mantener acorralado al Dr. Tapia:

- Si Dr. Tapia esta en una posición _naranja_, entonces Spider-Juan lo puede atrapar en un movimiento.
- Si Dr. Tapia esta en una posición _amarilla_ (`abs(j_juan - j_tapia) == i_tapia - i_juan + 1`), Spider-Juan tiene que moverse de manera horizontal,
  - ya sea a la izquierda si `j_tapia < j_juan`,
  - o a la derecha, si `j_tapia > j_juan`.
- Si Dr. Tapia esta en una posición _morada_ (`abs(j_juan - j_tapia) < i_tapia - i_juan + 1`), Spider-Juan puede moverse hacía abajo.

Siguiendo esa estrategia, no importa que movimiento haga Dr. Tapia, seguirá estando en una posición coloreada.

Con la estrategia que planteamos, el número de posiciones naranjas y moradas se irá reduciendo a medida que se muevan Spider-Juan y Dr. Tapia, hasta llegar al punto que sólo queden las naranjas y a lo más dos posiciones amarillas, momento en el que Dr. Tapia estará acorralado y sólo queden un par de movimientos para que Spider-Juan lo atrape.

Entonces, nos podemos preguntar... ¿y cómo podemos hacer que Spider-Juan tenga dicha ventaja?. La estrategia para resolver esta subtarea es la siguiente:

- Si la distancia entre Spider-Juan y Dr. Tapia es par, Spider-Juan debe ir al techo y cambiar la paridad.
- Si la distancia entre Spider-Juan y Dr. Tapia es impar, hay que checar si Dr. Tapia esta en una posición naranja, amarilla, o morada:
  - Para ello, basta con checar `abs(j_juan - j_tapia) <= i_tapia - i_juan + 1`. De ser el caso, podemos seguir la estrategia que acabamos de describir.
  - Si no se cumple la desigualdad, hay que subir al techo y movernos a la columna encima del Dr. Tapia (o una adyacente a está, para cumplir tener una distancia impar).
- Para bajar del techo, podemos usar la función que se describió en la subtarea 1.

<details><summary>Solución para la subtarea 2 (60+ puntos)</summary>

{{subtask2_estrategia_Juan.cpp}}

</details>

## Subtarea 3

Contamos con una estrategia en la que siempre atrapamos a Dr. Tapia, pero... ¿hacemos la mínima cantidad de movimientos?. Lamentablemente la respuesta es _no_, pero estamos **cerca** de lograrlo.

Dr. Tapia es consiente que Spider-Juan es el protagonista y logrará atraparlo. Tenemos que pensar en qué puede hacer el Dr. Tapia para ralentizar su captura.

- Si la distancia entre Dr. Tapia y Spider-Juan es par, Dr. Tapia no corre peligro... **por el momento**.
  - La estrategia que tomará Dr. Tapia será acercarse a la posición $\left(2, \left\lfloor\frac{(M + 1)}{2}\right\rfloor \right)$, para asegurar tener al menos $\frac{M}{2}$ movimientos laterales cuando quiera escapar de Spider-Juan, o bien, cambiar la paridad rápido si puede lograrlo.
- Si la distancia es impar, Dr. Tapia esta en desventaja y debe cambiar la paridad para no ser atrapado. Por ello tratará de ir al techo.
  - Si el Dr. Tapia esta arriba o a la altura de Spider-Juan (`i_tapia <= i_juan`), Dr. Tapia se moverá en dirección al techo.
  - Si el Dr. Tapia se encuentra abajo de Spider-Juan, debe checar si Spider-Juan ya lo acorraló o no:
    - Si `abs(j_juan - j_tapia) > abs(i_juan - i_tapia) + 1`, no importa que tan rápido se mueva Spider-Juan, Dr. Tapia puede moverse tranquilamente hacía arriba sin ser alcanzado y cambiar la paridad.
    - Si `abs(j_juan - j_tapia) <= abs(i_juan - i_tapia) + 1`, Dr. Tapia esta acorralado por Spider-Juan, como lo vimos en la subtarea anterior.
      - Si Dr. Tapia esta en una posición _naranja_, será atrapado por Spider-Juan inmediatamente.
      - Si Dr. Tapia esta en una posición _amarilla_, se moverá de acuerdo con su posición relativa a Spider-Juan:
        - Si `j_tapia < j_juan`, se moverá a la izquierda. Si no puede, irá abajo.
        - Si `j_tapia > j_juan`, se moverá a la derecha. Si no puede, irá abajo.
      - Si Dr. Tapia esta en una posición _morada_, se moverá al lado que tenga más espacio horizontalmente.

Teniendo en cuenta la estrategia de Dr. Tapia, Spider-Juan debe anticipar sus movimientos. Una de las posibles estrategias que Spider-Juan puede hacer es la siguiente:

- Si la distancia entre Spider-Juan y Dr. Tapia es par, Spider-Juan debe ir al techo y cambiar la paridad.
- Si la distancia es impar, puede verificar si Dr. Tapia esta acorralado o no (`abs(j_juan - j_tapia) <= abs(i_juan - i_tapia) + 1`), en caso de no estarlo, Spider-Juan debe ir al techo y cambiar de columna.
  - Si esta acorralado Dr. Tapia, aún puede decidir Spider-Juan si subir al techo, cambiar de columna, y sorprender al Dr. Tapia, limitando más los movimientos de la cobaya.

Antes de explicar cómo Spider-Juan decidirá si le conviene acorralar al Dr. Tapia de una vez, o es mejor subir al techo y cambiar de columna, tenemos que ver cuál es la mejor forma de bajar de columna.

Una vez que Spider-Juan baja del techo, esta sería la perspectiva del Dr. Tapia:

![Zona del terror para el doctor cobaya](cobaya_miedo.png)

Las posiciones con color _azul_ indican donde corre peligro Dr. Tapia, esto es, si Spider-Juan esta en una de estas posiciones, Dr. Tapia será acorralado.

Esto se debe a que si Spider-Juan decide bajar a una posición que no es azul, la distancia sería par, o bien, Spider-Juan estaría suficientemente lejos para que el Dr. Tapia pueda subir a cambiar la paridad de su distancia, que es algo que Spider-Juan no quiere que suceda.

Esto nos ayuda a identificar a qué posiciones puede ir Spider-Juan cuando baja del techo. Nos podemos preguntar, ¿en cuál debe de bajar, para atrapar al Dr. Tapia en menos movimientos?.

Vamos a calcular la cantidad de movimientos en los que atraparía al Dr. Tapia si Spider-Juan se baja en la posición `(1, j_juan)`:

- Si las posiciones cumplen que `i_tapia - i_juan > abs(j_tapia - j_juan) + 1`, entonces Dr. Tapia tiene mucha libertad para moverse de manera horizontal; tanta libertad como para decidir en qué esquina será atrapado, donde al querer sobrevivir la mayor cantidad de tiempo posible, tomará la que le tome mayor distancia a Spider-Juan.
- Si `i_tapia - i_juan == abs(j_tapia - j_juan) + 1`, entonces Dr. Tapia no puede elegir esquina para ser atrapado y sólo le queda dirigirse a la esquina que le esta orientando Spider-Juan.
- Dado que Dr. Tapia esta acorralado, no es posible que `i_tapia - i_juan < abs(j_tapia - j_juan) + 1`.

En la siguiente secuencia de movimientos, se puede ver como el Dr. Tapia logra escabullirse a la esquina contraria:

![Cambio](cambio1.png)
![Cambio](cambio2.png)
![Cambio](cambio3.png)
![Cambio](cambio4.png)

<figcaption align = "center"><i>El escape perfecto.</i></figcaption>

Observemos porque a Spider-Juan le conviene bajarse en `(1, j_tapia - i_tapia + 1)`, `(1, j_tapia + i_tapia -1)`, o en `(1, (M + 1) / 2)`, si es que es una posición valida.

- Si baja en `(1, j_tapia - i_tapia + 1)`, Dr. Tapia sí o sí será atrapado en la esquina inferior derecha.
- Si baja en `(1, j_tapia + i_tapia - 1)`, Dr. Tapia sí o sí será atrapado en la esquina inferior izquierda.
- Si baja en `(1, (M + 1) / 2)` y esta es una posición valida, no importa en que esquina sea atrapado, no tardará más de `M / 2` pasos horizontales.

Después de haber bajado del techo, es posible hacer un cálculo de cuántos movimientos horizontales se harán para llegar a la esquina inferior izquierda o derecha, mientras que los movimientos verticales sabemos que van a ser a lo más `N`, que es la cantidad de filas.

Si Spider-Juan decide subir al techo para cambiar de columna y acorralar más rápido al Dr. Tapia; el Dr. Tapia tratará de dirigirse a la columna del centro, para así entorpecer lo máximo posible los movimientos de Spider-Juan.

Entonces, podemos predecir que tanto se movería al centro Dr. Tapia en `i_juan` movimientos (que es lo que tardamos en llegar al techo), y podríamos predecir en cuántos movimientos atraparíamos al malévolo Dr. Tapia.

Después de hacer los cálculos de cuántos movimientos costaría cada una de las estrategias, elegimos aquella con la menor cantidad y la efectuamos.

A continuación presentamos una de las soluciones que implementa la estrategia mencionada, en ella, podrán ver con más detalle cómo se hace el cálculo de cada una de las estrategias (subir al techo y luego acorralar, o acorralar directamente).

<details><summary>Solución para la subtarea 3 (100 puntos)</summary>

{{solution.cpp}}

</details>

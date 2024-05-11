# Descripción

Mérida, la princesa, ha decidido mudarse a Mérida, Yucatán, ya que quiere participar en los Juegos Panamericanos 2023 en la categoría de tiro con arco, y Escocia (su país natal) no es un país invitado.

La princesa arquera ha entrenado disparándole flechas a objetivos en forma de cuadrado, pero se dio cuenta de que en Mérida, Yucatán utilizan cubos, para que así varias personas puedan entrenar al mismo tiempo.

Los cubos yucatecos son muy especiales. Para formarlos, inicialmente se tiene un cubote vacío de tamaño $N \times N \times N$, definido solo por sus aristas. Después, se eligen algunas coordenadas enteras dentro de éste y en cada una de dichas coordenadas se insertan bloques sólidos de $1 \times 1 \times 1$. Estos bloques tienen magia yucateca y pueden flotar de ser necesario, por lo que pueden ser colocados donde sea dentro del cubote, siempre y cuando sus coordenadas $x$, $y$ y $z$ sean números enteros no negativos.

Una vez hecho esto, cada persona de Mérida, Yucatán mira hacia una "cara" del cubote y ve una proyección distinta del resultado de poner los bloques. Una proyección es cuando ves el cubote de $N \times N \times N$ enfocándote en alguna de sus caras, lo que causará que veas lo que parece ser un cuadrado de $N \times N$, y que algunos de los bloques de $1 \times 1 \times 1$ tapen a otros desde tu punto de vista.

Debido a que hay muchas formas de ver las caras del cubote, los yucatecos le han dado nombre a tres proyecciones que destacan: la XY, la XZ y la YZ. Aquí puedes ver como ejemplo un cubote de largo $2$, y cómo el añadirle bloques va modificando estas tres proyecciones.

| Descripción             | Vista 3D                  | Proyección XY             | Proyección XZ             | Proyección YZ             |
| ----------------------- | ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| Cubo vacío              | ![Vacio 3d](vacio_3d.png) | ![Vacio XY](vacio_xy.png) | ![Vacio XZ](vacio_xz.png) | ![Vacio YZ](vacio_yz.png) |
| Nuevo bloque en (0,0,0) | ![Bloque 1 3d](c1_3d.png) | ![Bloque 1 XY](c1_xy.png) | ![Bloque 1 XZ](c1_xz.png) | ![Bloque 1 YZ](c1_yz.png) |
| Nuevo bloque en (1,1,1) | ![Bloque 2 3d](c2_3d.png) | ![Bloque 2 XY](c2_xy.png) | ![Bloque 2 XZ](c2_xz.png) | ![Bloque 2 YZ](c2_yz.png) |
| Nuevo bloque en (0,1,1) | ![Bloque 3 3d](c3_3d.png) | ![Bloque 3 XY](c3_xy.png) | ![Bloque 3 XZ](c3_xz.png) | ![Bloque 3 YZ](c3_yz.png) |
| Nuevo bloque en (0,0,1) | ![Bloque 4 3d](c4_3d.png) | ![Bloque 4 XY](c4_xy.png) | ![Bloque 4 XZ](c4_xz.png) | ![Bloque 4 YZ](c4_yz.png) |
| Nuevo bloque en (1,0,0) | ![Bloque 5 3d](c5_3d.png) | ![Bloque 5 XY](c5_xy.png) | ![Bloque 5 XZ](c5_xz.png) | ![Bloque 5 YZ](c5_yz.png) |
| Nuevo bloque en (1,1,0) | ![Bloque 6 3d](c6_3d.png) | ![Bloque 6 XY](c6_xy.png) | ![Bloque 6 XZ](c6_xz.png) | ![Bloque 6 YZ](c6_yz.png) |

Con la intención de darle la bienvenida en Mérida, Yucatán, se le ha pedido a Mérida, la princesa que coloque en un cubote de $N \times N \times N$ los bloques de $1 \times 1 \times 1$ que ella desee para un entrenamiento de tiro con arco que se realizará. Al no querer perder la costumbre de cómo entrena, y ya que no sabe con qué cara del cubo le va a tocar entrenar (es decir, qué proyección le va a tocar ver), Mérida quiere acomodar los bloques de $1 \times 1 \times 1$ de tal manera que, sin importar la proyección que le asignen, ella vea lo que parezca ser un cuadrado de $N \times N$, donde no haya ningún hueco sin un bloque.

Para lograr este objetivo ha recurrido a las participantes de la OFMI por su conocido gusto para resolver retos como este. Como colocar un bloque de $1 \times 1 \times 1$ puede ser muy cansado, a Mérida le agradará más tu solución entre menos bloques de $1 \times 1 \times 1$ utilices.

# Problema

Dado $N$, la longitud de la arista de un cubote inicialmente vacío, diseña una forma de insertar bloques de $1 \times 1 \times 1$ dentro de él hasta que las tres proyecciones XY, XZ y YZ muestren lo que aparente ser un cuadrado completo de $N \times N$. Cualquier solución que logre esto se considerará válida, pero obtendrás más puntos entre menos bloques uses.

# Implementación

Deberás implementar la función `cubo(N)`, que mande llamar la función `ponerBloque(x, y, z)`.

# Tu función `cubo`

`void cubo(int N)`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

## Parámetros

- `N` la longitud de un arista del cubote vacío inicial.

Dentro de esta función, deberás de usar la función `ponerBloque(x, y, z)` para lograr que las tres proyecciones XY, XZ y YZ muestren lo que aparente ser un cuadrado completo.

Tu puntaje en este problema depende de la cantidad de veces que mandes llamar la función `ponerBloque(x, y, z)`. Entre menos veces la mandes a llamar, más puntos obtendrás.

# Función del evaluador `ponerBloque`

`bool ponerBloque(int x, int y, int z)`

## Descripción

El evaluador te proveerá con esta función. Llama a esta función para colocar un bloque de $1 \times 1 \times 1$ dentro del cubote en la posición $(x, y, z)$. Las coordenadas en las tres dimensiones del cubote comienzan en $0$.

No deberás implementar esta función, solo llamarla.

## Parámetros

- `x` la coordenada en $x$ de la posición en que se coloca el bloque.
- `y` la coordenada en $y$ de la posición en que se coloca el bloque.
- `z` la coordenada en $z$ de la posición en que se coloca el bloque.

## Regresa

Un booleano que indicará si aún quedan huecos en alguna de las proyecciones. Es decir, si al ver las proyecciones XY, XZ y YZ hay un hueco en al menos una de ellas que no va a dejar satisfecha a Mérida, la función regresará `false` (falso). Por el contrario, si las tres proyecciones ya muestran un cuadrado como Mérida lo quería, la función regresará `true` (verdadero).

**Nota:** Todas las funciones reciben enteros.

# Ejemplo

Las llamadas mencionadas en este caso de ejemplo corresponden al cómo se van agregando bloques a un cubo de $2 \times 2 \times 2$ como se muestra en la tabla en la descripción del problema. Puedes usarla como referencia para analizar el valor que va regresando cada llamada a la función `ponerBloque(x, y, z)` que se muestra.

||input
Función llamada
||output
Valor devuelto
|| description
Descripción
||input
cubo(2)
||output

- ||description
  El evaluador llama a tu función `cubo`. Tienes entonces que colocar bloques en un cubo de $2 \times 2 \times 2$.
  ||input
  ponerBloque(0, 0, 0)
  ||output
  false
  ||description
  Se coloca un bloque en (0, 0, 0). Las tres proyecciones muestran un cuadrado de $2 \times 2$ incompleto.
  ||input
  ponerBloque(1, 1, 1)
  ||output
  false
  ||description
  Se coloca un bloque en (1, 1, 1). Las tres proyecciones muestran un cuadrado de $2 \times 2$ incompleto.
  ||input
  ponerBloque(0, 1, 1)
  ||output
  false
  ||description
  Se coloca un bloque en (0, 1, 1). Las tres proyecciones muestran un cuadrado de $2 \times 2$ incompleto.
  ||input
  ponerBloque(0, 0, 1)
  ||output
  false
  ||description
  Se coloca un bloque en (0, 0, 1). Las tres proyecciones muestran un cuadrado de $2 \times 2$ incompleto.
  ||input
  ponerBloque(1, 0, 0)
  ||output
  false
  ||description
  Se coloca un bloque en (1, 0, 0). Las proyecciones XY y XZ muestran ambas un cuadrado de $2 \times 2$ completo, pero el de la proyección YZ aún muestra un hueco.
  ||input
  ponerBloque(1, 1, 0)
  ||output
  true
  ||description
  Se coloca un bloque en (1, 1, 0). Las tres proyecciones ya muestran un cuadrado de $2 \times 2$, como Mérida lo deseaba.
  ||end

# Límites

- $1 \leq N \leq 50$
- No se te dará puntos si haces una llamada inválida.

# Evaluación

Para cada caso de prueba:

- Si hay al menos una proyección en que lo que se ve no es un cuadrado completo de $N \times N$, sino que se puede ver algún hueco sin bloques (es decir, la función `ponerBloque(int x, int y, int z)` nunca regresó `true`), la solución se considerará inválida y se te darán 0 puntos.
- Tu cantidad de puntos para una solución válida dependerá de $c$, el número de veces que mandaste a llamar a la función `ponerBloque(int x, int y, int z)`.

- Si $c\leq N^2$ se te darán 100 puntos.
- Si $N^2 < c \leq 2N^2$ se te darán mínimo 80 puntos.
- Si $2N^2 < c \leq 3N^2$ se te darán mínimo 40 puntos.
- Si $3N^2 < c \leq N^3$ se te darán mínimo 20 puntos.
- Si $c > N^3$ se te darán 0 puntos.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con el valor $N$. Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
2
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

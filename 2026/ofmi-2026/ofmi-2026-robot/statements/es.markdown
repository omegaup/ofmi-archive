La Organización Federal de Misiones Interplanetarias (OFMI) invirtió muchísimo dinero en diseñar un robot autónomo para sus misiones de exploración espacial. Actualmente, este robot se encuentra en Titán, la luna más grande de Saturno y la segunda más grande del sistema solar.

La composición de la atmósfera de Titán, que es prácticamente puro nitrógeno, crea una capa de smog naranja que hace imposible obtener imágenes de la superficie. Sin embargo, el robot explorador es capaz de reportar sus actividades gracias a señales de radio que envía a la estación espacial de la OFMI.

La OFMI representa la superficie de Titán como un plano bidimensional donde el robot se ubicará siempre en coordenadas representadas por dos enteros: una latitud y una longitud. El lugar donde el robot aterriza se le asigna la posición $(0, 0)$; la cual es el centro del plano bidimensional en el que el robot se moverá.

El robot envía a la OFMI la secuencia de comandos que está ejecutando. Con cada comando, el robot modificará su posición. Los posibles movimientos del robot son:

- Arriba, representado por el caracter `'^'`: el robot aumenta su latitud en $1$ unidad. Por ejemplo, si inicia en la coordenada $(0, 0)$, se moverá a la coordenada $(1, 0)$.
- Izquierda, representado por el caracter `'<'`: el robot disminuye su longitud en $1$ unidad. Siguiendo el ejemplo anterior, si estaba en la coordenada $(1, 0)$ pasará a la $(1, -1)$.
- Abajo, representado por el caracter `'v'`: el robot disminuye su latitud en $1$ unidad. Desde la posición anterior $(1, -1)$ se moverá a la posición $(0, -1)$.
- Derecha, representado por el caracter `'>'`: el robot aumenta su longitud en $1$ unidad. Desde la posición anterior $(0, -1)$ volverá a la posición de su aterrizaje en $(0, 0)$.

Como parte de tu trayectoria en la división de cómputo y análisis de la OFMI, te han asignado la tarea de ayudar a la organización a ubicar al robot en la superficie de Titán.

# Problema

Dados los comandos que el robot ejecutó en Titán desde su posición de aterrizaje, quieres saber en qué coordenada se encuentra actualmente el robot explorador.

# Entrada

En la primera línea vendrá un entero $n$, representando el número de comandos que ejecutó el robot.

En la segunda línea vendrá una cadena de $n$ caracteres, donde el $i$-ésimo caracter representa el $i$-ésimo movimiento que ejecutó el robot. La cadena solo contendrá caracteres `^`, `<`, `>` y `v`.

# Salida

Dos enteros $x$ y $y$, representando la latitud y longitud en la que el robot se encuentra después de ejecutar los $n$ comandos.

# Ejemplo

||examplefile
sub3_sample1
||description
Este caso se ejemplifica en la explicación de los comandos. Como se mencionó, el robot volvió a la posición de su aterrizaje en $(0, 0)$.
||examplefile
sub3_sample2
||description
El primer comando es ir a la izquierda, con lo que el robot disminuye su longitud, llegando a la posición $(0, -1)$.

Después realiza dos comandos de ir abajo, por lo que el robot disminuye su latitud en $2$ unidades, llegando a las coordenadas $(-2, -1)$.

Después realiza dos comandos de ir a la derecha, con lo que el robot aumenta su longitud en $2$ unidades, quedando en $(-2, 1)$.

Finalmente, el robot se mueve arriba, aumentando su latitud en $1$ unidad, teniendo su ubicación final en $(-1, 1)$.
||end

# Límites

- $1 \leq n \leq 10^6$.

# Subtareas

- **Subtarea 1 (12 puntos):**
  - $n = 1$.
- **Subtarea 2 (20 puntos):**
  - Todos los comandos de la cadena son del mismo tipo.
- **Subtarea 3 (68 puntos):**
  - Sin restricciones adicionales.

**Nota:** Las casos **NO** estarán agrupados.

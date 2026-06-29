La Organización Federal de Misiones Interplanetarias (OFMI) coordina misiones en distintos sistemas estelares con el objetivo de recolectar información sobre nuevos planetas, analizar posibles condiciones de habitabilidad y estudiar fenómenos astronómicos desconocidos.

La OFMI también realiza misiones de reconocimiento que permiten obtener datos preliminares antes de enviar operaciones más complejas. Cada misión de reconocimiento debe estar conformada por un equipo de científicas, donde cada integrante pertenece a una especialidad distinta. En particular, cada equipo debe incluir:

- una astrofísica,
- una bióloga,
- una ingeniera,
- y una médica.

Recientemente, la OFMI ha reunido a un grupo de científicas disponibles para participar en nuevas misiones. Sin embargo, debido a limitaciones de personal, no siempre es posible formar tantos equipos como se quisiera.

Con mucha alegría te has unido a la división de cómputo y análisis de la OFMI. Tu primera tarea consiste en determinar cuántas misiones de reconocimiento pueden formarse con el personal disponible.

# Problema

Dada la cantidad de científicas disponibles en cada una de las cuatro especialidades, debes determinar el **máximo número de misiones de reconocimiento** que se pueden formar, donde cada misión de reconocimiento debe estar conformada por exactamente una científica de cada especialidad.

# Entrada

En la primera línea vendrán cuatro enteros $a$, $b$, $c$ y $d$ que representan el número de astrofísicas, biólogas, ingenieras y médicas, respectivamente.

# Salida

Un solo entero que representa el número máximo de misiones de reconocimiento que se pueden formar.

# Ejemplo

||examplefile
sub1_sample1
||description
La OFMI tiene disponibles $3$ astrofísicas, $5$ biólogas, $2$ ingenieras y $4$ médicas.

Aunque algunas áreas tienen más personal disponible, las misiones de reconocimiento se ven limitadas a $2$ porque no hay más ingenieras.
||examplefile
sub1_sample2
||description
Lamentablemente, como no hay astrofísicas disponibles, no es posible formar ni una misión de reconocimiento.
||end

# Límites

- $0 \leq a, b, c, d \leq 100$.

**Nota:** Los casos **NO** estarán agrupados.

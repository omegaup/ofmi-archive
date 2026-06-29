La Organización Federal de Misiones Interplanetarias (OFMI) ha detectado un cinturón de asteroides que representa un riesgo para futuras misiones en la zona. Para garantizar la seguridad de los drones que navegan por ahí, la OFMI ha desplegado una nave equipada con un cañón de antimateria para destruir todos los asteroides.

Existen $n$ asteroides en el cinturón, convenientemente numerados del $1$ al $n$. Para destruir el $i$-ésimo asteroide con masa de $M_i$ toneladas, el cañón debe tener una carga de antimateria de al menos $M_i$ toneladas. Después de destruirlo, la nave recolecta su materia y la carga del cañón de antimateria aumenta en $M_i$ toneladas.

Por ejemplo, si el cañón tiene una carga de antimateria de $10$ toneladas, puede destruir un asteroide de $7$ o $10$ toneladas, pero no uno de $11$. Si en este mismo ejemplo, el cañón de $10$ toneladas destruyera un asteroide de $7$ toneladas, la carga de antimateria incrementaría a $10 + 7 = 17$ toneladas.

Antes de comenzar la misión, la nave debe cargar antimateria. La división de suministros de la OFMI tarda exactamente una hora en cargar una tonelada de antimateria a la nave. Afortunadamente, todos los asteroides se encuentran dentro del campo de visión de la nave, por lo que **es posible decidir cuáles destruir primero y cuáles después** para obtener más antimateria mientras la nave va destruyéndolos.

Dado que el tiempo es crucial en esta misión, la división de cómputo y análisis de la OFMI te ha asignado la tarea de planear una estrategia para minimizar la carga inicial de antimateria que la nave necesita para destruir todos los asteroides.

# Problema

Dado el número de asteroides y la lista de las masas de todos ellos, debes determinar la **menor carga inicial** que permite destruir todos los asteroides.

Recuerda que puedes elegir el orden en que la nave destruye los asteroides.

# Entrada

En la primera línea vendrá un entero $n$, representando el número de asteroides en el cinturón.

En la segunda línea vendrán $n$ enteros, donde el $i$-ésimo entero representa la masa $M_i$ del $i$-ésimo asteroide.

# Salida

Un solo entero representando la menor cantidad de antimateria inicial que se debe cargar a la nave para destruir todos los asteroides.

# Ejemplo

||examplefile
sub1.sample
||description
Este ejemplo entra dentro de los límites de la **subtarea $1$**.

Hay un asteroide con masa de $10$ toneladas y otro con masa de $8$ toneladas.

Necesitamos que el cañón esté cargado con al menos $8$ toneladas de antimateria, de lo contrario no podríamos destruir ninguno de los asteroides. Una vez que la nave destruya el segundo asteroide y recolecte su materia, tendremos $16$ toneladas de antimateria, suficientes para destruir el primero.
||examplefile
sub2.sample
||description
Los asteroides en este ejemplo tienen masas de $1$, $16$, $6$, $3$ y $30$ toneladas.

Observa que si se empieza la misión con una carga de $5$ toneladas de antimateria, es posible destruir los asteroides con índice $1$, $3$ y $4$ en ese orden, agregando su materia al cañón. La nave tendría entonces una carga de $5 + 1 + 6 + 3 = 15$ toneladas de antimateria. Con lo anterior, la nave se quedaría corta para destruir el resto de los asteroides. Cualquier otra carga inicial por debajo de las $5$ toneladas tampoco permite destruir todos los asteroides.

Sin embargo, cualquier carga inicial por encima de las $5$ toneladas **sí puede** destruir todos los asteroides. Como podrás darte cuenta, con un mínimo de $6$ toneladas, en el ejemplo anterior habríamos alcanzado una carga de antimateria de $16$ toneladas, con lo que se pueden destruir los asteroides con índice $2$ y $5$ en ese orden.
||end

# Límites

- $1 \leq n \leq 10^5$.
- $1 \leq M_i \leq 10^9$.
- $\sum_{i = 1}^{n} M_i \leq 10^9$; es decir, la suma de las masas de todos los asteroides será a lo más $10^9$.

# Subtareas

- **Subtarea 1 (32 puntos):**
  - $1 \leq n \leq 2$, es decir, habrá uno o dos asteroides.
- **Subtarea 2 (28 puntos):**
  - $1 \leq n \leq 100$.
  - $\sum_{i = 1}^{n} M_i \leq 10^4$; es decir, la suma de las masas de todos los asteroides será a lo más $10^4$.
- **Subtarea 3 (24 puntos):**
  - $1 \leq n \leq 1,000$.
- **Subtarea 4 (16 puntos):**
  - Sin restricciones adicionales.

**Nota:** La subtarea 1 **NO** tiene sus casos agrupados. Todas las demás subtareas tienen sus casos agrupados.

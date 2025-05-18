Mientras la delegación mexicana se encontraba en el tren rumbo a Bonn, notaron que debajo de sus asientos se encontraba una nueva carta de la directora de la OFMI (Organización Femenil Mundial de Investigación). En la carta se mencionaba que, pese a sus esfuerzos por detener a la misma organización malvada del año pasado, esta ha vuelto a infiltrar en la ciudad a $n$ espías numeradas del $1$ al $n$.

A cada espía se le asignó la misión de robar el código de una concursante, con el objetivo de que ninguna delegación pueda obtener medallas. Esto es un problema crítico, ya que va en contra de los principios de la EGOI (Excelencia y Grandeza Olímpica Internacional), por lo que la delegación mexicana sabe que no puede quedarse de brazos cruzados y debe evitar a toda costa que la organización malvada logre apoderarse de los códigos de las concursantes.

Afortunadamente, la organización malvada es muy desconfiada y le ha ordenado a cada una de sus espías que mantenga vigilada a otra espía dentro de la organización. Estas espías son tan meticulosas que también se encargan de robar los códigos de la espía a la que vigilan, es decir, si una espía $A$ tiene como tarea espiar a la espía $B$ y la espía $B$ tiene que espiar a la espía $C$, como parte de su trabajo, la espía $A$ robará el código de la espía $B$, el código de la espía $C$, y así sucesivamente todos los códigos que la espía $C$ haya robado.

La OFMI ha identificado de manera exitosa quiénes son las $n$ espías y a qué espía sigue cada una de ellas, pero en esta ocasión no cuenta con los recursos para desmantelar la red de espionaje como hizo el año pasado. En una movida inesperada, la OFMI decidió sacar del retiro a la agente Alondra para ejecutar el siguiente plan: hará entrar en razón a **una sola espía** para que se reivindique, garantizándole su protección, a cambio de que entregue toda su información. Cuando Alondra convence a una espía de reivindicarse, esta le entregará todos los códigos que pudo robar, tanto el de la concursante que se le asignó como los que obtuvo de otras espías.

Como la mano derecha de Alondra, tu misión, si decides aceptarla, es ayudarle a encontrar cuál es el máximo número de códigos que puede recuperar ejecutando el plan de la OFMI.

# Problema

Dado $n$ y una lista que describe la red de espionaje dentro de la organización malvada, deberás imprimir cuál es la máxima cantidad de códigos que Alondra puede recuperar convenciendo a **una sola espía** de entregarte toda su información.

# Entrada

En la primera línea un entero $n$, representando el número de espías en la organización malvada.

En la segunda línea vendrán $n$ enteros $U_1, U_2, \dots, U_n$, donde el $i$-ésimo entero $U_i$ representa que la espía $i$ está espiando a la espía $U_i$.

# Salida

Un solo entero representando la máxima cantidad de códigos que Alondra puede recuperar convenciendo a **una sola espía** de la organización malvada.

# Ejemplo

||examplefile
sub1.sample
||description
Las espías $1$, $2$ y $3$ están en un círculo de espionaje, por lo que si convences a cualquiera de ellas para darte sus códigos, obtendrás el código de todas ellas. La espía $4$ investiga a la espía $5$, y esta última investiga a la espía $1$, por lo que, si Alondra convence a la espía $4$ de reivindicarse, recuperaría **todos** los códigos que robó la organización malvada.
||examplefile
sub2.sample
||description
Las espías $1$ y $3$ se vigilan la una a la otra, mientras que las espías $2$, $4$ y $5$ están en otro círculo de espionaje. Alondra puede convencer a la espía $3$ de darle su código y el de la espía $1$, recuperando $2$ códigos en total.

Sin embargo, Alondra puede recuperar $3$ códigos si convence a la espía $4$, que es la solución óptima.
||end

# Límites

- $2 \leq n \leq 10^6$.
- $1 \leq U_i \leq n$.
- Ninguna espía se investiga a sí misma, es decir, $U_i \neq i$.

# Subtareas

- **Subtarea 1 (24 puntos):**
  - Se asegura que la $i$-ésima espía solo puede tener como objetivo a la espía $1$ o $i + 1$.
- **Subtarea 2 (31 puntos):**
  - Se asegura que toda espía es seguida exactamente por una espía.
- **Subtarea 3 (45 puntos):**
  - Sin consideraciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

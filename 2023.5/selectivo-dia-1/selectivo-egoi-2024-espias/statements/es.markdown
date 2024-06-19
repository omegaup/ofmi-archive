Mientras la delegación mexicana se encontraba en el tren rumbo a Eindhoven, notaron que debajo de sus asientos se encontraba una carta de la directora de la OFMI (Organización Femenil Mundial de Investigación). En la carta se mencionaba que habían detectado la presencia de una organización malvada que había infiltrado $N$ espías en la ciudad numeradas de $1$ a $N$. Estas espías tenían como objetivo robar los códigos de las concursantes para que ninguna delegación pudiera obtener medallas, con la intención final de quedarse con todas las medallas no reclamadas.

Esto es un problema crítico, ya que va en contra de los principios de la EGOI (Excelencia y Grandeza Olímpica Internacional), por lo que la delegación mexicana sabe que no puede quedarse de brazos cruzados y debe evitar a toda costa que las espías roben los códigos de las participantes y se roben las medallas.

Desafortunadamente, las espías infiltradas son de élite, por lo que cuando se les ordena seguir a una persona, se dedican exclusivamente a espiar a esa persona y a nadie más. Sin embargo, estas espías son tan meticulosas que también se encargan de robar los códigos de la espía a la que siguen, es decir, si una espía $A$ tiene como tarea espiar a la espía $B$ y la espía $B$ tiene que espiar a la espía $C$, como parte de su trabajo, la espía $A$ robará el código de la espía $B$, el código de la espía $C$, y así sucesivamente todos los códigos que la espía $C$ haya robado.

La OFMI ha identificado de manera exitosa quiénes son las $N$ espías y a qué espía sigue cada una de ellas, pero no quiere actuar precipitadamente y darles motivo para huir, por lo que se ha decidido ejecutar el siguiente plan: harán entrar en razón a un conjunto de esas espías para que se reivindiquen, garantizándoles su protección, a cambio de que entreguen todos sus códigos. Cuando convences a una espía de colaborar, esta te dará toda su información, es decir su código y todos los códigos a los puede llegar a tener acceso de otras espías.

Aunque lo ideal sería convencer a todas las espías de reivindicarse, el programa de protección es muy costoso, así que la directora de la OFMI te ha pedido que encuentres el mínimo número de espías que debes convencer para obtener los códigos de todas las espías y evitar que se haga un mal uso de estos.

# Problema

Dado $N$ el número de espías y una lista de números $U$, donde la espía $i$ está espiando a la espía $U_i$, deberás imprimir el mínimo número de espías que debes convencer para obtener todos los códigos.

# Entrada

En la primera línea un entero $N$ que representa la cantidad de espías.

En las siguiente línea vendrán $N$ enteros separados por espacio. El $i$-ésimo entero $U_i$ representa que la espía $i$ está espiando a la espía $U_i$.

# Salida

El mínimo número de espías que tienes convencer para obtener los códigos de todas las espías.

# Ejemplo

||examplefile
sample00
||description
Las espías `1`, `2` y `3` están en un círculo de espionaje, por lo que si convences a cualquiera de ellas para darte sus códigos, obtendrás el código de todas ellas. Sin embargo, aún necesitarías convencer a la espía `4`.

Nota que la solución óptima es simplemente convencer a la espía `4`, ya que ella investiga a la espía `1` y te entregará los códigos que robó sobre el círculo de espionaje.
||examplefile
sample01
||description
Las espías `1` y `3` no tienen forma de conocer lo que las espías `2`, `4` y `5` saben y viceversa. Por lo que necesitas convencer a una espía de cada grupo para tener información de todas las espías.
||end

# Límites

- $2 \leq N \leq 10^6$
- $1 \leq U_i \leq N$.
- Ninguna espía se investiga a si misma, es decir, $U_i \neq i$.

# Subtareas

- **Subtarea 1 (17 puntos):**
  - Se asegura que la $i$-ésima espía solo puede tener como objetivo a la espía $1$ o $i + 1$.
- **Subtarea 2 (34 puntos):**
  - Se asegura que toda espía es seguida exactamente por una espía.
- **Subtarea 3 (49 puntos):**
  - Sin consideraciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![Espias](espias.jpg 'Espias.')

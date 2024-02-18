Es bien sabido que Miguel tiene una pasión especial por la música. Sin embargo, el ver los Juegos Panamericanos en Santiago 2023 y el enterarse de que su Tía Victoria corría maratones lo han inspirado a practicar atletismo. Para esto a veces corre en la ciudad en que vive, pero a veces se va a practicar senderismo en las sierras aledañas.

Su tía Victoria, viendo todo desde el Mictlán (la Tierra de los Muertos), se sintió muy conmovida, y sabiendo que a Miguel le gusta la música le escribió una canción sobre su experiencia entrenando con una bruja deportista, además de un reto para que también entrene la mente. Le dio una hoja con la canción a Dante (recordemos que los xoloitzcuintles pueden cruzar entre ambos mundos), y Dante se la entregó a Miguel. La canción va así.

_¡Ay, qué bonito es trotar a las 2 de la mañana!_  
_A las 2 de la mañana, ¡ay que bonito es trotar, ay mamá!_  
_Salir y ponerse a correr en las sierras mexicanas._  
_En las sierras mexicanas, ¡ay que bonito es correr, ay mamá!_  
_Me agarra la bruja y me lleva al Picacho,_  
_al Popocatépetl y hasta al Nevado._  
_En cada cerrito agarré una florcita_  
_que no más ahí crezca y que esté bonita._  
_Ay, dígame, dígame, dígame usted_  
_en cuántos cerritos yo me ejercité._  
_Le digo qué flor cada vez recogí,_  
_ya usted haga el cálculo que le pedí._

Después de la letra de la canción, la tía de Miguel anotó una lista de $N$ números $f_0, f_1, ..., f_{N-1}$ que representan las flores recogidas por su tía. Por la letra de la canción, Miguel sabe que cada noche recogió un tipo de flor que crece únicamente en el cerro en el que entrenó dicha noche, y siempre que entrena en el mismo cerro recoge el mismo tipo de flor.

# Problema

Dados $N$ (el número de noches que entrenó su tía Victoria) y la lista de $N$ números $f_0, f_1, ..., f_{N-1}$, representando la flor que recogió en cada noche, ayúdale a Miguel a calcular en cuántos cerros diferentes entrenó su tía durante esas $N$ noches.

# Entrada

En la primera línea un entero $N$, que representa el total de noches que la tía Victoria fue a entrenar a un cerro.

En la segunda línea $N$ enteros separados por espacio, que representan el tipo de flor $f_i$ que la tía Victoria recogió en la $i$-ésima noche.

# Salida

Un único entero, la cantidad de cerros diferentes en los cuales la tía de Miguel entrenó.

# Ejemplo

||examplefile
sample-sub1
||description
La tía Victoria recogió 4 tipos de flor diferentes:

- Del tipo -1 en la primera noche.
- Del tipo 0 en la segunda noche.
- Del tipo 2 en la tercera y cuarta noche.
- Del tipo 5 en las noches restantes.

Esto significa que visitó 4 cerros.

||examplefile
sample2-sub2
||description
La tía Victoria recogió 7 tipos de flor diferentes:

- Del tipo 0 en la primera y sexta noche.
- Del tipo 3 en la segunda noche.
- Del tipo 7 en la tercera, quinta y décima noche.
- Del tipo 8 en la cuarta noche.
- Del tipo 9 en la séptima y octava noche.
- Del tipo 22 en la novena noche.
- Del tipo 4 en la última noche.

Esto significa que visitó 7 cerros.
||examplefile
sample3-sub3
||description
La tía Victoria recogió 8 tipos de flor diferentes:

- Del tipo 7 en la primera noche.
- Del tipo 5 en la segunda y octava noche.
- Del tipo 8 e la tercera noche
- Del tipo 10 en la cuarta noche.
- Del tipo 2 en la quinta y séptima noche.
- Del tipo 9 en la sexta noche.
- Del tipo -6 en la penúltima noche.
- Del tipo 4 en la última noche.
  Esto significa que visitó 8 cerros.
  ||end

# Límites

- $1 \leq N \leq 2*10^5$
- $-10^9 \leq f_i \leq 10^9$, para todo $0 \leq i \leq N-1$

# Subtareas

- **Subtarea 1 (15 puntos):**
  - Después de recoger 1 o más flores del mismo tipo de manera consecutiva, Tía Victoria nunca vuelve a recoger ningún tipo de flor que ya haya recogido antes.
- **Subtarea 2 (20 puntos):**
  - $0 \leq f_i \leq 1000$ (El tipo de flor está entre 0 y 1000)
- **Subtarea 3 (20 puntos):**
  - $-10000 \leq f_i \leq 10000$ (El tipo de flor está entre -10000 y 10000)
- **Subtarea 4 (45 puntos):**
  - Sin restricciones adicionales.

Las subtareas no estarán agrupadas.

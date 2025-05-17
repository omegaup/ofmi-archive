Andrea es muy sociable y tiene muchísimas amigas que la invitan a hacer todo tipo de actividades, por lo que siempre está ocupada y necesita organizar muy bien su calendario. Ella hizo una lista de los $n$ eventos a los que la invitaron, numerados del $1$ al $n$ para identificarlos fácilmente.

Para el $i$-ésimo evento de la lista, Andrea hizo un estimado de cuánto tiempo le tomará prepararse, sacar a pasear a su perrita Lola antes de salir y transportarse hasta el lugar del evento, por lo que sabe el tiempo $S_i$ en que debe comenzar a prepararse para salir de su casa sin demora y llegar puntual. Andrea también sabe en qué tiempo $E_i$ estaría de vuelta en casa si decidiera asistir, tomando en cuenta que **ella debe volver a casa** para sacar a pasear a Lola antes de ir a cualquier otro evento.

Es posible que Andrea no pueda asistir a todos los eventos, por lo que quiere decidir a cuáles ir de tal manera que se divierta al máximo. Para poder elegir, ella le asigna a cada evento $i$ una calificación $V_i$ entre $0$ y $100$, donde $0$ significa que no tiene nada de ganas de ir y $100$ significa que se muere de ganas de ir al evento $i$.

Como la EGOI 2025 está a la vuelta de la esquina, Andrea te ha pedido ayuda para organizar su calendario y elegir a qué eventos asistir de manera que la suma de sus calificaciones $V_i$ sea la mayor posible.

# Problema

Dados $n$ eventos, el $i$-ésimo de ellos representado por $S_i$, $E_i$ y $V_i$, ayuda a Andrea a encontrar la máxima suma de calificaciones de un conjunto de eventos a los que pueda asistir.

# Entrada

En la primera línea un entero $n$, representando el número de eventos a los que invitaron a Andrea.

Después vendrán $n$ líneas. La $i$-ésima línea contendrá tres enteros $S_i$, $E_i$ y $V_i$, representando el tiempo en que Andrea debe comenzar a prepararse para asistir al evento $i$, el tiempo en que volvería a su casa y la calificación que le asignó al evento, respectivamente.

# Salida

Un único entero representando la máxima suma de calificaciones de un conjunto de eventos a los que Andrea pueda asistir.

# Ejemplo

||examplefile
sub1.sample1
||description
Si Andrea asiste al primer evento, sumaría una calificación de $10$, pero no le da tiempo de asistir a ningún otro evento.

Si Andrea asiste al segundo evento, suma una calificación de $5$, pero inmediatamente después de regresar a casa en el tiempo $4$ puede comenzar su preparación para asistir al tercer evento y sumar una calificación de $7$. Esta estrategia suma un total de calificaciones de $12$, que es la máxima suma posible.
||examplefile
sub1.sample2
||description
Si Andrea asiste al primer evento no tendría tiempo de asistir a ningún otro evento, pero sumaría una calificación de $100$.

En cambio, si Andrea decide **no** ir al primer evento, tendría tiempo de sobra para asistir a un total de $5$ eventos, pero todos ellos tienen una calificación muy baja que apenas suma $15$.
||end

# Límites

- $1 \leq n \leq 10^5$.
- $0 \leq S_i < E_i \leq 10^9$.
- $0 \leq V_i \leq 100$.

# Subtareas

- **Subtarea 1 (21 puntos):**
  - $1 \leq n \leq 15$.
- **Subtarea 2 (17 puntos):**
  - $V_i = V_j$ para toda $1 \leq i < j \leq n$, es decir, todos los eventos tienen la misma calificación.
- **Subtarea 3 (19 puntos):**
  - $0 \leq S_i < E_i \leq 10^6$.
- **Subtarea 4 (21 puntos):**
  - $1 \leq n \leq 1,000$.
- **Subtarea 5 (22 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

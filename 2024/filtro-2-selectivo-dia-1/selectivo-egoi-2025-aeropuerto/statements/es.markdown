Ethan vive en la hermosa ciudad de Ofmilandia, donde tiene una agencia de transporte que se dedica a llevar personas desde la _Aguja Espacial_ hasta el aeropuerto de la ciudad. Ofmilandia está dividida en $n$ barrios, numerados del $1$ al $n$, que se conectan entre sí por $m$ avenidas. La _Aguja Espacial_ se encuentra en el barrio $1$ y el aeropuerto de Ofmilandia, en el barrio $n$.

Las $m$ avenidas que conectan los barrios de la ciudad son gestionadas por empresas diferentes. Específicamente, la $i$-ésima avenida, que conecta a los barrios $U_i$ y $V_i$, es gestionada por la empresa $X_i$. Para que un automóvil pueda circular por la avenida $i$, la empresa que gestiona la avenida requiere que los vehículos tengan una estampa de circulación en su parabrisas con el número $X_i$ de la empresa.

Como era de esperarse, las empresas mismas son las que les venden a los conductores las estampas que necesitan para circular y, como también era de esperarse, no son nada baratas. Como las empresas son muy competitivas, es posible que haya múltiples avenidas que conecten el mismo par de barrios, cada una gestionada por una empresa diferente.

Ethan no quiere pagar de más en estampas de circulación, ya que de por sí gasta mucho en gasolina, por lo que te ha pedido que lo ayudes a saber cuál es la mínima cantidad de estampas distintas que necesita para conducir de la _Aguja Espacial_ al aeropuerto de Ofmilandia.

# Problema

Dados $n$, $m$ y una lista de las avenidas en Ofmilandia, donde la $i$-ésima avenida es representada por $U_i$, $V_i$ y $X_i$, ayuda a Ethan a encontrar la mínima cantidad de estampas distintas que necesita para conducir desde la _Aguja Espacial_ en el barrio $1$ hasta el aeropuerto, que se encuentra en el barrio $n$.

# Entrada

En la primera línea, dos enteros $n$ y $m$, representando el número de barrios y el número de avenidas que hay en la ciudad de Ofmilandia, respectivamente.

Después vendrán $m$ líneas. En la $i$-ésima línea vendrán tres enteros $U_i$, $V_i$ y $X_i$, representando que hay una avenida que conecta los barrios $U_i$ y $V_i$ y que requiere la estampa de la empresa $X_i$ para transitar. Toma en cuenta que las avenidas de Ofmilandia se pueden transitar en ambas direcciones.

# Salida

Una sola línea con un entero: la mínima cantidad de estampas (distintas) necesarias para llegar del barrio $1$ al $n$.

Aunque Ofmilandia es hermosa, su infraestructura puede dejar mucho que desear, por lo que, si Ethan no puede conducir desde el barrio $1$ al barrio $n$, imprime `"-1"` (sin comillas).

# Ejemplo

||examplefile
sub2.sample
||description
En este caso, Ethan quiere llegar al aeropuerto en el barrio $6$. Él empieza su trayecto en el barrio $1$, y tiene dos opciones: dar la vuelta por el barrio $5$ o por el $4$.

Si escoge el trayecto por el barrio $5$, su camino hacia el aeropuerto sería pasando por los barrios $1 \rightarrow 5 \rightarrow 3 \rightarrow 2 \rightarrow 6$, necesitando las estampas $1$, $2$ y $3$. Observa que la estampa $3$ se usa dos veces, pero una vez que Ethan la compra, puede circular por avenidas gestionadas por la empresa $3$ tantas veces como quiera.

Si escoge el trayecto por el barrio $4$, su camino hacia el aeropuerto sería pasando por los barrios $1 \rightarrow 4 \rightarrow 6$, necesitando únicamente las estampas $5$ y $7$, que es la solución óptima.
||examplefile
sub1.sample
||description
En este caso, sin importar cuántas estampas compre Ethan, la infraestructura de Ofmilandia no le permite llegar de la _Aguja Espacial_ al aeropuerto.
||end

# Límites

- $2 \leq n \leq 10^4$.
- $1 \leq m \leq 2 \times 10^4$.
- $1 \leq U_i, V_i \leq n$.
- $1 \leq X_i \leq 10$.
- $U_i \neq V_i$, es decir, no hay avenidas que conecten un barrio consigo mismo.

# Subtareas

- **Subtarea 1 (23 puntos):**
  - $2 \leq n \leq 10$.
  - $1 \leq m \leq 50$.
- **Subtarea 2 (13 puntos):**
  - Cada barrio tiene exactamente dos avenidas.
- **Subtarea 3 (23 puntos):**
  - $1 \leq X_i \leq 2$, es decir, solo hay estampas de dos empresas.
- **Subtarea 4 (41 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

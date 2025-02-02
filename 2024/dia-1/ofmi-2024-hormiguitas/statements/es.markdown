Andrea tiene un patio enorme. En un extremo de su patio hay $n$ hormigueros organizados sobre una línea recta. Al inicio de la línea está el hormiguero con índice $1$, después el hormiguero con índice $2$, y así hasta llegar al $n$-ésimo hormiguero al final de la línea.

En el otro extremo del jardín, Andrea organizó un picnic con sus $m$ amigas, donde cada una trajo un platillo para compartir. Ellas colocan sus platillos en una manta en el suelo, organizados en otra línea recta, donde al inicio de la línea colocan el platillo con índice $1$, después colocan el platillo con índice $2$, y así hasta llegar al $m$-ésimo platillo al final de la línea.

Estas dos líneas son paralelas y están ubicadas en extremos opuestos del patio, como se muestra en la figura a continuación:

![Ejemplo del patio de Andrea](hormiguitas0.png)

Las hormiguitas están planeando atravesar el patio para tomar un poco de la comida del picnic (¡era para compartir, ¿no?!). Para tomar comida, las hormiguitas realizan lo que ellas llaman "una expedición". En una expedición, un grupo de hormiguitas forma una fila para llegar desde el hormiguero $u$ hasta el platillo $v$, esta fila debe ser continua para que, cuando tomen comida del platillo, puedan pasarse las migajas de patita en patita hasta volver al hormiguero.

En la siguiente figura, puedes ver un ejemplo de múltiples expediciones simultáneas: una expedición desde el hormiguero $1$ hasta el platillo $2$, otra del hormiguero $2$ al platillo $3$, y una tercera expecidión del hormiguero $3$ al platillo $4$.

![Ejemplo de expediciones](hormiguitas1.png)

Las filas de hormiguitas se mantienen a lo largo del tiempo. Sin embargo, si una nueva expedición sale de un hormiguero que ya tiene una fila de hormigas, se dice que ese hormiguero cambia de objetivo. En el ejemplo anterior, podemos imaginar una nueva expedición desde el hormiguero $1$ para cambiar su objetivo al platillo $4$.

Cuando las hormiguitas hacen la fila hacia su objetivo, **nunca rodean un hormiguero o un platillo** porque lo consideran ineficiente. Con lo anterior, puedes darte cuenta de que, para llegar del hormiguero $1$ al platillo $4$, las hormiguitas se cruzan en el camino con otra expedición; esto está prohibido por el sindicato de hormiguitas para evitar incidentes, por lo que, si una nueva expedición provoca cruces con otras filas de hormiguitas, todas las filas previas que se crucen con la nueva expedición deben retirarse de vuelta a su hormiguero y quedarse allí esperando a que se les asigne una nueva expedición.

![Ejemplo de un cruce](hormiguitas2.png)

Como ya sabes, las hormiguitas son extremadamente eficientes, por lo que, cuando organizan una nueva expedición, siempre eligen una ruta que garantice que se retire la menor cantidad de filas de expediciones anteriores.

# Problema

Dado el número de hormigueros $n$ y el número de platillos $m$ en el picnic de Andrea, las hormiguitas te dirán su plan de $q$ expediciones y quieren que les ayudes a saber cuántas filas se retiraron en cada expedición.

# Entrada

En la primera línea se proporcionan tres enteros $n$, $m$, $q$, representando el número de hormigueros, el número de platillos en el picnic y el número de expediciones que las hormiguitas tienen planeadas.

En las siguientes $q$ líneas, dos enteros $u_i$ y $v_i$, representando que en la $i$-ésima expedición las hormiguitas quieren ir del hormiguero $u_i$ al platillo $v_i$.

# Salida

Para cada expedición en la entrada, un entero $r_i$, representando que para realizar la $i$-ésima expedición, las hormiguitas necesitan retirar $r_i$ filas de expediciones pasadas para llegar al platillo deseado.

# Ejemplo

||examplefile
2_sub1.sample
||description
Las hormiguitas organizarán $4$ expediciones.

- La primera expedición va del hormiguero $1$ al platillo $2$, no se tienen que retirar filas.
- La segunda expedición va del hormiguero $2$ al platillo $3$, no se tienen que retirar filas.
- La tercera expedición va del hormiguero $3$ al platillo $4$, no se tienen que retirar filas.
- Para la cuarta expedición, el hormiguero $1$ cambia de objetivo; ahora quieren ir por el platillo $4$. Para llegar a ese platillo, las hormiguitas tienen que retirar la fila que sale del hormiguero $2$ y se quedarán esperando allí la siguiente expedición.
- La quinta expedición sale del hormiguero $3$ hacia el platillo $1$, cruzándose únicamente con la fila de la expedición anterior, que se retira al hormiguero $1$ a esperar órdenes.

||end

# Límites

- $1 \leq n, m \leq 10^6$.
- $1 \leq q \leq 2 \times 10^5$.
- $1 \leq u_i \leq n$.
- $1 \leq v_i \leq m$.

# Subtareas

- **Subtarea 1 (23 puntos):**
  - $1 \leq q \leq 2,000$.
- **Subtarea 2 (35 puntos):**
  - $u_i \leq u_j$ para toda $1 \leq i < j \leq q$.
- **Subtarea 3 (24 puntos):**
  - $m = 2$.
- **Subtarea 4 (18 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![](hormiguitas.jpeg 'Hormiguitas en expedición.')

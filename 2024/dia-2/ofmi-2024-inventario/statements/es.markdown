Las abejas chambeadoras visitan muchas flores diferentes para hacer su miel y cada día hay una cantidad diferente de cada tipo de flor.

Las abejas chambeadoras conocen $m$ tipos de flor, que identifican con códigos de $1$ a $m$. Durante $n$ días, ellas llevan un registro de su inventario, anotando el código de cada tipo de flor que tienen cada día.

Al final, las abejas chambeadoras quieren saber qué flores fueron las más comunes. Un tipo de flor es común si la registraron en su inventario al menos $k$ veces a lo largo de los $n$ días.

# Problema

Dada la cantidad de días, la cantidad de tipos de flor y el registro que llevaron las abejas, deberás responder $q$ consultas. Cada consulta proporciona un valor $k$, y tienes que determinar cuántos tipos de flor se registraron al menos $k$ veces a lo largo de los $n$ días.

# Entrada

En la primera línea, tres enteros separados por espacios $n$, $m$ y $q$, que representan la cantidad de días, la cantidad de tipos de flor y la cantidad de consultas respectivamente.

Luego, vendrán $n$ pares de líneas. Para el $i$-ésimo par de líneas, la primera línea contiene un entero $t_i$ que representa la cantidad de tipos de flor que registraron en el inventario en el día $i$, y la siguiente línea contiene $t_i$ enteros distintos separados con espacios que corresponden a los códigos de los tipos de flor registrados ese día.

En la siguientes $q$ líneas vendrá un entero $k_i$ correspondiente al valor de la $i$-ésima consulta de las abejas chambeadoras.

# Salida

Deberás imprimir $q$ líneas, cada una con un entero representando la cantidad de tipos de flor que se registraron al menos $k_i$ veces en el inventario.

# Ejemplo

||examplefile
sub4.sample
||description
A lo largo de $5$ días, hay $10$ tipos de flor, y las abejas chambeadoras hacen $5$ consultas.

- Para la primera consulta, todos los tipos de flor se registraron $0$ o más veces.
- Para la segunda consulta, los tipos de flor ${1, 2, 3, 4, 5, 6, 7, 8, 9}$ se registraron $1$ o más veces.
- Para la tercera consulta, los tipos de flor ${5, 9}$ se registraron $4$ o más veces.
- Para la cuarta consulta, los tipos de flor ${1, 2, 3, 5, 7, 8, 9}$ se registraron $2$ o más veces.
- Para la quinta consulta, los tipos de flor ${2, 5, 7, 9}$ se registraron $3$ o más veces.

||examplefile
sub4.sample2
||end

# Límites

- $1 \leq n \leq 10^4$.
- $1 \leq m \leq 10^5$.
- $1 \leq q \leq n + 1$.
- $0 \leq t_i \leq m$ para toda $1 \leq i \leq n$.
- $ \sum\_{i=1}^{n} t_i \leq 10^5$; es decir, la cantidad de tipos de flor que las abejas chambeadoras registraron durante todos los días es menor o igual a $10^5$.
- $0 \leq k_i \leq n$ para toda $1 \leq i \leq q$.

# Subtareas

- **Subtarea 1 (16 puntos):**
  - $m = 1$.
- **Subtarea 2 (15 puntos):**
  - $n = 1$.
- **Subtarea 3 (28 puntos):**
  - $q = 1$.
  - $k_1 = 1$.
- **Subtarea 4 (41 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

![](inventario.jpeg 'Las abejas chambeadoras haciendo su inventario.')

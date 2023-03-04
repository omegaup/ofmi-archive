Tyler Sweet acaba de anunciar su gira mundial para todos sus fans herbívoros, la Gira de las Épocas, y le pidió a la página Ticket Monster que se encargara de la venta de hongos (Hongus Boletus) que sirven como acceso para entrar al concierto, esto para que la venta no se fuera a saturar durante la preventa.

También quería que solo algunos hongos se vendieran durante la preventa, para así darle a más animales la oportunidad de conseguir un hongo, preocupada de forma muy específica de que las serpientes revendedoras acapararan la venta.

Ticket Monster le dijo a Tyler que podrían manejar todo esto, pero la regaron de forma muy mala y, además de saturarse, vendieron todo durante la preventa.

Tyler está muy enojada, así que te ha contratado a ti para que hagas un código que va a ser mejor que el de Ticket Monster. Para probarte, te pide que solo te encargues de los hongos de la ciudad de Aguascalientes.

Te han dicho que tienes que hacer un programa que procese a $N$ animales que llegaron a una fila virtual, y los tienes que atender en el orden en que llegaron. También te dijeron que hay un total de $B$ hongos, pero quieres que después de la preventa hayan al menos $R$ hongos restantes. Para no darle muchos hongos a las serpientes, no venderás más de $L$ hongos por animal.

# Entrada

En la primera línea vendrán 4 enteros $N$, $B$, $R$ y $L$.

En la siguiente línea vendrán $N$ enteros separados por un espacio, que representan los boletos $D_i$ que pidió el $i$-ésimo aminal en la fila.

# Salida

Imprime $N$ enteros que representan la cantidad de boletos que le vendiste a la $i$-ésima persona.

# Ejemplos

||examplefile
sample
||end

# Límites

- $1 \leq N \leq 10^5$
- $0 \leq R \leq B \leq 10^5$
- $0 \leq L, D_i \leq 1000$

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $N = 1$, $L \gt D_i$ para toda $i$
- **Subtarea 2 (15 puntos):**
  - $L \gt D_i$ para toda $i$
- **Subtarea 3 (15 puntos):**
  - Se te asegura que siempre se tendrán suficientes hongos. $(B - R \gt \sum D_i)$
- **Subtarea 4 (60 puntos):**
  - Sin consideraciones adicionales.

---

![](ticketmonster.jpeg 'Fans en la gran gira de las épocas.')

Todo el mundo sabe que a Spiderman y a las cobayas les gustan los memes, y las Spidercobayas no son la excepción. Las Spidercobayas quieren traducir textos al lenguaje de _Chems_, es decir _chemsificarlos_.

Un texto está formado por $N$ palabras separadas por espacios, cada palabra está formada por letras minúsculas del alfabeto (a-z) sin usar letras acentuadas y sin usar la `ñ`. Las palabras se dividen en sílabas de exactamente tres letras, excepto tal vez la última sílaba de cada palabra, que puede tener menos de tres letras (ver casos de ejemplo).

La forma de _chemsificar_ un texto, es agregando una "m" justo después de cada sílaba que termine en **exactamente** una vocal.

# Problema

Dado el texto, imprímelo _chemsificado_.

# Entrada

En la primera línea, un entero $N$ que representa el número de palabras.

En la segunda línea vendrán las $N$ palabras separadas por un espacio que representa el texto a _chemsificar_.

# Salida

Una sola línea, el texto _chemsificado_.

# Ejemplo

||examplefile
sample
||description
Si lo dividimos en las sílabas serían

"no", "pue", "de" y "ser"

"no" y "de" cumplen porque terminan en exactamente una vocal.

"pue" no cumple porque termina con dos vocales.

Al agregarles las m's a las sílabas se transforma en

"nom puedem ser"
|| examplefile
sample2
||end

# Límites

- $1 \leq N \leq 1000$
- El tamaño de cada palabra es a lo más $10$.

# Subtareas

- (10 puntos): $N = 1$
- (10 puntos): Se te asegura que toda sílaba termina en exactamente una vocal.
- (10 puntos): Se te asegura que ninguna sílaba tiene dos vocales juntas.
- (70 puntos): No hay consideraciones adicionales.

---

![](spider_cheems.png)

<figcaption align = "center"><i>Spider-Cheems</i></figcaption>

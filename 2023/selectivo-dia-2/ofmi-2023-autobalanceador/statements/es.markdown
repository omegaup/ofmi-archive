Se dice que una cadena de paréntesis está balanceada si cada paréntesis de apertura tiene un paréntesis de cierre correspondiente y que los paréntesis están apropiadamente anidados. Por ejemplo, las siguientes cadenas de paréntesis están balanceadas: `(()()()())`, `(((())))` y `(()((())()))`. En cambio, las siguientes no están balanceadas: `((((((())`, `()))` y `(()()(()`.

Charly tiene un teclado con únicamente tres teclas, los paréntesis `(`, `)` y un paréntesis comodín `]`. Charly escribe una cadena $S$ con su teclado.

La computadora puede reemplazar el paréntesis comodín `]` por uno o más paréntesis de cierre `)`. Cuando Charly termina de escribir, su computadora reemplaza inteligentemente los paréntesis comodines `]` de tal forma que se construya una cadena balanceada.

Últimamente la computadora de Charly no funciona, por lo que te ha pedido que le ayudes a remplazar los paréntesis comodines para tener una cadena balanceada.

# Implementación

Deberás implementar las función `balancea(n, S)` y llamar a la función `respuesta(m, T)`. Este procedimiento es descrito a continuación.

# Tu función `balancea`

`void balancea(int n, char[] S);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `n`: el tamaño de la cadena.
- `S`: la cadena que Charly escribió.

# Función del evaluador `respuesta`

`void respuesta(int m, char[] T);`

## Descripción

Tu función debe llamar a la función `respuesta` exactamente una vez con los siguientes parámetros:

- `m`: El tamaño de la cadena $T$.
- `T`: La cadena final balanceada posible. Si hay muchas, regresa cualquiera. Si no existe cadena final válida, entonces regresa la cadena `"IMPOSIBLE"` (sin comillas).

**Importante**: Nota que si $T$ es "IMPOSIBLE", $m$ debe ser 9.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
balancea(10, "((((](()])")
||output

- ||description
  El evaluador llama a tu función `balancea`. La cadena que escribió Charly tiene 10 caracteres, con dos comodines.
  ||input
  respuesta(12, "(((()))(()))")
  ||output
- ||description
  Si el primer comodín lo reemplazamos por ")))" y el segundo por ")" obtenemos la cadena balanceada "(((()))(()))".
  ||end

# Límites

- $1 \leq n \leq 10^5$

# Subtareas

- **Subtarea 1 (15 puntos):**
  - No hay ningún caracter `]` en $S$.
- **Subtarea 2 (25 puntos):**
  - Hay exactamente un caracter `]` en $S$
- **Subtarea 3 (30 puntos):**
  - Se te asegura que la cadena siempre se podrá balancear
- **Subtarea 4 (30 puntos):**
  - Sin consideraciones adicionales.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`. En la primera línea los enteros $n$. En la segunda línea la cadena $S$.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
10
((((](()])
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

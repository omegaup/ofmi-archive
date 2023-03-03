Nicolás es una serpiente, pero no es una serpiente común y corriente, es una serpiente vegetariana. Es la única serpiente vegetariana en el mundo.

Tú la has visto un par de veces robando vegetales de tu huerto y cuando les contaste a tus amigos no te creyeron, entonces quieres tomarle una foto para que lo conozcan.

Nicolás tiene una longitud de $L$ metros y avanza a $X$ mps (metros por segundo).

El huerto esta representado por una fila de casillas, cada casilla mide $1$ metro.

Cuando Nicolás empieza a moverse es el tiempo $0$, su cola está en la casilla $0$ y su cabeza en la casilla $L - 1$ y avanza siempre en línea recta hacia adelante.

En cada segundo (a partir del segundo 1) apuntas la cámara a la casilla $y$ y tomas una foto a ciegas que captura lo que hay en el metro $y$.

# Problema

Tu tarea es calcular cuánto mide Nicolás ($L$) y a qué velocidad avanza ($X$). Usando la información que te dan estas fotos.

# Implementación

Debes implementar la función `nicolas()`. Este procedimiento puede llamar a las funciones `foto(y)` y `reporta(X, L)`. Todos estos procedimientos son descritos a continuación.

# Tu función `nicolas`

`void nicolas();`

## Descripción

Debes implementar esta función. El evaluador busca en tu código esta función y la llama inicialmente.

Puedes llamar a la función `foto(y)` las veces que sean necesarias para obtener información de Nicolás.

Debes llamar a la función `reporta(X, L)` exactamente una vez para reportar los valores de $X$ y $L$.

# Función del evaluador `foto`

`bool foto(int y);`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función con el parámetro `y` que representa la casilla donde quieres tomar la foto.

## Regresa

Esta función devuelve `true` si en la casilla $y$ hay una parte de Nicolás en el momento en que tomaste la foto. Y devuelve `false` en caso contrario.

Recuerda que la primera vez que llames a `foto` será en el segundo 1, a la siguiente que lo llames se tomará como el segundo 2, y así sucesivamente.

# Función del evaluador `reporta`

`void reporta(int X, int L);`

## Descripción

El evaluador tiene implementada esta función. Llama a esta función **exactamente una vez** con los parámetros `X` y `L` que representan la velocidad y longitud de Nicolás.

Una vez que mandes llamar esta función tu programa terminará y el evaluador verificará si los valores que mandaste son correctos.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
nicolas()
||output

- ||description
  El evaluador llama a la función `nicolas()`. La velocidad de Nicolás es de 3mps y tiene una longitud de 2m. Recuerda que serán valores desconocidos para tu programa.
  ||input
  foto(2)
  ||output
  false
  ||description
  En el segundo 1, Nicolás abarca las casillas $[3, 4]$. Por lo que no sale en la foto del metro 2.
  ||input
  foto(7)
  ||output
  true
  ||description
  En el segundo 2, abarca las casillas $[6, 7]$.
  ||input
  reporta(3, 2)
  ||output
  ||description
  Cuando sepas la velocidad y la longitud, debes llamar a reporta para que el evaluador pueda verificar tu solución.
  ||end

# Límites

- $1 \leq X, L \leq 1,000$

# Subtareas

- **Subtarea 1 (12 puntos) agrupados:**

  - $L = 1$
  - Puedes llamar a `foto` las veces que quieras.

- **Subtarea 2 (12 puntos) agrupados:**

  - $X = 1$
  - Puedes llamar a `foto` las veces que quieras.

- **Subtarea 3 (26 puntos) agrupados:**

  - Puedes llamar a `foto` las veces que quieras.

- **Subtarea 4 (50 puntos) agrupados:**
  - Tu puntaje depende del número de llamadas a `foto`
    - (10 ptos) Si el número de llamadas está entre $1,011$ y $1,020$
    - (25 ptos) Si el número de llamadas está entre $1,001$ y $1,010$
    - (50 ptos) Si es menor o igual a $\leq 1,000$

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $X$ y $L$. Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
3 2
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

---

![](nicolas.jpeg 'Nicolas, la serpiente vegetariana.')

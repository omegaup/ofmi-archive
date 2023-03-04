Después de arreglar tu huerto estabas muy cansado y para descansar, decidiste averiguar por qué te cansaste tanto.

Resulta que fue por moverte de un lado a otro, a veces olvidando los vegetales que ibas a sembrar y otras tratando de atrapar a la serpiente vegetariana que se las robaba. Y como tu huerto es de $1$ de ancho e infinítamente largo, solo te puedes mover hacia adelante y hacia atras.

Tienes el registro de los movimientos que hiciste (porque eres así de organizado) y quieres saber en cualquier momento cuántos metros habías avanzado y cuántas veces habías cambiado de dirección.

# Implementación

Deberás implementar las funciones `adelante(x)`, `atras(y)`, `avanzado()` y `vueltas()`. Estos procedimientos son descritos a continuación.

# Tu función `adelante`

`void adelante(int x);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `x` representa la cantidad de metros que te moviste hacia el frente.

# Tu función `atras`

`void atras(int y);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `y` representa la cantidad de metros que te moviste hacia atrás.

# Tu función `avanzado`

`int avanzado();`

## Regresa

Tu envío deberá implementar esta función. Esta función debera regresar un entero que representa la distancia en metros que has avanzado desde el inicio de la pista hasta el punto donde te encuentras.

# Tu función `vueltas`

`int vueltas();`

## Regresa

Tu envío deberá implementar esta función. Esta función debera regresar cuántas vueltas has dado, es decir cuántas veces has cambiado de dirección. Se considera que cambiaste de dirección cuando te moviste hacia adelante y acto seguido hacia atrás o cuando te moviste hacia atrás y acto seguido hacia adelante.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
adelante(4)
||output

- ||description
  Te mueves $4$ metros hacia adelante
  ||input
  atras(1)
  ||output
- ||description
  Te mueves $1$ metro hacia atrás. Como antes te moviste hacia adelante, tuviste que cambiar de dirección.
  ||input
  vueltas()
  ||output
  1
  ||input
  adelante(2)
  ||output
- ||description
  Como estás mirando hacia atrás, tienes que cambiar de dirección nuevamente para después moverte $2$ metros hacia adelante.
  ||input
  vueltas()
  ||output
  2
  ||input
  avanzado()
  ||output
  5
  ||end

# Límites

- Tus funciones se llamarán a lo más $N$ veces.
- $1 \leq N, x, y \leq 10^4$

# Subtareas

- **Subtarea 1 (20 puntos):**
  - No se llamará ninguna vez a tu función `atras`.
- **Subtarea 2 (20 puntos):**
  - Se llamará exactamente una vez a tu función `avanzado` después de todos los `adelante` y `atras`.
  - No se llamará jamás a `vueltas`.
- **Subtarea 3 (20 puntos):**
  - Nunca se llamará un `adelante` después de haber llamado a algún `atras`.
- **Subtarea 4 (40 puntos):**
  - Sin consideraciones adicionales.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con un valor $N$, que es el número de eventos. En las siguientes $N$ líneas vendrá descrito cada evento de la siguiente manera:

- `1 x`: donde $x$ es un entero positivo y significa que el evaluador hará una llamada a `adelante(x)`.
- `2 y`: donde $y$ es un entero positivo y significa que el evaluador hará una llamada a `atras(y)`.
- `3`: significa que el evaluador hará una llamada a `avanzado`.
- `4`: significa que el evaluador hará una llamada a `vueltas`.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
6
1 4
2 1
4
1 2
4
3
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

---

![](recorriendo.jpeg 'Nicolas, la serpiente vegetariana.')

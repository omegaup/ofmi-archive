Hoy Cynthia y tú jugarán una partida de "Frijolitos Mágicos". Este juego se desarrolla por turnos. Al inicio se colocan $N$ frijolitos sobre la mesa y en cada turno, la jugadora puede optar por uno de los siguientes movimientos:

1. Tomar un frijolito de la mesa.
2. Tomar la mitad de los frijolitos de la mesa. Este movimiento solo está permitido si hay una cantidad par de frijolitos sobre la mesa.

El juego termina cuando ya no hay frijolitos en la mesa.

# Problema

Dado la cantidad de frjolitos que hay en la mesa y sabiendo que tú empiezas el primer turno y que Cynthia es una experta en este juego (siempre garantiza que tendrá la mayor cantidad de frijolitos posible al final del juego), debes maximizar la cantidad total de frijolitos que tienes al finalizar el juego.

# Implementación

Debes implementar la función `frijolitos(N)`. Este procedimiento debe llamar a `tomar(cantidad)`. Estos procedimientos son descritos a continuación.

# Tu función `frijolitos`

`void frijolitos(long long int n)`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

## Parámetros

- `N` la cantidad inicial de frijolitos en la mesa.

Dentro de esta función, deberás de simular el juego mandando a llamar `tomar(cantidad)` hasta que no hayan más frijolitos en la mesa. Tú empiezas el primer turno.

# Función del evaluador `tomar`

`long long int tomar(long long int cantidad)`

## Descripción

El evaluador te proveerá con esta función. Llama a esta función para tomar cierta cantidad de frijolitos de la mesa.

No deberás implementar esta función, solo llamarla.

## Parámetros

- `cantidad` la cantidad de frijolitos que tomas de la mesa. Esta candidad debe ser un valor válido.

## Regresa

En caso de que ya no hayan frijolitos en la mesa, regresará $0$ y deberás terminar la ejecución. De lo contrario, regresa un entero que indica la cantidad de frijolitos que toma Cynthia. Se te asegura que es un movimiento válido.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
|| description
Descripción
||input
frijolitos(6)
||output

- ||description
  El evaluador llama a tu función `frijolitos`. El juego empieza con $6$ frijolitos en la mesa.
  ||input
  tomar(3)
  ||output
  1
  ||description
  Inicias tú el primer turno tomando la mitad de los frijolitos de la mesa. Después de esto, Cynthia toma $1$ frijolito y quedan $2$ frijolitos en la mesa.
  ||input
  tomar(1)
  ||output
  1
  ||description
  En tu segundo turno, tomas $1$ frijolito. Cynthia toma entonces el último frijolito, terminando el juego.

En total, lograste tomar $4$ frijolitos.
||end

# Límites

- $1 \leq n \leq 10^{18}$

# Subtareas

- **Subtarea 1 (15 puntos):**
  - $n \leq 20$.
  - Para obtener todos los puntos de esta subtarea, deberás maximizar en todos los casos la cantidad de frijolitos que tomes.
- **Subtarea 2 (35 puntos):**
  - $n \leq 10^6$.
  - Para obtener todos los puntos de esta subtarea, deberás maximizar en todos los casos la cantidad de frijolitos que tomes.
- **Subtarea 3 (50 puntos)**
  - Para cada caso de esta subtarea obtendrás una cantidad de puntos relativo a la cantidad de frijolitos que pongas. Sea $Y$ el máximo de frijolitos de la mejor estrategia y $X$ los frijolitos que tomaste. Obtendrás:
    - $1$ si $Y \leq X$ (el 100% de los puntos).
    - $(X + 1)/Y * 0.7$ si $X < Y$.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con el valor $N$. Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```sh
6
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de manera distinta.

---

![Frijolitos](frijolito.jpg 'Frijolitos.')

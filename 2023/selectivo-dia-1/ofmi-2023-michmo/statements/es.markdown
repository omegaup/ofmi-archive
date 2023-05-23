Existe un famoso cuyo tenismesista llamado `Michmo Boll`, quien ha ganado múltiples campeonatos en los últimos años. Un dato curioso de Michmo es que su raqueta es un ramo de espinaca, y en vez de jugar con una pelota convencional, juega con una micro-papa. Michmo piensa que es superior a ti, y para demostrarlo, te ha desafiado a que juegues tenis de mesa contra él.

La mesa donde jugarán es un área rectangular de dimensiones $N$ por $M$, de la cual representaremos sus esquinas con los puntos $(0, 0), (0, M), (N, 0)$, y $(N, M)$. Tú estás en algún punto de la columna $N$ (puntos de la forma $(N, y)$) y Michmo en la columna $0$ (puntos de la forma $(0, y)$). Michmo y tú solo se pueden mover verticalmente.

La mesa de juego se divide en dos, la _zona del contrincante_ (zona de Michmo) que abarca de la columna $0$ a la columna $N / 2$, y en tu _zona personal_, de la columna $N / 2$ a la columna $N$. Observa que la columna $N / 2$ pertenece a ambas zonas (podemos interpretarla como la red que les divide).

Michmo está tan confiado que te ganará que realizará un único saque de micro-papa y no defenderá después. Tú te puedes aprovechar de ello y ganarle en cualquier situación.

Michmo mandará la micro-papa desde cierta posición $(0, P)$ y dirección (pendiente) hacía ti. Si la micro-papa no pasa por tu _zona personal_ antes o al llegar a la columna $N$, entonces decimos que el tiro habrá fallado y tu le ganarías a Michmo. Si la micro-papa pasa por alguna esquina de tu zona, se considera que fue un tiro válido. En caso de que Michmo no falle, deberás regresar la micro-papa a Michmo con la dirección (pendiente) que desees pero desde la posición que llego a tu columna, cuidando de no fallar el tiro. Cuando recibas la micro-papa en tu columna, debes redondear la posición hacia abajo. Se considera tiro válido si la micro-papa pasó por el área rival **antes** de redondear la posición.

¡Es tu momento de demostrarle a Michmo que puedes ganarle! En caso de que Michmo falle su tiro al principio, deberás reportarlo. En caso de que no falle, deberás devolver la micro-papa a Michmo sin fallar.

# Implementación

Debes implementar la función `michmo(int N, int M, int P, int A, int B)`. Este procedimiento debe llamar a las funciones `terminar` si Michmo falló su tiro, o a la función `devolver` con la posición que llegó la micro-papa y la pendiente con la que decidas devolverla a Michmo. Todos estos procedimientos son descritos a continuación.

# Tu función `michmo`

`void michmo(int N, int M, int P, int A, int B);`

## Descripción

Tu envío debe implementar esta función. El evaluador buscará en tu código esta función y la llamará inicialmente.

## Parámetros

- $N$ y $M$ son las dimensiones de la mesa de juego.

- $P$ es la coordenada $y$ desde donde Michmo mandó la micro-papa $(0, P)$.

- $A / B$ es la pendiente con la que Michmo mandó te mandó la micro-papa.

Dentro de esta función debes llamar a la función `terminar()` exactamente una vez si Michmo falló el tiro. Si Michmo no falla el tiro, debes llamar a la función `devolver(p, a, b)`, con la posición de la micro-papa y la pendiente con la que vas a regresarla. El valor de $b$ debe ser distinto de cero, si no, se considerara como un tiro fallido.

# Función del evaluador `devolver`

`void devolver(int p, int a, int b);`

## Descripción

El evaluador te proveerá con esta función. Llama a esta función **exactamente una vez** con los parámetros $p$ para la posición inicial de tu tiro $(N, p)$, y $a$ y $b$ para la pendiente $a / b$ con la que mandarás tu tiro. Al regresar la micro-papa, esta debe pasar por la zona de Michmo para que tu tiro sea válido y ganes el partido. Recuerda redondear hacia abajo la posición con la que recibes la micro-papa.

Después de llamar a esta función, no debes realizar más instrucciones.

# Función del evaluador `terminar`

`void terminar();`

## Descripción

El evaluador te proveerá con esta función. Llama a esta función **exactamente una vez** para indicar que Michmo falló el tiro e indicar tu victoria.

Después de llamar a la función, no debes realizar más instrucciones.

# Ejemplos

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
michmo(16, 10, 2, 2, 5)
||output

- ||description
  El evaluador llama a la función `michmo`. Michmo te mandan la micro-papa desde la posición $(0, 2)$ con pendiente $2/5$.
  ||input
  devolver(8, -1, 5)
  ||output
- ||description
  Michmo no falló y la micro-papa llegó a la columna $N$ a la altura $8.4$, se redondea hacia abajo y entonces llega en la posición $(16, 8)$.

Decides regresar la micro-papa con pendiente $-1/5$, pasando por la zona de Michmo y ganando el partido.
||end

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
michmo(16, 10, 8, 2, 3)
||output

- ||description
  El evaluador llama a la función `michmo(16, 10, 8, 2, 3)`.
  ||input
  terminar()
  ||description
  La micro-papa que lanza Michmo nunca toca tu zona personal.
  ||end

# Límites

- $1 \leq N, M \leq 10^6$
- $-10^6 \leq A, B \leq 10^6$, $B \neq 0$
- $-10^6 \leq P \leq 10^6$
- $N$ siempre es par.

# Subtareas

- **Subtarea 1 (5 puntos)**
  - $A=0$ y $B=1$. Es decir, el tiro es válido si y solo si Michmo tiró en algún $(0, P)$ dentro de la mesa. Además, si el tiro es válido, puedes llamar a `devolver` con parámetros cualesquiera sin que el tiro de vuelta sea válido.
- **Subtarea 2 (20 puntos)**
  - Se asegura que el tiro de Michmo no va a fallar.
- **Subtarea 3 (30 puntos)**
  - Se asegura que el primer tiro de Michmo será dentro de la mesa de juego.
- **Subtarea 4 (45 puntos)**
  - Sin consideraciones adicionales.

Nota: Los casos están agrupados.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $N$, $M$ y los primeros valores $P$, $A$ y $B$. Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
16 10
2 2 5
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

---

![](michmo.jpeg 'Michmo, el tenismesista.')

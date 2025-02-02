Después de años de estar peleando contra las hormigas por el territorio del patio de Andrea, las termitas aprovecharon que casi todas las hormigas han salido del hormiguero para buscar la comida del picnic, y ahora tienen acorralada a la hormiga reina en su propia cámara. Como la reina no tiene a sus compañeras para que la defiendan, decidió enfrentar a las termitas en un juego que se le da muy bien: el ajedrez.

Pero como está sola, les propone a las termitas jugar una variante del juego tradicional. La cámara de la hormiga reina es un tablero de $n \times n$. En él se van a acomodar $k$ piezas entre termitas-torre, termitas-alfil y termitas-caballo, cada una de ellas localizada alguna posición $(x_i, y_i)$. La hormiga reina se encuentra localizada en la coordenada $(x, y)$.

La hormiga reina se puede desplazar a alguna posición en la fila $x$ o la columna $y$, o bien sobre sus diagonales, tal como se mueve una reina de ajedrez.

De manera similar, cada termita-pieza en el tablero se puede desplazar a todas las posiciones alcanzables de acuerdo con sus movimientos correspondientes en el ajedrez original.

Además, en esta variante, las termita-piezas pueden ignorar la presencia de otras piezas en el tablero. Es decir, para llegar a su posición final, puede saltar a cualquier pieza que tenga en medio. La única condición para que un movimiento sea válido es que la posición final debe estar libre.

La hormiga reina también puede saltar a las termita-piezas, pero para que el movimiento sea válido, su posición final debe estar libre y tampoco debe estar amenazada por alguna termita-pieza. Una casilla se considera amenazada si una termita-pieza puede llegar a ella en el siguiente turno.

Es el turno de la hormiga reina y te pide ayuda para determinar si existe alguna posición válida a la cual se pueda mover, de lo contrario perderá. En caso de que la haya, imprime las coordenadas a las cuales se debe mover para poder seguir jugando. De lo contrario, imprime $-1$ indicando que no existe dicha posición.

# Problema

Dadas las $k$ posiciones $(x_i, y_i)$ de las termita-piezas y la posición $(x, y)$ de la hormiga reina en el tablero de $n \times n$, debes determinar si existe alguna posición válida a la cual se pueda mover la hormiga reina, o bien, indicar que dicha posición no existe.

# Entrada

En la primera línea, dos enteros $n$ y $k$ separados por un espacio. Donde $n$ es el tamaño de los lados del tablero (que será de $n \times n$), y $k$ es el número de termita-piezas en el tablero (sin contar a la hormiga reina).

En la segunda línea, recibirás $x$ y $y$, que representan la fila y columna iniciales de la hormiga reina, respectivamente.

Luego, vendrán $k$ líneas, cada una con tres enteros: $t$, $x_i$, $y_i$. $t$ es un caracter que indica el tipo de la pieza (`'T'` para termita-torre, `'A'` para termita-alfil y `'C'` para termita-caballo), mientras que $x_i$ y $y_i$ representan la fila y columna donde se encuentra dicha pieza.

# Salida

Deberás imprimir dos enteros $x_f$ y $y_f$ separados por un espacio, representando la fila y columna en donde la hormiga reina estará a salvo. Si hay múltiples posiciones donde la hormiga reina estará a salvo, puedes imprimir cualquiera de ellas.

Si no existe alguna posición en la que la hormiga reina estaría a salvo, deberás imprimir $-1$.

# Ejemplo

||examplefile
sub1.sample
||description

| -     | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- |
| **1** | A   | .   | .   | .   | .   | .   | .   | .   |
| **2** | .   | .   | .   | C   | .   | .   | .   | .   |
| **3** | .   | .   | R   | .   | .   | .   | .   | .   |
| **4** | .   | .   | .   | .   | .   | .   | .   | .   |
| **5** | .   | .   | .   | .   | .   | .   | .   | .   |
| **6** | .   | .   | .   | .   | .   | T   | T   | T   |
| **7** | .   | .   | .   | .   | .   | .   | .   | .   |
| **8** | .   | .   | .   | .   | .   | .   | .   | .   |

Si la hormiga reina se mueve a $(1, 5)$ sobre la diagonal, y salta a la termita-caballo, se salva.

||examplefile
sub1.sample2
||description

| -     | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- |
| **1** | T   | .   | .   | .   | .   | .   | .   | .   |
| **2** | T   | .   | .   | .   | .   | .   | .   | .   |
| **3** | T   | .   | .   | .   | R   | .   | .   | .   |
| **4** | T   | .   | .   | .   | .   | .   | .   | .   |
| **5** | T   | .   | .   | .   | .   | .   | .   | .   |
| **6** | T   | .   | .   | .   | .   | A   | .   | .   |
| **7** | T   | .   | .   | .   | .   | .   | .   | .   |
| **8** | T   | .   | .   | .   | .   | .   | .   | .   |

**Ninguna** posición es segura para la hormiga reina.

||end

# Límites

- $1 \leq n \leq 10^6$.
- $1 \leq k \leq 2 \times 10^5$.
- $1 \leq x_i, y_i \leq n$ para toda $1 \leq i \leq k$.
- Todas las termita-piezas y la hormiga reina se encuentran en posiciones diferentes.

# Subtareas

- **Subtarea 1 (19 puntos):**
  - $n = 8$.
- **Subtarea 2 (17 puntos):**
  - Solo hay termitas-torre.
- **Subtarea 3 (28 puntos):**
  - Solo hay termitas-torre y termitas-alfil.
- **Subtarea 4 (36 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

---

Movimientos de las piezas:

- La hormiga reina se puede mover a cualquier posición hacia arriba o abajo, sobre la columna; hacia la izquierda o derecha, sobre la fila o sobre las diagonales en las que se encuentra. La hormiga reina se puede mover al igual que una reina normal en el ajedrez, como se muestra en la imagen.

  ![Movimientos permitidos de la reina](movimientos-reina.png)

- Una termita-torre se puede mover hacia arriba o abajo, sobre la columna o hacia la izquierda o derecha, sobre la fila en la que se encuentra. Una termita-torre se puede mover al igual que una torre normal en el ajedrez, como se muestra en la imagen.

  ![Movimientos permitidos de la torre](movimientos-torre.png)

- Una termita-alfil se puede mover solamente en diagonal, en cualquiera de las 4 direcciones NE, NO, SE, SO. Una termita-alfil se puede mover al igual que un alfil normal en el ajedrez, como se muestra en la imagen.

  ![Movimientos permitidos de la alfil](movimientos-alfil.png)

- Una termita-caballo se mueve en `'L'`, es decir, hay 8 posibilidades asumiendo que inicialmente está en $(x, y)$: $(x+1, y+2)$, $(x-2, y+1)$, $(x-1, y-2)$, $(x+2, y-1)$, $(x+2, y+1)$, $(x-1, y+2)$, $(x-2, y-1)$, $(x+1, y-2)$. Una termita-caballo se puede mover al igual que un caballo normal en el ajedrez, como se muestra en la imagen.

  ![Movimientos permitidos de la caballo](movimientos-caballo.png)

---

![](reina.jpeg 'La hormiga reina en peligro.')

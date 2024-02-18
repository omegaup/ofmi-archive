Mickey y sus amigos se inscribieron a una carrera, pero no cualquier carrera, sino a la Mega Carrera OFMI de Jane Street (patrocinador oficial de la OFMI).

Mickey y sus amigos son $n$ corredores numerados de $0$ a $n-1$. Los corredores están posicionados en el kilómetro $0$ de la pista de carreras. Además, cada uno de ellos tiene una botella de $L$ litros de energía líquida (gracias a la magia de Mickey) que inicialmente está completamente llena. Para avanzar un kilómetro tienen que consumir un litro de su botella de energía.

El objetivo es alcanzar la mayor cantidad de kilómetros posible con al menos uno de los corredores.

Tú puedes indicarle a los corredores cuándo y cuánto avanzar. Adicionalmente, si dos corredores están en el mismo kilómetro uno de ellos puede transferirle energía al otro, siempre y cuando el corredor que recibe energía tenga suficiente espacio en su botella.

# Problema

Dados $n$, la cantidad de corredores, y $L$, la capacidad de la botella de energía, diseña una estrategia para correr la mayor cantidad de kilómetros con al menos uno de los corredores, indicándoles cuando avanzar y transefir energía.

# Implementación

Deberás implementar la función `avanzaMaximo(n, L)` que mande a llamar las funciones `mueve(i, k)` y `pasaEnergia(i, j, l)`.

# Tu función `avanzaMaximo`

`void avanzaMaximo(int n, int L)`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

## Parámetros

- `n` el numero de corredores.
- `L` la capacidad de la botella de energía de los corredores.

Dentro de esta función, deberás usar las funciones `mueve(i, k)` y `pasaEnergia(i, j, l)` para alcanzar la mayor cantidad de kilómetros posible con al menos uno de los corredores.

# Función del evaluador `mueve`

`long long int mueve(int i, int k)`

## Descripción

El evaluador te proveerá con esta función. Llama esta función para hacer avanzar al corredor con índice `i`, `k` kilómetros.

No deberás implementar esta función, solo llamarla.

## Parámetros

- `i` el índice del corredor que avanzará
- `k` la cantidad de kilómetros que avanzará el corredor

## Regresa

Un entero que indica el nuevo kilómetro que alcanzó el corredor o $-1$ si el corredor se quedó sin energía y no pudo avanzar los `k` kilómetros.

# Función del evaluador `pasaEnergia`

`int pasaEnergia(int i, int j, int l)`

## Descripción

El evaluador te proveerá con esta función. Llama esta función para que el corredor con índice `i`, le pase `l` litros de energía al corredor con índice `j`.

No deberás implementar esta función, solo llamarla.

## Parámetros

- `i` el índice del corredor que **pasa** energía
- `j` el índice del corredor que **recibe** energía
- `l` la cantidad de litros de energía que se pasan

## Regresa

Un entero que representa la nueva cantidad de energía del corredor `j`, o $-1$ si es un movimiento inválido (los corredores no estaban en el mismo kilómetro, el corredor `i` no tenía `l` litros para pasar o el corredor `j` no tenía suficiente espacio para aceptar los `l` litros)

**Nota:** Todas las funciones reciben y regresan enteros.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
avanzaMaximo(2, 100)
||output

- ||description
  El evaluador llama a tu función `avanzaMaximo`. Tienes entonces 2 corredores, cada uno con una botella de 100 litros llena.
  ||input
  mueve(0, 50)
  ||output
  50
  ||description
  Mueves al corredor $0$ al kilómetro 50. Ahora al corredor le quedan 50 litros.
  ||input
  mueve(1, 50)
  ||output
  50
  ||description
  Mueves al corredor $1$ al kilómetro 50. Ahora al corredor le quedan 50 litros.
  ||input
  pasaEnergia(1, 0, 50)
  ||output
  100
  ||description
  El corredor 1 le pasa su energía restante al corredor 0. El corredor 0 tiene nuevamente la botella llena con 100 litros de energía
  ||input
  mueve(0, 100)
  ||output
  150
  ||description
  Avanzar al corredor $0$ con los $100$ litros restantes hasta el kilómetro $150$.
  ||input
- ||output
- ||description
  Debido a que ambos corredores se quedaron sin energía, no puedes avanzar más. Tu función inicial `avanzaMaximo` retorna y $150$ es el kilómetro máximo que se alcanzó.
  ||end

# Límites

- $1 \leq n \leq 300$
- $2 \leq L \leq 10^9$
- No se te dará puntos si haces una llamada inválida

# Subtareas

- **Subtarea 1 (10 puntos):**
  - $n = 2$
- **Subtarea 2 (25 puntos):**
  - $n$ es potencia de dos.
  - $L = 2$
- **Subtarea 3 (65 puntos):**
  - Para esta subtarea se te darán un porcentaje puntos parciales respecto a qué tan lejos llegaste. Sea $Y$ el kilómetro máximo y $X$ la solución oficial. Tendrás entonces para ese caso sqrt(Y / X)

Las subtareas están agrupadas. Para la subtarea con puntos parciales se tomará el porcentaje mínimo que obtuviste.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con los valores $n$ y $L$. Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
2 100
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

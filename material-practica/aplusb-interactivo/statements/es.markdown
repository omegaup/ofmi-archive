Este problema consiste en crear un programa que sume dos números $A$ y $B$.

Inicialmente desconocerás el valor de $B$.

# Implementación

Deberás implementar las función `suma(A)` que mande llamar a la función `valorB()` y finalmente regresar la suma de $a+b$.

# Tu función `suma`

`int suma(int A);`

## Descripción

Tu envío deberá implementar esta función. El evaluador buscará en tu código esta función y la llamará con los parámetros descritos:

- `A` representa el valor de $a$ a sumar.

## Regresa

Tu función deberá regresar la suma de `A` más el parámetro desconocido `B`.

# Función del evaluador `valorB`

`int valorB();`

## Descripción

El evaluador te proveerá con esta función.

## Regresa

Esta función te devolverá el valor del parámetro `B`. Deberás llamar a esta función exactamente una vez para para saber el valor desconocido a sumar.

# Ejemplo

||input
Función llamada
||output
Valor devuelto
||description
Descripción
||input
suma(1)
||output
--
||description
El evaluador mandó a llamar a tu función `suma`, con $A=1$.
||input
valorB()
||output
2
||description
Llamamos a la función `valorB` para saber que $B = 2$.
||input
--
||output
3
||description
Ahora que sabemos $A$ y $B$, regresamos 3 en la función `suma`
||end

# Límites

- $1 \leq A, B \leq 1000$

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in` con dos valores $A$ y $B$, los números a sumar.

Para el caso de ejemplo anterior, `sample.in` se vería de la siguiente manera:

```
1 2
```

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

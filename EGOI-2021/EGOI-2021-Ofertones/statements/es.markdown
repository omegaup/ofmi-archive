Heidi está en una gran tienda. A ella le gustaría comprar artículos.

Hoy es su día de suerte. La tienda tiene una oferta especial: en cada compra, el cliente recibe una de las siguientes dos promociones:

1. Cuando se compran al menos artículos juntos, el más barato de ellos es gratis.
2. Cuando se compran menos de artículos juntos, el cliente obtiene un $q%$ de descuento en esa compra.

A Heidi le gustaría comprar todos los artículos de su lista de compras, cada artículo exactamente una vez. Ella puede realizar un número arbitrario de compras. Para cada compra que hará, se aplicará la promoción adecuada.

¿Cuál es el precio total mínimo que tiene que pagar para comprar los artículos?

# Entrada

La primera línea contiene dos enteros separados por un espacio $n$ y $q$ — el número de artículos que Heidi quiere comprar y el porcentaje de descuento que obtiene al comprar menos de tres artículos.

La siguiente línea contiene enteros separados por espacio $p_1$, ..., $p_n$ — los precios de los artículos.

Adicionalmente, se garantiza que cada $p_i$ siempre será divisible por 100. Así, el precio con descuento de cada compra será siempre un entero.

# Salida

Imprime un solo entero — el precio total mínimo que Heidi tiene que pagar para comprar todos los $n$ artículos.

# Ejemplo

||examplefile
sample
||description
Primero, Heidi puede comprar los tres artículos que cuestan 200 cada uno en una sola transacción por 400 (ella obtiene uno de los tres gratis). Luego puede comprar los tres artículos que cuestan 300 cada uno por 600 (de nuevo, uno es gratis). Finalmente, ella compra el último artículo faltante (de costo 100) con un de descuento.
||examplefile
sample2
||description
En el segundo caso de ejemplo, si Heidi compra los tres artículos en una sola transacción, recibe un descuento de . Sin embargo, si compra cada artículo individualmente, su descuento sería de .
||examplefile
sample3
||end

# Límites

- $1 \leq n \leq 10^5$
- $1 \leq q \leq 100$
- $100 \leq p_i \leq 10^5$

# Subtareas

- Subtarea 1 (8 puntos): $n = 3$ y $100 \leq p_i \leq 1000$
- Subtarea 2 (18 puntos): $q = 0$
- Subtarea 3 (16 puntos): $q = 40$
- Subtarea 4 (22 puntos): $100 \leq p_i \leq 1000$
- Subtarea 5 (36 puntos): No hay restricciones adicionales.
Bruna es una cobaya muy viejita. Tiene muchas descendientes. Cada domingo, les da su domingo a una miembro de su familia y a todas las descendientes de esa miembro. Esta miembro recibe $X$ pesos, sus hijas reciben $X/2$ pesos, sus nietas $X/4$ pesos, sus bisnietas $X/8$ pesos y así sucesivamente hasta darles su domingo a todas las descendientes de esa miembro. Las cobayas no tienen centavos, entonces solo se reparten los pesos completos, redondeando el resultado de la división hacia abajo.

# Problema

Tu tarea es que conociendo la estructura de esta familia, les ayudes a hacer cuentas.

Tendrás que procesar $Q$ operaciones. Hay 2 tipos de operaciones:

1. Tienes 2 enteros $i$ y $X$, que indican que la miembro $i$ recibió $X$ pesos.

2. Tienes 1 entero $i$, debes imprimir cuánto dinero tiene la miembro $i$ en este momento.

Al inicio del problema, nadie tiene dinero.

# Implementación

Deberás implementar tres funciones:

- `void familiaBruna(int N, int mama[])`: Donde `N` es el número de miembros de la familia que hay, y `mama` el arreglo de `N` enteros, donde para cada cobaya $i$, el $i$-ésimo entero ($y_i$) en el arreglo representa que la cobaya $y_i$ es mamá de la cobaya $i$. `-1` indica que es hija de Bruna; Bruna tiene exactamente una hija.
- `void depositarDinero(int i, int X)`: La primer operación descrita; la miembro $i$ recibe $X$ pesos.
- `int checarCuenta(int i)`: La segunda operación descrita; debes regresar cuánto dinero tiene la miembro $i$ en ese momento.

# Ejemplo

||examplefile
sample
||end

# Límites

- $1 \leq N,Q \leq 100,000$
- $1 \leq X \leq 10^9$
- $1 \leq i \leq N$

# Subtareas

- (10 puntos): $X = 1$
- (10 puntos): Solo se reparte dinero una vez, y es la primera operación.
- (10 puntos): $N,Q \leq 10^3$
- (10 puntos): Las operaciones de tipo 2 estarán hasta el final.
- (30 puntos): Cada miembro tiene a lo más una hija.
- (30 puntos): No hay consideraciones adicionales.

# Experimentación

{{libinteractive:download}}

El evaluador de prueba recibe el archivo `sample.in`, donde la primera línea contiene 2 enteros, $N$ y $Q$, separados por un espacio.

En la siguiente línea $N$ enteros separados por un espacio: Para cada cobaya $i$, el $i$ésimo entero ($y_i$) en la línea representa que la cobaya $y_i$ es mamá de la cobaya $i$. `-1` indica que es hija de Bruna; Bruna tiene exactamente una hija.

En las siguientes $Q$ líneas, las operaciones que debes procesar. En cada línea:

- Si es una operación de tipo `1`, habrá 3 enteros separados por un espacio. El primero es un `1` que indica que se mandará llamar a la funcián `depositarDinero` los siguientes enteros $i$ y $X$.
- Si es una operación de tipo `2`, habrá 2 enteros separados por un espacio. El primero es un `2` que indica que se mandará llamar a la función `checarCuenta` y el siguiente $i$.

_IMPORTANTE:_ El evaluador de prueba y el evaluador final que se usará para calificar tu solución son diferentes. El evaluador de prueba tiene la depuración de tu solución y puede implementar algunas de sus funciones de distinta manera.

---

![](inversiones.jpeg)

<figcaption align = "center"><i>Bruna con su fortuna.</i></figcaption>

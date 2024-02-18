Si $F$ es el arreglo que contiene los tipos de flores que la tía de Miguel recogió durante las $N$ noches, en este problema debemos contar cuántos valores diferentes hay en el arreglo $F$.

## Subtarea 1

La restricción para esta subtarea es que después de recoger $1$ o más flores del mismo tipo de manera consecutiva, la cantante nunca vuelve a recoger ningún tipo de flor que ya haya recogido antes. En otras palabras, todas las flores del mismo tipo aparecen juntas en el arreglo $F$. Por ejemplo, el arreglo $F$ podría verse así:

```
10, 10, 10, 2, 2, 2, 14, 14, 3, 3
```

pero no podría lucir así:

```
10, 2, 10, 2, 10
```

Si todos los valores del mismo tipo aparecen juntos en el arreglo, podemos contar fácilmente la cantidad de valores diferentes. Recorramos el arreglo de izquierda a derecha, cada vez que observemos que el valor en una posición $i$ es distinto al valor en la posición $i-1$, sabemos que hemos encontrado un nuevo tipo de valor. Por ejemplo, en el arreglo válido que antes mostramos, hemos marcado con $+1$ las posiciones que evidencían la aparición de un nuevo tipo de número.

```
+1         +1        +1      +1
10, 10, 10, 2 , 2, 2, 14, 14, 3, 3
```

Podemos entonces resolver la subtarea recorriendo el arreglo $F$ de flores y aumentando en uno un contador para la respuesta cada que encontremos un nuevo tipo de flor. La siguiente porción de código implementa esta parte del proceso:

```cpp
// En la variable distintos almacenamos la cantidad de números
// diferentes que hemos visto en el arreglo; aumentamos en uno su
// valor cada que vemos un cambio de número.
int distintos = 1;
for (int i = 1; i < n; i++) {
  if (F[i] != F[i - 1]) {
    distintos++;
  }
}
```

Una adaptación de esta misma idea nos será de utilidad para diseñar una solución de $100$ puntos.

## Subtarea 2

Para esta subtarea los valores $f_i$ son menores o iguales a $1000$. Estos límites nos permiten usar una estructura de datos auxiliar, como una _cubeta_.

Es decir, podemos definir un arreglo auxiliar `cubeta` de tamaño $1001$, en el que `cubeta[x]` será igual a $1$ si $x$ aperece en el arreglo $F$. Luego, la cantidad de valores distintos en $F$ será igual a la cantidad de posiciones en `cubeta` que tengan un $1$.

Por ejemplo, si el arreglo $F$ se ve así:

```
4, 5, 2, 1, 2, 4, 4, 5
```

Los valores en el arreglo `cubeta` serían:

```
índice: 0 1 2 3 4 5 6 ...
cubeta:  [0 1 1 0 1 1 0 ...]
```

Nota que `cubeta[1] = 1` porque $1$ aparece en el arreglo, pero `cubeta[0] = 0` porque $0$ no aparece en el arreglo; `cubeta[2] = 1` porque $2$ aparece en el arreglo, pero `cubeta[3] = 0` porque $3$ no aparece en el arreglo.

En este ejemplo, la cantidad de valores distintos es $4$ porque hay $4$ posiciones de la cubeta (los índices $1, 2, 4$ y $5$) que tienen un $1$.

Para resolver la subtarea debemos entonces recorrer el arreglo $F$ para _construir_ la cubeta y contar cuántas posiciones de la cubeta fueron marcadas. El siguiente fragmento de código ilustra esta idea:

```cpp
// En la variable distintos almacenamos la cantidad de numeros
// diferentes que hemos visto en el arreglo.
int distintos = 0;

std::cin >> n;
for (int i = 0; i < n; i++) {
  std::cin >> val;

  if (!cubeta[val]) {
    // Si la cubeta en la posición del valor que acabamos de leer
    // no estaba marcada, significa que acabamos de encontrar un
    // nuevo valor.
    distintos++;
    cubeta[val] = true;
  }
}
```

## Subtarea 3

Podemos hacer una solución análoga a la de la subtarea $2$. Lo que nos impide aplicar directamente la solución de la subtarea anterior es que para la subtarea $3$ los valores en el arreglo $F$ pueden ser negativos (y no podemos acceder a posiciones negativas en una cubeta). Sin embargo, el rango de posibles valores sigue siendo pequeño.

Podemos _transformar_ los valores de la entrada para forzar que todos sean no-negativos. Nota que si a cada valor original $f_i$ de la entrada le sumamos el valor mínimo para esta subtarea, $10,000$, el nuevo valor mínimo será $0$. Más aún, como a todos los valores les sumaremos el mismo número, la cantidad de números diferentes no se verá alterada.

Hacer esta transformación de los valores de la entrada nos permite hacer la misma solución que antes explicamos para la subtarea $2$.

## Subtarea 4

Recordemos la solución de la subtarea $1$. Esta solución funciona siempre que todos los valores del mismo tipo aparezcan juntos en el arreglo $F$. En un caso general, por su puesto, no podemos estar seguras de que esto ocurra. Sin embargo, si ordenamos los valores del arreglo $F$ se cumplirá que todos los valores del mismo tipo aparecerán juntos, lo que nos permitirá hacer el algoritmo que describimos para la subtarea $1$.

En otras palabras, para obtener los puntos completos de este problema podemos ordenar el arreglo $F$ y luego contar la cantidad de cambios en el arreglo ordenado (como antes hicimos para la subtarea $1$).

La complejidad de este algoritmo es $O(n log n)$, ya que hay que ordenar el arreglo (complejidad $O(n log n)$) y luego recorrerlo una vez para contar los cambios de valor (complejidad $O(n)$).

```cpp
int n;
std::cin >> n;  /// Lee la primera linea.
int nums[n];
for (int i = 0; i < n; ++i) {  /// Lee los n enteros de la segunda linea
  std::cin >> nums[i];
}

/// Ordenamos los numeros para tener todos los iguales
/// consecutivos
std::sort(nums, nums + n);

/// La variable 'cnt' nos servira para contar los cambios de valor.
/// Siempre hay al menos un valor (1 <= n <= 10^6).
int cnt = 1;
for (int i = 1; i < n; ++i) {
  /// Si el numero actual es diferente del anterior,
  /// entonces acabamos de cambiar de valor.
  if (nums[i] != nums[i - 1]) cnt++;
}
```

Una solución alternativa a este problema se basa en el concepto de cubetas que antes vimos para las subtareas $2$ y $3$. No podemos utilizar una cubeta, tal cual la describimos, para resolver el problema completo porque el rango de valores que puede haber en $F$ es muy grande (y la cubeta debe ser tan grande como el valor más grande en $F$). Sin embargo podemos servirnos de una estructura como _set_ (puedes leer más sobre esta estructura [aquí](https://cplusplus.com/reference/set/set/)) para que haga las veces de cubeta.

En específico, recorreremos el arreglo $F$ e insertaremos cada valor que encontremos en un set (como si lo insertaramos en una cubeta). Finalmente, el tamaño del set después de haber insertado todos los elementos nos dirá la cantidad de elementos distintos en $F$ (así como antes la cantidad de unos en la cubeta nos decía la respuesta).

```cpp
/// Declaramos un set que contiene enteros.
std::set<int> diferentes;
int n;
std::cin >> n;  /// Lee la primera linea.

while (n--) {
  int x;
  /// Lee cada uno de los n enteros de la segunda linea.
  std::cin >> x;

  /// Inserta cada uno de los n enteros de la segunda linea
  /// en el set en tiempo O(log T), siendo T el tamanio de 'diferentes'
  diferentes.insert(x);
}  /// Tiempo total: O(n log n)

/// La respuesta es la cantidad de elementos diferentes,
/// esto es, el tamanio del set.
std::cout << diferentes.size() << '\n';
```

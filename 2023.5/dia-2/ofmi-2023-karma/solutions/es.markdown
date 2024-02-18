## Subtarea 1

Para esta subtarea se cumple siempre que $M = 1$, es decir, Jessie y Tiro al Blanco son los primeros en llegar al registro. Para resolver esta subtarea basta entonces encontrar la rutina con dificultad máxima, y luego verificar si dicha dificultad tiene un valor mayor a $0$. Podemos encontrar dicho elemento recorriendo el arreglo una vez, por lo que la complejidad del algoritmo es $O(N)$.

```cpp
// Leemos los n elementos del arreglo.
for (int i = 0; i < n; ++i) {
  std::cin >> A[i];
}

// Solución para la subtarea 1: buscar el mayor elemento del arreglo y
// verificar que sea positivo.
int idxMayor = 0;
for (int i = 1; i < n; i++) {
  if (A[i] > A[idxMayor]) {
    idxMayor = i;
  }
}

if (A[idxMayor] > 0) {
  std::cout << A[idxMayor] << "\n";
} else {
  std::cout << "sencillo\n";
}
```

## Subtarea 2

Para esta subtarea ya no se cumple que $M=1$, sin embargo, los límites para $N$ ($N \leq 1000$) nos permitirán simular el proceso de registro de los equipos.

Para cada equipo en el registro simulemos cómo elige la rutina más difícil que quede disponible. Recorramos el arreglo de dificultades para encontrar la rutina con mayor dificultad, ignorando aquellas rutinas que ya hayan sido seleccionadas por algún otro equipo. Una vez que encontremos la rutina que le será asignada al equipo en turno, indiquemos, en un arreglo auxiliar, que la rutina ya no puede ser elegida por otros equipos. Repitamos este proceso $M$ veces, para llegar al turno de Jessie y Tiro al Blanco.

Nota que esta idea es similar a la da subtarea anterior, la diferencia es que el proceso de buscar el elemento mayor en el arreglo se repetira $M$ veces (una por cada equipo que pasa al registro) y en cada una de estas iteraciones ignoramos los elementos que ya han sido asignados. La complejidad del algoritmo es $O(NM)$, pues recorremos el arreglo de $N$ elementos $M$ veces. El siguiente es un fragmento de la implementación de esta idea. En ella se guardan los valores de las dificultades de las rutinas en un arreglo $A$, y se usa un arreglo auxiliar `usado` para marcar las rutinas que ya han sido seleccionadas por algún equipo.

```cpp
// Simulamos el proceso: hacemos m iteraciones y para cada una
// de ellas buscamos el mayor elemento del arreglo que no ha
// sido previamente usado.
int idxMayor;
while (m--) {
  idxMayor = -1;
  for (int i = 0; i < n; i++) {
    if (usado[i]) {
      continue;
    }
    if (idxMayor == -1 or A[i] > A[idxMayor]) {
      idxMayor = i;
    }
  }
  usado[idxMayor] = true;
}

if (A[idxMayor] > 0) {
  std::cout << A[idxMayor] << "\n";
} else {
  std::cout << "sencillo\n";
}
```

## Subtarea 3

En esta subtarea todas las dificultades de las rutinas son $1$ o $0$. Por la manera en que los equipos seleccionan la dificultad de sus rutinas, sabemos que primero serán elegidas todas las rutinas con dificultad $1$ y luego todas las rutinas con dificultad $0$.

Como Jessie y Tiro al Blanco solo eligirán rutinas con dificultades mayores a $0$, para esta subtarea su única alternativa es que alcancen a elegir una con dificultad $1$ o no elegir ninguna rutina. Para que puedan elegir una rutina de dificultad $1$, la cantidad de rutinas con dificultad $1$ debe ser mayor o igual a $M$ (es decir, debe haber suficientes rutinas con dificultad $1$ para que ellos alcancen a elegir una cuando les llegue su turno).

```cpp
// Leemos los n elementos del arreglo; solo contamos cuántos unos hay.
int num;
int unos = 0;
for (int i = 0; i < n; ++i) {
  std::cin >> num;
  if (num == 1) {
    unos++;
  }
}

if (m <= unos) {
  std::cout << "1\n";
} else {
  std::cout << "sencillo\n";
}
```

## Subtarea 4

Así como en la subtarea anterior contamos cuántos unos había en el arreglo, para esta subtarea, en la que los valores de las dificultades están entre $-100$ y $100$, podemos contar cuántas veces aparece cada número usando una cubeta. Es decir, definamos un arreglo auxiliar `cubeta` que cumpla que `cubeta[x]` es igual a la cantidad de veces que aparece $x$ en el arreglo de dificultades de las rutinas. Nota que podemos ignorar las rutinas de dificultad menor o igual a $0$ y no registrarlas en la cubeta, porque Jessie y Tiro al Blanco nunca elegiran ninguna de esas rutinas.

Habiendo construido la cubeta como antes describimos, nos será posible simular el proceso de registro de los equipos. A diferencia de la Subtarea $2$, sin embargo, no será necesario recorrer todo el arreglo para saber la dificultad de la rutina que le toca a un equipo. Sabemos que los primeros equipos en llegar intentarán elegir rutinas de dificultad $100$, y cuando estas se acaben los siguientes equipos intentarán elegir rutinas de dificultad $99$, y así sucesivamente hasta que se acaben las rutinas de dificultad positiva.

Podemos entonces simular el proceso de registro de la siguiente manera: Mantengamos una variable que nos indique cuántos equipos faltan por registrarse para llegar al de Jessie; al inicio esta variable es igual a $M$. Recorramos la cubeta de derecha a izquierda, comenzando por la dificultad máxima para la subtarea, $100$. En cada paso, restemos al faltante de equipos el valor de la cubeta en la posición actual (esto lo hacemos porque sabemos que los siguientes equipos por elegir rutina agotarán las rutinas con la dificultad actual). Hagamos esto mientras el faltante de equipos por registrar sea positivo o hasta llegar a la posición $0$ de la cubeta, en cuyo caso sabremos que Jessie no podrá elegir una rutina de dificultad positiva.

El siguiente código ilustra el proceso de construir la cubeta y el de la simulación del registro.

```cpp
int n, m;
std::cin >> n >> m;

int num;
for (int i = 0; i < n; ++i) {
  std::cin >> num;
  if (num > 0)
    cubeta[num]++;
}

int idx = 100;
while (m > 0 && idx > 0) {
  m -= cubeta[idx];
  if (m > 0) {
    idx--;
  }
}

if (m > 0) {
  std::cout << "sencillo\n";
} else {
  std::cout << idx << "\n";
}
```

## Subtarea 5

Nota que si $M = 1$, se nos pide encontrar el elemento mayor del arreglo. Cuando $M = 2$, debemos encontrar el segundo elemento más grande del arreglo. Cuando $M = 3$, debemos encontrar el tercer elemento más grande. Y, en un caso general, para un valor dado de $M$ debemos encontrar el $M$-ésimo elemento más grande del arreglo.

Una manera de encontrar dicho elemento es ordenar el arreglo original de mayor a menor. En el arreglo ordenado, el $M$-ésimo elemento más grande se econtrará en la posición $M$. Faltará solo verificar si dicho valor es positivo, para que pueda ser elegido por Jessie y Tiro al Blanco.

```cpp
// Leemos las variables de entrada n y m.
int n, m;
std::cin >> n >> m;

// Leemos los n elementos del arreglo.
for (int i = 0; i < n; ++i) {
  std::cin >> a[i];
}

// Ordenamos el arreglo de mayor a menor.
std::sort(a, a + n);
std::reverse(a, a + n);

if (a[m - 1] > 0) {
  // Si el m-esimo elemento es positivo, lo imprimimos.
  std::cout << a[m - 1] << std::endl;
} else {
  std::cout << "sencillo" << std::endl;
}

return 0;
```

La complejidad de este algoritmo es la complejidad de ordenar un arreglo de tamaño $N$, $O(N log N)$.

Notarás que, en muchos problemas, ordenar los elementos del arreglo es de gran utilidad.

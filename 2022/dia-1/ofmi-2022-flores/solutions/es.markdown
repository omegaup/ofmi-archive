# Flores crecientes - Solución

## Descripción

Antes de comenzar con el problema, aclaramos que hay dos formas de interpretar las coordenadas que nos comparte el problema. Una de ellas es interpretar las coordenadas como puntos en el plano cartesiano, mientras que la otra es interpretarlas como posiciones en una cuadrícula de tamaño infinito. Aunque son similares, cada una tiene sus ventajas al momento de procesar la información. A continuación les describiremos las soluciones usando la interpretación donde las coordenadas son puntos en el plano cartesiano, sin embargo, en la carpeta de soluciones se encuentran códigos con la interpretación de posiciones en cuadrícula para quienes gusten verlas.

El problema nos plantea una dinámica que tiene lugar en el plano cartesiano, en el que es posible, en vez de manipular coordenadas, interpretarlo como un grafo que nos permitirá elaborar diferentes ideas en torno a la búsqueda de caminos. Consideremos el siguiente caso de prueba después de haber transcurrido dos minutos:

![Entrada](Entrada.png)

Los cuadros púrpuras representan una flor; La flor ubicada en la posición (9, 1) ha llegado al máximo de su crecimiento por lo que es más pequeña que el resto de las flores que aún no terminan de crecer. Desde la posición de la entrada es posible saltar únicamente a la flor ubicada en la posición (2, 1), que a su vez, desde esta flor se puede saltar a las flores ubicadas en la posición (4, 4) y (6, 2).

Si representamos con un nodo a cada flor del mundo, podemos conectar con una arista a cada par de flores donde sea posible saltar de una a otra en el momento $t$. De esta forma, obtendremos un grafo como el siguiente:

![EntradaGrafo](EntradaGrafo.png)
Podemos aclarar desde ahora que, la entrada y salida tendrán sus propios nodos, y estos se pueden conectar con las flores **sólo** si estas flores cubren completamente a dichas posiciones.
Recordemos que para que dos flores estén conectadas, estás pueden coincidir en las esquinas, en los lados, o compartir una posición que ambas estén cubriendo.

Para saber si es posible llegar a la salida en el momento $t$ basta con encontrar un camino desde un nodo que represente a la entrada hasta un nodo que represente a la salida. Esto lo hacemos utilizando algoritmos de búsqueda como [DFS](https://www.programiz.com/dsa/graph-dfs) o [BFS](https://www.programiz.com/dsa/graph-bfs).

En la imagen de arriba se observa que no existe un camino que nos lleve desde el nodo que representa a la entrada hasta el nodo que presesenta a la salida, por lo que podemos decir que hasta el momento $t = 2$ no es posible llegar a la salida.

Por sencillez, los nodos que representan a la entrada y a la salida pueden ser tratados como flores con límite de crecimiento igual a $0$. De esta forma la entrada de nuestro programa puede quedar como el siguiente código:

```
struct Flor {
  int x, y, limite;
};

int main() {
  std::cin >> n >> m;
  n += 2;
  // Creamos un arreglo de n + 2 flores
  flores = std::vector<Flor>(n);
  const int ENTRADA = 0;
  const int SALIDA = 1;

  /* A continuación leemos la ubicación de
   * la entrada, la salida y de las flores */
  for (auto &[x, y, _] : flores)
    std::cin >> x >> y;
  // Leemos el límite de crecimiento de cada flor
  for (int i = 2; i < n; i ++)
    std::cin >> flores[i].limite;

  ...
}
```

## Subtarea 1

Para obtener los puntos de la primera subtarea podemos iterar sobre los valores de $t$ de menor a mayor, ejecutando en cada iteración nuestro algoritmo de búsqueda y terminando en el primer tiempo $t$ en el que se encuentre un camino hacia la salida. Podemos decir que no es posible llegar a la salida si nuestro algoritmo de búsqueda no encuentra un camino en el momento más alto posible ($t = 100$). El límite de tiempo es 100 puesto que, suponiendo que las flores crecen lo máximo posible, en 100 minutos ya habrán cubierto todas las posiciones posibles que hay entre (0, 0) hasta (100, 100).

El código de esta solución puede ser el siguiente:

```
bool conectan(Flor a, Flor b, int tiempo);

bool dfs(int tiempo, int actual, int salida) {
  // Verificamos si llegamos a la salida
  bool encontrado = actual == salida;
  // Marcar nodo actual como visitado
  visitado[actual] = true;

  for (int nodo = 0; nodo < n; nodo ++) {
    // Exploramos vecinos no visitados
    if (!visitado[nodo]) {
      Flor a = flores[actual];
      Flor b = flores[nodo];
      if(conectan(a, b, tiempo)) {
        // Buscamos un camino por este nodo
        encontrado |= dfs(tiempo, nodo, salida);
      }
    }
  }
  return encontrado;
}

int main() {
  ...

  const int MAX_T = 100, t;
  for (t = 0; t <= MAX_T; t ++) {
    // Inicializar arreglo de nodos visitados
    visitado.resize(n);
    std::fill(visitado.begin(), visitado.end(), 0);

    if(dfs(t, ENTRADA, SALIDA))
      // Respuesta encontrada
      break;
  }

  if (t >= MAX_T)
    std::cout << "-1\n"; // Imposible llegar
  else
    std::cout << t << "\n";
  return 0;
```

Para este programa el algoritmo de búsqueda utilizado fue DFS. El tiempo de ejecución de este algoritmo es de $O(V + E)$ donde $V$ es el número de nodos y $E$ es el número de aristas. Nótese que para este problema el número de nodos es $N$ y el número máximo de aristas es $N^2$. De esta forma el tiempo de ejecución final de esta solución es de $O(T \times (N + N^2))$ donde $T$ es el tiempo máximo que puede pasar para que podamos encontrar un camino en caso de que exista, que a su vez también es la distancia máxima que puede existir de la entrada a la salida en cualquiera de los ejes.

Este tiempo de ejecución es suficiente para obtener los puntos de la primera subtarea, sin embargo, esta solución está sujeta a que el tiempo de ejecución de la función `conectan` (la cual no hemos implementado aún) tenga tiempo constante $O(1)$.

## Subtarea 2

Para implementar la función `conectan` nos enfocaremos primero en la segunda subtarea. En esta subtarea podemos representar el área que abarca una flor en el momento $t$ como una línea recta, utilizando los valores $l_i$ y $r_i$ que representan el punto en la recta númerica en el que inicia la flor y en el que termina, respectivamente. En la siguiente imagen observaremos 4 ejemplos en los que comparamos si 2 flores intersectan:

![InterseccionRectas](InterseccionRectas.png)

Sin pérdida de la generalidad, podemos decir que 2 flores intersectan si $max(l_1, l_2) <= min(r_1, r_2)$.

Para saber si dos cuadrados intersectan (como en las subtareas 1 y 3) es suficiente con aplicar la misma idea con cada uno de los ejes y asegurarnos de que existe una intersección en cada eje.

![InterseccionCuadro](InterseccionCuadro.png)

De esta forma el código para la función `conectan` puede quedar de la siguiente forma:

```
typedef long long ll;
const int oo = 3e5;

bool conectan(ll l1, ll r1, ll l2, ll r2) {
  return std::max(l1, l2) <= std::min(r1, r2);
}

bool conectan(Flor a, Flor b, ll tiempo) {
  // Preparar líneas de flor a
  ll limite = a.limite == -1 ? oo : a.limite;
  ll x1_a = a.x - std::min(m * tiempo, limite);
  ll x2_a = a.x + std::min(m * tiempo, limite);
  ll y1_a = a.y + std::min(m * tiempo, limite);
  ll y2_a = a.y - std::min(m * tiempo, limite);
  // Preparar líneas de flor b
  limite = b.limite == -1 ? oo : b.limite;
  ll x1_b = b.x - std::min(m * tiempo, limite);
  ll x2_b = b.x + std::min(m * tiempo, limite);
  ll y1_b = b.y + std::min(m * tiempo, limite);
  ll y2_b = b.y - std::min(m * tiempo, limite);

  // Evaluar el eje horizontal y vertical
  return conectan(x1_a, x2_a, x1_b, x2_b) &&
    conectan(y2_a, y1_a, y2_b, y1_b);
}
```

Por la naturaleza de esta subtarea, es posible resolverlo de muchas formas. Es posible abstraer el problema y verlo como en una línea: Queremos ver si con los rangos disponibles es posible conectar un punto A con un punto B (cubrir todos los números entre A y B). En la carpeta de soluciones hay códigos para esta subtarea que usan [Union-Find](https://cp-algorithms.com/data_structures/disjoint_set_union.html), algoritmos greedies, y BFS. Un ejemplo de un algoritmo greedy es el siguiente:

<details><summary>Una de las soluciones para la subtarea 2</summary>

{{subtask_2_mover_derecha.cpp}}

</details>

## Subtarea 3 y solución completa

A pesar de que tenemos lista la función `conectan`, la solución que implementamos hasta ahora no nos permite resolver los casos de las subtareas 2 y 3 debido a que daría [Tiempo Límite Excedido](https://www.instagram.com/p/CY2O6-BPDvA/). Es necesario implementar una solución más rápida. La última observación que nos permitirá resolver los casos de la subtarea 3 y 4 es la transitividad de la función DFS sobre el tiempo:

![Transitividad](Transitividad.png)

Se puede observar que a partir del primer momento $t'$ en el que el algoritmo de búsqueda DFS encuentra un camino desde la entrada hasta la salida, todas las ejecuciones de $DFS(t >= t' )$ también encontrarán un camino hacia la salida, y todas las ejecuciones de $DFS(t < t')$ no encontrarán ningún camino hacia la salida. De esta forma podemos aplicar búsqueda binaria para obtener una solución con un tiempo de ejecución de $O(log_2(T) \times (N + N^2))$, donde $T = 2 \times 10 ^ 5$.

El código de esta solución puede ser el siguiente:

<details><summary>Solución completa del problema</summary>

{{solutionC.cpp}}

</details>

Las invitamos a checar las demás soluciones disponibles para que vean distintas implementaciones.

<details><summary>Otra solución completa - las coordenadas son posiciones de cuadrícula</summary>

{{solution.cpp}}

</details>

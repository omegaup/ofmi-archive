# Bruna - Solución

### Algunas observaciones

- Nótese que en este problema las relaciones de parentesco pueden ser representadas como un grafo, para ser más específicos como un árbol unidireccional. Dicha representación se puede hacer de varias formas; se puede implementar con una lista de adyacencia, o también representarlo de forma dinámica. Recomendamos usar la representación que les parezca más sencilla. En las soluciones que veremos a continuación usaremos un arreglo en donde `arreglo[x] = y`, representa que `y` es la madre de `x`, y dado que que cada miembro tiene una sola madre, esta representación funciona.

- Máxima profundidad de derrame del dinero: Llamaremos derrame del dinero a este fenómeno descrito en el problema, en el cual si la cobaya $i$ tiene $x$ pesos, entonces su hija tendrá $\lfloor {x/2} \rfloor$, y su nieta tendrá $\lfloor {x/4} \rfloor$, y así, sucesivamente. Nótese que eventualmente todas las descendientes en cierto punto, obtendrán 0 pesos como efecto de esta actualización. Veamos cómo podemos calcular, en el mejor de los casos, cuántas podrán tener dinero con una sola actualización. Dicho derrame máximo sucederá cuando el dinero sea el máximo posible, es decir, cuando el dinero sea $10^9$. Podemos calcular a cuántas descendientes son posibles de alcanzar con una actualización: siendo precisos la actualización llegará a una profundidad de $\log_2 10^9$, esto es redondeando $30$, por lo que este será nuestro máximo de profundidad. Este es el máximo porque $\lfloor\frac{10^9}{2^{30}}\rfloor = 0$.

- Es necesario usar `long long int` para obtener 100 puntos, nótese que en el peor de los casos, cuando se le da todo el dinero posible a una cobaya, entonces, está tendrá $10^9 \cdot 10^5 = 10^{14}$ pesos, si preguntáramos cuánto dinero tiene esta cobaya, usando un `int` veríamos que no nos daría el resultado esperado, ya que $10^{14}$ esta por encima del rango de un `int`.

<br/>

## Subtarea 1 (10 puntos)

Ya que para esta subtarea el dinero que se le puede dar a una miembro de la familia solo es 1 peso, sus hijas recibirán 1/2 pesos, lo cual, de acuerdo con la redacción del problema, sería equivalente a 0. Por tanto, ninguna de sus descendientes recibirán dinero.

Con esta observación, vemos que solo tendrá dinero quién indique la actualización, y las demás descendientes no recibirán dinero, por ello podemos omitir en su totalidad el parentesco de cada cobaya, simplificando así el problema a tener solo un arreglo de cobayas (cubetas) de tamaño n, en este se actualiza el dinero que recibe cada cobaya en su respectiva posición, y cuando se pregunta cuánto dinero tiene una cobaya, solo se imprime lo que tiene el arreglo en la posición de la cobaya.

Esta solución tiene una complejidad en tiempo de $O(Q)$.

<br/>

<details><summary>Solución para la subtarea 1 (10 puntos)</summary>

{{subtask_1_X_1.cpp}}

</details>

<br/>

## Subtarea 2 (10 puntos)

Para esta subtarea se nos dice que el dinero se reparte solo una vez, sin embargo, como el dinero será mayor a 1, entonces se podrá "derramar" dinero sobre las demás descendientes, por lo que, ahora sí importa conservar este parentesco. Vamos a implementar una forma de representar el parentesco.

En la solución presentada a continuación se usó una lista de adyacencia, lo primero que se hace es implementar la función $update$, que lo que hace es dispersar el dinero de la forma descrita en el problema haciendo el recorrido por las descendientes de la miembro actual, asignándole el correspondiente dinero a cada una de ellas si es que el dinero es mayor a 0, después, de forma recursiva, se llama a la función $update$ para cada una de las descendientes. El dinero que obtuvo cada cobaya queda almacenado en el arreglo $ganancias$, que nos servirá para contestar todas las preguntas de tipo 2. Para cada pregunta de tipo 2, lo único que debemos hacer es imprimir el valor del arreglo $ganancias$ en la posición de la cobaya que se pregunta.

<br/>

<details><summary>Solución para la subtarea 2 (10 puntos)</summary>

{{subtask_2_update_al_inicio.cpp}}

</details>

<br/>

## Subtarea 3 (10 puntos)

Esta solución lleva a cabo las mismas dinámicas que la solución presentada en la subtarea 2, tanto de cómo se usa la función $update$, cómo de contestar cuánto dinero tiene cada cobaya. La diferencia esta en que aquí se implementa de una forma distinta de tal manera que podamos aplicar actualizaciones y preguntas en cualquier orden.

<br/>

<details><summary>Solución para la subtarea 3 (10 puntos)</summary>

{{partial_30pts_padre_actualiza_hijos.cpp}}

</details>

<br/>

## Subtarea 4 (10 puntos)

Para esta subtarea se tendría que explotar la propiedad mencionada en que primero se hacen todas las reparticiones de dinero entre las miembro, y finalmente se hacen las queries de tipo 2.

Si bien no se presenta una solución que hace un uso completo de esta propiedad, presentamos una solución que tiene una idea relacionada, en esta solución presentada lo que se hace es construir el árbol de parentescos con un solo arreglo que apunta a la madre de cada cobaya, posteriormente lo que se hace es en cada nodo de este árbol, tener un apartado también de ganancias, entonces cada que se hace un update, simplemente se le agrega la ganancia a la cobaya correspondiente, mas no a sus descendientes. Así tenemos las updates en una sola operación. Después cuando nos preguntan por el dinero de una cobaya, tenemos la función $obtenGanacias$, está, lo que hace es decir: "yo tengo el dinero que me dieron a mi, pero también tengo la mitad del de mi madre, y un cuarto del de mi abuela y un octavo el de mi bisabuela, y así sucesivamente", limitándonos a calcular el dinero que tiene cada cobaya hasta llegar a la raíz de la familia, o bien, a la `máxima profundidad de derrame del dinero`.

La implementación que presentamos tiene un detalle por el cual no daría la respuesta correcta en todos los casos. Este error es debido al hecho de que no se cumple para toda $x$ que $ x  + \lfloor \frac{x}{2} \rfloor + \lfloor \frac{x}{4} \rfloor + ... \neq \lfloor x + \frac{x}{2} + \frac{x}{4} + ...\rfloor$.

<br/>

<details><summary>Codigo de idea para subtarea 4 (10 puntos)</summary>

{{partial_10pts_queries_comprimidas.cpp}}

</details>

<br/>

## Subtarea 5 (30 puntos)

En esta subtarea cada miembro de la familia tendrá a lo más una madre y una hija, por lo que el árbol, en realidad será una sola "fila" que podemos interpretar como una lista. En la solución que presentamos, tomamos ventaja de este hecho para representar el árbol de la siguiente forma: `arreglo[x] = y`, donde `x` es la madre de `y`. A partir de ello se sigue una solución muy similar a la presentada en la subtarea 3 o 4 adaptada a esta representación del grafo.

<br/>

<details><summary>Solución para la subtarea 5 (30 puntos)</summary>

{{subtask_5_lista.cpp}}

</details>

<br/>

## Solución completa

<br/>
Para explicar la solución completa nos basaremos en el código descrito en $solutionB.cpp$.
 
Este código, es de hecho la corrección del presentado en la subtarea 4, reparando el detalle por el que aquella solución no funciona. Aún así, explicaremos a detalle todo el código.
 
Lo primero es la forma en que representamos el árbol:

```c++
struct Nodo {
    std::vector<long long> ganancias_hijos;
    int madre;
} arbol[MAX_N];
```

Lo que estamos usando aquí es la idea propuesta de que cada miembro tiene solo una madre, entonces con esto podemos representar el grafo, a su vez, cada nodo del árbol, tendrá un arreglo de ganancia de hijas, este sirve para corregir el error de la subtarea 4. Llevando en este las ganancias de las hijas de cada cobaya de forma individual, y sin mezclarlas con la de los demás, evitando así errores al sacar la función piso después de dividir entre dos. Veremos más a detalle a continuación.

```c++
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numNodos, numQueries;
    std::cin >> numNodos >> numQueries;

    for (int i = 1; i <= numNodos; i++) {
        int madre;
        std::cin >> madre;
        arbol[i].madre = madre;
        arbol[i].ganancias_hijos.assign(MAX_PROFUNDIDAD + 2, 0LL);
    }
```

Veamos las primeras líneas de la función `int main`; las primeras dos líneas nos sirven para leer e imprimir rápido los datos, esto es necesario por la gran cantidad de datos que vamos a manejar. Después leemos el número de nodos y el número de preguntas. Posteriormente leemos quién es la mamá de cada una de las $i$ cobayas. A su vez se inicializa para cada una de las cobayas su arreglo de las ganancias de sus hijas, que va a tener una longitud igual a `máxima profundidad de derrame del dinero` mas una holgura de dos para tener mayor seguridad al momento de programar, además, inicializamos la ganancias de sus hijas con 0.

Analicemos cómo procesamos cada pregunta:

```c++
    for (int i = 0; i < numQueries; i++) {
        int tipoQuery, nodo;
        long long cantidad;
        std::cin >> tipoQuery >> nodo;
        if (tipoQuery == ACTUALIZA_GANANCIAS) {
            std::cin >> cantidad;
            for (int j = 0; cantidad; j++) {
                arbol[nodo].ganancias_hijos[j] += cantidad;
                cantidad /= 2;
            }
        } else {
            std::cout << obtenGanancias(nodo, 0) << "\n";
        }
    }
```

Hacemos un ciclo `for` para leer cada pregunta; leemos el tipo y a qué nodo involucra, y si es para actualizar ganancias, leemos la cantidad. Lo que se procede a hacer es ir dividiendo la cantidad entre 2 y aplicar la función piso (como manejamos datos enteros, en C++ se redondea al entero hacía abajo de forma predeterminada). Repetimos el proceso hasta que la cantidad sea 0. Con estas cantidades que se van obteniendo se llena el arreglo de `ganancias_hijos`, el cual usaremos de la siguiente forma: `ganancias_hijos[0]` es la ganancia de la cobaya original, a la que se le da la cantidad completa, `ganancias_hijos[1]` será el dinero que se le da a las hija de la cobaya que recibió todo el dinero, `ganancias_hijos[2]` será el dinero que se le de a las nietas de la cobaya que recibió el dinero, y así sucesivamente. Este proceso tiene una complejidad en tiempo de $O(\log_2 cantidad)$.

Ahora que sabemos cómo hacer la actualización de dar dinero a una cobaya, nos queda por ver cómo hacer la pregunta para obtener cuánto dinero tiene la cobaya en la posición `nodo`.

Para esto vemos que se llama a la función `obtenGanancias(nodo, 0)`. Veamos que hace esta función.

```c++
long long obtenGanancias(int nodo, int ancestro) {
  if (nodo == -1 || ancestro >= MAX_PROFUNDIDAD) return 0;
  return arbol[nodo].ganancias_hijos[ancestro] +
         obtenGanancias(arbol[nodo].madre, ancestro + 1);
}
```

Esta función nos dice que si el nodo es `-1` o el número de ancestro en el que va la recursión es mayor o igual a `máxima profundidad de derrame del dinero` (este es nuestro caso base), entonces retornamos 0 (neutro aditivo), de lo contrario, retornamos la ganancia que la cobaya original obtiene de la ancestro en la que está parada, y le suma la ganancia que le da la ancestro de la ancestro actual.

Este procedimiento tiene una complejidad en tiempo de $O(MaxProfundidad) = O(\log_2 (x))$ donde $x$ es el dinero de la cobaya.

### Complejidad

$O(Q \cdot \log_2 (x))$.

En el peor de los casos $Q$ será $10^5$ y $x$ será $10^9$.

Para saber en cuántos segundos se supone que esto debería correr hacemos el siguiente cálculo:

$\frac{10^5 \cdot \log_2 (10^9)}{2 \cdot 10^8} \approx 0.015$

Lo cual es menor a $1.5$ segundos.

<br/>

<details><summary><b>Solución Completa (100 puntos)</b></summary>

{{solutionB.cpp}}

</details>

<br/>

## Referencia

- Instrucciones por segundo en una computadora. Puedes hacer cerca de $2 \cdot 10^8$ operaciones en C++ si estas operaciones son de bajo nivel (acceso a arreglos, sumas, desplazamiento de bits, multiplicaciones, restas, xors, etcétera). Los módulos y las divisiones son ligeramente mas lentas.

- Un `int` puede almacenar hasta $2^{31} - 1$ (el máximo valor de un `int` en C++) esto es menos de $10^{10}$ y más de $10^{9}$.

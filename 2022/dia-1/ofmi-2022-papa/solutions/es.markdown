# La papa caliente - Solución

La solución pensada para este problema es que programen una simulación del juego de la papa caliente entre Maeva, Lorena, y Ramona.

## Resolviendo a mano

Una observación particular de este problema es que los límites permiten poder hacer los casos a mano y escribir 27 sentencias `if`, y así obtener todos los puntos de este problema.

Si resolvemos todos los casos a mano, hay que tener cuidado de hacerlo en orden que no nos falte alguno o no repitamos el mismo caso varias veces.

<details><summary>Solución con 27 sentencias 'if'</summary>

{{solution_casos_a_mano.cpp}}

</details>

## Simulación

Hay diversas formas de simular el problema, una de ellas es la siguiente:

- Iniciamos una variable `tiempo` donde guardaremos el tiempo que ha transcurrido
- Sumamos el tiempo que Maeva conserva a la cobaya
- Si no nos hemos pasado de los 45 segundos, la cobaya pasaría a las manos de Lorena
- Sumamos el tiempo que Lorena conserva a la cobaya
- Si no nos hemos pasado de los 45 segundos, la cobaya pasaría a las manos de Ramona
- Sumamos el tiempo que Ramona conserva a la cobaya
- Si no nos hemos pasado de los 45 segundos, la cobaya regresa a las manos de Maeva, y se repite el proceso
- Si la variable `tiempo` llega a ser 45 o más, la cobaya mordería a la última persona y es el nombre que tenemos que imprimir

```cpp
int main() {
  int t_maeva, t_lorena, t_ramona;
  std::cin >> t_maeva >> t_lorena >> t_ramona;

  int tiempo = 0;
  while (tiempo < 45) {
    // Maeva tiene la cobaya
    tiempo += t_maeva;
    if (tiempo >= 45) {
      std::cout << "Ramona" << std::endl;
      return 0;
    }
    // Lorena tiene la cobaya
    tiempo += t_lorena;
    if (tiempo >= 45) {
      std::cout << "Lorena" << std::endl;
      return 0;
    }
    // Ramona tiene la cobaya
    tiempo += t_ramona;
    if (tiempo >= 45) {
      std::cout << "Ramona" << std::endl;
      return 0;
    }
  }
}
```

También pueden checar la solución que incluye comentarios:

<details><summary>Simulación de papa caliente</summary>

{{solution.cpp}}

</details>

Si $tiempos_{MLR}$ representa la suma de los tiempos de Maeva, Lorena, y Ramona (`tiempos_MLR = t_maeva + t_lorena + t_ramona`), y $tiempoMaximo$ el tiempo en que la cobaya se va a enojar, entonces la complejidad en tiempo de esta solución es $O(\frac{tiempoMaximo}{tiempo_{MLR})$, que, como $tiempoMaximo$ es 45 y $tiempos_{MLR}$ es al menos 3, en menos de 15 iteraciones debería de acabar la simulación.

## Constante

Esta solución la podemos conseguir después de analizar la simulación anterior. Denotaremos el tiempo que Maeva, Lorena, y Ramona conservan a la cobaya como `t_maeva`, `t_lorena`, y `t_ramona`, respectivamente.
Podemos hacernos las siguientes preguntas:

- ¿Cuánto tiempo habrá pasado después de un ciclo?
- ¿Cómo podemos saber si vamos a poder tener un ciclo más?
- Si no va a haber un ciclo más, ¿cuántos segundos restan para que la cobaya se enoje? y, ¿quién tendrá la cobaya en el último segundo?

Para que un ciclo (o iteración) transcurra, tienen que pasar al menos `t_maeva + t_lorena + t_ramona` segundos. Este tiempo se repetirá para todas las iteraciones, por lo que, si nos preguntan cuánto segundos habrán pasado después de $x$ iteraciones, es seguro decir que han pasado `x * (t_maeva + t_lorena + t_ramona)`.

Con la observación anterior, podemos saber cuántas iteraciones van a transcurrir antes de que se acabe el tiempo. Si `tiempo_MLR = t_maeva + t_lorena + t_ramona`, entonces transcurrirán $\left\lfloor \frac{tiempoMaximo}{tiempo_{MLR}}\right\rfloor$ iteraciones completas antes de que la cobaya se enoje.

En la última iteración, es donde podemos saber a quién morderá la cobaya.
Para hacer la última iteración, podríamos adelantar el tiempo hasta esta iteración (`tiempo = (tiempoMaximo / tiempo_MLR) * tiempo_MLR`, esto se cumple por los [redondeos de dividir enteros en C++](http://cym.wikidot.com/prog:division-entera-y-resto)). Otra alternativa es calcular el tiempo restante calculando el residuo de la división de `tiempoMaximo` y `tiempo_MLR`, que se calcula con el módulo, `tiempo_restante = tiempoMaximo % tiempo_MLR`.

Esta última iteración la podemos hacer como en la solución anterior.

La ventaja de esta solución es que podríamos tener números muy grandes y la cantidad de operaciones sería constante, esto es, siempre haríamos 5 operaciones, en vez de depender del tiempo, por ejemplo.

<details><summary>Solución en tiempo constante</summary>

{{solutionB.cpp}}

</details>

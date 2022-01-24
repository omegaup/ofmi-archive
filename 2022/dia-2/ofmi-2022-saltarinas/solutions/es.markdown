# Cobayas saltarinas - Solución

Calculemos $s_1, s_2, ..., s_Q$ de manera independiente. Es decir, hay que responder $Q$ preguntas donde la $i$-ésima pregunta es ¿Cuál es la menor cantidad de segundos $s_i$ que deben pasar para que las cobayas completen al menos $iX$ saltos en total?

Al final, hay que sumar las respuestas $s_1$, $s_2$, ..., $s_Q$ de cada una de estas preguntas e imprimirla módulo $10^9 + 7$.

### Primera observación

- Cada $16$ segundos se acumulan al menos $N$ saltos. Por lo tanto, para la $i$-ésima pregunta tenemos la cota $s_i \leq \frac{16iX}{N}$.

## Subtarea 1

Para esta subtarea, podemos enfocarnos en calcular el tiempo $s_i$ haciendo múltiples simulaciones. Esto sería, simular cada segundo mantener un contador de saltos, donde contaremos cada que salte una cobaya.

La i-ésima cobaya va a saltar en el segundo `t` si se cumple que `t % a[i] == 0`.

Por la primera observación, simular cada pregunta tendría una complejidad de a lo mucho $O(Q^2\cdot X)$, que es suficiente para los límites de esta subtarea.

<details><summary>Solución para la subtarea 1 (10 puntos)</summary>

{{subtask1_simulacion_individual.cpp}}

</details>

### Segunda observación

Las cobayas van a saltar siempre en los mismos segundos, por lo que simular los saltos repetidas veces nos dará los mismos resultados.

## Subtarea 2

Para esta subtarea, podemos simular los saltos de las cobayas hasta tener `QX` saltos, guardando en un arreglo los saltos que se hicieron en cada segundo.

Con dicho precalculo, podemos hacer un barrido para buscar en que segundo se consiguieron $iX$ saltos, o bien, una búsqueda binaria sobre el tiempo (que sería lo equivalente a buscar sobre las posiciones del arreglo).

Si optamos por la búsqueda binaria, tendríamos que preguntarnos si en el segundo `t` hay al menos `iX` saltos. En caso de serlo, nuestra respuesta para `iX` es **menor o igual** `t`, si no, es **mayor** a `t`.

Dependiendo si se implementa un barrido o una búsqueda binaria es la complejidad en tiempo que se obtiene. La búsqueda binaria tiene una complejidad de $O(QX + Q \cdot log(QX))$, mientras que la del barrido es $O(2QX)$.

<details><summary>Solución para la subtarea 2 con barrido (+20 puntos)</summary>

{{subtask2_simulacion_conjunto.cpp}}

</details>

<details><summary>Solución para la subtarea 2 con binaria (+20 puntos)</summary>

{{subtask2_simulacion_binaria.cpp}}

</details>

### Tercera observación

- Notemos que es posible calcular cuántos saltos habrá en el segundo $t$ sin tener que calcular los segundos $1, 2, 3, ..., t-1$.
- Si la i-ésima cobaya salta cada `a[i]` segundos, entonces, en el segundo `z * a[i]`, habrá realizado `z` saltos.
- Para conocer `z` dado el tiempo `t`, podemos calcularlo con la división $\left\lfloor \frac{t}{a[i]}\right\rfloor$.
- Sumando todas las cobayas obtendríamos la cantidad de saltos para el tiempo `t`: $saltos[t] = \sum_{i = 1}^n \left\lfloor\frac{t}{a_i}\right\rfloor$.

## Subtarea 3

Para esta subtarea podemos hacer binaria sobre el tiempo sin preocuparnos por el precalculo que era lo más costoso de la solución anterior.

La complejidad esperada para esta subtarea es $O(Q \cdot N \cdot log(QX))$.

<details><summary>Solución para la subtarea 3 (+50 puntos)</summary>

{{subtask3_binaria.cpp}}

</details>

### Cuarta observación

- La cantidad de saltos que realizarán dos cobayas que saltan cada $x$ segundos será la misma siempre. Por lo que, podemos contar cuántas cobayas hacen $x$ segundos, calcular cuántos saltos hace una de ellas, y multiplicar por la cantidad de cobayas.
- Esto nos permite calcular la cantidad de saltos para el tiempo `t` en 16 operaciones, que es mejor a $O(N)$.
- Esta técnica suele conocerse como "usar cubetas" para contar objetos que comparten características. Existe un algoritmo de ordenamiento [`bucket sort`](https://www.programiz.com/dsa/bucket-sort) que usa la técnica.

## Subtarea 4

Optimizando la búsqueda binaria de la solución anterior con la observación anterior podemos resolver esta subtarea.

Esta complejidad toma alrededor de $Q \cdot 16 \cdot 40  \leq 10^6 \cdot 640 \leq 6 \cdot 10^8 $ operaciones, lo cual no es suficiente para todos los puntos del problema.

<details><summary>Solución para la subtarea 4 (80 puntos)</summary>

{{subtask4_binaria_alternativa.cpp}}

</details>

### Quinta observación

- Existe un segundo en el que todas las cobayas saltan juntas, y es en el $mcm = mcm(a_1, a_2, \ldots , a_n)$.
- El orden en el que las cobayas dan los saltos es $mcm$-cíclico. Es decir, se está repitiendo cada $mcm$ segundos a partir del primer segundo.
- Como $a_i \leq 16$, entonces $1 \leq mcm \leq 720,720$.

## Solución completa

Para resolver el problema completo, vamos a abordar una estrategia un poco diferente. Tomando en cuenta que se repetirían cada `mcm` segundos la cantidad de saltos, podemos precalcular todos los saltos hasta dicho segundo.

### Definiciones auxiliares

- Sea $saltos\_por\_ciclo = saltos[mcm]$.
- Observemos que para hacer `iX` saltos, hay que hacer $piso\left(\frac{iX}{saltos\\_por\\_ciclo}\right) + 1$ ciclos.
- Sin embargo, el último ciclo no es totalmente necesario, ya que en algún segundo se logró la cantidad necesaria, siendo este segundo $t_f$.
- $s_i = piso\left(\frac{iX}{saltos\\_por\\_ciclo} \right) \cdot mcm + t_f$.
- $t_f$ es el segundo entre $1$ y $720,720$ que refleja en que segundo del ciclo se quedo el tiempo en el momento en que se acumularon $iX$ saltos por primera vez.

### Algoritmo

Podemos encontrar a $t_f$ para cada pregunta usando una búsqueda binaria sobre nuestro precalculo $saltos[t]$. Sólo que en vez de buscar `iX`, buscaríamos en qué segundo se logran hacer `iX % saltos_por_ciclo` saltos.

La complejidad es $O(Qlog(mcm))$, que gasta aproximadamente $log(720720) \cdot Q \leq 20 \cdot Q \leq 4 \cdot 10^7$ operaciones.

Esta optimización nos ayuda a ejecutar nuestro programa en menos de un segundo, y por tanto suficiente para todos los puntos del problema.

<details><summary>Solución completa</summary>

{{solution.cpp}}

</details>

<details><summary>Segunda solución completa</summary>

{{solutionB.cpp}}

</details>

### Complejidad

$O(Qlog(mcm))$.

## Referencia

Instrucciones por segundo en una computadora.

Puedes hacer cerca de $2 \cdot 10^8$ operaciones en C++ si estas operaciones son de bajo nivel (acceso a arreglos, sumas, desplazamiento de bits, multiplicaciones, restas, xors, etcétera). Los módulos y las divisiones son ligeramente mas lentas.

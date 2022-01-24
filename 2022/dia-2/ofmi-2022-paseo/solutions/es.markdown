# Paseo de Cobayas - Solución

La **observación más importante** para este problema es que, si las cobayas se ordenan por tamaño $T_1, T_2, ..., T_N$, entonces cada amigo de Andrea tendrá un subconjunto ordenado de cobayas. En otras palabras, para cada par de amigos, la cobaya más grande que saca a pasear un amigo será menor o igual que la cobaya más chica que saca a pasear el otro amigo.

## Subtarea 1

Para la primera subtarea Andrea tiene dos amigos. Se espera entonces que se ordenen las cobayas por tamaño y dado que queremos repartir las primeras $i$ cobayas al primer amigo y las últimas $N - i$ cobayas al segundo, basta con probar las $N$ diferentes posibilidades de repartirlo.

Si decidimos darle las primeras $i$ cobayas al primero, entonces la suma de los costos de los dos grupos será:

$$(T_i - T_1) + (T_N - T_{i + 1})$$

Por lo tanto la respuesta es $\min_i(T_i - T_1 + T_N - T_{i + 1})$ que se puede obtener en $O(N)$.

<details><summary>Solución para la subtarea 1 (+20 puntos)</summary>

{{subtask1.cpp}}

</details>

## Subtarea 2

Esta subtarea esta diseñada para ayudar a llegar a la solución completa.

Si hacemos un razonamiento similar a la subtarea anterior y decidimos que el primer amigo pasee $i$ cobayas y el segundo amigo pasee $j$ cobayas, entonces la suma de los costos de los tres grupos será de $(T_i - T_1) + (T_{i+j} - T_{i+1}) + (T_N - T_{i+j+1})$.

Sin embargo, tratar de encontrar la mejor opción para los valores de $i$ y $j$ no es suficiente para obtener una solución que corra en 1 segundo.

Para esto, veamos que podemos acomodar los términos anteriores como:

$$(T_N - T_1) - (T_{i+1} - T_i) - (T_{i+j+1} - T_{i+j})$$

Y si definimos $l = i+j$ entonces se puede ver como $(T_N - T_1) - (T_{i+1} - T_i) - (T_{l+1} - T_l)$. Viéndolo de esta manera, entonces tenemos que elegir los mejores $i$ y $l$ tal que maximicen esa expresión.

Para minimizar esa expresión notar que basta con maximizar $(T_{i+1} - T_i) + (T_{l+1} - T_l)$. Esto se logra al elegir los dos valores más grandes $(T_{x+1} - T_x)$.

## Solución completa (100 puntos)

Con la observación de la subtarea anterior podemos ver que si tenemos $K$ amigos, el costo se puede obtener como:

$$(T_N - T_1) - (T_{i_1+1} - T_{i_1}) - (T_{i_2+1} - T_{i_2}) - ... - (T_{i_k+1} - T_{i_k})$$

Y para minimizar esta expresión basta con tomar los $k$ valores más grandes $(T_{x+1} - T_x)$.

<details><summary>Solución (100 puntos)</summary>

{{solution.cpp}}

</details>

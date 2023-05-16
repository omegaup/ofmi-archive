# Nicolás - Solución

## Subtarea 1 ($L = 1$).

Para esta subtarea, debemos observar que dada una velocidad $X$, podemos calcular su posición $p$ en el tiempo $t$ con $p = X \dot{v} t$.

Entonces podemos recorrer las velocidades $X$ y tomar una foto en $p$. Si Nicolás está ahí, significa que escogimos una $X$ correcta.

Es importante recorrer las velocidades de $1$ a $X$, para asegurarnos de que la primera vez que `foto` regresa `true` significa que esa es la $X$ correcta.

<details><summary>Solución subtarea 1</summary>

{{sub1.cpp}}

</details>

## Subtarea 2 ($X = 1$).

Similar a la subtarea anterior, podemos calcular dónde está la cabeza de Nicolás. Al inicio, su cabeza está en la casilla $L - 1$ y cada segundo se moverá una casilla hacia adelante. Entonces $p = t + L - 1$. Al inicio, Nicolás saldrá en la foto cuando nos pasemos (`foto` regresa `false`), significa que encontramos su cabeza.

<details><summary>Solución subtarea 2</summary>

{{sub2.cpp}}

</details>

## Subtarea 3

Combinando las soluciones a las subtareas anteriores podemos encontrar la cola (subtarea 1). Ahora tenemos el mismo problema que en la subtarea 2 con la diferencia de que el tiempo no inicia en $0$ (aunque no nos importa) y tenemos que añadir $X$ (que ahora conocemos) a nuestra formula: $p = X \mdot t + L - 1$.

<details><summary>Solución subtarea 3</summary>

{{sub3.cpp}}

</details>

## Subtarea 4

Podemos ver un _espacio de búsqueda_ de $L_{max} \times X_{max}$ donde cada recuadro representa que Nicolás tiene longitud $L$ y velocidad $X$. Y tomar ciertas fotos nos puede dar información para reducir nuestro _espacio de búsqueda_.

Si suponemos la velocidad máxima y tomamos así la primera foto, podemos reducir el _espacio de búsqueda_ a la mitad. Para los siguientes ejemplos tomaremos $L_{max}$ y $X_{max}$ como $10$ para simplicidad.

![Espacio de búsqueda](espacio1.png)

<figcaption align = "center"><i>Espacio de búsqueda después de foto(X_{max})</i></figcaption>

Para que `foto(X_{max})` devuelva `true` en el segundo $1$, $X + L$ debe ser menor que $X_{max}$. Así que nuestro _espacio de búsqueda_ se divide en diagonal. Si `foto` fue `true`, el recuadro $(L, X)$ debe estar en la zona verde y si fue `false` debe estar en la zona blanca.

Si está en la zona blanca, podemos buscar la $X$ de la misma forma que en la subtarea 1 y con ello buscar la $L$ como en la subtarea 2.

Si está en la zona verde, tenemos que volver a reducir el _espacio de búsqueda_. Podemos hacerlo llamando a `foto(X_{max} * 2)` (porque ahora estamos en el segundo 2).

![Espacio de búsqueda](espacio2.png)

<figcaption align = "center"><i>Espacio de búsqueda después de foto(X_{max} * 2)</i></figcaption>

Si `foto` fue `true`, el recuadro $(L, X)$ debe estar en la zona verde oscuro y si fue `false` debe estar en la zona verde claro. Ahora podemos usar los algoritmos de las primeras subtareas.

Con esta idea tambien podemos tomar otras fotos para reducir aún más nuestro _espacio de búsqueda_.

También hay que adaptar nuestra búsqueda de $L$ a una búsqueda binaria para hacer menos llamadas a la función `foto`.

<details><summary>Solución</summary>

{{solution.cpp}}

</details>

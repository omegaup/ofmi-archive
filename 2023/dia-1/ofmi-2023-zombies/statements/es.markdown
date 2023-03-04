Hace un año decidiste comenzar a cultivar tu propio huerto, con el objetivo de obtener frutas y verduras frescas y saludables. Sabes que es importante incluir estos alimentos en tu dieta para mantener un estilo de vida saludable.

Lo que no sabías, es que una fila de $n$ zombies se acerca a tu huerto con la intención de destruir tus cultivos.
Cada zombie tiene una cantidad diferente de puntos de vida. Para proteger tu huerto, cuentas con un arma que inflige $d$ puntos de daño.

Tu estrategia es atacar al zombie más cercano hasta que ya no tenga vida. Cada disparo le resta $d$ puntos a su vida.
Sin embargo, cada vez que un zombie sobrevive a un disparo, te ataca y gasta uno de tus escudos.
Por eso, es esencial contar con suficientes escudos para protegerte de la infección.

# Problema

Debes calcular la cantidad mínima de escudos necesarios para protegerte de los zombies y salvar tus cultivos.

# Entrada

La primera línea contiene dos enteros $n$ y $d$, que representan el número de zombies y los puntos de daño de tu arma.

La siguiente línea contiene un arreglo de $n$ enteros, donde el $i$-ésimo entero representa la vida del zombie en la posición $i$.

# Salida

Debes imprimir la cantidad mínima de escudos necesarios para cumplir tu misión.

# Ejemplos

||examplefile
sample
||description
Hay 5 zombies y tu arma hace 3 puntos de daño.

- Atacas al primer zombie (que tiene 2 puntos de vida) y lo matas.
- Atacas al segundo zombie (que tiene 5 puntos de vida).
- El segundo zombie te ataca.
- Atacas al segundo zombie (con 2 puntos de vida) y lo matas.
- Atacas al tercer zombie (que tiene 8 puntos de vida).
- El tercer zombie te ataca.
- Atacas al tercer zombie (con 5 puntos de vida).
- El tercer zombie te ataca.
- Atacas al tercer zombie (con 2 puntos de vida) y lo matas.
- Atacas al cuarto zombie (que tiene 2 puntos de vida) y lo matas.
- Atacas al quinto zombie (que tiene 4 puntos de vida) y lo matas.
- El quinto zombie te ataca.
- Atacas al quinto zombie (que tiene 1 punto de vida) y lo matas.

En total, necesitaste 4 escudos para defenderte.
||end

# Límites

- $1 \leq n \leq 10^5$
- $1 \leq d, a_i \leq 10^9$

# Subtareas

- **Subtarea 1 (5 puntos):**
  - $d = 1$ (tu arma hace un solo punto de daño)
- **Subtarea 2 (5 puntos):**
  - $n = 1$ (solo hay un zombie)
- **Subtarea 3 (20 puntos):**
  - $1 \leq n \leq 100$, $1 \leq d, a_i \leq 100$ (hay hasta 100 zombies y tu pistola hace hasta 100 puntos de daño)
- **Subtarea 4 (70 puntos):**
  - Sin consideraciones adicionales

---

![](zombies.jpeg 'Los zombies acercándose a tu huerto.')

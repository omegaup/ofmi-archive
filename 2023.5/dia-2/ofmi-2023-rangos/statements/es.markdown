Pepe Grillo (PG) es el juez de la competencia de salto de longitud en los Juegos Panamericanos y Parapanamericanos 2023. En esta disciplina compiten $N$ participantes numeradas de $0$ a $N - 1$. La labor de Pepe Grillo es registrar la distancia de salto de cada una de las participantes.

Al finalizar el evento, PG se dio cuenta de que, aunque en efecto había anotado $N$ mediciones en su libreta de juez, una por cada participante, se había olvidado de anotar a qué participante pertenecía cada medición. Es decir, PG registró $N$ enteros positivos, $P_0, P_1, \dots, P_{N-1}$, y cada uno de ellos representa la distancia de salto de alguna competidora, pero PG desconoce de cuál.

Por su puesto, para poder entregar las medallas PG debe aclarar la confusión y descubrir a qué participante pertenece cada medición. Como PG confía en la honestidad de las participantes, le ha preguntado a cada una de ellas si recuerda cuál fue su distancia de salto. Las participantes no recordaban con exactitud la distancia que saltaron, y todas le dieron una respuesta parecida a PG. La respuesta de la $i$-ésima concursante fue: "Recuerdo que mi distancia de salto fue un valor en el rango $[L_i, R_i]$, es decir, un valor mayor o igual a $L_i$ pero menor o igual a $R_i$, con $L_i \leq R_i$".

Con esta nueva información, PG debe asignarle a cada participante una de las $N$ mediciones que originalmente registró, de tal manera que la medición que le sea asignada a cada participante coincida con los valores que ella recuerda. En otras palabras: si a la $i$-ésima participante le asigna la medición con índice $j$, se debe cumplir que $L_i \leq P_j \leq R_i$. Además, a dos competidoras diferentes no les puede asignar una medición con el mismo índice.

# Problema

Dados $N$, el número de participantes, $P_0, P_1, \dots, P_{N-1}$, las mediciones que PG registró, y las $N$ parejas de valores $L_i, R_i$, el rango de distancia que cada participante recuerda haber saltado, ayuda a PG a asignarle una medición distinta a cada participante que coincida con lo que ella recuerda, o, en caso de no existir dicha asignación, indícaselo a PG.

# Entrada

La primera línea contiene un único entero $N$, el número de participantes.

La segunda línea contiene $N$ enteros, $P_0, P_1, \dots, P_{N-1}$, las mediciones que PG anotó.

Las siguientes $N$ líneas contienen dos enteros cada una, $L_i, R_i$, que representan que la $i$-ésima participante recuerda haber saltado una distancia mayor o igual a $L_i$ y menor o igual a $R_i$.

# Salida

Si existe una asignación de mediciones que cumpla con las características antes descritas, entonces la única línea de salida deberá contener $N$ enteros distintos. El $i$-ésimo de estos enteros indicará el índice de la medición que le fue asignada a la $i$-ésima participante. Si hay más de una forma valida de asignar las mediciones a las participantes, cualquiera de ellas se aceptará como respuesta correcta.

Si no existe un asignación válida, deberás imprimir $-1$.

# Ejemplo

||examplefile
1-sub1.sample
||description

Hay $3$ participantes en la competencia. Las medidas que PG anotó son $5$, $7$ y $2$. La participante con índice $0$ recuerda que su distancia de salto fue un valor entre $3$ y $6$; la participante con índice $1$ recuerda que su distancia de salto fue un valor entre $1$ y $10$; y la participante con índice $2$ recuerda que su distancia de salto fue un valor entre $4$ y $7$.

A la participante con índice $0$ se le asigna la medición con índice $0$ (se cumple que medición con índice $0$ está en el rango que la participante con índice $0$ recuerda: $3 \leq 5 \leq 6$), a la participante con índice $1$ se le asigna la medición con índice $2$ ($1 \leq 2 \leq 10$), y a la participante con índice $2$ se le asigna la medición con índice 1 ($4 \leq 7 \leq 7$). Nota que a cada participante se le asignó una medición con índice distinto al de las demás y la medición que le fue asignada es un valor que coincide con el rango que ella recuerda.

||end

# Limites

- $1 \leq N \leq 10^5$
- $1 \leq P_i \leq 10^9$
- $1 \leq L_i \leq R_i \leq 10^9$

# Subtareas

- **Subtarea 1 (8 puntos)**
  - $1 \leq N \leq 8$.
  - $1 \leq L_i, R_i, P_i \leq 10^6$.
- **Subtarea 2 (10 puntos)**
  - $1 \leq N \leq 10^3$ y se te asegura que los rangos de las participantes no se intersecan entre ellos.
- **Subtarea 3 (10 puntos)**
  - Todos los rangos son del mismo tamaño, es decir, $R_i - L_i = C$ para toda $i \in \\{ 0, 1, \dots, N-1 \\}$.
- **Subtarea 4 (37 puntos)**
  - $1 \leq N \leq 10^3$.
- **Subtarea 5 (15 puntos)**
  - $1 \leq L_i, R_i, P_i \leq 10^6$.
- **Subtarea 6 (20 puntos)**
  - Sin consideraciones adicionales.

Los casos de prueba de cada subtarea están agrupados.

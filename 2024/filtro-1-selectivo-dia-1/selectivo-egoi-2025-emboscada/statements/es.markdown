Ekko recibió información de que una aeronave de Silco, con un importante cargamento de brillo a bordo, arribará a Piltover el día de hoy, por lo que él y las Firelights están planeando emboscarla.

En el puerto de Piltover hay $n$ hangares numerados del $1$ al $n$ de izquierda a derecha, donde las vigilantes inspeccionan el cargamento de cada aeronave que quiere ingresar a la ciudad.

Las Firelights han recolectado información sobre el proceso de inspección del puerto y han informado a Ekko de lo siguiente:

- Al inicio del día, todas las aeronaves que quieren ingresar a la ciudad deben hacer una fila para ser inspeccionadas.
- Siempre que haya un hangar desocupado, las vigilantes recibirán a la siguiente aeronave de la fila en ese hangar. Si hay múltiples hangares desocupados, se escoge aquel que esté más a la izquierda.
- Las vigilantes en el $i$-ésimo hangar tardan exactamente $T_i$ minutos en inspeccionar el cargamento de cualquier aeronave.

Ekko sabe que antes de la aeronave de Silco hay $k$ aeronaves formadas para ingresar a Piltover, y para poder ejecutar su plan a la perfección, él quiere saber cuándo y dónde podrá emboscarla.

# Problema

Dados $n$, $k$ y los tiempos $T_1, T_2, ..., T_n$ que las vigilantes del $i$-ésimo hangar tardan en realizar una inspección, ayuda a Ekko a saber en qué minuto y en qué hangar será inspeccionada la aeronave de Silco.

# Entrada

En la primera línea, dos enteros $n$ y $k$ representando el número de hangares y cuántas aeronaves están formadas antes que la de Silco.

En la segunda línea vendrán $n$ enteros, donde el $i$-ésimo entero representa el tiempo $T_i$ que tardan las vigilantes del $i$-ésimo hangar en inspeccionar el cargamento de cualquier aeronave.

# Salida

Dos enteros $t$ y $h$ representando el tiempo (en minutos) y el índice del hangar en el que se realizará la inspección de la aeronave de Silco respectivamente.

# Ejemplo

||examplefile
sub1.sample
||description
En la siguiente tabla, cada celda representa qué aeronave (representada por su lugar en la fila) está siendo inspeccionada cada minuto en cada uno de los hangares:

| Minuto   | 0   | 1   | 2   | 3   | 4   | 5     |
| -------- | --- | --- | --- | --- | --- | ----- |
| Hangar 1 | 1   | 4   | 5   | 7   | 8   | 10    |
| Hangar 2 | 2   | 2   | 6   | 6   | 9   | 9     |
| Hangar 3 | 3   | 3   | 3   | 3   | 3   | Silco |

Antes de la aeronave de Silco hay $10$ aeronaves, en el minuto $5$ los hangares $1$ y $3$ estarán disponibles para realizar una inspección. La décima aeronave es recibida en el hangar $1$. Inmediatamente después, la aeronave de Silco es recibida en el hangar $3$.
||examplefile
sub3.sample
||description
El único hangar tarda $580,973,130$ minutos en inspeccionar una aeronave. La aeronave de Silco no tiene otra opción más que esperar a que pasen las $17$ aeronaves de enfrente, por lo que será inspeccionada en el hangar $1$ después de $9,876,543,210$ minutos.
||end

# Límites

- $1 \leq n \leq 10^5$.
- $0 \leq k \leq 10^9$.
- $1 \leq T_i \leq 10^9$ para toda $1 \leq i \leq n$.

**Nota:** La respuesta puede no caber en un entero de $32$ bits; toma en cuenta los desbordamientos en variables de tipo `int`.

# Subtareas

- **Subtarea 1 (27 puntos):**
  - $1 \leq n \leq 100$.
  - $0 \leq k \leq 500$.
  - $1 \leq T_i \leq 100$ para toda $1 \leq i \leq n$.
- **Subtarea 2 (13 puntos):**
  - $0 \leq k \leq n$.
- **Subtarea 3 (29 puntos):**
  - $0 \leq k \leq 5 \times 10^5$.
- **Subtarea 4 (31 puntos):**
  - Sin restricciones adicionales.

**Nota:** Cada subtarea tiene todos sus casos agrupados.

[1]: data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABAQMAAAAl21bKAAAAA1BMVEUAAACnej3aAAAAAXRSTlMAQObYZgAAAApJREFUCNdjYAAAAAIAAeIhvDMAAAAASUVORK5CYII=

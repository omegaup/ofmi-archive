# Cómo Colaborar

Prerrequisitos:

- [Saber hacer problemas para omegaUp.](https://github.com/omegaup/omegaup/wiki/C%C3%B3mo-escribir-problemas-para-omegaUp)
- Saber usar git, y conocimiento básico de Python y C++.

Usamos git para coordinar el trabajo, así como pruebas automáticas
que revisan que los problemas tienen entradas válidas y que las
soluciones de prueba sacan los puntos que esperamos. Todo se coordina
con el archivo `problems.json` en la raíz del proyecto, y los
archivos individuales `settings.json` en las carpetas de los problemas.

La descripción del formato de estos archivos y la organización de las carpetas
está en
[este documento](https://docs.google.com/document/d/1OKOIdPMv3BasGZXqVmtVBWVIATrPfyPUbK8qXjXPwGU/edit).
Te recomendamos leerlo **después** de leer este archivo.

El flujo de trabajo para hacer un problema es _estrictamente_
el siguiente. En todos los casos, se debe hacer un branch y posteriormente
un pull request conteniendo una unidad de trabajo. Es importante no
mezclar trabajo de distintos problemas en el mismo branch o pull request.

Antes de comenzar, asegúrate de leer la sección de [convenciones](#convenciones), y
las [instrucciones para montar el entorno y correr las pruebas localmente](#cómo-correr-los-tests-localmente).

## 1. Especificación del problema

- Crea una carpeta con el nombre del problema. Dentro, agrega el archivo
  `settings.json` siguiendo el ejemplo de problemas anteriores, y agrega una
  línea con la carpeta del problema a `problems.json`, que está en la raíz
  del proyecto.
  - El alias del problema en `settings.json` **no** se determina
    hasta que se escribe la redacción final. Puedes usar el alias temporal
    `dummy-ofmi` mientras tanto.
  - A partir de ahora, todas las instrucciones del README se refieren a
    archivos dentro de la carpeta que acabas de crear.
- Escribe una descripción del problema en `statements/es.markdown`,
  pero no es la redacción final. Debe contener:
  - Descripción corta del problema. (Sin historia)
  - Descripción del formato de entrada y salida.
  - Descripción de las subtareas, de haber. Cada subtarea tiene que
    tener un identificador único que las distinga, de preferencia
    descriptivo en vez de `sub1` o similares.
    (Más detalles en la sección de [pruebas](#2-pruebas-tests).)
- Agrega por lo menos un caso de prueba válido en `cases`:
  por ejemplo, el caso de ejemplo en `cases/sample.0.in` y `cases/sample.0.out`.
  El nombre no es estricto, pero es útil poder identificar los
  casos de ejemplo para los siguientes pasos.
  - Agrega un `testplan` que contenga esos casos y obtenga 100 puntos.
- Crea el archivo `tests/tests.json` para asegurarnos que el testplan suma 100
  puntos. Su contenido debe ser el siguiente:
  ```json
  {
    "max_score": 100
  }
  ```
- El primer caso de ejemplo que se vaya a incluir en la redacción debe ir en
  `examples/sample.in` y `examples/sample.out` (aquí el nombre sí es estricto).
  Todos los demás casos de ejemplo también deben ir en `examples/`,
  preferentemente con nombres que indiquen a qué se refieren.
  Para asegurarnos que los casos de ejemplo también sean validados, en vez de
  hacer nuevos archivos, haz [symlinks](https://en.wikipedia.org/wiki/Symbolic_link)
  hacia la carpeta de `cases`.
  Luego, para incluirlos en la redacción, se puede usar la siguiente sintaxis:

  ```markdown
  ||examplefile
  sample
  ||description
  Aquí va la descripción del caso de ejemplo. Nota que arriba no se usó el
  nombre del directorio `examples/` ni la extensión de los archivos.
  ||examplefile
  caso_mas_grande
  ||examplefile
  caso_mas_complicado
  ||description
  No es necesario agregar una descripción en cada caso, pero se recomienda que
  se haga.
  ||end
  ```

- Al hacer el PR, asegúrate que el nuevo problema sí fue procesado por el sistema
  de integración continua.

## 2. Pruebas (`tests/`)

- En este paso, escribimos pruebas que verifiquen los casos de prueba. Puedes
  escribir las pruebas en cualquier lenguaje aceptado por omegaUp.
  - En este repositorio usualmente utilizamos Python con
    [libomegaup](https://github.com/omegaup/libomegaup). Puedes revisar otros
    problemas de concursos pasados para ver cómo escribir las pruebas.
- Para problemas de C++, el evaluador debe checar que la entrada sea válida
  y que sigue _exactamente_ el formato descrito, cuidando en particular
  los espacios en blanco y saltos de línea.
- Las pruebas tienen que considerar los límites especiales que pueden
  existir para las distintas subtareas. Esto se logra dándole nombres de
  archivo a los casos conteniendo el identificador de su subtarea, para
  poder distinguir a qué subtarea pertenecen.
  [Aquí hay un ejemplo.](https://github.com/ComiteMexicanoDeInformatica/OMI-2018/tree/master/omi/Convertidor)
- Agrega el validador que creaste a `tests/tests.json`. Si tu validador se llama
  `test-validator.py`, el archivo se vería así:
  ```json
  {
    "inputs": {
      "filename": "test-validator.py"
    },
    "max_score": 100
  }
  ```
- Agrega casos _inválidos_ para asegurarte que tu validador está funcionando
  correctamente. Para hacer eso, crea la carpeta `tests/invalid-cases` y coloca
  casos que esperas que tu validador rechace. Es decir, agrega archivos `.in` y `.out`
  emparejados como los casos normales; el `.out` puede ser vacío.
  - Cada caso inválido debe tener un string asociado a él en un archivo `.expected-failure`,
    conteniendo la razón por la que esperamos que el validador rechace ese caso.
    En general, este string es el mensaje asociado a la función de aserción que esperamos
    que falle para ese caso.

## 3. Solución oficial

- La solución oficial debe guardarse en la ruta `solutions/solution.[lang]`.
  Cuando esté lista la solución oficial, se puede trabajar tanto en soluciones
  como en casos al mismo tiempo.
- Agrega la solucion a `tests/tests.json`, que ahora se vería algo así:
  ```json
  {
    "solutions": [
      {
        "filename": "../solutions/solution.[lang]",
        "verdict": "AC"
      }
    ],
    "inputs": {
      "filename": "test-validator.py"
    },
    "max_score": 100
  }
  ```
- Si la solución oficial se puede usar para autogenerar las salidas de los
  casos (los `.out`), puedes borrar todos los archivos `.out` del problema y
  después agregar un archivo llamado `.gitignore` en la raíz del problema con
  el contenido:
  ```
  **/*.out
  !tests/invalid-cases/*.out
  ```
  - No borres los `.out` asociados a los casos inválidos. Como son inválidos
    no podemos autogenerar esas salidas, ya que las soluciones no sabrían cómo
    manejarlos.

## 4. Otras soluciones (`solutions`)

- Agrega tu solución en `solutions/[sol].[lang]`, así como en
  `tests/tests.json`, con el veredicto o puntaje esperado.
  Para soluciones parciales en lugar de `verdict` debes agregar `score_range`
  con el rango de puntos (entre 0 y 1) que esperas para esa solución. Si es
  un score definido, pon el mismo score en las dos posiciones. Por ejemplo,
  si tienes una solución que esperas que obtenga 20 puntos, debes agregar:
  ```json
  "solutions": [
    {
      "filename": "../solutions/[partial].[lang]",
      "score_range": [0.2, 0.2]
    }
  ]
  ```

## 5. Casos (`cases`)

- Escribe casos ya sea manualmente o autogenerados, siguiendo la especificación
  de la entrada. No olvides agruparlos de ser necesario, y si hay subtareas, de
  incluir en su nombre el identificador de la subtarea.
- **No borres los casos de ejemplo que ya se encuentran en `cases`.** Si no quieres
  que esos casos den puntos, puedes asignarles 0 puntos en el `testplan`.
  - Esto es necesario para que los casos de ejemplo sigan siendo validados;
    los tests solamente consideran los casos en `cases` para validación.
- En caso de que los `.in` de tus casos sean autogenerados, incluye el código
  que los generó en la raíz del problema, con el nombre
  `case-generator.[lang]`.
- Antes de planear y generar los casos, considera las siguientes limitaciones:
  - Los problemas en su totalidad deben pesar menos de 100 MiB (incluyendo entradas,
    redacciones, imágenes, etc.)
  - Cada archivo del caso (`.in`, `.out`) no puede pesar más de 2 MiB. Este es un límite
    estricto: si no lo respetas, las pruebas fallarán.
    - Intenta dejar un poco de holgura para que otras soluciones
      válidas no reciban OLE, en especial cuando haya múltiples salidas posibles.
  - El tiempo de ejecución máximo para _todo_ el problema es 1 minuto.
- Si la solución oficial no se puede utilizar para auto-generar los archivos
  `.out`, hay que generarlos manualmente y agregarlos:
  - Los problemas que tienen un validador personalizado pueden tener `.out`
    vacíos si el validador no necesita información más allá del `.in` original
    y la salida del concursante para generar el veredicto. También se puede
    poner información en el `.out` que le puede ayudar al validador. Por
    ejemplo, la cota superior / inferior conocida de lo que se desea optimizar.
  - Para los problemas interactivos, como el `Main.[lang]` típicamente hace las
    veces del validador, la misma información aplica.
  - Si generar los archivos `.out` toma mucho tiempo o es necesario generarlos
    a mano por cualquier razón, hay que agregar el código que los generó en la
    raíz del problema, con el nombre `output-generator.[lang]`.
- Haz un `testplan` para tus casos. No puede tener puntos decimales y
  necesariamente debe sumar 100.
- Si es un problema con más de una salida válida, agrega en la raiz el
  `validator.[lang]` y cambia en `settings.json` la sección de `validator`:
  ```json
  "validator": {
    "name": "custom",
    "limits": {
      "TimeLimit": 1000
    }
  }
  ```
- Si es un problema interactivo, puedes consultar la [documentación de
  libinteractive](https://omegaup.com/libinteractive/es/writing/) y usar el
  problema
  [`OMI-2019-Mobius`](https://github.com/ComiteMexicanoDeInformatica/OMI-Archive/tree/master/2019/OMI-2019-Mobius)
  como plantilla para empezar. Lo importante es tener la carpeta `interactive/`
  con un archivo `[ModuleName].idl`, un archivo `Main.cpp` con el programa juez
  oficial y un archivo `Main.distrib.cpp` que es el programa juez que se va a
  compartir con los concursantes (por si el juez oficial tiene secretos, o
  pistas de cómo se resuelve el problema). También hay que agregar a
  `settings.json` la sección de `interactive`:
  ```json
  "interactive": {
    "ModuleName": "[ModuleName]"
  }
  ```

## 6. Redacción (`statements/es.markdown`)

- Se escribe la redacción final del problema.
- Asegúrate de que los casos de ejemplo (`examples/sample.{in,out}`, etc.)
  existen y se están usando con la sintaxis `||examplefile` en la redacción.
  - Si hay solución oficial y esta puede generar el `.out`, no hace falta el
    `.out`.
- Se define el nombre oficial y el alias real del problema en el archivo de `settings.json`

## 7. Explicación (`solutions/es.markdown`)

- Escribe un documento que explique la solución oficial.
  - Si existen soluciones parciales para subtareas, también hay que
    explicarlas.
  - Incluye las observaciones importantes para poder atacar el problema.
- Para embeber soluciones en la explicación, se puede usar la siguiente
  sintaxis (asumiendo que la solución existe en el archivo
  `solutions/subtarea_1.cpp`):

  ```markdown
  <details><summary>Solución para la subtarea fácil (~4 puntos)</summary>

  {{subtarea_1.cpp}}

  </details>
  ```

- Enfocarse en dar valor didáctico y si el problema es un tema conocido
  explicar dónde se puede aprender más sobre este.

# Convenciones

- A menos de que la solución oficial no pueda usarse para generar las salidas
  (ver la sección de [Casos (`cases/`)](#5-casos-cases), sólamente se hace
  commit a las entradas de los casos de prueba (`.in`). Los `.out` se generan
  automáticamente con la solución oficial.
- Cuando hay casos agrupados, el primer caso en el `testplan` debe tener el
  valor entero del grupo, y todos los demás 0. Por ejemplo:

  ```
  group.1 40
  group.2 0
  group.3 0
  ```

- Los tests tienen que tener comentarios explicando qué condiciones están
  evaluando de la entrada.
- Todos los archivos de texto deben de estar en encoding UTF-8, con fin de
  línea estilo UNIX (`\n` o `LF`, nunca `\r\n` o `CRLF`).
- Debes correr el linter antes de mandar un PR para asegurarnos que el estilo
  sea consistente y fácil de leer. Para correrlo localmente puedes ejecutar:

  ```shell
  ./utils/lint fix --all
  ```

# Cómo correr los tests localmente

Cambiar el directorio a la raíz del proyecto.

La primera vez necesitas bajar el submódulo de utilidades para omegaUp:

```shell
git submodule init && git submodule update
```

Asegúrate de tener instalado lo siguiente:

- [Python 3](https://www.python.org/downloads/),
- [pipenv](https://github.com/pypa/pipenv) (`pip install pipenv`),
- **y** la versión más reciente de **[Docker](https://docs.docker.com/get-docker/)**.

Después, aún desde la raíz del proyecto, corre

```shell
./utils/lint fix --all
./utils/runtests.py --all --overwrite-outs
```

El `--all` en runtests sirve para correr los tests de todos los problemas, si no lo usas, se corre solo el test del problema que modificaste en tu local.
El `--overwrite-outs` sirve para cuando los problemas ya tienen casos y solución oficial, ignora los `.out` que existan y los vuelve a generar.

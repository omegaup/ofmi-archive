# Chemsificación - Solución

La solución pensada para este problema es que programen las condicionales para poder ver si una palabra es chemsificada.

## Atacando los posibles casos

Para resolver este problema es recomedable hacer una función que detecte si una letra es una vocal, devolviendo true y false en caso de que no lo sea

```cpp
bool es_vocal(char w) {
  return w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u';
}
```

Iniciemos poniendo un ejemplo de como podemos leer y trabajar las palabras:

```cpp
int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::string palabra;
    std::cin >> palabra;

    // Nos situamos en la primera letra de cada silaba
    for (int g = 0; g < palabra.size(); g += 3) {
      std::vector<char> subpalabra;
      // Guardamos las letras de la silaba en un vector
      for (int j = 0; j < 3 && g + j < palabra.size(); j++) {
        //Imprimos el caracter actual
        std::cout << palabra[g + j];
        //Metemos a un vector la actual subpalabra que procesaremos
        subpalabra.push_back(palabra[g + j]);
      }
```

## Subtarea 1

- (10 puntos): $N = 1$

Nos saltaremos esta subtarea por el momento, pues el problema completo se resuelve añadiendo un ciclo `for` a esta solución.

## Subtarea 2

Teniendo la función auxiliar que acabamos de definir, `es_vocal`, pasemos a resolver la siguiente subtarea:

- (10 puntos) Se te asegura que toda sílaba termina en exactamente una vocal.

Ya que se nos asegura que cada sílaba terminará en exactamente una vocal, entonces la penúltima letra es una consonante, por lo tanto, todas las sílabas son chemsificables y se les agregaría una 'm'.

<details><summary>Solución a subtarea 2: Agregar m's después de cada sílaba</summary>

{{subtask_2_terminacion_vocal.cpp}}

</details>

## Subtarea 3

- (10 puntos): Se te asegura que ninguna sílaba tiene dos vocales juntas.

Para esta subtarea basta con ver si la última letra de una palabra sea una vocal.

<details><summary>Solución a subtarea 3: Checar última letra de cada sílaba</summary>

{{subtask_3_vocales_separadas.cpp}}

 </details>

## Solución completa

Tanto para la subtarea 1, como en la solución completa, tenemos que hacer los procedimientos descritos en la subtarea 2 y 3, pero cuidando que la penúltima letra de cada sílaba (o subpalabra) es consonante, o bien, la sílaba es de tamaño 1. En la siguiente solución presentamos la unificación de las subtareas anteriores, además de checar la penúltima letra de cada sílaba:

<details><summary>Cheemsificación: Solución completa</summary>

{{solutionB.cpp}}

</details>

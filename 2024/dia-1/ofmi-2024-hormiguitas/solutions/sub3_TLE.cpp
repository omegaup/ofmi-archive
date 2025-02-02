// Subtarea 3: m = 2 (version chafa, da TLE)
//
// Como solo hay dos platillos, podemos guardar cuales hormigueros
// tienen como objetivo el platillo [1] y el platillo [2]. Los
// grupos deben cumplir que hay una clara separacion, esto es, todas
// los hormigueros que van al platillo 1 son menores que los
// hormigueros que van al platillo 2.
//
// Podemos guardar los hormigueros en un arreglo e ir actualizando
// de acuerdo a las nuevas rutas. Estos arreglos los mantendremos
// ordenados haciendo insercion si requerimos agregar, y eliminaremos
// el inicio o final dependiendo de lo que necesitemos.
#include <iostream>

const int MaxN = 1e6 + 10;
const int MaxQ = 2e5 + 10;

int num_hormigueros_en_1;
int hormigueros_en_1[MaxQ];

int num_hormigueros_en_2;
int hormigueros_en_2[MaxQ];

int platillo_actual_del_hormiguero[MaxN];

void quitar_valor(int arreglo[], int n, int valor) {
  // Vamos a modificar a [arreglo] para que las primeras
  // [n - 1] posiciones tengan los [n] valores pero sin [valor].
  int ultimo_valor = arreglo[n - 1];
  if (ultimo_valor == valor) {
    // No necesitamos modificar los primeros [n - 1] elementos.
    return;
  }
  for (int i = n - 2; i >= 0; --i) {
    if (arreglo[i] == valor) {
      // Encontramos [valor] y lo sobreescribimos.
      arreglo[i] = ultimo_valor;
      return;
    }
    // Tenemos que seguir recorriendo el arreglo.
    std::swap(arreglo[i], ultimo_valor);
  }
}

void agregar_valor(int arreglo[], int n, int valor) {
  // Agregamos el valor al arreglo.
  arreglo[n] = valor;
  for (int i = n - 1; i >= 0; --i) {
    // Mientras no este en su posicion [valor], lo vamos
    // recorriendo.
    if (arreglo[i] > arreglo[i + 1]) {
      std::swap(arreglo[i], arreglo[i + 1]);
    } else {
      break;
    }
  }
}

int quitar_menores_que_valor(int arreglo[], int n, int valor) {
  int num_posiciones_menores_que_valor = 0;
  while (num_posiciones_menores_que_valor < n) {
    if (arreglo[num_posiciones_menores_que_valor] < valor) {
      // Retiramos al hormiguero eliminado.
      int hormiguero_retirado = arreglo[num_posiciones_menores_que_valor];
      platillo_actual_del_hormiguero[hormiguero_retirado] = 0;

      ++num_posiciones_menores_que_valor;
    } else {
      break;
    }
  }
  if (num_posiciones_menores_que_valor == 0) {
    // No eliminamos posiciones, el arreglo se queda igual.
    return 0;
  }
  for (int i = num_posiciones_menores_que_valor; i < n; ++i) {
    arreglo[i - num_posiciones_menores_que_valor] = arreglo[i];
  }
  return num_posiciones_menores_que_valor;
}

int quitar_mayores_que_valor(int arreglo[], int n, int valor) {
  int num_posiciones_mayores_que_valor = 0;
  while (num_posiciones_mayores_que_valor < n) {
    if (arreglo[n - 1 - num_posiciones_mayores_que_valor] > valor) {
      // Retiramos al hormiguero eliminado.
      int hormiguero_retirado =
          arreglo[n - 1 - num_posiciones_mayores_que_valor];
      platillo_actual_del_hormiguero[hormiguero_retirado] = 0;

      ++num_posiciones_mayores_que_valor;
    } else {
      break;
    }
  }
  return num_posiciones_mayores_que_valor;
}

void quitar_platillo(int hormigas) {
  int platillo = platillo_actual_del_hormiguero[hormigas];
  if (platillo == 0) {
    // No tiene expediciones asignadas.
    return;
  }
  platillo_actual_del_hormiguero[hormigas] = 0;
  if (platillo == 1) {
    // Buscamos [hormigas] en el platillo 1.
    quitar_valor(hormigueros_en_1, num_hormigueros_en_1, hormigas);
    --num_hormigueros_en_1;
  }
  if (platillo == 2) {
    // Buscamos [hormigas] en el platillo 2.
    quitar_valor(hormigueros_en_2, num_hormigueros_en_2, hormigas);
    --num_hormigueros_en_2;
  }
}

int agregar_expedicion(int hormigas, int platillo) {
  quitar_platillo(hormigas);
  platillo_actual_del_hormiguero[hormigas] = platillo;

  if (platillo == 1) {
    int filas_retiradas = quitar_menores_que_valor(
        hormigueros_en_2, num_hormigueros_en_2, hormigas);
    num_hormigueros_en_2 -= filas_retiradas;
    agregar_valor(hormigueros_en_1, num_hormigueros_en_1, hormigas);
    ++num_hormigueros_en_1;
    return filas_retiradas;
  }

  // Asumimos que M = 2, entonces platillo = 2.
  int filas_retiradas = quitar_mayores_que_valor(
      hormigueros_en_1, num_hormigueros_en_1, hormigas);
  num_hormigueros_en_1 -= filas_retiradas;
  agregar_valor(hormigueros_en_2, num_hormigueros_en_2, hormigas);
  ++num_hormigueros_en_2;
  return filas_retiradas;
}

int main() {
  int N, M, Q;
  std::cin >> N >> M >> Q;
  for (int i = 0; i < Q; ++i) {
    int hormigas, platillo;
    std::cin >> hormigas >> platillo;
    int filas_retiradas = agregar_expedicion(hormigas, platillo);
    std::cout << filas_retiradas << "\n";
  }
  return 0;
}

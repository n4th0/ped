#include <iostream>

using namespace std;

#include "tlistaporo.h"

int main(void) {
  TPoro p(1, 1, 1, (char *)"rojo"), q(2, 2, 2, (char *)"verde");
  TPoro r(1, 1, 1, (char *)"azul"), s(2, 2, 2, (char *)"granate");
  TPoro t(1, 1, 1, (char *)"azul"), u(2, 2, 2, (char *)"granate");

  TPoro *arr = new TPoro[100];
  TListaPoro a;

  a.Insertar(t);

  for (size_t i = 0; i < 100; i++) {
    arr[i] = TPoro(i * 3 + 1, i * 4, i);
    a.Insertar(arr[i]);
  }

  for (size_t i = 0; i < 100; i++) {
    a.Borrar(arr[i]);
  }

  TListaPoro b(a);

  if (b.Insertar(t)) {
    cout << "se inserta (no debería)" << endl;
  }

  if (a.Primera().EsVacia() && a.Primera().EsVacia()) {
    cout << "primera a es vacía" << endl;
  }

  cout << a << endl;
  cout << b << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << a << endl;
  // cout << b << endl;

  // cout << (a - b) << endl;

  a.Insertar(TPoro(10, 30, 2, "cián"));
  cout << a << endl;

  cout << "aqui" << endl;
  cout << a.ExtraerRango(2, 2) << endl;
  cout << a << endl;
  // if (b.Buscar(a.Obtener(a.Primera()))) {
  //   cout << "encuentra" << endl;
  // }

  // cout << b << endl;
  // cout << a << endl;
  // cout << (a + b) << endl;
}

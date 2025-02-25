#include "../include/tlistaporo.h"
#include "../include/tporo.h"
#include <iostream>

using namespace std;

int main(void) {
  TPoro p(1, 1, 1, "rojo"), q(2, 2, 2, "verde");
  TPoro r(1, 1, 1, "azul"), s(2, 2, 2, "granate");
  TPoro t(1, 1, 1, "azul"), u(2, 2, 2, "granate");

  TPoro *arr = new TPoro[100];
  TPoro *arr2 = new TPoro[100];
  TListaPoro a;

  for (size_t i = 0; i < 100; i++) {
    arr[i] = TPoro(i * 3 + 1, i * 4, i);
    // cout << TPoro(i * 3, i * 4, i) << endl;
    a.Insertar(arr[i]);
  }

  a.Insertar(p);
  cout << a << endl;

  cout << "estoy" << endl;
  a.Insertar(q);
  cout << a << endl;
  a.Insertar(s);
  cout << a << endl;
  // cout << a << endl;

  TListaPoro b(a);
  b.Insertar(r);

  for (size_t i = 0; i < 100; i++) {
    arr2[i] = TPoro(i * 3 + 1, i * 4, i);
    // cout << TPoro(i * 3, i * 4, i) << endl;
    // cout << "llego " << i << endl;
    // cout << a << endl;
    a.Borrar(arr2[i]);
    b.Borrar(arr2[i]);
  }

  // cout << a << endl;

  if (b.Insertar(t)) {
    cout << "se inserta" << endl;
  }

  // cout << b.Obtener(b.Primera()) << endl;
  // cout << a.Obtener(a.Primera()) << endl;
  // cout << b.Obtener(a.Primera()) << endl;

  a.Primera().EsVacia(); // = a.EsVacia();
  if (a.Primera().EsVacia()) {
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

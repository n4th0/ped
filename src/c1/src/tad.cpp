#include "../include/tlistaporo.h"
#include "../include/tporo.h"
#include <iostream>

using namespace std;

int main(void) {
  TPoro p(1, 1, 1, (char *)"rojo"), q(2, 2, 1, (char *)"verde");
  TPoro r(1, 1, 1, (char *)"azul"), s(2, 2, 1, (char *)"granate");
  TPoro t(1, 1, 1, (char *)"blanco"), u(2, 2, 1, (char *)"granate");

  TPoro *arr = new TPoro[100];
  TListaPoro a;

  if (t != r) {
    cout << "distintos" << endl;
  }

  TListaPosicion it = a.Primera();
  it.Siguiente();
  a.Obtener(it.Anterior());

  // do {•••••••••
  //   cout << a.Obtener(it) << " ";•••••••••
  //   it = it.Siguiente();
  // } while (!it.EsVacia());
  // cout << endl;

  a.Insertar(t);
  cout << a << endl;
  // a.Borrar(t);
  cout << a << endl;

  for (size_t i = 0; i < 100; i++) {
    arr[i] = TPoro(i * 3 + 1, i * 4, i);
    a.Insertar(arr[i]);
    if (a.EsVacia() || a.Primera().EsVacia()) {
      cout << "no debería de salir" << endl;
    }
  }
  TListaPoro b(a);

  for (size_t i = 0; i < 100; i++) {
    a.Borrar(arr[i]);
  }

  it = b.Primera();
  while (!it.EsVacia()) {
    cout << b.Obtener(it) << " ";
    it = it.Siguiente();
  }
  cout << endl;

  it = b.Ultima();
  while (!it.EsVacia()) {
    cout << b.Obtener(it) << " ";
    it = it.Anterior();
  }
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;

  if (a == b) {
    cout << "efectivamente, a es igual que b bien " << endl;
  }

  if (b.Insertar(t)) {
    cout << "se inserta (no debería)" << endl;
  }

  if (!(a.Primera().EsVacia())) {
    cout << "primera de 'a' no es vacía" << endl;
  }

  cout << a << endl;
  a.Insertar(TPoro(10, 30, 2, (char *)"cián"));
  TListaPoro n(a);
  cout << a << endl;
  cout << a.ExtraerRango(1000, -102) << endl;
  if (n == a) {
    cout << "extraer fuera de rango no modifica a" << endl;
  }
  cout << a.ExtraerRango(1, 1) << endl;
  n.Borrar(r);
  if (n == a) {
    cout << "extraer que si que modifica" << endl;
  }
  delete[] arr;
}

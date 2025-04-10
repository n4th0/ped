#include <iostream>

using namespace std;

#include "../include/tabbporo.h"
#include "../include/tporo.h"
#include "../include/tvectorporo.h"

int main(void) {

  TABBPoro a;

  TPoro p100(1, 2, 100, (char *)"rojo");
  TPoro p50(1, 2, 50, (char *)"rojo");
  TPoro p20(1, 2, 20, (char *)"rojo");
  TPoro p110(1, 2, 110, (char *)"rojo");

  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;

  a.Insertar(p100);
  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;

  a.Insertar(p50);
  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;

  a.Insertar(p20);
  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;

  a.Insertar(p110);
  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;

  // a.Borrar(p20);
  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;
  a.paint("", true);
  cout << a << endl;
}

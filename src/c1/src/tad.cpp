#include "../include/tlistaporo.h"
#include "../include/tporo.h"
#include <iostream>

using namespace std;

int main(void) {
  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a;
  a.Insertar(p);

  cout << a.Obtener(a.Primera()) << endl;

  a.Insertar(q);
  a.Insertar(r);

  cout << a << endl;
}

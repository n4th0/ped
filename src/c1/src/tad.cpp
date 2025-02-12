#include <cstdlib>
#include <iostream>

using namespace std;

#include "../include/tporo.h"
#include "../include/tvectorporo.h"

int main(void) {
  TPoro p1(0, 0, 0, "Rojo");
  TPoro p2(2, 0, 0, "azul");
  TPoro p3(4, 0, 0, "granate");
  TPoro p4(1, 0, 0, "verde");
  TVectorPoro v(10);

  v[0] = p1; // error

  v[1] = p2;
  v[2] = p3;
  v[2] = p3;
  v[2] = p3;
  v[2] = p3;

  // cout << v[100] << endl;

  p4.Color("amarillo");

  cout << v << endl;
}

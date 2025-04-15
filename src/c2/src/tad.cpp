#include <iostream>

using namespace std;

#include "../include/tabbporo.h"
#include "../include/tporo.h"
#include "../include/tvectorporo.h"

int main(void)
{

  TABBPoro a,b,c;

  TPoro p1(1,2,1,(char *) "rojo");

  b.Insertar(p1);


  cout << (a = b).Inorden() << endl;

  cout << (a = c).Inorden() << endl;

}

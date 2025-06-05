#include <iostream>

using namespace std;

// #include "../include/tabbporo.h"
#include "../include/tporo.h"
#include "../include/tqueueporo.h"

int main(void)
{

  // TABBPoro a,b;

  TPoro p1(1,2,1,(char*) "rojo");
  TPoro p2(1,2,2,(char*) "rojo");

  TPoro p3(1,2,3,(char*) "rojo");
  TPoro p4(1,2,4,(char*) "rojo");
  TPoro p5(1,2,5,(char*) "rojo");
  TPoro p6(1,2,6,(char*) "rojo");
  TPoro p7(1,2,7,(char*) "rojo");


  TQueuePoro p = TQueuePoro();

  p.Enqueue(p1);
  p.Enqueue(p2);
  p.Enqueue(p3);
  p.Enqueue(p4);
  p.Enqueue(p5);
  p.Enqueue(p6);
  p.Enqueue(p7);

  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;
  cout << p.Dequeue() <<endl;


}

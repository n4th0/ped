#include "../include/tqueueporo.h"

#include <iostream>
using namespace std;

TQueueNodo::TQueueNodo(){
  siguiente = NULL;
}

TQueueNodo::~TQueueNodo(){
}

TQueueNodo::TQueueNodo(TQueueNodo & el){
  this->e = el.e;
}

TQueueNodo &TQueueNodo::operator=(TQueueNodo & el){
  this->~TQueueNodo();
  this->e = el.e;
  return *this;
}


TQueuePoro::TQueuePoro(){
  head=NULL;
}

TQueuePoro::~TQueuePoro(){

}

TQueuePoro::TQueuePoro(const TQueuePoro &){

}
TQueuePoro &TQueuePoro::operator=(const TQueuePoro & op){
  // deep copy

  return *this;

}

bool TQueuePoro::operator==(const TQueuePoro &) const{
  return false;
}
bool TQueuePoro::operator!=(const TQueuePoro &) const{
  return false;

}




void TQueuePoro::Enqueue(const TPoro & poro){

  if (EsVacia()) {
    head = new TQueueNodo();
    head->e = poro;

    head->siguiente = head;
    return;
  }

  TQueueNodo* aux = new TQueueNodo();
  aux->e = poro;
  aux->siguiente =  head->siguiente;
  head->siguiente = aux;
  head = aux;

}

TPoro TQueuePoro::Dequeue(){
  if (EsVacia()) {
    return TPoro();
  }

  if (head->siguiente == head) {
    TPoro p = head->e;
    delete head;
    head = NULL;
    return p;
  }

  TPoro p = head->siguiente->e;
  head->siguiente = head->siguiente->siguiente;


  return p;
}

bool TQueuePoro::EsVacia() const{
  return this->head == NULL;
}


std::ostream & operator<<(std::ostream &os, const TQueuePoro & q){
  os << "Hola"<<endl;
  return os;
}

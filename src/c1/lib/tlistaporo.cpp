#include "../include/tlistaporo.h"

////////////////////////////////////////////////////
/// clase TListaNodo
////////////////////////////////////////////////////
TListaNodo::TListaNodo() : e() { anterior = siguiente = NULL; }
TListaNodo::~TListaNodo() {
  anterior = siguiente = NULL;
  e.~TPoro();
}

TListaNodo::TListaNodo(TListaNodo &nodo) {
  this->e = nodo.e;
  anterior = siguiente = NULL;
}

TListaNodo &TListaNodo::operator=(TListaNodo &nodo) {
  this->~TListaNodo();

  this->e = nodo.e;
  anterior = siguiente = NULL; // la posicion debo ponerla en algún sitio?

  return *this;
}

////////////////////////////////////////////////////
/// clase TListaPosicion
////////////////////////////////////////////////////
TListaPosicion::TListaPosicion() { pos = NULL; }
TListaPosicion::TListaPosicion(TListaPosicion &pos) { this->pos = pos.pos; }
TListaPosicion::~TListaPosicion() { this->pos = NULL; }

TListaPosicion &TListaPosicion::operator=(TListaPosicion &pos) {
  this->~TListaPosicion();

  this->pos = pos.pos;
  return *this;
}

bool TListaPosicion::operator==(TListaPosicion &pos) const {
  return this->pos == pos.pos;
}

TListaPosicion TListaPosicion::Anterior() {
  TListaNodo p = *pos;
  // p.anterior;
  // no clue what to do here
}

TListaPosicion TListaPosicion::Siguiente() {}

bool TListaPosicion::EsVacia() const { return pos == NULL; }

////////////////////////////////////////////////////
/// clase TListaPoro
////////////////////////////////////////////////////
TListaPoro::TListaPoro() { primero = ultimo = NULL; }
TListaPoro::TListaPoro(TListaPoro &lista) {
  primero =
      lista.primero; // tengo que copiar toda la lista (duplicar la memoria)?
  ultimo = lista.ultimo;
}

TListaPoro::~TListaPoro() { primero = ultimo = NULL; }

TListaPoro &TListaPoro::operator=(TListaPoro &lista) {

  primero = lista.primero;
  ultimo = lista.ultimo;

  // tengo que copiar uno a uno?

  return *this;
}

bool TListaPoro::operator==(TListaPoro &lista) const {
  return primero == lista.primero && ultimo == lista.ultimo;
}
TListaPoro operator+(TListaPoro &) {}
TListaPoro operator-(TListaPoro &) {}
bool TListaPoro::EsVacia() const {}
bool TListaPoro::Insertar(TPoro &) {}
bool TListaPoro::Borrar(TPoro &) {}
bool TListaPoro::Borrar(TListaPosicion &) {}
TPoro TListaPoro::Obtener(TListaPosicion &) {}
bool TListaPoro::Buscar(TPoro &) const {}
int TListaPoro::Longitud() const {}
TListaPosicion TListaPoro::Primera() const { ; }
TListaPosicion TListaPoro::Ultima() const {}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {}

ostream &operator<<(ostream &, TListaPoro &) {}

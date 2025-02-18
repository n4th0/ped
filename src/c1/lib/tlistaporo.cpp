#include "../include/tlistaporo.h"

////////////////////////////////////////////////////
/// clase TListaNodo
////////////////////////////////////////////////////

TListaNodo::TListaNodo() : e() { anterior = siguiente = NULL; }
TListaNodo::~TListaNodo() {
  anterior = siguiente = NULL;
  e.~TPoro();
}

TListaNodo::TListaNodo(TListaNodo &nodo) : e(nodo.e) {
  // this->e = nodo.e;
  anterior = siguiente = NULL;
}

TListaNodo &TListaNodo::operator=(TListaNodo &nodo) {
  this->~TListaNodo();

  this->e = nodo.e;
  anterior = siguiente = NULL;

  return *this;
}

////////////////////////////////////////////////////
/// clase TListaPosicion
////////////////////////////////////////////////////

TListaPosicion::TListaPosicion() { pos = NULL; }
TListaPosicion::TListaPosicion(const TListaPosicion &pos) {
  this->pos = pos.pos;
}
TListaPosicion::~TListaPosicion() { this->pos = NULL; }

TListaPosicion &TListaPosicion::operator=(const TListaPosicion &pos) {
  this->~TListaPosicion();

  this->pos = pos.pos;
  return *this;
}

bool TListaPosicion::operator==(TListaPosicion &pos) const {
  return this->pos == pos.pos;
}

TListaPosicion TListaPosicion::Anterior() const {
  TListaNodo p = *pos;
  TListaPosicion tp;
  tp.pos = p.anterior;
  return tp;
}

TListaPosicion TListaPosicion::Siguiente() const {
  TListaNodo p = *pos;
  TListaPosicion tp;
  tp.pos = p.siguiente;
  return tp;
}

bool TListaPosicion::EsVacia() const { return pos == NULL; }

////////////////////////////////////////////////////
/// clase TListaPoro
////////////////////////////////////////////////////

TListaPoro::TListaPoro() { primero = ultimo = NULL; }
TListaPoro::TListaPoro(TListaPoro &lista) {
  if (lista.EsVacia()) {
    primero = lista.primero; // serán null
    ultimo = lista.ultimo;
    return;
  }

  TListaNodo it = *lista.primero;

  while (it.siguiente != NULL) {
    this->Insertar(it.e); // Insertar hará copia profunda de tporo
                          // También se encargará de la gestion de
                          //  punteros
    it = *it.siguiente;
  }

  this->Insertar(lista.ultimo->e);
}

TListaPoro::~TListaPoro() {

  if (this->EsVacia()) {
    return;
  }

  TListaNodo it = *this->primero;

  while (it.siguiente != NULL) {
    this->Borrar(it.e);
    it = *it.siguiente;
  }

  // this->Borrar(it.e);

  primero = ultimo = NULL;
}

TListaPoro &TListaPoro::operator=(TListaPoro &lista) {

  this->~TListaPoro();

  primero = lista.primero;
  ultimo = lista.ultimo;

  TListaNodo it = *lista.primero;

  while (it.siguiente != NULL) { // copia profunda
    this->Insertar(it.e);
    it = *it.siguiente;
  }
  this->Insertar(it.e);

  return *this;
}

bool TListaPoro::EsVacia() const { return NULL == primero && ultimo == NULL; }

// TODO comprobar uno a uno
bool TListaPoro::operator==(const TListaPoro &lista) const {
  return primero == lista.primero && ultimo == lista.ultimo;
}

TListaPoro operator+(TListaPoro &lista) { return lista; }
TListaPoro operator-(TListaPoro &lista) { return lista; }

bool TListaPoro::Insertar(const TPoro &poro) {

  if (this->EsVacia()) {
    this->primero = new TListaNodo();
    this->primero->e = poro;
    this->ultimo = this->primero;
    return true;
  }

  if (this->Buscar(poro)) {
    return false;
  }

  TListaNodo *p = primero;

  // inserto al principio
  if (p->e.Volumen() >= poro.Volumen()) {
    TListaNodo *n = new TListaNodo();
    n->e = poro;

    if (p->e.Volumen() > poro.Volumen()) {

      this->primero->anterior = n;
      n->siguiente = this->primero;
      this->primero = n;

    } else { // igualdad
      this->primero->siguiente = n;
      n->anterior = this->primero;
      this->ultimo = n;
    }
    return true;

  } else if (this->ultimo->e.Volumen() <= poro.Volumen()) {
    TListaNodo *n = new TListaNodo();
    n->e = poro;

    n->anterior = this->ultimo;
    this->ultimo->siguiente = n;
    this->ultimo = n;
    return true;
  }

  while (poro.Volumen() < p->e.Volumen()) {
    p = p->siguiente;
  }

  if (p->e.Volumen() == poro.Volumen()) {
    p = p->siguiente;
  }

  TListaNodo *nw = new TListaNodo();
  nw->e = poro;

  TListaNodo *s = p->siguiente;

  nw->siguiente = s;
  nw->anterior = p;

  p->siguiente = nw;
  s->anterior = nw;

  return true;
}

bool TListaPoro::Borrar(const TPoro &poro) {

  TListaNodo *p = primero;

  while (p->siguiente != NULL) { // && p->e.Volumen() <= poro.Volumen()
                                 // posible optimización
    if (p->e == poro) {
      TListaNodo *anterior = p->anterior;
      TListaNodo *siguiente = p->siguiente;

      anterior->siguiente = siguiente;
      siguiente->anterior = anterior;

      p->~TListaNodo();

      return true;
    }

    p = p->siguiente;
  }

  if (p->e == poro) { // TODO hacer la comprobación si es al final/al principio
    TListaNodo *anterior = p->anterior;
    TListaNodo *siguiente = p->siguiente;

    // cout << "llego" << endl;
    anterior->siguiente = siguiente;
    siguiente->anterior = anterior;

    p->~TListaNodo();

    return true;
  }

  return false;
}

bool TListaPoro::Borrar(const TListaPosicion &pos) {
  return this->Borrar((*pos.pos).e);
}

TPoro TListaPoro::Obtener(const TListaPosicion &posicion) const {
  if (posicion.EsVacia()) {
    return TPoro();
  } else {
    return posicion.pos->e;
  }
}

bool TListaPoro::Buscar(const TPoro &poro) const {
  TListaNodo *p = this->primero;

  while (p->siguiente != NULL && p->e.Volumen() <= poro.Volumen()) {
    if (p->e == poro) {
      return true;
    }

    p = p->siguiente;
  }

  return false;
}

int TListaPoro::Longitud() const {
  if (this->EsVacia()) {
    return 0;
  }

  TListaNodo *p = this->primero;
  int count = 1;

  while (p->siguiente != NULL) {
    count++;
    p = p->siguiente;
  }

  return count;
}

TListaPosicion TListaPoro::Primera() const {
  if (this->EsVacia()) {
    return TListaPosicion();
  } else {
    TListaPosicion p;
    p.pos = primero;
    return p;
  }
}

TListaPosicion TListaPoro::Ultima() const {
  if (this->EsVacia()) {
    return TListaPosicion();
  } else {
    TListaPosicion p;
    p.pos = ultimo;
    return p;
  }
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) { return *this; }

ostream &operator<<(ostream &os, const TListaPoro &lista) {
  if (lista.EsVacia()) {
    os << "()";
    return os;
  }

  TListaPosicion it = lista.Primera();
  os << "(";

  while (!it.EsVacia()) {
    os << lista.Obtener(it);
    if (!it.Siguiente().EsVacia()) {
      os << " ";
    }
    it = it.Siguiente();
  }

  os << ")";

  return os;
}

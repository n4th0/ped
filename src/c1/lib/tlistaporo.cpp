#include "../include/tlistaporo.h"
#include <cstddef>

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

bool TListaPosicion::operator==(const TListaPosicion &pos) const {
  return this->pos == pos.pos;
}

TListaPosicion TListaPosicion::Anterior() const {
  TListaPosicion tp;
  if (pos != NULL) {
    tp.pos = pos->anterior;
  } else {
    return TListaPosicion();
  }
  return tp;
}

TListaPosicion TListaPosicion::Siguiente() const {
  TListaPosicion tp;
  if (pos != NULL) {
    tp.pos = pos->siguiente;
  } else {
    return TListaPosicion();
  }
  return tp;
}

bool TListaPosicion::EsVacia() const { return pos == NULL; }

////////////////////////////////////////////////////
/// clase TListaPoro
////////////////////////////////////////////////////

TListaPoro::TListaPoro() { primero = ultimo = NULL; }
TListaPoro::TListaPoro(const TListaPoro &lista) {
  primero = ultimo = NULL;

  if (lista.EsVacia()) {
    return;
  }

  TListaNodo *it = lista.primero;

  while (it->siguiente != NULL) {
    this->Insertar(it->e);

    it = it->siguiente;
  }

  this->Insertar(lista.ultimo->e);
}

TListaPoro::~TListaPoro() {

  if (this->EsVacia()) {
    return;
  }

  TListaNodo *it = this->primero;
  TListaNodo *it2;

  while (it->siguiente != NULL) {
    // this->Borrar(it.e);

    it2 = it->siguiente;
    if (it != NULL) {
      delete it;
    }
    it = it2;
  }

  if (it != NULL) {
    delete it;
  }

  // this->Borrar(it.e);

  primero = ultimo = NULL;
}

TListaPoro &TListaPoro::operator=(const TListaPoro &lista) {

  this->~TListaPoro();

  // primero = lista.primero;
  // ultimo = lista.ultimo;

  TListaNodo it = *lista.primero;

  while (it.siguiente != NULL) { // copia profunda
    this->Insertar(it.e);
    it = *it.siguiente;
  }
  this->Insertar(it.e);

  return *this;
}

bool TListaPoro::EsVacia() const { return NULL == primero && ultimo == NULL; }

bool TListaPoro::operator==(const TListaPoro &lista) const {
  TListaPosicion it1 = this->Primera();
  TListaPosicion it2 = lista.Primera();

  // TODO optimizar
  if (this->Longitud() != lista.Longitud()) {
    return false;
  }

  while (!it1.EsVacia() && !it2.EsVacia()) {
    if (it1.pos->e != it2.pos->e) {
      return false;
    }

    it1 = it1.Siguiente();
    it2 = it2.Siguiente();
  }

  return true;
}

TListaPoro TListaPoro::operator+(const TListaPoro &lista) const {
  TListaPoro l = TListaPoro(lista);

  if (this->EsVacia()) {
    return lista;
  }
  if (lista.EsVacia()) {
    return *this;
  }

  TListaNodo *it = this->primero;

  while (it->siguiente != NULL) {
    l.Insertar(it->e);
    it = it->siguiente;
  }

  l.Insertar(it->e);

  return l;
}

TListaPoro TListaPoro::operator-(const TListaPoro &lista) const {
  if (this->EsVacia() || lista.EsVacia()) {
    return *this;
  }

  TListaPoro l(*this);
  TListaNodo *it = lista.primero;

  while (it->siguiente != NULL) {
    l.Borrar(it->e);
    it = it->siguiente;
  }
  l.Borrar(it->e);

  return l;
}

bool TListaPoro::Insertar(const TPoro &poro) {

  if (this->Buscar(poro)) {
    return false;
  }

  TListaNodo *n = new TListaNodo();
  n->e = poro;

  if (this->EsVacia()) {
    this->ultimo = n;
    this->primero = n;
    return true;
  }

  TListaNodo *p = primero;
  /*
   * TODO
   * a la hora de insertar tporos que tengan el mimso valor
   * de volumen, debe estar al final o despues del primero?
   *
   * se inserta "blanco"
   *
   * Justo despues:
   * ((1, 1) 1.00 rojo (1, 1) 1.00 azul)
   * ((1, 1) 1.00 rojo (1, 1) 1.00 blanco (1, 1) 1.00 azul)
   *
   * Despues de todos:
   * ((1, 1) 1.00 rojo (1, 1) 1.00 azul)
   * ((1, 1) 1.00 rojo (1, 1) 1.00 azul (1, 1) 1.00 blanco)
   *
   * */
  // int longitud = Longitud();

  // inserto al principio
  if (p->e.Volumen() > poro.Volumen()) { // poner el igual y descomentar
    //                                      el resto del if

    if (p->e.Volumen() > poro.Volumen()) {

      // TListaNodo * ap = this->primero;
      // n->siguiente = ap;
      // ap->anterior = n;
      // this->primero = n;

      this->primero->anterior = n;
      n->siguiente = this->primero;
      this->primero = n;

      // } else { // igualdad
      //   if (longitud == 1) {
      //     this->primero->siguiente = n;
      //     n->anterior = this->primero;
      //     this->ultimo = n;
      //   } else {
      //     TListaNodo *sig = this->primero->siguiente;
      //     sig->anterior = n;
      //     this->primero->siguiente = n;
      //     n->anterior = this->primero;
      //     n->siguiente = sig;
      //   }
    }
    return true;

  } else if (this->ultimo->e.Volumen() <= poro.Volumen()) {
    TListaNodo *ult = this->ultimo;

    ult->siguiente = n;
    n->anterior = ult;
    this->ultimo = n;

    return true;
  }

  while (p->e.Volumen() <= poro.Volumen()) {
    p = p->siguiente;
  }

  TListaNodo *s = p;
  TListaNodo *ant = p->anterior;

  s->anterior = n;
  ant->siguiente = n;

  n->anterior = ant;
  n->siguiente = s;

  return true;
}

bool TListaPoro::Borrar(const TPoro &poro) {

  if (this->EsVacia()) {
    return false;
  }

  // caso en el que pasa a ser vacía
  if (poro == primero->e && primero == ultimo) {
    // primero->~TListaNodo();
    delete primero;
    ultimo = primero = NULL;
    return true;
  }

  TListaNodo *p = primero;
  if (poro == primero->e) { // es el primero
    this->primero = p->siguiente;
    this->primero->anterior = NULL;
    delete p;
    // p->~TListaNodo();
    return true;
  }

  if (poro == ultimo->e) { // es el ultimo

    p = ultimo;
    this->ultimo = p->anterior;
    this->ultimo->siguiente = NULL;
    delete p;
    // p->~TListaNodo();
    return true;
  }

  while (p->siguiente != NULL && p->e.Volumen() <= poro.Volumen()) {
    if (p->e == poro) {

      TListaNodo *anterior = p->anterior;
      TListaNodo *siguiente = p->siguiente;

      anterior->siguiente = siguiente;
      siguiente->anterior = anterior;

      delete p;
      // p->~TListaNodo();
      return true;
    }

    p = p->siguiente;
  }

  return false;
}

bool TListaPoro::Borrar(const TListaPosicion &pos) {
  return this->Borrar(pos.pos->e);
}

TPoro TListaPoro::Obtener(const TListaPosicion &posicion) const {
  if (posicion.EsVacia()) {
    return TPoro();
  } else {
    return posicion.pos->e;
  }
}

bool TListaPoro::Buscar(const TPoro &poro) const {
  if (this->EsVacia()) {
    return false;
  }

  TListaNodo *p = this->primero;

  while (p->siguiente != NULL && p->e.Volumen() <= poro.Volumen()) {
    if (p->e == poro) {
      return true;
    }

    p = p->siguiente;
  }

  if (p->e == poro) {
    return true;
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

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
  if (n2 >= this->Longitud()) {
    n2 = this->Longitud();
  }

  if (n1 <= 0) {
    n1 = 1;
  }

  if (n1 == n2) { // caso en el que se extrae uno y se devuelve
    int count = 1;
    TListaPosicion it = this->Primera();
    while (!it.EsVacia() && count != n1) {
      it = it.Siguiente();
      count++;
    }

    TListaPoro l = TListaPoro();
    l.Insertar(this->Obtener(it));
    this->Borrar(this->Obtener(it));
    return l;
  }

  if (n1 > n2) { // caso en el que no abarque ninguno
    return TListaPoro();
  }

  int count = 1;
  TListaPosicion it2, it = this->Primera();
  TListaPoro l = TListaPoro();
  bool borrado = false;

  while (!it.EsVacia() && count <= n2) {

    if (n1 <= count) {
      l.Insertar(this->Obtener(it));
      it2 = it.Siguiente();
      this->Borrar(it);
      borrado = true;
    }

    count++;

    if (!borrado) {
      it = it.Siguiente(); // esto va a estar muy raro
    } else {
      it = it2;
    }
  }

  return l;
}

void TListaPoro::debug() {
  if (this->EsVacia()) {
    return;
  }

  TListaNodo *n = primero;

  while (n->siguiente != NULL) {
    cout << n->e << endl;
  }
  cout << n->e << endl;
}

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

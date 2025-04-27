#include "../include/tabbporo.h"
#include <iostream>
#include <queue>

/////////////////////////////
// TABBPoro
/////////////////////////////

void TABBPoro::InordenAux(TVectorPoro &v, int &pos) const {
  if (!this->EsVacio()) {
    nodo->iz.InordenAux(v, pos);
    v[pos] = nodo->item;
    pos++;
    nodo->de.InordenAux(v, pos);
  }
}

void TABBPoro::PreordenAux(TVectorPoro &v, int &pos) const {
  if (!this->EsVacio()) {
    v[pos] = nodo->item;
    pos++;
    nodo->iz.InordenAux(v, pos);
    nodo->de.InordenAux(v, pos);
  }
}

void TABBPoro::PostordenAux(TVectorPoro &v, int &pos) const {
  if (!this->EsVacio()) {
    nodo->iz.InordenAux(v, pos);
    nodo->de.InordenAux(v, pos);
    v[pos] = nodo->item;
    pos++;
  }
}

TABBPoro::TABBPoro() : nodo(NULL) {}

TABBPoro::TABBPoro(const TABBPoro &arb) {

  if (arb.EsVacio()) {
    return;
  }

  this->nodo = new TNodoABB(*arb.nodo);
}

TABBPoro::~TABBPoro() {

  if (nodo != NULL) {
    // nodo->~TNodoABB();
    delete nodo;
    nodo = NULL;
  }
}

TABBPoro &TABBPoro::operator=(const TABBPoro &tabb) {
  this->~TABBPoro();

  if (tabb.EsVacio()) {
    return *this;
  }

  this->nodo = new TNodoABB(*tabb.nodo);

  return *this;
}

bool TABBPoro::operator==(const TABBPoro &arb) const {
  if (this->EsVacio() && arb.EsVacio()) {
    return true;
  }
  if (this->EsVacio() || arb.EsVacio()) {
    return false;
  }

  return (arb.nodo->item == this->nodo->item &&
          arb.nodo->de == this->nodo->de && arb.nodo->iz == this->nodo->iz);
}

bool TABBPoro::EsVacio() const { return (nodo == NULL); }

bool TABBPoro::Insertar(const TPoro &p) {
  if (this->EsVacio()) {
    TNodoABB *n = new TNodoABB();
    n->item = p;
    nodo = n;
    return true;
  }

  if (nodo->item == p) {
    return false;
  }

  if (nodo->item.Volumen() < p.Volumen()) {
    return nodo->de.Insertar(p);
  }

  if (nodo->item.Volumen() > p.Volumen()) {
    return nodo->iz.Insertar(p);
  }

  return false;
}

// void TABBPoro::paint(const string &prefix, bool isLeft) {
//   if (!this->EsVacio()) {
//     cout << prefix;
//     cout << (isLeft ? "├──" : "└──");
//     cout << this->nodo->item.Volumen() << endl;
//     this->nodo->iz.paint(prefix + (isLeft ? "│   " : "    "), true);
//     this->nodo->de.paint(prefix + (isLeft ? "│   " : "    "), false);
//   }
// }

bool TABBPoro::Borrar(const TPoro &poro) {
  if (this->EsVacio()) {
    return false;
  }

  if (poro.Volumen() < this->nodo->item.Volumen()) {
    return nodo->iz.Borrar(poro);
  } else if (poro.Volumen() > this->nodo->item.Volumen()) {
    return nodo->de.Borrar(poro);
  }

  if (poro.Volumen() != this->nodo->item.Volumen()) {
    return false;
  }

  if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()) {
    if (this->nodo != NULL) {
      delete this->nodo;
      this->nodo = NULL;
    }
    return true;
  }

  if (!this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()) {
    this->nodo = this->nodo->de.nodo;
    return true;
  }

  if (this->nodo->de.EsVacio() && !this->nodo->iz.EsVacio()) {
    this->nodo = this->nodo->iz.nodo;
    return true;
  }

  TNodoABB *it = this->nodo->iz.nodo;
  TABBPoro *it2 = this;

  while (it->de.nodo != NULL) {
    it2 = &it->de;
    it = it->de.nodo;
  }

  TPoro aux = this->nodo->item;
  this->nodo->item = it->item;

  this->nodo->iz.Borrar(this->nodo->item);

  // if (!it->iz.EsVacio()) {
  //   TABBPoro arb = it2->nodo->de;
  //   it2->nodo = it2->nodo->iz.nodo;
  //   it2->nodo->de = arb;
  // } else {
  //   it2->nodo = NULL;
  // }

  return true;
}

bool TABBPoro::Buscar(const TPoro &p) const {
  if (this->EsVacio()) {
    return false;
  }

  if (nodo->item == p)
    return true;

  return (nodo->iz.Buscar(p) || nodo->de.Buscar(p));
}

TPoro TABBPoro::Raiz() const {
  if (nodo == NULL) {
    return TPoro();
  }
  return nodo->item;
}

int TABBPoro::Altura() const {
  if (this->EsVacio()) {
    return 0;
  }

  int a = this->nodo->de.Altura();
  int b = this->nodo->iz.Altura();

  if (a < b) {
    return b + 1;
  } else {
    return a + 1;
  }
}

int TABBPoro::Nodos() const {
  if (EsVacio()) {
    return 0;
  } else {
    return (1 + nodo->de.Nodos() + nodo->iz.Nodos());
  }
}

int TABBPoro::NodosHoja() const {
  if (EsVacio()) {
    return 0;
  }
  if (nodo->de.EsVacio() && nodo->iz.EsVacio()) {
    return 1;
  }

  return nodo->de.NodosHoja() + nodo->iz.NodosHoja();
}

TVectorPoro TABBPoro::Niveles() const {

  queue<TABBPoro> queue;

  TVectorPoro v(this->Nodos());
  TABBPoro abb = *this;
  queue.push(abb);
  int i = 1;

  while (!queue.empty()) {
    abb = queue.front();
    v[i] = abb.nodo->item;

    if (!abb.nodo->iz.EsVacio()) {
      queue.push(abb.nodo->iz);
    }
    if (!abb.nodo->de.EsVacio()) {
      queue.push(abb.nodo->de);
    }
    i++;

    queue.pop();
  }

  return v;
}

TVectorPoro TABBPoro::Inorden() const {
  int posicion = 1;
  TVectorPoro v(Nodos());
  InordenAux(v, posicion);
  return v;
}

TVectorPoro TABBPoro::Preorden() const {
  int posicion = 1;
  TVectorPoro v(Nodos());
  PreordenAux(v, posicion);
  return v;
}

TVectorPoro TABBPoro::Postorden() const {
  int posicion = 1;
  TVectorPoro v(Nodos());
  PostordenAux(v, posicion);
  return v;
}

TABBPoro TABBPoro::operator+(const TABBPoro &arb) {
  TVectorPoro v = arb.Inorden();

  TABBPoro a(*this);

  for (int i = 1; i <= v.Longitud(); i++) {
    a.Insertar(v[i]);
  }

  return a;
}

TABBPoro TABBPoro::operator-(const TABBPoro &arb) {
  TVectorPoro v = this->Inorden();

  TABBPoro a;

  for (int i = 1; i <= v.Longitud(); i++) {
    if (!arb.Buscar(v[i])) {
      a.Insertar(v[i]);
    }
  }

  return a;
}

ostream &operator<<(ostream &os, const TABBPoro &abb) {
  TVectorPoro v = abb.Niveles();
  os << v;
  return os;
}

/////////////////////////////
// T TNodoABB
/////////////////////////////
TNodoABB::TNodoABB() : item(), iz(), de() {}

TNodoABB::TNodoABB(const TNodoABB &n) : item(n.item), iz(n.iz), de(n.de) {}

TNodoABB::~TNodoABB() {}

TNodoABB &TNodoABB::operator=(const TNodoABB &n) {
  item = n.item;
  de = n.de;
  iz = n.iz;

  return *this;
}

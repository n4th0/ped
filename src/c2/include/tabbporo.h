#ifndef _TABB_PORO_H_
#define _TABB_PORO_H_

#include "tporo.h"
#include "tvectorporo.h"

using namespace std;

class TNodoABB;
class TABBPoro;

class TABBPoro {
  friend TNodoABB;

private:
  TNodoABB *nodo;
  void InordenAux(TVectorPoro &, int &) const;
  void PreordenAux(TVectorPoro &, int &) const;
  void PostordenAux(TVectorPoro &, int &) const;

public:
  TABBPoro();
  TABBPoro(const TABBPoro &);
  ~TABBPoro();
  TABBPoro &operator=(const TABBPoro &);

  bool operator==(const TABBPoro &) const;
  bool EsVacio() const;
  bool Insertar(const TPoro &);
  bool Borrar(const TPoro &);
  bool Buscar(const TPoro &) const;
  TPoro Raiz() const;
  int Altura() const;
  int Nodos() const;
  int NodosHoja() const;
  TVectorPoro Niveles() const;
  TVectorPoro Inorden() const;
  TVectorPoro Preorden() const;
  TVectorPoro Postorden() const;
  TABBPoro operator+(const TABBPoro &);
  TABBPoro operator-(const TABBPoro &);
  void paint(const string &prefix, bool isLeft);

  friend ostream &operator<<(ostream &, const TABBPoro &);
};

class TNodoABB {
  friend TABBPoro;

private:
  TPoro item;
  TABBPoro iz, de;

public:
  TNodoABB();
  TNodoABB(const TNodoABB &);
  ~TNodoABB();
  TNodoABB &operator=(const TNodoABB &);
};

#endif

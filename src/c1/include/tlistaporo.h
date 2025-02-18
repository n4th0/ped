#ifndef _TLISTA_PORO_
#define _TLISTA_PORO_
#include "./tporo.h"
#include <iostream>

using namespace std;

class TListaNodo {
  friend class TListaPosicion;
  friend class TListaPoro;

private:
  TPoro e;
  TListaNodo *anterior;
  TListaNodo *siguiente;

public:
  TListaNodo();
  ~TListaNodo();
  TListaNodo(TListaNodo &);
  TListaNodo &operator=(TListaNodo &);
};

class TListaPosicion {
  friend class TListaNodo;
  friend class TListaPoro;

private:
  TListaNodo *pos;

public:
  TListaPosicion();
  TListaPosicion(const TListaPosicion &);
  ~TListaPosicion();
  TListaPosicion &operator=(const TListaPosicion &);

  bool operator==(TListaPosicion &) const;
  TListaPosicion Anterior() const;
  TListaPosicion Siguiente() const;
  bool EsVacia() const;
};

class TListaPoro {
  friend class TListaNodo;
  friend class TListaPosicion;

private:
  TListaNodo *primero;
  TListaNodo *ultimo;

public:
  TListaPoro();
  TListaPoro(TListaPoro &);
  ~TListaPoro();
  TListaPoro &operator=(TListaPoro &);

  bool operator==(const TListaPoro &) const;
  TListaPoro operator+(TListaPoro &);
  TListaPoro operator-(TListaPoro &);
  bool EsVacia() const;
  bool Insertar(const TPoro &);
  bool Borrar(const TPoro &);
  bool Borrar(const TListaPosicion &);
  TPoro Obtener(const TListaPosicion &) const;
  bool Buscar(const TPoro &) const;
  int Longitud() const;
  TListaPosicion Primera() const;
  TListaPosicion Ultima() const;

  TListaPoro ExtraerRango(int n1, int n2);

  friend ostream &operator<<(ostream &, const TListaPoro &);
};

#endif

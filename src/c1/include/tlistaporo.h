#ifndef _TLISTA_PORO_
#define _TLISTA_PORO_
#include "./tporo.h"
#include <iostream>

using namespace std;

class TListaNodo {
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
private:
  TListaNodo *pos;

public:
  TListaPosicion();
  TListaPosicion(TListaPosicion &);
  ~TListaPosicion();
  TListaPosicion &operator=(TListaPosicion &);

  bool operator==(TListaPosicion &) const;
  TListaPosicion Anterior();
  TListaPosicion Siguiente();
  bool EsVacia() const;
};

class TListaPoro {
private:
  TListaNodo *primero;
  TListaNodo *ultimo;

public:
  TListaPoro();
  TListaPoro(TListaPoro &);
  ~TListaPoro();
  TListaPoro &operator=(TListaPoro &);

  bool operator==(TListaPoro &) const;
  TListaPoro operator+(TListaPoro &);
  TListaPoro operator-(TListaPoro &);
  bool EsVacia() const;
  bool Insertar(TPoro &);
  bool Borrar(TPoro &);
  bool Borrar(TListaPosicion &);
  TPoro Obtener(TListaPosicion &);
  bool Buscar(TPoro &) const;
  int Longitud() const;
  TListaPosicion Primera() const;
  TListaPosicion Ultima() const;

  TListaPoro ExtraerRango(int n1, int n2);

  friend ostream &operator<<(ostream &, TListaPoro &);
};

#endif

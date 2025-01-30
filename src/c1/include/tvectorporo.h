#ifndef T_VECTOR_PORO
#define T_VECTOR_PORO

#include "../include/tporo.h"

class TVectorPoro {

private:
  int dimension;
  TPoro *datos;
  TPoro error;

  TVectorPoro & copy(TVectorPoro &);
public:
  TVectorPoro();
  ~TVectorPoro();
  TVectorPoro(int);
  TVectorPoro(TVectorPoro &);
  TVectorPoro &operator=(TVectorPoro &);

  bool operator==(TVectorPoro &);
  bool operator!=(TVectorPoro &);

  TPoro &operator[](int);
  TPoro operator[](int) const;

  int Longitud();
  int Cantidad();
  bool Redimensionar(int);

  friend std::ostream &operator<<(std::ostream &, TVectorPoro &);
};

#endif

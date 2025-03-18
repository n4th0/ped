#ifndef T_VECTOR_PORO
#define T_VECTOR_PORO

#include "../include/tporo.h"

class TVectorPoro {

private:
  int dimension;
  TPoro *datos;
  TPoro error;

  TVectorPoro &copy(const TVectorPoro &);

public:
  TVectorPoro();
  ~TVectorPoro();
  TVectorPoro(int);
  TVectorPoro(const TVectorPoro &);
  TVectorPoro &operator=(const TVectorPoro &);

  bool operator==(const TVectorPoro &) const;
  bool operator!=(const TVectorPoro &) const;

  TPoro &operator[](int);
  TPoro operator[](int) const;

  int Longitud() const;
  int Cantidad() const;
  bool Redimensionar(int);

  friend std::ostream &operator<<(std::ostream &, const TVectorPoro &);
};

#endif

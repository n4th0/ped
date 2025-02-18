#ifndef T_PORO_H
#define T_PORO_H

#include <ostream>
using namespace std;

class TPoro {

public:
  TPoro();
  TPoro(int, int, double, char *);
  TPoro(int, int, double);
  TPoro(const TPoro &);
  ~TPoro();
  TPoro &operator=(const TPoro &);
  bool operator==(const TPoro &);
  bool operator!=(const TPoro &);
  void Posicion(int, int);
  void Volumen(double);
  void Color(char *);
  int PosicionX() const;
  int PosicionY() const;
  double Volumen() const;
  char *Color() const;
  bool EsVacio() const;

private:
  int x = 0;
  int y = 0;
  double volumen = 0;
  char *color = NULL;

  friend ostream &operator<<(ostream &, const TPoro &);
};

#endif // !T_PORO_H

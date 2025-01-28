#ifndef T_PORO_H
#define T_PORO_H

#include <ostream>
class TPoro {

public:
  TPoro();
  TPoro(int, int, double, char *);
  TPoro(TPoro &);
  ~TPoro();
  TPoro &operator=(TPoro &);
  bool operator==(TPoro &);
  bool operator!=(TPoro &);
  void Posicion(int, int);
  void Volumen(double);
  void Color(char *);
  int PosicionX();
  int PosicionY();
  double Volumen();
  char *Color();
  bool EsVacio();

private:
  int x = 0;
  int y = 0;
  double volumen = 0;
  char *color = NULL;

  friend std::ostream &operator<<(std::ostream &, TPoro &);
};

#endif // !T_PORO_H

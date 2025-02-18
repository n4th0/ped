
#include "../include/tporo.h"
#include <cctype>
#include <cstring>
#include <ios>

////////////////////////////////////////////////////
/// clase TPoro
////////////////////////////////////////////////////

TPoro::TPoro() {
  this->color = NULL;
  this->volumen = 0;
  this->x = 0;
  this->y = 0;
}

TPoro::TPoro(int x, int y, double vol) {
  this->volumen = vol;
  this->x = x;
  this->y = y;
  this->color = NULL;
}

TPoro::TPoro(int x, int y, double volumen, char *color) {
  Color(color);
  this->volumen = volumen;
  this->x = x;
  this->y = y;
}

TPoro::TPoro(const TPoro &p) {
  // this->color = p.color;
  Color(p.color);
  this->volumen = p.volumen;
  this->x = p.x;
  this->y = p.y;
}

TPoro::~TPoro() {
  if (this->color != NULL) {
    delete[] this->color;
    this->color = NULL;
  }
}

TPoro &TPoro::operator=(const TPoro &p) {

  if (this != &p) {
    this->~TPoro();
    this->x = p.x;
    this->y = p.y;
    this->volumen = p.volumen;
    this->Color(p.color);
  }

  // this = new TPoro(p.x, p.y, p.volumen, p.color);

  return *this;
}

bool TPoro::operator==(const TPoro &p) {
  if (this->color != NULL && p.color != NULL) {
    return p.x == this->x && p.y == this->y && p.volumen == this->volumen &&
           !strcmp(this->color, p.color);
  } else {
    return p.x == this->x && p.y == this->y && p.volumen == this->volumen &&
           this->color == NULL && p.color == NULL;
  }
}

bool TPoro::operator!=(const TPoro &p) { return !(*this == p); }

void TPoro::Posicion(int x, int y) {
  this->x = x;
  this->y = y;
}

void TPoro::Volumen(double vol) { this->volumen = vol; }

void TPoro::Color(char *col) {
  if (this->color != NULL) {
    delete[] this->color;
  }

  if (col != NULL) {

    int size = (int)strlen(col);
    this->color = new char[size + 1];

    for (size_t i = 0; i < size; i++) {
      color[i] = tolower(col[i]);
    }

    color[size] = '\0';
    // delete[] col;

  } else {
    color = NULL;
  }
}

int TPoro::PosicionX() const { return x; }

int TPoro::PosicionY() const { return y; }

double TPoro::Volumen() const { return volumen; }

char *TPoro::Color() const { return this->color; }

bool TPoro::EsVacio() const {
  return this->x == 0 && this->y == 0 && this->color == NULL;
}

std::ostream &operator<<(std::ostream &os, const TPoro &poro) {
  if (!poro.EsVacio()) {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << "(" << poro.PosicionX() << ", " << poro.PosicionY() << ") "
       << poro.Volumen() << " ";

    if (poro.Color() != NULL)
      os << poro.Color();
    else
      os << "-";

  } else
    os << "()";

  return os;
}

#include "../include/tvectorporo.h"
#include <cstddef>
#include <iostream>

////////////////////////////////////////////////////
/// clase TVectorPoro
////////////////////////////////////////////////////

TVectorPoro::TVectorPoro() : error() {
  this->datos = NULL;
  this->dimension = 0;
}

TVectorPoro::~TVectorPoro() {
  if (this->datos != NULL) {
    delete[] this->datos;
    this->datos = NULL;
    return;
  }

  this->dimension = 0;
}

TVectorPoro::TVectorPoro(int size) : error() {
  if (size <= 0) {
    this->datos = NULL;
    this->dimension = 0;
    return;
  }

  this->datos = new TPoro[size];
  this->dimension = size;
}

TVectorPoro::TVectorPoro(const TVectorPoro &vecporo) {

  if (vecporo.dimension == 0) {
    this->datos = NULL;
    this->dimension = 0;
    return;
  }

  *this = copy(vecporo);
}

TVectorPoro &TVectorPoro::copy(const TVectorPoro &vecporo) {
  TVectorPoro *n = new TVectorPoro();

  n->dimension = vecporo.Longitud();
  n->datos = new TPoro[vecporo.Longitud()];
  for (size_t i = 0; i < vecporo.Longitud(); i++) {
    n->datos[i] = vecporo.datos[i];
  }

  return *n;
}

TVectorPoro &TVectorPoro::operator=(const TVectorPoro &vecporo) {

  this->~TVectorPoro();

  this->dimension = vecporo.Longitud();
  this->datos = new TPoro[vecporo.Longitud()];
  for (size_t i = 0; i < vecporo.Longitud(); i++) {
    this->datos[i] = vecporo.datos[i];
  }

  return *this;
}

bool TVectorPoro::operator==(const TVectorPoro &vecporo) const {
  if (this->dimension != vecporo.Longitud()) {
    return false;
  }

  for (size_t i = 0; i < this->Longitud(); i++) {
    if (this->datos[i] != vecporo.datos[i]) {
      return false;
    }
  }

  return true;
}

bool TVectorPoro::operator!=(const TVectorPoro &vecporo) const {
  return !(*this == vecporo);
}

TPoro &TVectorPoro::operator[](int pos) {

  if (pos <= 0 || pos > this->dimension) {
    return this->error;
  }

  pos--;

  return datos[pos];
}

TPoro TVectorPoro::operator[](int pos) const {
  if (pos <= 0 || pos > this->dimension) {
    return this->error;
  }

  pos--;

  return datos[pos];
}

int TVectorPoro::Longitud() const { return this->dimension; }

int TVectorPoro::Cantidad() const {
  int ocupadas = 0;

  for (size_t i = 0; i < dimension; i++) {
    if (this->datos[i] == (TPoro)error) {
      break;
    }
    ocupadas++;
  }

  return ocupadas;
}

bool TVectorPoro::Redimensionar(int size) {
  if (size <= 0 || size == dimension) {
    return false;
  }

  TPoro *arr = new TPoro[size];

  int min;
  // TODO hacer el min
  if (size < dimension)
    min = size;
  else
    min = dimension;
  

  for (size_t i = 0; i < min; i++)
    arr[i] = datos[i];


  this->~TVectorPoro();

  this->datos = arr;
  this->dimension = size;

  return true;
}

std::ostream &operator<<(std::ostream &os, const TVectorPoro &vecporo) {
  if (vecporo.Longitud() == 0) {
    os << "[]";
    return os;
  }

  os << "[";

  for (size_t i = 0; i < vecporo.Longitud(); i++) {
    if (i == vecporo.Longitud() - 1) {
      os << i + 1 << " " << vecporo.datos[i];
    } else {
      os << i + 1 << " " << vecporo.datos[i] << " ";
    }
  }

  os << "]";

  return os;
}

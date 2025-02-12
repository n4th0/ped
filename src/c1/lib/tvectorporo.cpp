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

TVectorPoro::TVectorPoro(TVectorPoro &vecporo) {

  if (vecporo.dimension == 0) {
    vecporo.datos = NULL;
    vecporo.dimension = 0;
    return;
  }

  *this = copy(vecporo);
}

TVectorPoro &TVectorPoro::copy(TVectorPoro &vecporo) {
  TVectorPoro *n = new TVectorPoro();

  n->dimension = vecporo.dimension;
  n->datos = new TPoro[vecporo.dimension];
  for (size_t i = 0; i < vecporo.dimension; i++) {
    n->datos[i] = vecporo.datos[i];
  }

  return *n;
}

TVectorPoro &TVectorPoro::operator=(TVectorPoro &vecporo) {

  this->~TVectorPoro();

  this->dimension = vecporo.dimension;
  this->datos = new TPoro[vecporo.dimension];
  for (size_t i = 0; i < vecporo.dimension; i++) {
    this->datos[i] = vecporo.datos[i];
  }

  return *this;
}

bool TVectorPoro::operator==(TVectorPoro &vecporo) const {
  if (this->dimension != vecporo.dimension) {
    return false;
  }

  for (size_t i = 0; i < this->dimension; i++) {
    if (this->datos[i] != vecporo.datos[i]) {
      return false;
    }
  }

  return true;
}

bool TVectorPoro::operator!=(TVectorPoro &vecporo) const {
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

  if (size < dimension) {
    for (size_t i = 0; i < size; i++) {
      arr[i] = datos[i];
    }
  } else {
    for (size_t i = 0; i < size; i++) {
      arr[i] = datos[i];
      if (i >= dimension) {
        TPoro p = TPoro();
        arr[i] = p;
      }
    }
  }

  this->~TVectorPoro();

  this->datos = arr;
  this->dimension = size;

  return true;
}

std::ostream &operator<<(std::ostream &os, TVectorPoro &vecporo) {
  if (vecporo.dimension == 0) {
    os << "[]";
    return os;
  }

  os << "[";

  for (size_t i = 0; i < vecporo.dimension; i++) {
    if (i == vecporo.dimension - 1) {
      os << i + 1 << " " << vecporo.datos[i];
    } else {
      os << i + 1 << " " << vecporo.datos[i] << " ";
    }
  }

  os << "]";

  return os;
}

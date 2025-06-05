#ifndef T_QUEUE_PORO
#define T_QUEUE_PORO

#include "./tporo.h"

class TQueueNodo {
  friend class TQueuePoro;

private:
  TPoro e;
  TQueueNodo *siguiente;

public:
  TQueueNodo();
  ~TQueueNodo();
  TQueueNodo(TQueueNodo &);
  TQueueNodo &operator=(TQueueNodo &);
};

class TQueuePoro {
  friend class TQueueNodo;

private:
  TQueueNodo *head;

public:
  TQueuePoro();
  ~TQueuePoro();
  TQueuePoro(const TQueuePoro &);
  TQueuePoro &operator=(const TQueuePoro &);

  bool operator==(const TQueuePoro &) const;
  bool operator!=(const TQueuePoro &) const;

  void Enqueue(const TPoro &);
  TPoro Dequeue();

  bool EsVacia() const;


  friend std::ostream &operator<<(std::ostream &, const TQueuePoro &);
};

#endif

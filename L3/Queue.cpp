#include "Queue.h"
//Complexity: O(n)
Queue::Queue(const int &_cap)
{
  this->cap = _cap;
  this->elems = make_unique<TElem[]>(_cap);
  this->next = make_unique<TElem[]>(_cap);
  this->head = -1;
  for (int i = 0; i < this->cap - 1; i++)
    this->next[i] = i + 1;

  this->next[this->cap - 1] = -1;
  this->firstEmpty = 0;
}

bool Queue::addFirst(const TElem &elem)
{
  if (firstEmpty == -1)
    return false;

  int newPosition = this->firstEmpty;
  this->elems[newPosition] = elem;
  this->firstEmpty = this->next[firstEmpty];
  this->next[newPosition] = this->head;
  this->head = newPosition;

  return true;
}

void Queue::smartShow()
{
  int index = this->head;

  while (index != -1)
  {
    auto elem = this->elems[index];
    cout << elem << " ";
    index = this->next[index];
  }
  cout << endl;
}

void Queue::showAll()
{
  for (int i = 1; i < this->cap; i++)
    //if (this->elems[i])
    cout << this->elems[i] << " ";
  cout << endl;
}
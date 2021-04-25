#include "Queue.h"
#include <stdexcept>

//Complexity: O(n)
Queue::Queue(const int &_cap)
{
  this->cap = _cap;
  size = 0;
  this->elems = make_unique<TElem[]>(_cap);
  this->next = make_unique<TElem[]>(_cap);
  this->head = -1;
  for (int i = 0; i < this->cap - 1; i++)
    this->next[i] = i + 1;

  this->next[this->cap - 1] = -1;
  this->firstEmpty = 0;
}

//elementele se adauga in spate
bool Queue::add(const TElem &elem)
{
  if (this->firstEmpty == -1)
    return false;

  int newPosition = this->firstEmpty;
  this->elems[newPosition] = elem;
  this->firstEmpty = this->next[firstEmpty];
  this->next[newPosition] = this->head;
  this->head = newPosition;

  size++;
  return true;
}

void Queue::addFromStack(const vector<TElem> &vec)
{
  if (vec.size() + size > cap)
    throw std::invalid_argument("Dimensiunea cozii depasita!!");

  for (TElem elem : vec)
    add(elem);

  size += vec.size();
}

bool Queue::deleteElem(const TElem &elem)
{
  TElem nodC = head;
  TElem prevNode = -2;

  while (nodC != -1 && elems[nodC] != elem)
  {
    prevNode = nodC;
    nodC = next[nodC];
  }

  if (nodC != -1)
  { //am gasit elementul cautat
    if (nodC == head)
      head = next[head];
    else
      next[prevNode] = next[nodC];

    //adaugam pozitia nodului sters la lista de pozitii goale
    next[nodC] = firstEmpty;
    firstEmpty = nodC;

    //nu stiu sigur daca e ok
    //elem.reset();
    size--;
    return true;
  }

  else
    throw std::invalid_argument("Elementul pe care doresti sa il stergi nu exista");
}

TElem Queue::push()
{
  TElem elem = -1;
  TElem index = head;

  while (next[index] != -1)
    index = next[index];

  elem = elems[index];
  deleteElem(elem);

  return elem;
}

void Queue::show()
{
  if (head == -1)
    cout << "Coada goala";

  int index = this->head;

  while (index != -1)
  {
    auto elem = this->elems[index];
    cout << elem << " ";
    index = this->next[index];
  }
  cout << endl;
}

void Queue::showNext()
{
  for (int i = 0; i < cap; i++)
    cout << next[i] << " ";

  cout << "head: " << head << endl;
}
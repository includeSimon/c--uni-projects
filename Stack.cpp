#include "Stack.h"
#include <stdexcept>

Stack::Stack(const int &_cap)
{
  this->cap = _cap;
  this->nodes = make_unique<Node[]>(_cap);
  this->head = -1;
  nodes[cap - 1].next = -1; //trebuie sa specificam sfarsitul stivei
  //creem lista de noduri libere
  for (int i = 0; i < cap - 1; i++)
  {
    nodes[i].next = i + 1;
    nodes[i].prev = i - 1;
  }

  this->firstEmpty = 0;
}

//elementele se adauga in fata
bool Stack::add(const TElem &elem)
{
  if (this->firstEmpty == -1)
    throw std::invalid_argument("Nu mai exista spatiu pentru adaugare");
  //return false;

  int newPosition = this->firstEmpty;
  this->nodes[newPosition].info = elem;
  firstEmpty = nodes[firstEmpty].next;

  nodes[head].next = newPosition; //il legam pe cel din spate cu noul nod adaugat
  nodes[newPosition].prev = head; //legam nodul nou adaugat cu cel din spate
  head = newPosition;             //modificam head-ul

  size++;
  return true;
}

vector<TElem> Stack::empty()
{
  if (size == 0)
    throw invalid_argument("Stiva deja este goala!!");
  
  vector<TElem> elems;
  int index = head, i = 0;

  while (index != -1)
  {
    TElem elem = nodes[index].info;
    elems.push_back(elem);
    index = nodes[index].prev;
  }

  //eliberam stack-ul
  this->head = -1;
  nodes[cap - 1].next = -1;
  for (int i = 0; i < cap - 1; i++)
  {
    nodes[i].next = i + 1;
    nodes[i].prev = i - 1;
  }

  this->firstEmpty = 0;

  size = 0;
  return elems;
}

void Stack::show()
{
  if (head == -1)
    return;
  int index = head;

  while (index != -1)
  {
    TElem elem = nodes[index].info;
    cout << elem << " ";
    index = nodes[index].prev;
  }
  cout << endl;
}

void Stack::showInfo()
{
  if (head == -1)
    return;

  for (int i = 0; i < cap; i++)
    cout << nodes[i].info << " ";

  cout << endl;
}

void Stack::showNext()
{
  if (head == -1)
    return;

  for (int i = 0; i < cap; i++)
    cout << nodes[i].next << " ";

  cout << endl;
}

void Stack::showPrev()
{
  for (int i = 0; i < cap; i++)
    cout << nodes[i].prev << " ";

  cout << endl;
}
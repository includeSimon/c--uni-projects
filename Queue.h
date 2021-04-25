#pragma once
#include "Stack.h"
#include <memory>
#include <iostream>
using namespace std;

typedef int TElem;

class Queue
{
public:
  Queue(const int &);
  ~Queue(){}; //nu avem nevoie de destructor deoarece folosim smart pointers

  bool add(const TElem &elem);
  void addFromStack(const vector<TElem> &);
  bool deleteElem(const TElem &elem);

  //simuleaza punerea unei carti pe stack
  TElem push();

  //metodele de afisare
  void show();
  void showNext();

private:
  unique_ptr<TElem[]> elems;
  unique_ptr<TElem[]> next;
  int cap;
  int head;
  int firstEmpty;
  int size;
};
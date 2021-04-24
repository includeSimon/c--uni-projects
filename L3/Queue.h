#pragma once
#include <memory>
#include <iostream>
using namespace std;


typedef int TElem;

class Queue
{
public:
  Queue(const int &);
  ~Queue(){}; //nu avem nevoie de destructor deoarece folosim smart pointers
  bool addFirst(const TElem &elem);
  void smartShow();
  void showAll();

private:
  unique_ptr<TElem[]> elems;
  unique_ptr<TElem[]> next;
  int cap;
  int head;
  int firstEmpty;
};
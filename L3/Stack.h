#pragma once
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

typedef int TElem;

struct Node
{
  TElem info;
  int next;
  int prev;
};

class Stack
{
public:
  Stack(const int &);
  bool add(const TElem &elem);
  vector<TElem> empty();  //returneaza un vector de elemente si sterge elementele
  void show();

  //debugging
  void showInfo();
  void showNext();
  void showPrev();

private:
  unique_ptr<Node[]> nodes;
  int cap;
  int head;
  int tail;
  int firstEmpty;
  int size;
};
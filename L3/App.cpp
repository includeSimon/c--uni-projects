//#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
  Queue queue(5);

  for (int i = 0; i < 5; i++)
    queue.addFirst(i);

  cout << "Show all: \n";
  queue.showAll();

  cout << "Show smart: \n";
  queue.smartShow();
  
}
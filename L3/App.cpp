#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
  Queue q1(6), q2(5);
  Stack stack(5);

  for (int i = 0; i < 4; i++)
    stack.add(i);

  q1.add(9);
  cout << "Before: \n";
  q1.show();

  vector<TElem> vec = stack.empty();

  q1.addFromStack(vec);

  cout << "After: \n";
  cout << q1.push() << " " << q1.push() << endl;

  cout << "What remained of our queue:\n";
  q1.show();

  return 0;
}

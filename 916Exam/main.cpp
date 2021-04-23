#include <iostream>
#include "presentation/Console.h"
#include "tests/Tests.h"
#include <string>
using namespace std;

class Person
{
public:
  Person(const string &_name) : name{_name} {};
  string get_name() { return "Person" + name; };
  

private:
  string name;
};

class Student : public Person
{
public:
  Student(const string &_name, const int &_age) : Person(_name) { this->age = _age; };
   string get_name() { return "Student" + name + to_string(age); };

private:
  string name;
  int age;
};

main()
{
  Student student("Simon", 19);
  Person person = Person("Filip");

  cout << person.get_name() << endl;

  person = student;
  cout << person.get_name() << endl;

  // Tests t;
  // t.run_all_tests();
  // Repo<Gene> repo;
  // GeneService srv{repo};
  // srv.add_gene("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG");
  // srv.add_gene("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG");
  // srv.add_gene("E_Coli_ETEC", "yqgE", "GTGACAGCGCCCTTCTTTCCACG");
  // srv.add_gene("E_Coli__K12", "yqgE", "ATCATCATCATG");
  // srv.add_gene("E_Coli_K1", "yqgE", "ACATCATT");
  // srv.add_gene("E_Coli_K", "yqgE", "ACATCATT");
  // Console c{srv};
  // c.run();
  // return 0;
}

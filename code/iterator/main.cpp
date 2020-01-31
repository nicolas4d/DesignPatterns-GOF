#include <iostream>
#include "../FoundationClasses/List.cpp"
#include "Iterator.cpp"
#include "ListIterator.cpp"
#include "ReverseListIterator.cpp"
#include "Employee.cpp"
#include "../FoundationClasses/AbstractList.cpp"
#include "IteratorPtr.cpp"
#include "ListTraverser.cpp"
#include "PrintNEmployees.cpp"
#include "FilteringListTraverser.cpp"
#include "PrintFilteringEmployees.cpp"

using namespace std;

void PrintEmployees (Iterator<Employee*>& i) {
  for (i.First(); !i.IsDone(); i.Next()){
    i.CurrentItem()->Print();
  }
}

int main(int argc, char *argv[])
{
  cout << "main"<< "\n" << "\n";

  // List<int> list();

  List<Employee*>* employees = new List<Employee*>();
  Employee* e = new Employee(1);
  Employee* e0 = new Employee(2);

  employees->Append(e);
  employees->Append(e0);

  ListIterator<Employee*> forward(employees);
  PrintEmployees(forward);

  cout <<  "\n";

  ReverseListIterator<Employee*> backward(employees);
  PrintEmployees(backward);

  cout <<  "\n";

  AbstractList<Employee*>* ale = new List<Employee*>();
  ale->Append(e);
  ale->Append(e0);
  Iterator<Employee*>* aleIter = ale->CreateIterator();
  PrintEmployees(*aleIter);
  delete aleIter;

  cout << "\n";

  AbstractList<Employee*>* ale0 = new List<Employee*>();
  ale0->Append(e);
  ale0->Append(e0);
  IteratorPtr<Employee*> ale0Iterator(ale0->CreateIterator());
  PrintEmployees(*ale0Iterator);

  cout <<  "\n";

  List<Employee*>* iiList = new List<Employee*>();
  Employee* e3 = new Employee(3);
  Employee* e4 = new Employee(4);
  iiList->Append(e3);
  iiList->Append(e4);
  PrintNEmployees pa(iiList, 10);
  pa.Traverse();

  cout << "\n";

  List<Employee*>* iifList = new List<Employee*>();
  Employee* e5 = new Employee(5);
  Employee* e6 = new Employee(6);
  iifList->Append(e3);
  iifList->Append(e4);
  iifList->Append(e5);
  iifList->Append(e6);
  PrintFilteringEmployees pfe(iifList, 10);
  pfe.Traverse();

  cout << "\n" << "main end" << "\n";

  return 0;
}

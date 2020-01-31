#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
public:
  Employee(int);
  void Print();
  int GetNo();

private:
  int _no;
};

Employee::Employee(int no)
{
  _no = no;
}

void Employee::Print()
{
  std::cout << _no << "\n";
}

int Employee::GetNo()
{
  return _no;
}
#endif /* EMPLOYEE_H */

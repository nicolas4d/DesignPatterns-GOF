#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
public:
  MyClass();
  virtual void Action();
  //virtual ~MyClass();
};

MyClass::MyClass()
{
  std::cout << "MyClass::MyClass()" << "\n";
}

void MyClass::Action()
{
  std::cout << "void MyClass::Action()" << "\n";
}

#endif /* MYCLASS_H */

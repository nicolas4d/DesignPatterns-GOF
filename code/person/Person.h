#ifndef PERSON_H
#define PERSON_H
class Person
{
 public:
  int age;
  char* name;
  char* sex;
 public:
  Person();    //构造函数
  void say();
};
#endif

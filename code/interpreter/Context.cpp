#ifndef CONTEXT_H
#define CONTEXT_H

#include <map>

class VariableExp;

class Context {
public:
  bool Lookup(const char*) const;
  void Assign(VariableExp*, bool);
};

bool Context::Lookup(const char* name) const
{
  std::cout << "bool Context::Lookup(const char* name) const" << "\n";

  return true;
}

void Context::Assign(VariableExp* ve, bool b)
{
  std::cout << "void Context::Assign(VariableExp* ve, bool b)" << "\n";
}

#endif /* CONTEXT_H */

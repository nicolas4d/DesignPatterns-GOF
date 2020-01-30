#ifndef VARIABLEEXP_H
#define VARIABLEEXP_H

#include "string.h"

class VariableExp : public BooleanExp {
public:
  VariableExp(const char*);
  //virtual ~VariableExp();
  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;
private:
  char* _name;
};

VariableExp::VariableExp (const char* name)
{
  std::cout << "VariableExp::VariableExp (const char* name)" << "\n";

  _name = strdup(name);
}

bool VariableExp::Evaluate (Context& aContext)
{
  std::cout << "bool VariableExp::Evaluate (Context& aContext)" << "\n";

  return aContext.Lookup(_name);
}

BooleanExp* VariableExp::Copy () const
{
  std::cout << "BooleanExp* VariableExp::Copy () const" << "\n";

  return new VariableExp(_name);
}

BooleanExp* VariableExp::Replace ( const char* name, BooleanExp& exp )
{
  std::cout <<
    "BooleanExp* VariableExp::Replace ( const char* name, BooleanExp& exp )" <<
    "\n";

  if (strcmp(name, _name) == 0) {
    return exp.Copy();
  } else {
    return new VariableExp(_name);
  }
}

#endif /* VARIABLEEXP_H */

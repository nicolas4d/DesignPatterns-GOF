#ifndef CONSTANT_H
#define CONSTANT_H

class Constant : public BooleanExp {
public:
  Constant(bool);
  //virtual ~Constant();
  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;
private:
  bool _boolValue;
};

Constant::Constant (bool boolValue)
{
  std::cout << "Constant::Constant (BooleanExp* op1, BooleanExp* op2)" << "\n";

  _boolValue = boolValue;
}

bool Constant::Evaluate (Context& aContext)
{
  std::cout << "bool Constant::Evaluate (Context& aContext)" << "\n";

  return _boolValue;
}

BooleanExp* Constant::Copy () const
{
  std::cout << "BooleanExp* Constant::Copy () const" << "\n";

  return new Constant(_boolValue);
}

BooleanExp* Constant::Replace (const char* name, BooleanExp& exp)
{
  std::cout
    << "BooleanExp* Constant::Replace (const char* name, BooleanExp& exp)"
    << "\n";

  return new Constant(_boolValue);
}

#endif /* CONSTANT_H */

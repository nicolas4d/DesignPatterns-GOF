#ifndef OREXP_H
#define OREXP_H

class OrExp : public BooleanExp {
public:
  OrExp(BooleanExp*, BooleanExp*);
  //virtual ~OrExp();
  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;
private:
  BooleanExp* _operand1;
  BooleanExp* _operand2;
};

OrExp::OrExp (BooleanExp* op1, BooleanExp* op2)
{
  std::cout << "OrExp::OrExp (BooleanExp* op1, BooleanExp* op2)" << "\n";

  _operand1 = op1;
  _operand2 = op2;
}

bool OrExp::Evaluate (Context& aContext)
{
  std::cout << "bool OrExp::Evaluate (Context& aContext)" << "\n";

  return _operand1->Evaluate(aContext) || _operand2->Evaluate(aContext);
}

BooleanExp* OrExp::Copy () const
{
  std::cout << "BooleanExp* OrExp::Copy () const" << "\n";

  return new OrExp(_operand1->Copy(), _operand2->Copy());
}

BooleanExp* OrExp::Replace (const char* name, BooleanExp& exp)
{
  std::cout
    << "BooleanExp* OrExp::Replace (const char* name, BooleanExp& exp)"
    << "\n";

  return new OrExp(
                    _operand1->Replace(name, exp),
                    _operand2->Replace(name, exp)
                    );
}

#endif /* OREXP_H */

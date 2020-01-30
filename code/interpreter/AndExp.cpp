#ifndef ANDEXP_H
#define ANDEXP_H

class AndExp : public BooleanExp {
public:
  AndExp(BooleanExp*, BooleanExp*);
  //virtual ~AndExp();
  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;
private:
  BooleanExp* _operand1;
  BooleanExp* _operand2;
};

AndExp::AndExp (BooleanExp* op1, BooleanExp* op2)
{
  std::cout << "AndExp::AndExp (BooleanExp* op1, BooleanExp* op2)" << "\n";

  _operand1 = op1;
  _operand2 = op2;
}

bool AndExp::Evaluate (Context& aContext)
{
  std::cout << "bool AndExp::Evaluate (Context& aContext)" << "\n";

  return _operand1->Evaluate(aContext) && _operand2->Evaluate(aContext);
}

BooleanExp* AndExp::Copy () const
{
  std::cout << "BooleanExp* AndExp::Copy () const" << "\n";

  return new AndExp(_operand1->Copy(), _operand2->Copy());
}

BooleanExp* AndExp::Replace (const char* name, BooleanExp& exp)
{
  std::cout
    << "BooleanExp* AndExp::Replace (const char* name, BooleanExp& exp)"
    << "\n";

  return new AndExp(
                    _operand1->Replace(name, exp),
                    _operand2->Replace(name, exp)
                    );
}

#endif /* ANDEXP_H */

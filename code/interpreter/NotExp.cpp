#ifndef NOTEXP_H
#define NOTEXP_H

class NotExp : public BooleanExp {
public:
  NotExp(BooleanExp*);
  //virtual ~NotExp();
  virtual bool Evaluate(Context&);
  virtual BooleanExp* Replace(const char*, BooleanExp&);
  virtual BooleanExp* Copy() const;
private:
  BooleanExp* _operand1;
};

NotExp::NotExp (BooleanExp* op1)
{
  std::cout << "NotExp::NotExp" << "\n";

  _operand1 = op1;
}

bool NotExp::Evaluate (Context& aContext)
{
  std::cout << "bool NotExp::Evaluate (Context& aContext)" << "\n";

  return not _operand1->Evaluate(aContext);
}

BooleanExp* NotExp::Copy () const
{
  std::cout << "BooleanExp* NotExp::Copy () const" << "\n";

  return new NotExp(_operand1->Copy());
}

BooleanExp* NotExp::Replace (const char* name, BooleanExp& exp)
{
  std::cout
    << "BooleanExp* NotExp::Replace (const char* name, BooleanExp& exp)"
    << "\n";

  return new NotExp(
                    _operand1->Replace(name, exp)
                    );
}

#endif /* NOTEXP_H */

#ifndef BOOLEANEXP_H
#define BOOLEANEXP_H

class Context;

class BooleanExp {
public:
  BooleanExp();
  //virtual ~BooleanExp();
  virtual bool Evaluate(Context&) = 0;
  virtual BooleanExp* Replace(const char*, BooleanExp&) = 0;
  virtual BooleanExp* Copy() const = 0;
};

BooleanExp::BooleanExp()
{
  std::cout << "BooleanExp::BooleanExp()" << "\n";
}

#endif /* BOOLEANEXP_H */

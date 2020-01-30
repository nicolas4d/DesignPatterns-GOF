#include <iostream>
#include "BooleanExp.cpp"
#include "Context.cpp"
#include "VariableExp.cpp"
#include "AndExp.cpp"
#include "OrExp.cpp"
#include "Constant.cpp"
#include "NotExp.cpp"
#include "Constant.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "mian \n" << "\n";

  // (true and x) or (y and (not x))
  BooleanExp* expression;
  Context context;
  VariableExp* x = new VariableExp("X");
  VariableExp* y = new VariableExp("Y");
  expression = new OrExp(
                         new AndExp(new Constant(true), x),
                         new AndExp(y, new NotExp(x))
                         );
  context.Assign(x, false);
  context.Assign(y, true);
  bool result = expression->Evaluate(context);

  cout << "\n";

  VariableExp* z = new VariableExp("Z");
  NotExp not_z(z);
  BooleanExp* replacement = expression->Replace("Y", not_z);
  context.Assign(z, true);
  result = replacement->Evaluate(context);

  cout << "\n main end" << "\n";

  return 0;
}

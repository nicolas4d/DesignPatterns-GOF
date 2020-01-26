#include <iostream>
#include "Token.cpp"
#include "Scanner.cpp"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "main"<< "\n" << "\n";

  new Token();
  new Scanner();


  cout << "\n" << "main end"<< "\n" << "\n";

  return 0;
}

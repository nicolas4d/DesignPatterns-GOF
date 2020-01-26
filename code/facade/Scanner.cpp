#ifndef SCANNER_H
#define SCANNER_H

#include "Token.cpp"

#include <iostream>

using namespace std;

class Scanner {
public:
  Scanner(istream&);
  Scanner();

  virtual Token& Scan();

private:
  istream& _inputStream(stringstream&(stringstream()));
};

Scanner::Scanner()
{
  cout << "Scanner::Scanner()" << "\n";
}

Scanner::Scanner(istream& i)
{
  std::cout << "Scanner::Scanner(istream& istream)" << "\n";
}

Token& Scanner::Scan()
{
  std::cout << "Token& Scanner::Scan()" << "\n";
}

#endif /* SCANNER_H */

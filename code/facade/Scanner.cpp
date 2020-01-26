#ifndef SCANNER_H
#define SCANNER_H

#include "Token.cpp"

using namespace std;

class Scanner {
public:
  Scanner(istream&);

  virtual Token& Scan();

private:
  istream& _inputStream;
};

Scanner::Scanner(istream& istream)
{
  std::cout << "Scanner::Scanner(istream& istream)" << "\n";

  _inputStream = istream;
}

Token& Scanner::Scan()
{
  std::cout << "Token& Scanner::Scan()" << "\n";
}
#endif /* SCANNER_H */

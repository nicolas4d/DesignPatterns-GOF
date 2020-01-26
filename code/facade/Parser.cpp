#ifndef PARSER_H
#define PARSER_H

class Parser {
public:
  Parser();
  virtual ~Parser();

  virtual void Parse(Scanner&, ProgramNodeBuilder&);
};

#endif /* PARSER_H */

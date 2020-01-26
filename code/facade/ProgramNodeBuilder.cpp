#ifndef PROGRAMNODEBUILDER_H
#define PROGRAMNODEBUILDER_H

class ProgramNodeBuilder {
public:
  ProgramNodeBuilder();

  virtual ProgramNode* NewVariable(
                                   const char* variableName
                                   ) const;
  virtual ProgramNode* NewAssignment(
                                     ProgramNode* variable, ProgramNode* expression
                                     ) const;
  virtual ProgramNode* NewReturnStatement(
                                          ProgramNode* value
                                          ) const;
  virtual ProgramNode* NewCondition(
                                    ProgramNode* condition,
                                    ProgramNode* truePart, ProgramNode* falsePart
                                    ) const;

  // ...
  ProgramNode* GetRootNode();
  
private:
  ProgramNode* _node;
};

#endif /* PROGRAMNODEBUILDER_H */

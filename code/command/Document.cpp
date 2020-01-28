#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document
{
public:
  Document(const char*);
  virtual void Open();
  virtual void Paste();
};

Document::Document(const char*)
{
  std::cout << "Document::Document(const char*)" << "\n";
}

void Document::Open()
{
  std::cout << "void Document::Open()" << "\n";
}

void Document::Paste()
{
  std::cout << "void Document::Paste()" << "\n";
}

#endif /* DOCUMENT_H */

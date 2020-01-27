#ifndef TEXTDOCUMENT_H
#define TEXTDOCUMENT_H

#include "Graphic.cpp"
#include "Point.cpp"

class TextDocument {
public:
  TextDocument();
  void Insert(Graphic*);
};

TextDocument::TextDocument()
{
  std::cout << "TextDocument::TextDocument()" << "\n";
}

void TextDocument::Insert(Graphic* g)
{
  std::cout << "void TextDocument::Insert(Graphic* g)" << "\n";

  g->Draw(Point(3, 3));
}


#endif /* TEXTDOCUMENT_H */

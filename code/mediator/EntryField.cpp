#ifndef ENTRYFIELD_H
#define ENTRYFIELD_H

class Widget;
class DialogDirector;
class MouseEvent;

class EntryField : public Widget {
public:
  EntryField(DialogDirector*);
  virtual void SetText(const char* text);
  virtual const char* GetText();
  virtual void HandleMouse(MouseEvent& event);
  // ...
};

EntryField::EntryField(DialogDirector* dd):Widget(dd)
{
  std::cout << "EntryField::EntryField(DialogDirector*)" << "\n";
}

void EntryField::SetText(const char* text)
{
  std::cout << "void EntryField::SetText(const char* text)" << "\n";
}

const char* EntryField::GetText()
{
  std::cout << "const char* EntryField::GetText()" << "\n";
}

void EntryField::HandleMouse(MouseEvent& event)
{
  std::cout << "void EntryField::HandleMouse(MouseEvent& event)" << "\n";
}


#endif /* ENTRYFIELD_H */

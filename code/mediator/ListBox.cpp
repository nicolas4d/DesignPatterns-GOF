#ifndef LISTBOX_H
#define LISTBOX_H

class Widget;
class DialogDirector;
class MouseEvent;
template <class Item> class List;

class ListBox : public Widget {
public:
  ListBox(DialogDirector*);
  virtual const char* GetSelection();
  virtual void SetList(List<char*>* listItems);
  virtual void HandleMouse(MouseEvent& event);
  // ...
};

ListBox::ListBox(DialogDirector* dd):Widget(dd)
{
  std::cout << "ListBox::ListBox(DialogDirector*)" << "\n";
}

const char* ListBox::GetSelection()
{
  std::cout << "const char* ListBox::GetSelection()" << "\n";
}

void ListBox::SetList(List<char*>* listItems)
{
  std::cout << "void ListBox::SetList(List<char*>* listItems)" << "\n";
}

void ListBox::HandleMouse(MouseEvent& event)
{
  std::cout << "void ListBox::HandleMouse(MouseEvent& event)" << "\n";
}

#endif /* LISTBOX_H */

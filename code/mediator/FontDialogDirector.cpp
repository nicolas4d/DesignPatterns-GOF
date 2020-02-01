#ifndef FONTDIALOGDIRECTOR_H
#define FONTDIALOGDIRECTOR_H

class DialogDirector;
class Widget;
class Button;
class ListBox;
class EntryField;

class FontDialogDirector : public DialogDirector {
public:
  FontDialogDirector();
  //virtual ~FontDialogDirector();
  virtual void WidgetChanged(Widget*);
protected:
  virtual void CreateWidgets();
  //private: for convince alter to public.
public:
  Button* _ok;
  Button* _cancel;
  ListBox* _fontList;
  EntryField* _fontName;
};

FontDialogDirector::FontDialogDirector()
{
  std::cout << "FontDialogDirector::FontDialogDirector()" << "\n";

  CreateWidgets();
}

void FontDialogDirector::CreateWidgets ()
{
  std::cout << "void FontDialogDirector::CreateWidgets ()" << "\n";

  _ok = new Button(this);
  _cancel = new Button(this);
  _fontList = new ListBox(this);
  _fontName = new EntryField(this);
  // fill the listBox with the available font names
  // assemble the widgets in the dialog
}

void FontDialogDirector::WidgetChanged ( Widget* theChangedWidget )
{
  std::cout
    << "void FontDialogDirector::WidgetChanged ( Widget* theChangedWidget )"
    << "\n";

  if (theChangedWidget == _fontList) {
    _fontName->SetText(_fontList->GetSelection());
  } else if (theChangedWidget == _ok) {
    // apply font change and dismiss dialog
    // ...
    _ok->SetText("1");
  } else if (theChangedWidget == _cancel) {
    // dismiss dialog
    _ok->SetText("1");
  }
}

#endif /* FONTDIALOGDIRECTOR_H */

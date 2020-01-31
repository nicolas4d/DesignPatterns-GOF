#ifndef LISTITERATOR_H
#define LISTITERATOR_H

template <class Item>
class List;

template <class Item>
class ListIterator : public Iterator<Item> {
public:
  ListIterator( List<Item>* aList);
  virtual void First();
  virtual void Next();
  virtual bool IsDone() ;
  virtual Item CurrentItem() ;
private:
  List<Item>* _list;
  long _current;
};

template <class Item>
ListIterator<Item>::ListIterator (List<Item>* aList)
  : _list(aList), _current(0)
{
  
}

template <class Item>
void ListIterator<Item>::First ()
{
  _current = 0;
}

template <class Item>
void ListIterator<Item>::Next ()
{
  _current++;
}

template <class Item>
bool ListIterator<Item>::IsDone () 
{
  return _current >= _list->Count();
}

template <class Item>
Item ListIterator<Item>::CurrentItem ()  {
  // if (IsDone()) {
  //   throw "IteratorOutOfBounds";
  // }

  Item item = _list->Get(_current);

  return _list->Get(_current);
}

#endif /* LISTITERATOR_H */

#ifndef REVERSELISTITERATOR_H
#define REVERSELISTITERATOR_H

template <class Item>
class ReverseListIterator : public Iterator<Item> {
public:
  ReverseListIterator( List<Item>* aList);
  virtual void First();
  virtual void Next();
  virtual bool IsDone() ;
  virtual Item CurrentItem() ;
private:
  List<Item>* _list;
  long _current;
};

template <class Item>
ReverseListIterator<Item>::ReverseListIterator (List<Item>* aList)
  : _list(aList), _current(aList->Count() - 1)
{
  
}

template <class Item>
void ReverseListIterator<Item>::First ()
{
  _current = _list->Count() - 1;
}

template <class Item>
void ReverseListIterator<Item>::Next ()
{
  _current--;
}

template <class Item>
bool ReverseListIterator<Item>::IsDone () 
{
  return _current < 0;
}

template <class Item>
Item ReverseListIterator<Item>::CurrentItem ()  {
  // if (IsDone()) {
  //   throw "IteratorOutOfBounds";
  // }

  Item item = _list->Get(_current);

  return _list->Get(_current);
}

#endif /* REVERSELISTITERATOR_H */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <list>

using namespace std;

static  long DEFAULT_LIST_CAPACITY = 0;

template <class Item>
class Iterator;

template <class Item>
class AbstractList;

template <class Item>
class ListIterator;

template <class Item>
class List : public AbstractList<Item>
{
public:
  List(long size = DEFAULT_LIST_CAPACITY);
  //List(List&);
  //~List();

  Iterator<Item>* CreateIterator();

  //List& operator=(const List&);
  long Count() const;
  //Item& Get(long index) const;
  Item& Get(long index) ;
  //Item Get(long index) const;
  //Item& First() const;
  //Item& Last() const;
  //bool Includes(const Item&) const;
  void Append(const Item&);
  //void Prepend(const Item&);
  void Remove(const Item&);
  //void RemoveLast();
  //void RemoveFirst();
  //avoid RemoveAll();
  //Item& Top() const;
  //void Push(const Item&);
  //Item& Pop();
private:
  list<Item> _list;
};

template <class Item>
List<Item>::List(long size)
{
  _list.resize(size);
}

template <class Item>
Iterator<Item>* List<Item>::CreateIterator ()
{
  return new ListIterator<Item>(this);
}

// template <class Item>
// List<Item>::List(List& list)
// {
//   _list = list;
// }

// template <class Item>
// List<Item>& List<Item>::operator=( List& list)
// {
//   return list;
// }

template <class Item>
long List<Item>::Count() const 
{
  return _list.size();
}

template <class Item>
Item& List<Item>::Get(long index)
{
  typename  list<Item>::iterator iter;
  iter = _list.begin();
  advance(iter, index);

  return *iter;
}

template <class Item>
void List<Item>::Append(const Item& item)
{
  _list.push_back(item);
}

template <class Item>
void List<Item>::Remove(const Item&)
{
  
}

#endif /* LIST_H */

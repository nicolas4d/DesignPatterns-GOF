#ifndef ABSTRACTLIST_H
#define ABSTRACTLIST_H

template <class Item>
class Iterator;

template <class Item>
class AbstractList {
public:
  AbstractList();
  virtual Iterator<Item>* CreateIterator() = 0;

  //List& operator=(const List&);
  virtual long Count() const = 0;
  //Item& Get(long index) const;
  virtual Item& Get(long index) = 0 ;
  //Item Get(long index) const;
  //Item& First() const;
  //Item& Last() const;
  //bool Includes(const Item&) const;
  virtual void Append(const Item&) = 0;
  //void Prepend(const Item&);
  //void Remove(const Item&);
  //void RemoveLast();
  //void RemoveFirst();
  //avoid RemoveAll();
  //Item& Top() const;
  //void Push(const Item&);
  //Item& Pop();
};

template <class Item>
AbstractList<Item>::AbstractList()
{

}

#endif /* ABSTRACTLIST_H */

#ifndef ITERATORPTR_H
#define ITERATORPTR_H

template <class Item>
class Iterator;

template <class Item>
class IteratorPtr {
public:
  IteratorPtr(Iterator<Item>* i): _i(i) { }
  ~IteratorPtr() { delete _i; }
  Iterator<Item>* operator->() { return _i; }
  Iterator<Item>& operator*() { return *_i; }

private:
  // disallow copy and assignment to avoid
  // multiple deletions of _i:
  IteratorPtr(const IteratorPtr&);
  IteratorPtr& operator=(const IteratorPtr&);
  
private:
  Iterator<Item>* _i;
};


template <class Item>
IteratorPtr<Item>::IteratorPtr(const IteratorPtr&)
{
  
}

template <class Item>
IteratorPtr<Item>& IteratorPtr<Item>::operator=(const IteratorPtr&)
{
  
}

#endif /* ITERATORPTR_H */

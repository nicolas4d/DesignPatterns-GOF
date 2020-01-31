#ifndef PRINTFILTERINGEMPLOYEES_H
#define PRINTFILTERINGEMPLOYEES_H

template <class Item>
class FilteringListTraverser;

class PrintFilteringEmployees : public FilteringListTraverser<Employee*> {
public:
  PrintFilteringEmployees(List<Employee*>* aList, int n) :
    FilteringListTraverser<Employee*>(aList),
    _total(n), _count(0) { }

protected:
  //virtual bool ProcessItem(Item* const& ) = 0;
  bool ProcessItem(Employee* const&);
  bool TestItem(Employee* const&);

private:
  int _total;
  int _count;
};

bool PrintFilteringEmployees::ProcessItem (Employee* const& e) {
  _count++;
  e->Print();
  return _count < _total;
}

bool PrintFilteringEmployees::TestItem( Employee* const & e) 
{
  return  e->GetNo() > 4;

  //return true;
}


#endif /* PRINTFILTERINGEMPLOYEES_H */

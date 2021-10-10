#include "List.h"

int main(){
    List* a = new List();
    a->insertFirst(10);
    a->insertFirst(125);
    a->insertFirst(2323);
    a->insertFirst(12);
    a->insertFirst(5435);
    a->insertFirst(32);
    a->print();
    cout << "Find:" << a->exists(125) << endl;
    cout << "Size:" <<a->size() << endl;;
    a->removeFirst();
    a->print();
    cout <<endl;
    a->remove(15, List::DeleteFlag::LESS);
    a->print();
}
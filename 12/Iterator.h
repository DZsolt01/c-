//
// Created by Adek on 2021. 12. 16..
//

#ifndef INC_12_ITERATOR_H
#define INC_12_ITERATOR_H
#include "OrderedList.h"


template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class Iterator{
    OrderedList<T, LessComp, Equal> &list;
    typename OrderedList<T, LessComp, Equal>::Node* act;

public:
    Iterator(OrderedList<T, LessComp, Equal>& );

    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &list):list(list) {
    act = list.first;
}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    return act != nullptr;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    T item = act->value;
    act = act->next;
    return item;
}


#endif //INC_12_ITERATOR_H

//
// Created by Adek on 2021. 12. 16..
//

#ifndef INC_12_ORDEREDLIST_H
#define INC_12_ORDEREDLIST_H
#include <iostream>
#include <string>
using namespace std;

template <class T, class LessComp, class Equal >
class Iterator;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
    friend class Iterator<T, LessComp, Equal>;
    struct Node{
        T value;
        Node* next;
        Node(const T& v, Node *n) : value(v), next(n){
        }
    };
    Node* first;
    int numElements = 0;
public:
    OrderedList();
    ~OrderedList();
    bool isEmpty();
    void insert(const T& item);
    void remove(const T& item);
    int size() const;
    bool find(T& item) const;
    void listItems(ostream&);

};
template <class T, class LessComp, class Equal >
OrderedList<T,LessComp,Equal>::OrderedList(){
    first = nullptr;
}
template <class T, class LessComp, class Equal >
OrderedList<T,LessComp,Equal>::~OrderedList(){
    while(first != nullptr){
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}
template <class T, class LessComp, class Equal >
bool OrderedList<T,LessComp,Equal>::isEmpty(){
    if(first == nullptr){
        return true;
    }
    return false;
}

template <class T, class LessComp, class Equal >
void OrderedList<T,LessComp,Equal>::insert(const T& item){
    LessComp comparator;

    Node* prev = nullptr;
    for(Node* p = first; p != nullptr; p = p->next){
        if(!comparator(p->value, item)){
            break;
        }
        prev = p;
    }
    if(prev == nullptr){
        first = new Node(item, first);
    }
    else{
        prev->next = new Node(item, prev->next);
    }
    numElements++;
    /*
    if(first == nullptr){
        first = new Node(item, first);
        return;
    }

    Node* before = first;
    Node* mFirst = first;



    while(mFirst != nullptr){
        if(comparator(mFirst->value,item)){
            Node* insertNode = new Node(item, mFirst);
            before->next = insertNode;
            return;
        }
        before = mFirst;
        mFirst = mFirst->next;
    }
    if(mFirst == nullptr){
        Node* insertNode = new Node(item, mFirst);
        before->next = insertNode;
    }
     */
}

template <class T, class LessComp, class Equal >
void OrderedList<T,LessComp,Equal>::remove(const T& item){
    Equal equal;
    LessComp comparator;

    Node* prev = nullptr;
    for(Node* p = first; p != nullptr; p = p->next){
        if (comparator(p->value, item)){
            return;
        }
        if(equal(p->value, item)){
            if(prev == nullptr){
                first = first->next;
            }
            else{
                prev->next = p->next;
            }
            delete(p);
            continue;
        }

        prev = p;
    }
}
template <class T, class LessComp, class Equal >
int OrderedList<T,LessComp,Equal>::size() const{
    return numElements;
}
template <class T, class LessComp, class Equal >
bool OrderedList<T,LessComp,Equal>::find(T& item) const{
    Equal equal;
    Node* mFirst = first;
    while(mFirst != nullptr){
        if(equal(mFirst->value, item)){
            return true;
        }
    }
    return false;
}
template <class T, class LessComp, class Equal >
void OrderedList<T,LessComp,Equal>::listItems(ostream& os){
    Node* mFirst = first;
    while (mFirst != nullptr){
        os << mFirst->value << " ";
        mFirst = mFirst->next;
    }
}


#endif //INC_12_ORDEREDLIST_H

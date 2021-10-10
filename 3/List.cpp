#include "List.h"
#include <iostream>

using namespace std;

List::List(){
    cout << "INI" <<endl;
    this->first = nullptr;
};

List::~List(){
    cout << "DES" << endl;
    for(Node *p=first; p!= nullptr;){
        Node *n = p->next;
        delete p;
        p = n;
    }
    first = nullptr;
};

void List::insertFirst(int d){
    first = new Node(d, first);
    nodeCounter++;
};

bool List::empty() const{
    if(this->first == nullptr){
        return true;
    }
    return false;
}

bool List::exists(int d) const{
    for(Node *p = first; p!= nullptr;){
        if(p->value == d){
            return true;
        }
        p = p->next;
    }
    return false;
}

int List::size() const{
    return this->nodeCounter;
}
void List::remove(int d, DeleteFlag df){
    if(empty() ){
        throw runtime_error("Hiba tortent");
    }
    for(Node* p = first, *prev = first; p!= nullptr;){
        if(p == first && ((df == DeleteFlag::EQUAL && d == p->value) || (df == DeleteFlag::LESS && d < p->value) || (df == DeleteFlag::GREATER && d > p->value)) ){
            Node* del = first;
            first = del->next;
            p = first;
            prev = p;
            delete del;
            nodeCounter--;
        }

        else if(df == DeleteFlag::EQUAL && p->value == d){
            prev->next = p->next;
            delete p;
            p = prev->next;
            nodeCounter--;
        }
        else if(df == DeleteFlag::LESS && p->value > d){
            prev->next = p->next;
            delete p;
            p = prev->next;
            nodeCounter--;
        }
        else if(df == DeleteFlag::GREATER && p->value < d){
            prev->next = p->next;
            delete p;
            p = prev->next;
            nodeCounter--;
        }
        else{
            prev = p;
            p = p->next;
        }
    }
}

int List::removeFirst(){
    if(empty()){
        throw runtime_error("Hiba tortent#1");
    }
    int x = first->value;
    Node* p = first;
    first = first->next;
    delete p;
    nodeCounter--;
    return x;
}

void List::print() const{
    for(Node *p = first; p!= nullptr; p = p->next){
        cout << p->value << endl;
    }
}


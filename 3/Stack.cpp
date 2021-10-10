#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
    cout << "INI" <<endl;
    this->first = nullptr;
};

Stack::~Stack(){
    cout << "DES" << endl;
    for(Node *p=first; p!= nullptr;){
        Node *n = p->next;
        delete p;
        p = n;
    }
    first = nullptr;
};

bool Stack::empty() const{
    if(this->first == nullptr){
        return true;
    }
    return false;
}

void Stack::push(int e){
    first = new Node(e, first);
    nodeCounter++;
}

int Stack::pop(){
    if(empty()){
        runtime_error("Sikertelen!");
    }


    int v = first->value;
    Node* d = first;
    Node* n = first->next;
    this->first = n;
    delete d;
    nodeCounter--;
    return v;
}
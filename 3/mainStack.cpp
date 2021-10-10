#include "Stack.h"

int main(){
    cout << endl << "STACK" <<endl;
    Stack* b = new Stack();
    b->push(14);
    b->push(12);
    b->push(15);
    cout << b->pop() <<endl;
    b->~Stack();
}
#ifndef STACK_H

using namespace std;
#include <iostream>
#define STACK_H
class Stack
{
public:
    /* creates an empty stack */
    Stack();
    /* destroys this stack */
    ~Stack();
    /* insert element to stack*/
    void push(int e);
    /* check if empty*/
    bool empty() const;
    /* return top element */
    int pop();

    /* removes the first element less than/equal to/greater than d,
depending on the value of df. Does nothing if there is no value
to remove. The enum values are accessed with stack::DeleteFlag::LESS,
..., outside the class */
    enum class DeleteFlag
    {
        LESS,
        EQUAL,
        GREATER
    };
    void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);
    /* prints the contents of this stack */
    void print() const;
    /* forbid copying of stacks */
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

private:
    /* number of nodes in the stack */
    int nodeCounter{0};
    /* a stack node */
    struct Node
    {
        int value;  // the node value
        Node *next; // pointer to the next node, nullptr in the last node
        Node(int v, Node *n) : value(v), next(n)
        {
        }
    };
    Node *first; // pointer to the first node
};
#endif /* STACK_H */

#ifndef UNTITLED7_EMPTYDOUBLYLINKEDLIST_H
#define UNTITLED7_EMPTYDOUBLYLINKEDLIST_H
#include <exception>
using namespace std;
class EmptyDoublyLinkedList:public exception {
    //error message displays if doubly linked list is empty
public:
    const char * what () const noexcept override
    {
        return "EmptyDoublyLinkedListException";
    }
};


#endif //UNTITLED7_EMPTYDOUBLYLINKEDLIST_H

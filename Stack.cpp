#include "Stack.h"
#include <iostream>
#include "EmptyStackException.h"
using namespace std;
template<typename T>
Stack<T>::Stack() {
    _head= nullptr;
    _size=0;
}
template<typename T>
Stack<T>::~Stack() {
    // Deallocate the memory in the heap when the stack leaves the scope
    while (!isEmpty()) {
        pop();
    }
}
template<typename T>
bool Stack<T>::isEmpty() const {
    if(_head==nullptr){
        return true;
    }
    return false;
}

template<typename T>
void Stack<T>::push(const T &newItem) {
    auto* newNode=new ListNode();
    newNode->item=newItem;
    newNode->next=_head;
    _head=newNode;
    _size++;
}

template<typename T>
void Stack<T>::pop() {
    if(!isEmpty()){
        ListNode* temp=_head;
        _head=_head->next;
        temp=nullptr;
        _size--;}
    else{
        throw EmptyStackException();
    }
}

template<typename T>
int Stack<T>::size() const {
    return _size;
}

template<typename T>
void Stack<T>::getTop(T &stackTop) const {
    if (isEmpty())
        throw EmptyStackException();
    else
        stackTop =_head;
}
template<typename T>
T Stack<T>::getTop() const {
    return _head->item;
}

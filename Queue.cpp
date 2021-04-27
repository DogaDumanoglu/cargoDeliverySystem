#include "Queue.h"
#include "EmptyQueueException.h"
using namespace std;
template<typename T>
Queue<T>::Queue() {
_head=_lastNode= nullptr;
_size=0;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return _size==0;
}

template<typename T>
int Queue<T>::size() const {
    return _size;
}

template<typename T>
void Queue<T>::enqueue(const T &newItem) {
    auto *newNode=new QueueNode;
    newNode->item=newItem;
    newNode->next=nullptr;
    if(isEmpty()){
        _head=_lastNode=newNode;
    }
    else{
        _lastNode->next=newNode;
        _lastNode=newNode;
    }
    _size++;
}

template<typename T>
void Queue<T>::dequeue() {
    if(!isEmpty()){
        QueueNode* temp=_head;
        if(_lastNode==_head){
            _head=_lastNode= nullptr;
        }
        else{
            _head=_head->next;
        }
        temp= nullptr;
        _size--;
    }
    else{
        throw EmptyQueueException();
    }

}

template<typename T>
Queue<T>::~Queue() {
    // Deallocate the memory in the heap when the stack leaves the scope
    while(!isEmpty()) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::getFront(T &queueTop) const {
    if (isEmpty())
        throw EmptyQueueException();
    else
        queueTop =_head;
}

template<typename T>
T Queue<T>::getFront() const{
    return _head->item;
}

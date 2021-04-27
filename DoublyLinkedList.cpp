#include "DoublyLinkedList.h"
#include "EmptyDoublyLinkedList.h"
#include <iostream>
using namespace std;
template<typename T>
void DoublyLinkedList<T>::insertAtEnd(const T &newItem) {
    auto *newNode=new DoublyNode();
    newNode->prev= nullptr;
    newNode->next= nullptr;
    newNode->item=newItem;//The data of the new item has been set
    if(isEmpty()){
        _head=_tail=newNode;//if it is empty head and tail pointers points the same node
    }
    else{//if it is not empty
        _tail->next=newNode;
        newNode->prev=_tail;
        _tail=newNode;// tail pointers points the new node

    }
    _size++;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return _size==0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    _head= nullptr;
    _size=0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    // Deallocate the memory in the heap when the doubly linked list leaves the scope
    while (!isEmpty()) {
        removeFromBeginning();
    }
}

template<typename T>
T DoublyLinkedList<T>::removeFromBeginning() {
    if(!isEmpty()){
        T removed=_head->item;
        if(_head->next== nullptr){
            _head= nullptr;//directly removes head because it is only element
        }
        else{
            DoublyNode* temp=_head;
            if(_head!=_tail){
                _head=_head->next;//head pointer points to the second item because head is removed
            }
            _head->prev= nullptr;
            free(temp);//deallocates memory frees _head
        }
        _size--;
        return removed;//returns the removed item
    }
    else{//if doubly linked list is empty throws empty stack exception
        throw EmptyDoublyLinkedList();
    }

}

template<typename T>
T DoublyLinkedList<T>::removeSpecificNode(int pos) {
    if(!isEmpty()) {
        T removed;
        DoublyNode *temp = _head;
        if (_head!=0) {
            for(int i=0;i<pos+1&&temp!= nullptr;i++){//sets the temp to the  position of removed item
                temp = temp->next;}
            removed=temp->item;
            if(temp!=_tail){//connects the links of the prev and next of the removed
                temp->prev->next = temp->next;
                temp->next->prev=temp->prev;
            }
            else{//makes null the next link of removed
                temp->prev->next= nullptr;
                _tail=temp->prev;//rearrange _tail pointer
            }
            _size--;
            free(temp);
            return removed;//returns removed item

        }
        else{
            _size--;
            return removeFromBeginning();
        }


    }
    else{
        //if doubly linked list is empty throws empty stack exception
        throw EmptyDoublyLinkedList();
    }
}

template<typename T>
int DoublyLinkedList<T>::size() {
    return _size;
}


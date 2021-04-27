#ifndef UNTITLED7_DOUBLYLINKEDLIST_H
#define UNTITLED7_DOUBLYLINKEDLIST_H
template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    //insertAtEnd:this function adds an element end of the doubly linked list
    void insertAtEnd(const T &newItem);
    //removeFromBeginning:this function removes an element from beginning and returns removed node
    T removeFromBeginning();
    //removeSpecificNode:this function removes an element from a given position and returns removed node
    T removeSpecificNode(int pos);
    bool isEmpty();
    int size();
private:
    struct DoublyNode {
        T item;
        DoublyNode *prev;
        DoublyNode *next;
    };
    int _size{};
    DoublyNode* _head;
    DoublyNode* _tail;
};



#endif //UNTITLED7_DOUBLYLINKEDLIST_H

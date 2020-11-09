/****************************************************************************************************************************
Title        : DoublyLinkedList.hpp
Author       : Andrew Alagna
Description  : header file of my doublylinkedlist
****************************************************************************************************************************/


#ifndef MIXTAPE_DOUBLYLINKEDLIST_HPP
#define MIXTAPE_DOUBLYLINKEDLIST_HPP

#include "DoubleNode.hpp"

template<typename ItemType>
class DoublyLinkedList {
protected:
    DoubleNode<ItemType> *headPtr;
    int itemCount;
public:
    // Default constructor
    DoublyLinkedList();

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList<ItemType> &aList);

    // Custom destructor
    virtual ~DoublyLinkedList();

    //inserts item at position in caller list
    bool insert(const ItemType &item, const int &position);

    //removes the node at position
    bool remove(const int &position);

    // returns the number of the nodes in the calling list
    int getSize() const;

    // returns a copy of the headPtr
    DoubleNode<ItemType> *getHeadPtr() const;

    // returns a pointer to the node located at pos
    DoubleNode<ItemType> *getAtPos(const int &pos) const;

    // returns whether the calling list is empty
    bool isEmpty() const;

    // clears the list
    void clear();

    // returns the position of the given item in the list, -1 otherwise
    int getIndexOf(const ItemType &item) const;

    // prints the contents of the calling list in order
    void display() const;

    // prints the contents of the calling list in reverse order
    void displayBackwards() const;

    // returns the interleaved list of the calling and parameter lists
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list);
};

#include "DoublyLinkedList.cpp"

#endif //MIXTAPE_DOUBLYLINKEDLIST_HPP

/****************************************************************************************************************************
Title        : DoubleNode.cpp
Author       : Andrew Alagna
Description  : header file of DoubleNode for my linked list
****************************************************************************************************************************/


#ifndef MIXTAPE_DOUBLENODE_HPP
#define MIXTAPE_DOUBLENODE_HPP

template<typename ItemType>
class DoubleNode {
private:
    ItemType item_;
    DoubleNode<ItemType> *next_;
    DoubleNode<ItemType> *prev_;
public:
    // Constructor
    DoubleNode();

    // Parametrized constructor
    DoubleNode(const ItemType &an_item);

    // Parameterized constructor
    DoubleNode(const ItemType &an_item, DoubleNode<ItemType> *next_node, DoubleNode<ItemType> *prev_node);

    // Setter Functions
    void setItem(const ItemType &anItem);

    // Set the previous item in the list
    void setPrevious(DoubleNode<ItemType> *previousNodePtr);

    // Set the next item in the list
    void setNext(DoubleNode<ItemType> *nextNodePtr);

    // Getter Functions
    ItemType getItem() const;

    // Gets the next item in the list
    DoubleNode<ItemType> *getNext() const;

    // Gets the previous item in the list
    DoubleNode<ItemType> *getPrevious() const;
};

#include "DoubleNode.cpp"

#endif //MIXTAPE_DOUBLENODE_HPP

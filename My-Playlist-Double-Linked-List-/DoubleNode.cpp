/****************************************************************************************************************************
Title        : DoubleNode.cpp
Author       : Andrew Alagna
Description  : implementation file of DoubleNode for my linked list
Dependencies : DoubleNode.hpp
****************************************************************************************************************************/

#include "DoubleNode.hpp"

// Constructor
template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(): next_{nullptr}, prev_{nullptr} {}

// Parametrized constructor
template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &an_item): item_{an_item}, next_{nullptr}, prev_{nullptr} {
}

// Parameterized constructor
template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &an_item, DoubleNode<ItemType> *next_node,
                                 DoubleNode<ItemType> *prev_node) : item_{an_item}, next_{next_node}, prev_{prev_node} {
}

// Setter Functions
template<typename ItemType>
void DoubleNode<ItemType>::setItem(const ItemType &anItem) {
    item_ = anItem;
}

// Set the previous item in the list
template<typename ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr) {
    prev_ = previousNodePtr;
}

// Set the next item in the list
template<typename ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr) {
    next_ = nextNodePtr;
}

// Getter Functions
template<typename ItemType>
ItemType DoubleNode<ItemType>::getItem() const {
    return item_;
}

// Gets the next item in the list
template<typename ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getNext() const {
    return next_;
}

// Gets the previous item in the list
template<typename ItemType>
DoubleNode<ItemType> *DoubleNode<ItemType>::getPrevious() const {
    return prev_;
}








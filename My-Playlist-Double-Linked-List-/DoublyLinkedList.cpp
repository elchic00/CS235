/****************************************************************************************************************************
Title        : DoublyLinkedList.cpp
Author       : Andrew Alagna
Description  : implementation file of my doublylinkedlist
Dependencies : DoublyLinkedList.hpp
****************************************************************************************************************************/


#include <iostream>
#include "DoublyLinkedList.hpp"

//Default Constructor
template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(): headPtr{nullptr}, itemCount{0} {
}

//Copy Constructor
template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &aList) {
    itemCount = aList.itemCount;
    DoubleNode<ItemType> *firstChainPtr = aList.headPtr;
    //set head to null if the given chain is null
    if (firstChainPtr == nullptr)
        headPtr = nullptr;
    else {
        // Set first node to given head ptr
        headPtr = new DoubleNode<ItemType>();
        headPtr->setItem(firstChainPtr->getItem());

        // Copy remaining nodes and traverse
        DoubleNode<ItemType> *newChainPtr = headPtr;
        DoubleNode<ItemType> *lastChainPtr = headPtr;
        firstChainPtr = firstChainPtr->getNext();

        while (firstChainPtr != nullptr) {
            // traverse original chain
            ItemType nextItem = firstChainPtr->getItem();
            // Create new node with the next item in the list
            DoubleNode<ItemType> *newNodePtr = new DoubleNode<ItemType>(nextItem);
            // Link the new node to the end of chain
            newChainPtr->setNext(newNodePtr);
            // Traverse to the last node
            newChainPtr = newChainPtr->getNext();
            newChainPtr->setPrevious(lastChainPtr);
            lastChainPtr = lastChainPtr->getNext();
            // Advance original-chain pointer
            firstChainPtr = firstChainPtr->getNext();
        }
        //Set/mark the end of the list by making it null
        newChainPtr->setNext(nullptr);
    }
}

//Destructor
template<typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList() {
    clear();
}

//inserts item at position in caller list
template<typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position) {
    if (position < 1 || position > itemCount + 1) {
        return false;
    } else {
        DoubleNode<ItemType> *nodeToInsert = new DoubleNode<ItemType>(item);
        if (position == 1) {
            if (headPtr == nullptr) {
                headPtr = nodeToInsert;
            } else {
                nodeToInsert->setNext(headPtr);
                headPtr->setPrevious(nodeToInsert);
                headPtr = nodeToInsert;
            }
        } else {
            DoubleNode<ItemType> *currPtr = headPtr;
            for (int i = 2; i < position; i++) {
                currPtr = currPtr->getNext();
            }
            if (currPtr->getNext() != nullptr) {
                currPtr->getNext()->setPrevious(nodeToInsert);
                nodeToInsert->setNext(currPtr->getNext());
            }
            currPtr->setNext(nodeToInsert);
            nodeToInsert->setPrevious(currPtr);
        }
        itemCount++;
        return true;
    }
}

//removes the node at position
template<typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position) {
    if (position < 1 || position > itemCount) {
        return false;
    } else {
        DoubleNode<ItemType> *tempPtr;
        if (position == 1) {
            tempPtr = headPtr;
            headPtr = headPtr->getNext();
            if (headPtr != nullptr) {
                headPtr->setPrevious(nullptr);
            }
            delete tempPtr;
        } else {
            DoubleNode<ItemType> *curPtr = headPtr;
            tempPtr = getAtPos(position);

            for (int i = 1; i < position - 1; i++) {
                curPtr = curPtr->getNext();
            }
            if (curPtr->getNext() != nullptr) {
                curPtr->getNext()->setPrevious(curPtr->getPrevious());
                curPtr->setNext(curPtr->getNext()->getNext());
            } else {
                curPtr->setNext(nullptr);
            }
            delete tempPtr;
        }
    }
    itemCount--;
    return true;
}

// returns the number of the nodes in the calling list
template<typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const {
    return itemCount;
}

// returns a copy of the headPtr
template<typename ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const {
    return headPtr;
}

// returns a pointer to the node located at pos
template<typename ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getAtPos(const int &pos) const {
    if ((pos < 1) || (pos > itemCount))
        return nullptr;
    else {
        //count from the beggining of the chain
        DoubleNode<ItemType> *curPtr = headPtr;
        int currPos = 1;
        while (currPos != pos) {
            curPtr = curPtr->getNext();
            currPos++;
        }
        return curPtr;
    }
}

// returns whether the calling list is empty
template<typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

// clears the list
template<typename ItemType>
void DoublyLinkedList<ItemType>::clear() {
    while (!isEmpty()) {
        remove(1);
    }
}

// returns the position of the given item in the list, -1 otherwise
template<typename ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const {
    bool found = false;
    int index = 1;
    int result = -1;
    DoubleNode<ItemType> *curPtr = headPtr;
    while (!found && (curPtr != nullptr)) {
        if (item == curPtr->getItem()) {
            found = true;
            result = index;
        } else {
            curPtr = curPtr->getNext();
            index++;
        }
    }
    return result;
}

//display each item in the list to console
template<typename ItemType>
void DoublyLinkedList<ItemType>::display() const {
    // Loop through and call display function for each item in the list
    DoubleNode<ItemType> *currPtr = headPtr;
    for (int i = 0; i < itemCount; i++) {
        std::cout << currPtr->getItem();
        if (i < itemCount - 1) {
            std::cout << " ";
        }
        currPtr = currPtr->getNext();
    }
    std::cout << std::endl;
}
//display each item in the list in reverse order
template<typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {

    //Go to the last node in the list
    DoubleNode<ItemType> *currPtr = headPtr;
    for (int i = 1; i < itemCount; i++) {
        currPtr = currPtr->getNext();
    }//Traverse the list backwards and print each item to console
    for (int i = 0; i < itemCount; i++) {
        std::cout << currPtr->getItem();
        if (i < itemCount - 1) {
            std::cout << " ";
        }
        currPtr = currPtr->getPrevious();
    }
    std::cout << std::endl;
}

//merge each list at alternative positions (merging (1,3,5) and (2,4,6) = (1,2,3,4,5,6)
template<typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list) {

    DoublyLinkedList<ItemType> *return_list = new DoublyLinkedList();
    if (!(isEmpty()) && !(a_list.isEmpty()))  //This checks if both lists are not empty
    {
        DoubleNode<ItemType> *orig_list = headPtr;
        DoubleNode<ItemType> *given_list = a_list.headPtr;
        int index = 1;
        while (orig_list != nullptr && given_list != nullptr) {
            if (index % 2 != 0) {
                return_list->insert(orig_list->getItem(), index);
                orig_list = orig_list->getNext();
                index++;
            } else {
                return_list->insert(given_list->getItem(), index);
                given_list = given_list->getNext();
                index++;
            }
        }
        while (orig_list != nullptr) {
            return_list->insert(orig_list->getItem(), index);
            orig_list = orig_list->getNext();
            index++;
        }
        while (given_list != nullptr) {
            return_list->insert(given_list->getItem(), index);
            given_list = given_list->getNext();
            index++;
        }

    }
    return *return_list;
}


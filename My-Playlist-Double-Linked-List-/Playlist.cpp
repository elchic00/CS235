/****************************************************************************************************************************
Title        : Playlist.cpp
Author       : Andrew Alagna
Description  : implementation file of my Playlist to use for my playlist
Dependencies : Playlist.hpp
****************************************************************************************************************************/


#include "Playlist.hpp"

Playlist::Playlist() : DoublyLinkedList<PlaylistItem *>() {
}

double Playlist::getTotalTime() const {
    DoubleNode<PlaylistItem *> *curPtr = headPtr;
    double total_time = 0;
    //Traverse the chain and add total time of each item until you reach the end of the list.
    for (int i = 0; i < itemCount; i++) {
        //PlaylistItem* currItem = curPtr->getItem();
        total_time += curPtr->getItem()->getLength();
        curPtr = curPtr->getNext();
    }
    return total_time;
}

void Playlist::operator+=(Playlist rhs) {
    DoubleNode<PlaylistItem *> *rhsPtr = rhs.getHeadPtr();

    for (int i = 0; i < rhs.itemCount; i++) {
        this->insert(rhsPtr->getItem(), this->itemCount + 1);
        rhsPtr = rhsPtr->getNext();
    }

}

void Playlist::operator-=(Playlist rhs) {
    DoubleNode<PlaylistItem *> *rhsPtr = rhs.getHeadPtr();

    for (int i = 0; i < rhs.itemCount; i++) {
        this->remove(this->getIndexOf(rhsPtr->getItem()));
        rhsPtr = rhsPtr->getNext();
    }


}

void Playlist::skip() {
    PlaylistItem *skipped_head_item = headPtr->getItem();

    remove(1);
    insert(skipped_head_item, itemCount + 1);

}

void Playlist::rewind() {

    DoubleNode<PlaylistItem *> *currPtr = headPtr;
    for (int i = 1; i < itemCount; i++) {
        currPtr = currPtr->getNext();
    }
    PlaylistItem *skipped_last_item = currPtr->getItem();
    remove(itemCount);
    insert(skipped_last_item, 1);


}

void Playlist::display() const {
    // Loop through and call display function for each item in the list
    DoubleNode<PlaylistItem *> *currentPtr = headPtr;
    while (currentPtr != nullptr) {
        currentPtr->getItem()->display();
        currentPtr = currentPtr->getNext();
    }

}


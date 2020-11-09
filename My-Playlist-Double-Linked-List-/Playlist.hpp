/****************************************************************************************************************************
Title        : Playlist.hpp
Author       : Andrew Alagna
Description  : header file of my Playlist to use for my playlist
****************************************************************************************************************************/


#ifndef MIXTAPE_PLAYLIST_HPP
#define MIXTAPE_PLAYLIST_HPP

#include "DoublyLinkedList.hpp"
#include "PlaylistItem.hpp"

class Playlist : public DoublyLinkedList<PlaylistItem *> {
public:
/*
    Default Constructor
    Goal: Calls its parent constructor
*/
    Playlist();

/*
    Goal: Returns the sum of the lengths of the each item in the Playlist
*/
    double getTotalTime() const;

/*
    Parameter: Another Playlist (rhs)
    Goal: Implement Union.
            rhs to be combined with the contents of this (the calling) list.
            Duplicates are allowed.
*/
    void operator+=(Playlist rhs);

/*
    Parameter: Another Playlist (rhs)
    Goal: Implement Difference.
            Removes all items from this (the calling) list that are also in rhs.
*/
    void operator-=(Playlist rhs);

/*
    Goal: Moves the current object at the head of the list to the end of the list.
*/
    void skip();

/*
    Goal: Moves the current object at the end of the list to the head of the list.
*/
    void rewind();

//Display's all the values of each item in the list
    void display() const;
};


#endif //MIXTAPE_PLAYLIST_HPP

/****************************************************************************************************************************
Title        : Song.cpp
Author       : Andrew Alagna
Description  : implementation file of my Song file to use for my playlist
Dependencies : Song.hpp
****************************************************************************************************************************/


#include <iostream>
#include "Song.hpp"

Song::Song(std::string title, double length, std::string genre, std::string artist) : PlaylistItem(title, length,
                                                                                                   genre),
                                                                                      artist_{artist} {
}

std::string Song::getArtist() const {
    return artist_;
}

void Song::setArtist(std::string artist) {
    artist_ = artist;
}

//Display all the data members of song (overridden)
void Song::display() const {
    std::cout << getTitle() << std::endl;
    std::cout << "Artist: " << artist_ << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Length: " << getLength() << std::endl << std::endl;
}

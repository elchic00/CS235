/****************************************************************************************************************************
Title        : Audiobook.cpp
Author       : Andrew Alagna
Description  : implementation file of audiobook which inherits from playlistitem
Dependencies : AudioBook.hpp, playlistitem.hpp
****************************************************************************************************************************/


#include <iostream>
#include "AudioBook.hpp"

AudioBook::AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker) :
        PlaylistItem(title, length, genre), author_{author}, speaker_{speaker} {
}

std::string AudioBook::getAuthor() const {
    return author_;
}

std::string AudioBook::getSpeaker() const {
    return speaker_;
}

void AudioBook::setAuthor(std::string author) {
    author_ = author;
}

void AudioBook::setSpeaker(std::string speaker) {
    speaker_ = speaker;
}

//Display all data members of audiobook (overridden).
void AudioBook::display() const {
    std::cout << getTitle() << std::endl;
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "Narrator: " << speaker_ << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Length: " << getLength() << std::endl << std::endl;
}

/****************************************************************************************************************************
Title        : PlaylistItem.cpp
Author       : Andrew Alagna
Description  : implementation file of my PlaylistItem to use for my playlist as the parent class for all other items
Dependencies : PlaylistItem.hpp
****************************************************************************************************************************/


#include "PlaylistItem.hpp"

PlaylistItem::PlaylistItem(std::string title, double length, std::string genre) : title_{title}, length_{length},
                                                                                  genre_{genre} {
}

std::string PlaylistItem::getTitle() const {
    return title_;
}

double PlaylistItem::getLength() const {
    return length_;
}

std::string PlaylistItem::getGenre() const {
    return genre_;
}

void PlaylistItem::setTitle(std::string title) {
    title_ = title;
}

void PlaylistItem::setLength(double length) {
    length_ = length;
}

void PlaylistItem::setGenre(std::string genre) {
    genre_ = genre;
}

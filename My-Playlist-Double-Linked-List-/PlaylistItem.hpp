/****************************************************************************************************************************
Title        : PlaylistItem.hpp
Author       : Andrew Alagna
Description  : header file of my PlaylistItem to use for my playlist as the parent class for all other items
****************************************************************************************************************************/


#ifndef MIXTAPE_PLAYLISTITEM_HPP
#define MIXTAPE_PLAYLISTITEM_HPP

#include <string>

class PlaylistItem {
private:
    std::string title_;
    double length_;
    std::string genre_;
public:
    /*
    Parameterized Construtor
    Parameters: title, length, genre
    Update member variables with given parameters
*/
    PlaylistItem(std::string title, double length, std::string genre);

/************************ Getter Functions ************************/

/*
    Return the value of title_
*/
    std::string getTitle() const;

/*
    Return the value of length_
*/
    double getLength() const;

/*
    Return the value of genre_
*/
    std::string getGenre() const;

/************************ Setter Functions ************************/

/*
    Goal: Update the value of title_ with the given parameter
*/
    void setTitle(std::string title);

/*
    Goal: Update the value of length_ with the given parameter
*/
    void setLength(double length);

/*
    Update the value of genre_ with the given parameter
*/
    void setGenre(std::string genre);

/************************ Other Functions ************************/

/*
    A virtual function to be implemented by the children classes
*/
    virtual void display() const = 0;
};


#endif //MIXTAPE_PLAYLISTITEM_HPP

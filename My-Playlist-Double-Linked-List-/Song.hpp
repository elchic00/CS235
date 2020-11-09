/****************************************************************************************************************************
Title        : Song.hpp
Author       : Andrew Alagna
Description  : header file of my Song file to use for my playlist
****************************************************************************************************************************/

#ifndef MIXTAPE_SONG_HPP
#define MIXTAPE_SONG_HPP

#include "PlaylistItem.hpp"

class Song : public PlaylistItem {
private:
    std::string artist_;
public:
    /*
    Parameterized Construtor
    Parameters: title, length, genre, artist
    Update member variables with given parameters
*/
    Song(std::string title, double length, std::string genre,
         std::string artist);

/************************ Getter Functions ************************/

/*
    Return the value of artist_
*/
    std::string getArtist() const;

/************************ Setter Functions ************************/

/*
    Update the value of artist_ with the given parameter
*/
    void setArtist(std::string artist);

/************************ Other Functions ************************/

/*
    Displays the member variables to the console.
          Format is based on the given example in songExample.txt.
*/
    void display() const override;
};


#endif //MIXTAPE_SONG_HPP

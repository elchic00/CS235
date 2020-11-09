/****************************************************************************************************************************
Title        : Audiobook.hpp
Author       : Andrew Alagna
Description  : header file of audiobook which inherits from playlistitem
Dependencies : playlistitem.hpp
****************************************************************************************************************************/

#include "PlaylistItem.hpp"

#ifndef MIXTAPE_AUDIOBOOK_HPP
#define MIXTAPE_AUDIOBOOK_HPP


class AudioBook : public PlaylistItem {
private:
    std::string author_;
    std::string speaker_;
public:
    // Constructor
    AudioBook(std::string title, double length, std::string genre,
              std::string author, std::string speaker);
    //Get author
    std::string getAuthor() const;

    //Get speaker
    std::string getSpeaker() const;

    //set author
    void setAuthor(std::string author);

    //set speaker
    void setSpeaker(std::string speaker);

/*
    Displays the member variables to the console.
    Format is based on the given example in audioBookExample.txt.
*/
    void display() const override;
};


#endif //MIXTAPE_AUDIOBOOK_HPP

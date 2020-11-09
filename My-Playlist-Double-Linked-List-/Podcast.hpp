/****************************************************************************************************************************
Title        : Podcast.hpp
Author       : Andrew Alagna
Description  : header file of my podcast to use for my playlist
****************************************************************************************************************************/


#ifndef MIXTAPE_PODCAST_HPP
#define MIXTAPE_PODCAST_HPP

#include <string>
#include "PlaylistItem.hpp"

class Podcast : public PlaylistItem {
private:
    std::string name_of_podcast_;
    std::string host_;
    std::string guest_;
public:
    //Constructor
    Podcast(std::string title, double length, std::string genre,
            std::string nameOfPodcast, std::string host, std::string guest);

    std::string getNameOfPodcast() const;

    std::string getHost() const;

    std::string getGuest() const;

    void setNameOfPodcast(std::string nameOfPodcast);

    void setHost(std::string host);

    void setGuest(std::string guest);

/*
        Displays the member variables to the console.
            Format is based on the given example in podcastExample.txt.
*/
    void display() const override;
};


#endif //MIXTAPE_PODCAST_HPP

cmake_minimum_required(VERSION 3.17)
project(Mixtape)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mixtape main.cpp DoublyLinkedList.hpp PlaylistItem.cpp Song.cpp AudioBook.cpp AudioBook.hpp Podcast.cpp Playlist.cpp)
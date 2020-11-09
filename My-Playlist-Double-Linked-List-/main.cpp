#include <iostream>
#include "DoubleNode.hpp"
#include "AudioBook.hpp"
#include <string>
#include "Podcast.hpp"
#include "Song.hpp"
#include "DoublyLinkedList.hpp"
#include "Playlist.hpp"

int main() {

    DoublyLinkedList<Song> Songlst1;
    DoublyLinkedList<PlaylistItem *>();
    PlaylistItem *s1 = new Song("Miracle", 2.48, "Electro Pop", "Beachwood");
    PlaylistItem *s2 = new Song("Midnight Sky", 3.43, "Pop Rock", "Miley Cyrus");
    PlaylistItem *s3 = new Song("Diablo", 3.18, "Hip Hip", "Mac Miller");
    Song s4("Kiss Me Thru the Phone", 3.13, "Hip Hop", "Soulja Boy");
    Song s5("Let Me Love You", 4.16, "R&B", "Mario");
    Song s6("Sweet Child O' Mine", 5.55, "Hard Rock", "Guns n Roses");

    //Song listOfSongs[] = {s1, s2, s3, s4, s5, s6};

    Playlist plylist, plylist1;
    plylist.insert(s1, 1);
    plylist.insert(s2, 2);

    plylist1.insert(s3, 3);
    plylist1.insert(s1, 1);
    plylist.skip();
    plylist.display();
    std::cout << std::endl << plylist.getTotalTime() << std::endl;
    plylist += plylist1;
    //plylist-=plylist1;
    plylist.rewind();
    plylist.display();



    //plylist.displayBackwards();

    DoublyLinkedList<int> List;
    DoublyLinkedList<int>();
    List.insert(1, 1);
    List.insert(3, 2);
    List.insert(5, 3);
/*    List.insert(4,4);
    List.insert(5,5);*/
    //List.display();





    DoublyLinkedList<int> List2;
    List2.insert(2, 1);
    List2.insert(4, 2);
    List2.insert(6, 3);
    List2.insert(7, 4);
    std::cout << "\n";
    List.interleave(List2).display();


}







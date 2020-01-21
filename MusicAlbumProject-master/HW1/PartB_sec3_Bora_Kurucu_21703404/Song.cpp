       #include "Song.h"
        #include <string>
        #include <iostream>
        using namespace std;


    Song::Song(string sName,int sMins,int sSecs)
      {
      name = sName;
      mins = sMins;
      secs = sSecs;

     }
     Song::Song(const Song &songToCopy)
     {
     name = songToCopy.name;
     mins = songToCopy.mins;
     secs = songToCopy.secs;

     }
     void Song::operator=(const Song &right)
     {
         name = right.name;
         mins = right.mins;
         secs = right.secs;
     }
     string Song::getName()
     {
         return name;
     }
     int Song::getMins()
     {
         return mins;
     }

     int Song::getSecs()
     {
         return secs;
     }




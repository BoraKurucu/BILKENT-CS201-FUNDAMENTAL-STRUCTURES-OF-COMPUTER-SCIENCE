            #include "SimpleMusicAlbum.h"
            #include <string>
            #include <iostream>
            using namespace std;


             string MusicAlbum::getMusicAlbumArtist()
            {
             return artist;
            }
             string MusicAlbum::getMusicAlbumTitle()
            {
               return title;
            }
             int MusicAlbum::getMusicAlbumYear()
            {
               return year;
            }

            MusicAlbum::MusicAlbum(const string maArtist,
            const  string maTitle,
             const int maYear)
             {
                  artist = maArtist;
                  title =maTitle;
                  year =maYear;
             }

            MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
             {
                artist = maToCopy.artist;
                title = maToCopy.title;
                year = maToCopy.year;


             }
             MusicAlbum::~MusicAlbum()
             {

             }


            void MusicAlbum::operator=(const MusicAlbum &right)
            {
                 artist = right.artist;
                 title = right.title;
                 year = right.year;

            }



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

        MusicAlbum::MusicAlbum(const string maArtist ,
         const string maTitle,
         const int maYear)
         {
              noSongs = 0;
              artist = maArtist;
              title =maTitle;
              year =maYear;
              songs = NULL;

         }

        MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
         {
             noSongs = maToCopy.noSongs;
            artist = maToCopy.artist;
            title = maToCopy.title;
            songs = new Song[maToCopy.noSongs];
          for( int i = 0; i < (noSongs);i++)
          {
             songs[i] = (maToCopy.songs)[i];
          }


         }
         MusicAlbum::~MusicAlbum()
         {
            if(songs  != NULL )
                delete[] songs;

         }

        void MusicAlbum::operator=(const MusicAlbum &right)
        {
             artist = right.artist;
             title = right.title;
             year = right.year;
            noSongs = right.noSongs;

            songs = new Song[right.noSongs];
          for( int i = 0; i < (noSongs);i++)
          {
             songs[i] = (right.songs)[i];
          }


        }
        void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds)
        {
            minutes = seconds = 0;

            for( int i = 0; i< noSongs;i++)
            {
               minutes += (songs[i]).getMins();
               seconds += (songs[i]).getSecs();
            }


            minutes = minutes + (int)(seconds / 60);
            seconds = seconds % 60;
        }
        int MusicAlbum::getNoSongs()
            {
                return noSongs;
            }
            Song* MusicAlbum::getSongs()
            {
                return songs;
            }
       void MusicAlbum::setNoSong(int x)
       {
           noSongs = x;
       }
       void MusicAlbum::setSongs(Song* k)
       {
           songs = k;
       }






            #include "SimpleMac.h"
            #include <string>
            #include <iostream>
            #include <cstddef>

            using namespace std;

                MAC::MAC()
                {
                  noOfMusicAlbums = 0;
                  musicAlbums = NULL;
                }

                MAC::~MAC()
                {
                    if(musicAlbums)
                   delete[] musicAlbums;
                }

               MAC::MAC( const MAC &macToCopy)
            {
              musicAlbums = new MusicAlbum[macToCopy.noOfMusicAlbums];
              noOfMusicAlbums = macToCopy.noOfMusicAlbums;
              for( int i = 0; i < (macToCopy.noOfMusicAlbums);i++)
              {
                  musicAlbums[i] = (macToCopy.musicAlbums[i]);
              }

            }

             void  MAC::operator=( const MAC &right)
            {
             musicAlbums = new MusicAlbum[right.noOfMusicAlbums];
              noOfMusicAlbums = right.noOfMusicAlbums;

              for( int i = 0; i < (right.noOfMusicAlbums);i++)
              {
                  musicAlbums[i] = (right.musicAlbums[i]);
              }

            }
                bool MAC::addMusicAlbum( string maArtist,
                  string maTitle,
                 int maYear)
                {
                    if(noOfMusicAlbums == 0)
                    {
                        MusicAlbum album(maArtist,maTitle,maYear);
                        musicAlbums = new MusicAlbum[++noOfMusicAlbums];
                        musicAlbums[0] = album;
                        return true;
                    }
                    else
                    {
                    int index = -1;
                    bool albumFound = albumExist(maArtist,maTitle,index);

               if(albumFound == false)
               {
                 MusicAlbum * temp = new MusicAlbum[++noOfMusicAlbums];
                 MusicAlbum album(maArtist,maTitle,maYear);


                 for(int i = 0; i < noOfMusicAlbums - 1;i++)
                    temp[i] = musicAlbums[i];

                 temp[noOfMusicAlbums-1] = album;
                 delete[] musicAlbums;
                 musicAlbums = temp;
               }
               return !(albumFound);
                    }

                }

              bool MAC::removeMusicAlbum( string maArtist,
             const string maTitle)
             {

                 int index = -1;
                 bool found = false;
                 if(noOfMusicAlbums > 0)
                 {
                     found = albumExist(maArtist,maTitle,index);
                 }
                 if(found == false)
                    return false;


                 MusicAlbum* temp = new MusicAlbum[noOfMusicAlbums - 1];

                 for(int i = 0; i < index;i++)
                 {
                    temp[i] = musicAlbums[i];
                 }
                 for( int k = index + 1; k < noOfMusicAlbums;k++)
                 {
                     temp[k-1] = musicAlbums[k];
                 }
                 delete[] musicAlbums;
                 noOfMusicAlbums = noOfMusicAlbums - 1;
                 musicAlbums =  temp;

                 return true;

             }
                 int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
                 {
                        allMusicAlbums = new MusicAlbum[noOfMusicAlbums];

                  for (int i = 0; i < noOfMusicAlbums; i++) {
                   allMusicAlbums[i] = musicAlbums[i];
              }
                  return noOfMusicAlbums;
                  }



                 bool MAC::albumExist(string maArtist,string maTitle,int &indexFinder)
                 {
                     bool foundAlbum = false;
                    int index = -1;
              for(int i = 0;i < noOfMusicAlbums;i++)
             {
                 if(musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle() == maTitle)
                 {
                     index = i;
                     foundAlbum = true;
                 }
             }
             indexFinder = index;
             return foundAlbum;
                 }


                 bool MAC::songExistInAlbum(string sName,int index)
                 {
                     bool songExist = false;
                     for( int i = 0;i < musicAlbums[index].getNoSongs();i++)
             {
                 if((musicAlbums[index].getSongs()[i]).getName() == sName)
                 {
                     songExist = true;
                 }
             }
             return songExist;
                 }
                 bool MAC::addSong(const string maArtist, const string maTitle,
         const string sName, const int sMins,
         const int sSecs)
         {

             int index = -1;

             bool albumFound = albumExist(maArtist,maTitle,index);

             if(!(albumFound))
                return false;

             if(songExistInAlbum(sName,index))
                return false;

        int no = (musicAlbums[index].getNoSongs());


           Song * temp = new Song[no + 1];
         for(int i = 0;i < no;i++)
         {
             temp[i] = (musicAlbums[index].getSongs())[i];
         }
         temp[no] = Song (sName,sMins,sSecs);
         delete[] musicAlbums[index].getSongs();
         musicAlbums[index].setSongs(temp);
         musicAlbums[index].setNoSong(no + 1);

         return true;
         }
    bool MAC::removeSongs
    (string maArtist,
     string maTitle)
     {
         int index = -1;
         bool foundAlbum = albumExist(maArtist,maTitle,index);
         if(foundAlbum == false)
            return false;

         delete[] musicAlbums[index].getSongs();

     }
     void MAC::calculateAvgMusicAlbumLength(int &minutes,
     int &seconds)
     {
         int secondsTemp = 0;

         if(noOfMusicAlbums == 0)
         {

              return;
         }
         for( int i = 0;i < noOfMusicAlbums;i++)
         {

                 minutes = seconds = 0;
                 musicAlbums[i].calculateMusicAlbumLength( minutes, seconds);
                 secondsTemp = secondsTemp + minutes * 60 + seconds;

         }



    secondsTemp = secondsTemp / noOfMusicAlbums;
	minutes = secondsTemp / 60;
	seconds = secondsTemp % 60 ;

     }



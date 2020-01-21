#ifndef __SIMPLE_MUSIC_ALBUM_H
#define __SIMPLE_MUSIC_ALBUM_H
#include "Song.h"
#include <string>
using namespace std;
class MusicAlbum {
public:
 MusicAlbum(const string maArtist = "",
 const string maTitle = "",
 const int maYear = 0);
 ~MusicAlbum();
 MusicAlbum(const MusicAlbum &maToCopy);
 void operator=(const MusicAlbum &right);
 string getMusicAlbumArtist();
 string getMusicAlbumTitle();
 int getMusicAlbumYear();
 void calculateMusicAlbumLength(int &minutes, int &seconds);
 int getNoSongs();
 Song* getSongs();
 void setNoSong(int x);
 void setSongs(Song * k);
//private:
 string artist;
 string title;
 int year;
 Song *songs;
 int noSongs;
};
#endif

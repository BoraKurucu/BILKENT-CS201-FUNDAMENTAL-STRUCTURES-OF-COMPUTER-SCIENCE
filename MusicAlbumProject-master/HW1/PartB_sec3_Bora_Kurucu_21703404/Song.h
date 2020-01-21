#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED
#include <string>

using namespace std;
class Song {
public:
 Song(const string sName = "", const int sMins = 0,
 const int sSecs = 0);

 Song(const Song &songToCopy);
 void operator=(const Song &right);
 string getName();
 int getMins();
 int getSecs();
private:
 string name;
 int mins;
 int secs;
};


#endif // SONG_H_INCLUDED

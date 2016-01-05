#ifndef TRACK_HPP
#define TRACK_HPP
#include<fstream>
#include<cstring>
#include<string>
#include<iostream>
#include<ctype.h>
#include "JSONDataObject.hpp"

using namespace std;

class Track: public JSONDataObject
{
public:
  Track(): JSONDataObject() { _artistName = ""; _title = ""; _albumName = "";  _duration = ""; _position = ""; _albumID = 0; cachedArtistName = false; cachedTitle = false; cachedAlbumName = false; cachedAlbumID = false; cachedDuration = false; cachedPosition = false;}
  Track(JSONDataObject *);
  ~Track();

  string artistName(); 
  string title(); 
  string albumName();
  unsigned albumID();
  string duration(); 
  string position(); 

  bool hasArtist() { return artistName() != ""; }
  bool hasTitle() { return title() != ""; }
  bool hasAlbum() { return albumName() != ""; }
  bool hasAlbumID() { return albumID() != 0; }
  bool hasDuration() { return duration() != ""; }
  bool hasPosition() { return position() != ""; }

  void print();
  string htmlString();

private:
  string _artistName, _title, _albumName, _duration, _position;
  unsigned _albumID;

  bool cachedArtistName, cachedTitle, cachedAlbumName, cachedAlbumID, cachedDuration, cachedPosition;
};

#endif

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include<fstream>
#include<cstring>
#include<iostream>
#include<string>
#include<ctype.h>

#include "JSONDataObject.hpp"
#include "AlbumImage.hpp"


class Tracks;
class Artist;

using namespace std;

class Album: public JSONDataObject{
public:
  Album();
  ~Album();
  Album(JSONDataObject *json);

  string title();
  unsigned albumID(); 
  unsigned artistID();
  string genres(); 
  unsigned numImages(); 
  unsigned numTracks(); 
  unsigned year(); 

  bool hasTitle() { return title() != ""; }
  bool hasAlbumID() { return albumID() != 0; }
  bool hasArtistID() { return artistID() != 0; }
  bool hasGenres() { return genres() != ""; }
  bool hasImages() { return numImages() != 0; }
  bool hasTracks() { return numTracks() != 0; }
  bool hasYear() { return year() != 0; }

  void print();
  string htmlString();

  AlbumImage *&primaryImage() { return _primaryImage; }
  AlbumImage *&secondaryImage() { return _secondaryImage; }

  void setTracks(Tracks *tracks) { _tracks = tracks;}
  void setArtist(Artist *artist) { _artist = artist;}
  Artist *artist() {return _artist;}
  Tracks *tracks() { return _tracks;}

private:
  string _title, _genres;
  unsigned _albumID, _numTracks, _year, _numImages, _artistID;
  bool cachedTitle, cachedAlbumID, cachedGenres, cachedNumImages, cachedNumTracks, cachedYear, cachedArtistID;

  AlbumImage *_primaryImage, *_secondaryImage;
  Artist *_artist;
  Tracks *_tracks;
};

#endif

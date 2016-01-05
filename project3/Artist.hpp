#ifndef ARTIST_HPP
#define ARTIST_HPP
#include<fstream>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<string>

#include "JSONDataObject.hpp"

class Albums;
class ArtistImage;

using namespace std;

class Artist: public JSONDataObject
{
public:
  Artist();
  Artist(JSONDataObject *);
  ~Artist();

  string profile();   
  string artistName(); 
  string realName();  
  string numImages(); 
  unsigned artistID();   

  bool hasProfile() { return profile() != ""; }
  bool hasArtistName() { return artistName() != ""; }
  bool hasRealName() { return realName() != ""; }
  bool hasImages() { return numImages() != ""; }
  bool hasArtistID() { return artistID() != 0; }

  void print();
  string htmlString();

  void setAlbums(Albums *albums) { _albums = albums; }
  Albums *albums() { return _albums; }
  ArtistImage *&primaryImage() { return _primaryImage; }
  ArtistImage *&secondaryImage() { return _secondaryImage; }

private:
  std::string _name, _realName, _profile, _numImages;
  unsigned _artistID;
  bool cachedArtistName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

  ArtistImage *_primaryImage, *_secondaryImage;
  Albums *_albums;
};

#endif

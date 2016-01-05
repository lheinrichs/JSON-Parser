
#ifndef ALBUMS_HPP
#define ALBUMS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Album.hpp"
#include "JSONArray.hpp"

class AlbumImages;
class Tracks;
class Artists;

using namespace std;

class Albums: public JSONArray
{
public:
  Albums() : JSONArray() {}
  ~Albums();

  int numAlbums();
  void addAlbum(Album *album);
  Album *albumWithID(unsigned int aID);
  void loadAlbumsFromFile(string fileName);
  string htmlString();
  JSONDataObject *jsonObjectNode() { return new Album(); }
  void setImagesForAlbums(AlbumImages *);
  void setTracksForAlbums(Tracks *);
  void setArtistsForAlbums(Artists *);
  vector <Album *> *listOfAlbums() { return (vector<Album *> *) _listOfDataObjects; }
  void runAsserts();
  void print();

};

#endif

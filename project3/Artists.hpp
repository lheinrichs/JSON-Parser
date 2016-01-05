#ifndef ARTISTS_HPP
#define ARTISTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "JSONArray.hpp"
#include "Artist.hpp"
#include "JSONDataObject.hpp"

class Albums;
class ArtistImages;

using namespace std;

class Artists: public JSONArray
{
public:
  Artists(): JSONArray() {}

  int numArtists();
  void addArtist(Artist *artist);
  Artist *artistWithID(unsigned int aID);
  void loadArtistsFromFile(string fileName);
  string htmlString();
  JSONDataObject *jsonObjectNode() { return new Artist(); }
  void setAlbumsForArtists(Albums *albums);
  void setImagesForArtists(ArtistImages *);
  vector <Artist *> *listOfArtists() { return (vector <Artist *> *) _listOfDataObjects; }
  void runAsserts();
  void print();
};

#endif

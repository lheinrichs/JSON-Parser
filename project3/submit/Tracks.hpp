#ifndef TRACKS_HPP
#define TRACKS_HPP

#include<iostream>
#include<string>
#include <vector>
#include "JSONArray.hpp"
#include "Track.hpp"
#include "Albums.hpp"


using namespace std;

class Tracks: public JSONArray
{
public:
  Tracks() : JSONArray() {}
  ~Tracks() {}

  int numTracks();
  void addTracks(Track *track);
  void loadTracksFromFile(string fileName);
  string htmlString();
  JSONDataObject *jsonObjectNode() { return new Track(); }
  vector<Track *> *listOfTracks() { return (vector<Track *> *) _listOfDataObjects; }
  void runAsserts();
  void print();

};

#endif

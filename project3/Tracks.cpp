#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Tracks.hpp"
#include "Track.hpp"
#include "Albums.hpp"

using namespace std;

int Tracks:: numTracks()
{
  return listOfTracks() -> size();
}

void Tracks:: addTracks(Track *track)
{
  listOfTracks() -> push_back(track);
}


void Tracks:: loadTracksFromFile(string fileName)
{
  fstream trackStream;
  string tracksName = "Tracks.json";
  trackStream.open(tracksName.c_str(), fstream::in);
  parseJSONArray(trackStream);
  trackStream.close();
}

string Tracks:: htmlString()
{
  string html;
  for(int i = 0; i < numTracks(); i++)
    {
      html.append(" Artist Name: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("artist_name"));
      html.append(" Album ID: " + to_string(_listOfDataObjects -> at(i) -> valueForIntegerAttribute("album_id")));
      html.append(" Title: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("title"));
      html.append(" Album Name: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("album_name"));
      html.append(" Duration:  " + _listOfDataObjects -> at(i) -> valueForStringAttribute("duration"));
      html.append(" Position: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("position"));
    }
  return html;
}


void Tracks:: runAsserts()
{
}

void Tracks:: print()
{
  for( int i = 0; i < numTracks(); i++)
    listOfTracks() -> at(i) -> print();
}


#include "Album.hpp"
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

Album::Album()
{
  _title = "";
  _genres = "";
  _albumID = 0;
  _numTracks = 0;
  _year = 0;
  _numImages = 0;
  cachedTitle = false;
  cachedAlbumID = false;
  cachedArtistID = false;
  cachedGenres = false;
  cachedNumImages = false;
  cachedNumTracks = false;
  cachedYear = false;

}

Album::~Album()
{
}

Album:: Album(JSONDataObject *json)
{
  _title = json -> valueForStringAttribute("title");
  _genres = json -> valueForStringAttribute("genres");
  _albumID = json -> valueForIntegerAttribute("album_id");
  _numTracks = json -> valueForIntegerAttribute("num_tracks");
  _year = json -> valueForIntegerAttribute("year");
  _numImages = json -> valueForIntegerAttribute("num_images");
}

string Album:: title()
{
  if(!hasTitle())
    return "";
  if(cachedTitle)
    return _title;
  cachedTitle = true;
  return _title = valueForStringAttribute("title");
}

unsigned Album:: albumID()
{
  if(!hasAlbumID())
    return 0;
  if(cachedAlbumID)
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album:: artistID()
{
  if(!hasArtistID())
    return 0;
  if(cachedArtistID)
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}

string Album:: genres()
{
  if(!hasGenres())
    return "";
  if(cachedGenres)
    return _genres;
  cachedGenres = true;
  return _genres = valueForStringAttribute("genres");
}

unsigned Album:: numImages()
{
  if(!hasImages())
    return 0;
  if(cachedNumImages)
    return _numImages;
  cachedNumImages = true;
  return _numImages = valueForIntegerAttribute("num_images");
}

unsigned Album:: numTracks()
{
  if(!hasTracks())
    return 0;
  if(cachedNumTracks)
    return _numTracks;
  cachedNumTracks = true;
  return _numTracks = valueForIntegerAttribute("num_tracks");
}

unsigned Album:: year()
{
  if(!hasYear())
    return 0;
  if(cachedYear)
    return _year;
  cachedYear = true;
  return _year = valueForIntegerAttribute("year");
}


//reads in the document into an html style document 
string Album:: htmlString()
{
  stringstream html;
  html << "<li><p>Title: ";
  html <<  _title;
  html<< "</p>\n\t<ul><li><p>Album ID: ";
  html << _albumID;
  html <<"</p></li>\n\t<li><p>Artist ID: ";
  html << _artistID;
  html << "</p></li>\n<li><p>Number of images: ";
  html << _numImages;
  html << "</p></li>\n<li><p>Number of tracks:";
  html << _numTracks;
  html <<"</p></li>\n<li><p>Year: ";
  html << _year;
  html << "</p></li></ul></li>";
  html << endl;
  return html.str();
}

void Album:: print()
{
  cout << "-----ALBUM FILE------" << endl;
  cout << "Title: " << title() << endl;
  cout << "Album ID: " << albumID() << endl;
  cout << "Artist ID: " << artistID() << endl;
  cout << "Number of images:  " << numImages() << endl;
  cout << "Number of tracks: " << numTracks() << endl;
  cout << "Year: " << year() << endl;

}

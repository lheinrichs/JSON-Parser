#include "Track.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cstring>
#include <sstream>

using namespace std;


Track:: ~Track()
{
}

Track:: Track(JSONDataObject *json)
{
  _artistName = json -> valueForStringAttribute("artist_name");
  _title = json -> valueForStringAttribute("title");
  _albumName = json -> valueForStringAttribute("album_name");
  _albumID = json -> valueForIntegerAttribute("album_id");
  _duration = json -> valueForStringAttribute("duration");
  _position = json -> valueForStringAttribute("position");
}

string Track:: artistName()
{
  if(!hasArtist())
    return "";
  if(cachedArtistName)
    return _artistName;
  cachedArtistName = true;
  return _artistName = valueForStringAttribute("artist_name");
}

string Track:: title()
{
  if(!hasTitle())
    return "";
  if(cachedTitle)
    return _title;
  cachedTitle = true;
  return _title = valueForStringAttribute("title");
}

string Track:: albumName()
{
  if(!hasAlbum())
    return "";
  if(cachedAlbumName)
    return _albumName;
  cachedAlbumName = true;
  return _albumName = valueForStringAttribute("album_name");
}

unsigned Track:: albumID()
{
  if(!hasAlbumID())
    return 0;
  if(cachedAlbumID)
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}

string Track:: duration()
{
  if(!hasDuration())
    return "";
  if(cachedDuration)
    return _duration;
  cachedDuration = true;
  return _duration = valueForStringAttribute("duration");
}

string Track:: position()
{
  if(!hasPosition())
    return "";
  if(cachedPosition)
    return _position;
  cachedPosition = true;
  return _position = valueForStringAttribute("position");
}


string Track::htmlString()

//allows it to read into an html document
{
  stringstream html;
  html << "<li><p>" << _artistName << "</p>\n\t\t<ul>\n\t\t\t<li><p>ID: " << _albumID << "</p></li>\n\t\t\t<li><p>Position: " << _position << "</p></li>\n\t\t\t<li><p>Album Name: " << _albumName <<"</p></li>\n\t\t\t<li><p>Duration: " << _duration << "</p></li>\n\t\t\t<li><p>Title: "<< _title <<"</p></li>\n\t\t</ul>\n\t</li>" << endl;
  return html.str();

}

void Track:: print()
{
  cout << "------TRACK FILE---------" << endl;
  cout << "Album Name: " << albumName() << endl;
  cout << "Album ID: " << albumID() << endl;
  cout << "Duration: " << duration() << endl;
  cout << "Position: " << position()  << endl;

}

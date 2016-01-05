#include "AlbumImage.hpp"
#include <iostream>
#include <sstream>

using namespace std;

AlbumImage:: AlbumImage()
{ 
  _type = "";
  _uri = "";
  _albumID = 0;
  _width = 0;
  _height = 0;
  cachedUri = false;
  cachedAlbumID = false;
  cachedType = false;
  cachedWidth = false;
  cachedHeight = false;
}

AlbumImage:: ~AlbumImage()
{
}

void AlbumImage:: constructAlbumImage(JSONDataObject *json)
{
  _type = json -> valueForStringAttribute("type");
  _uri = json -> valueForStringAttribute("uri");
  _albumID = json -> valueForIntegerAttribute("album_id");
  _width = json -> valueForIntegerAttribute("width");
  _height = json -> valueForIntegerAttribute("height");
}


string AlbumImage:: uri()
{
  if(!hasUri())
    return "";
  if(cachedUri)
    return _uri;
  cachedUri = true;
  return _uri = valueForStringAttribute("uri");

}

unsigned AlbumImage:: albumID()
{
  if(!hasAlbumID())
    return 0;
  if(cachedAlbumID)
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");

}

string AlbumImage:: type()
{
  if(!hasType())
    return "";
  if(cachedType)
    return _type;
  cachedType = true;
  return _type = valueForStringAttribute("type");

}

unsigned AlbumImage:: width()
{
  if(!hasWidth())
    return 0;
  if(cachedWidth)
    return _width;
  cachedWidth = true;
  return _width = valueForIntegerAttribute("width");
}

unsigned AlbumImage:: height()
{
  if(!hasHeight())
    return 0;
  if(cachedHeight)
    return _height;
  cachedHeight = true;
  return _height = valueForIntegerAttribute("height");
}

void AlbumImage:: print()
{
  cout << "--------ALBUM IMAGE-------" << endl;
  cout << "uri: " << _uri << endl;
  cout << "type: " << _type << endl;
  cout << "width: " << _width << endl;
  cout << "height: " << _height << endl;
  cout << "album id: " << _albumID << endl;
}

string AlbumImage:: htmlString()
{
  stringstream html;
  html << "<li><p>Album ID: ";
  html << _albumID;
  html << "</p>\n\t<ul><li><p>Type: ";
  html << _type;
  html << "</p></li>\n\t<li><p>Width: ";
  html << _width;
  html << "</p></li>\n\t<li><p>Height: ";
  html << _height;
  html << "</p></li>\n\t<li><p>Uri: ";
  html << _uri;
  html << "</p><li></ul></li>";
  html << endl;
  return html.str();    
}

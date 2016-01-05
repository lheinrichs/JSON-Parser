#include "ArtistImage.hpp"
#include <iostream>
#include <sstream>

using namespace std;

ArtistImage:: ArtistImage()
{
  _type = "";
  _uri = "";
  _artistID = 0;
  _width = 0;
  _height = 0;
  cachedUri = false;
  cachedType = false;
  cachedArtistID = false;
  cachedWidth = false;
  cachedHeight = false;
}

ArtistImage:: ~ArtistImage()
{
}

void ArtistImage:: constructArtistImage(JSONDataObject *json)
{
  _type = json -> valueForStringAttribute("type");
  _uri = json -> valueForStringAttribute("uri");
  _artistID = json -> valueForIntegerAttribute("artist_id");
  _width = json -> valueForIntegerAttribute("width");
  _height = json -> valueForIntegerAttribute("height");
}

string ArtistImage:: uri()
{
  if(!hasUri())
    return "";
  if(cachedUri)
    return _uri;
  cachedUri = true;
  return _uri = valueForStringAttribute("uri");
}

string ArtistImage:: type()
{
  if(!hasType())
    return "";
  if(cachedType)
    return _type;
  cachedType = true;
  return _type = valueForStringAttribute("type");
}

unsigned ArtistImage:: artistID()
{
  if(!hasArtistID())
    return 0;
  if(cachedArtistID)
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}

unsigned ArtistImage:: width()
{
  if(!hasWidth())
    return 0;
  if(cachedWidth)
    return _width;
  cachedWidth = true;
  return _width = valueForIntegerAttribute("width");
}

unsigned ArtistImage:: height()
{
  if(!hasHeight())
    return 0;
  if(cachedHeight)
    return _height;
  cachedHeight = true;
  return _height = valueForIntegerAttribute("height");
}

void ArtistImage:: print()
{
  cout << "---------ARTIST IMAGE------"<< endl;
  cout << "uri: " << uri() << endl;
  cout <<"type: " << type() << endl;
  cout <<"height: " << height() << endl;
  cout << "width: " << width() << endl;
  cout << "artist id: " << artistID() << endl;
}

string ArtistImage:: htmlString()
{
stringstream html;
html <<"<li><p>Artist ID: ";
html << _artistID;
html << "</p></li>\n\t<ul><li><p>Type: ";
html << _type;
html << "</p></li>\n\t<li><p>Width: ";
html << _width;
html << "</p></li>\n\t<li><p>Height: ";
html << _height;
html << "</p></li>\n\t<li><p>Uri: ";
html << _uri;
html << "</p></li>\n\t</ul></li>";
html << endl;
return html.str();
}

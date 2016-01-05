#ifndef ARTISTIMAGE_HPP
#define ARTISTIMAGE_HPP

#include <iostream>
#include "JSONDataObject.hpp"

using namespace std;

class ArtistImage: public JSONDataObject
{
public:
  ArtistImage();
  ~ArtistImage();
 void constructArtistImage(JSONDataObject *json);

  string type();
  string uri();
  unsigned artistID();
  unsigned width();
  unsigned height();

  bool hasUri() { return uri() != ""; }
  bool hasType() { return type() != ""; }
  bool hasArtistID() { return artistID() != 0; }
  bool hasWidth() { return width() != 0; }
  bool hasHeight() { return height() != 0;}

  void print();
  string htmlString();

private:
  string _type, _uri;
  unsigned _artistID, _width, _height;
  bool cachedArtistID, cachedWidth, cachedHeight, cachedType, cachedUri;



};

#endif

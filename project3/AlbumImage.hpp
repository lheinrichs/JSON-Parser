#ifndef ALBUMIMAGE_HPP
#define ALBUMIMAGE_HPP

#include <iostream>

using namespace std;

#include "JSONDataObject.hpp"

class AlbumImage: public JSONDataObject
{
public:
  AlbumImage();
  ~AlbumImage();
  void constructAlbumImage(JSONDataObject *json);

  unsigned albumID();
  string type();
  string uri();
  unsigned width();
  unsigned height();

  bool hasUri() { return uri() != ""; }
  bool hasAlbumID() { return albumID() != 0; }
  bool hasType() { return type() != ""; }
  bool hasWidth() { return width() != 0; }
  bool hasHeight() { return height() != 0; }

  void print();
  string htmlString();

private:
  string _type, _uri;
  unsigned _albumID, _width, _height;
  bool cachedAlbumID, cachedType, cachedWidth, cachedHeight, cachedUri;
};

#endif

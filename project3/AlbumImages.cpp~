#include "AlbumImages.hpp"
#include <vector>
#include <iostream>

using namespace std;

int AlbumImages:: numAlbumImages()
{
  return listOfDataObjects() -> size();
}

void AlbumImages:: addAlbumImages(AlbumImage *albumImage)
{
  listOfDataObjects() -> push_back(albumImage);
}

void AlbumImages:: loadAlbumImagesFromFile(string fileName)
{
  fstream albumImagesStream;
  albumImagesStream.open(fileName.c_str(), fstream:: in);
  parseJSONArray(albumImagesStream);
  albumImagesStream.close();
}

string AlbumImages:: htmlString()
{
  string html;
  for(int i = 0; i < numAlbumImages(); i++)
    {
      html.append(to_string(_listOfDataObjects -> at(i) -> valueForIntegerAttribute("height")));
      html.append(_listOfDataObjects -> at(i) -> valueForStringAttribute("type"));
      html.append(_listOfDataObjects -> at(i) -> valueForStringAttribute("uri"));
      html.append(to_string(_listOfDataObjects -> at(i) -> valueForIntegerAttribute("width")));
      html.append(to_string(_listOfDataObjects -> at(i) -> valueForIntegerAttribute("album_id")));
    }
  return html;
}

void AlbumImages:: runAsserts()
{
}


void AlbumImages:: print()
{
  for(int i = 0; i < numAlbumImages(); i++)
    listOfDataObjects() -> at(i) -> print();
}

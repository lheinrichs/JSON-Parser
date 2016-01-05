#include "JSONArray.hpp"
#include "AlbumImage.hpp"
#include <vector>
#include <string>

using namespace std;

class AlbumImages: public JSONArray
{
public: 

  AlbumImages() : JSONArray() {}

  int numAlbumImages();
  void addAlbumImages(AlbumImage *albumImage);
  void loadAlbumImagesFromFile(string fileName);
  string htmlString();
  JSONDataObject *jsonObjectNode() {return new AlbumImage(); } 
  vector<AlbumImage *> *listOfDataObjects() { return (vector<AlbumImage *> *) _listOfDataObjects; };
  void runAsserts();
  void print();
};

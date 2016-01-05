#include "JSONArray.hpp"
#include "ArtistImage.hpp"

class ArtistImages: public JSONArray
{
public:
  ArtistImages(): JSONArray() {}

  int numArtistImages();
  void addArtistImages(ArtistImage *artistImage);
  void loadArtistImagesFromFile(string fileName);
  string htmlString();
  JSONDataObject *jsonObjectNode() { return new ArtistImage(); }
  vector<ArtistImage *> *listOfDataObjects() { return (vector<ArtistImage *> *) _listOfDataObjects; }
  void runAsserts();
  void print();

};


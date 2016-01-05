#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Artists.hpp"
#include "Artist.hpp"
#include "Albums.hpp"
#include "ArtistImages.hpp"

using namespace std;

int Artists:: numArtists()
{
  return listOfArtists() -> size();  

}

Artist* Artists:: artistWithID(unsigned int aID)
{
  for(int i = 0; i < listOfArtists() -> size(); i++)
    {
      if(listOfArtists() -> at(i) -> valueForIntegerAttribute("artist_id") == aID)
	{
	  return new Artist(_listOfDataObjects -> at(i));
	}
    }  
}

void Artists:: loadArtistsFromFile(string artistsFileName)
{
  fstream artStream;
  artStream.open(artistsFileName.c_str(), fstream::in);
  parseJSONArray(artStream);
  artStream.close();
}

void Artists:: addArtist(Artist *artist)
{
  _listOfDataObjects -> push_back(artist);
}

string Artists:: htmlString()
{
  string html;
  for(int i = 0; i < listOfArtists() -> size(); i++)
    {
      html.append(" Artist Name: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("artist_name"));
      html.append(" Artist ID: " + to_string(_listOfDataObjects -> at(i) -> valueForIntegerAttribute("artist_id")));
      html.append(" Profile: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("profile"));
      html.append(" Real Name: " + _listOfDataObjects -> at(i) -> valueForStringAttribute("real_name"));
      html.append(" Num Images:  " + _listOfDataObjects -> at(i) -> valueForStringAttribute("num_images"));
    }
  return html;
}

void Artists:: setAlbumsForArtists(Albums *albums)
{
  for(int i = 0; i < numArtists(); i++)
    {
      Albums *album_artist = new Albums;
      for(int j = 0; j < albums -> numAlbums(); j++)
	{
	  if(albums -> listOfAlbums() -> at(j) -> artistID() == listOfArtists() -> at(i) -> artistID())
	    {
	      album_artist -> addAlbum(albums -> listOfAlbums() -> at(j));
	    }
	}
      listOfArtists() -> at(i) -> setAlbums(album_artist);
    }
  
}

void Artists:: setImagesForArtists(ArtistImages *artistImages)
{
  for(int i = 0; i < numArtists(); i++)
    {
    listOfArtists() -> at(i) -> primaryImage() = new ArtistImage();
    listOfArtists() -> at(i) -> secondaryImage() = new ArtistImage();
    for(int j = 0; j < artistImages -> numArtistImages(); j++)
      {
	if(artistImages -> listOfDataObjects() -> at(j) -> artistID() == listOfArtists() -> at(i) -> artistID())
	  {
	    if(artistImages -> listOfDataObjects() -> at(j) -> valueForStringAttribute("type") == "primary")
	      listOfArtists() -> at(i) -> primaryImage() = artistImages -> listOfDataObjects() -> at(j);
	    else
	      listOfArtists() -> at(i) -> secondaryImage() = artistImages -> listOfDataObjects() -> at(j);
	  }
      }
    }
}

/* for(vector<JSONDataObject *>::iterator iter = _listOfDataObjects -> begin(); iter != _listOfDataObjects -> end(); ++iter)
    {
      for(int i = 0; i < numArtists(); i++)
	{
	  if(listOfArtists() -> at(i) -> valueForIntegerAttribute("album_id") == (*iter) -> valueForIntegerAttribute("album_id"))
	    {
	      if((*iter) -> valueForStringAttribute("type") == "primary")
		listOfArtists() -> at(i) -> primaryImage() -> constructArtistImage((*iter));
	      else if((*iter) -> valueForStringAttribute("type") == "secondary")
		listOfArtists() -> at(i) -> secondaryImage() -> constructArtistImage((*iter));
	    }
	}
    }
    }*/

void Artists:: runAsserts()
{
}

void Artists:: print()
{
  for(int i = 0; i < numArtists(); i++)
    listOfArtists() -> at(i) -> print();

}


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "Album.hpp"
#include "AlbumImages.hpp"
#include "Tracks.hpp"
#include "Albums.hpp"
#include "Artists.hpp"

using namespace std;


Albums:: ~Albums()
{
}

int Albums:: numAlbums()
{
  return listOfAlbums() -> size();
}

void Albums:: addAlbum(Album *album)
{
  listOfAlbums() -> push_back(album);
}

Album* Albums:: albumWithID(unsigned int aID)
{
  for(int i = 0; i < listOfAlbums() -> size();i++)
    {
      if(listOfAlbums() -> at(i) -> valueForIntegerAttribute("artist_id") == aID)
	{
	  return new Album(_listOfDataObjects -> at(i));
	}
    }
}

void Albums:: loadAlbumsFromFile(string fileName)
{
  fstream albumStream;
  albumStream.open("Albums.json", fstream::in);
  parseJSONArray(albumStream);
  albumStream.close();
}

string Albums:: htmlString()
{
  string html;
  for(int i = 0; i < numAlbums(); i++)
    {
      html.append(listOfAlbums() -> at(i) -> htmlString());
    }
  return html;
}

void Albums:: setArtistsForAlbums(Artists *artists)
{
  for(int i = 0; i < numAlbums(); i++)
    {
      bool hasArtist = false;
      for(int j = 0; j < artists -> numArtists(); j++)
	{
	  if(listOfAlbums() -> at(i) -> artistID() == artists -> listOfArtists() -> at(j) -> artistID());
	  {
	    listOfAlbums() -> at(i) -> setArtist(artists -> listOfArtists() -> at(j));
	    hasArtist = true;
	  }
	}
      if(!hasArtist)
	listOfAlbums() -> at(i) -> setArtist(new Artist());
    }



}

void Albums:: setTracksForAlbums(Tracks *tracks)
{
  for(int i = 0; i < numAlbums(); i++)
    {
      Tracks *track_album = new Tracks;
      for(int j = 0; j < tracks -> numTracks(); j++)
	{
	  if(tracks -> listOfTracks() -> at(j) -> albumID() == listOfAlbums() -> at(i) -> albumID())
	    {
	      track_album -> addTracks(tracks -> listOfTracks() -> at(j));
	    }
	}
      listOfAlbums() -> at(i) -> setTracks(track_album);
    }
}

void Albums:: setImagesForAlbums(AlbumImages *albumImages)
{

  for(vector<JSONDataObject *>:: iterator iter = _listOfDataObjects -> begin(); iter != _listOfDataObjects -> end(); iter++)
    {
      for(int i = 0; i < numAlbums(); i++)
	{
	  if(listOfAlbums() -> at(i) -> valueForIntegerAttribute("album_id") == (*iter) -> valueForIntegerAttribute("album_id"))
	    {
	      if((*iter) -> valueForStringAttribute("type") == "primary")
		listOfAlbums() -> at(i) -> primaryImage() -> constructAlbumImage((*iter));
	      else if((*iter) -> valueForStringAttribute("type") == "secondary")
		listOfAlbums() -> at(i) -> secondaryImage() -> constructAlbumImage((*iter));
	    }
	}
    }
 
}

void Albums:: runAsserts()
{
}


void Albums:: print()
{
  for(int i = 0; i < numAlbums(); i++)
    {
      listOfAlbums() -> at(i) -> print();
    }
}

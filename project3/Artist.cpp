#include "Albums.hpp"
#include "ArtistImage.hpp"
#include "Artist.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <string>
#include <sstream>

using namespace std;

Artist::Artist()
{
  _name = "";
  _realName = "";
  _profile = "";
  _artistID = 0;
  _numImages = "";
  cachedProfile = false;
  cachedArtistName = false;
  cachedRealName = false;
  cachedNumImages = false;
  cachedArtistID = false;
}

Artist:: Artist(JSONDataObject *json)
{
  _name = json -> valueForStringAttribute("artist_name");
  _realName = json -> valueForStringAttribute("real_name");
  _profile = json -> valueForStringAttribute("profile");
  _numImages = json -> valueForStringAttribute("num_images");
  _artistID = json -> valueForIntegerAttribute("artist_id");
}

Artist:: ~Artist()
{
}

string Artist:: profile()
{
  if(cachedProfile)
    return _profile;
  cachedProfile = true;
  return _profile = valueForStringAttribute("profile");
}

string Artist:: artistName()
{

  if(cachedArtistName)
    return _name;
  cachedArtistName = true;
  return _name = valueForStringAttribute("artist_name");
}

string Artist:: realName()
{

  if(cachedRealName)
    return _realName;
  cachedRealName = true;
  return _realName = valueForStringAttribute("real_name");
}

string Artist:: numImages()
{

  if(cachedNumImages)
    return _numImages;
  cachedNumImages = true;
  return _numImages = valueForStringAttribute("num_images");
}

unsigned Artist:: artistID()
{
  if(cachedArtistID)
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}




//takes the file and allows it to read the document as an html 
string Artist::htmlString()
{
  string html = "artist Name: " + artistName() + " width: " + to_string(primaryImage() -> width()) + " height: " + to_string(primaryImage() -> height());
  html.append(_primaryImage -> uri());
  html.append("Number of images: " + numImages() + "Profile: " + profile());
  html.append(albums() -> htmlString());
  return html;  
}


void Artist:: print()
{
  cout << "--------ARTIST FILE----------"<< endl;
  cout << "PrimaryImage url: " << primaryImage() -> uri() << endl;
  cout << "Artist id: " << artistID() << endl;
  cout << "Number of Images:  " << numImages() << endl;
  cout << "Profile: " << profile() << endl;
  cout << "Artist name:  " << artistName() << endl;
  cout << "Real name: " << realName() << endl;

}

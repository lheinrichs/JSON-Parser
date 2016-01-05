#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "JSONArray.hpp"
#include "JSONDataObject.hpp"

using namespace std;

JSONArray:: JSONArray()
{
  _listOfDataObjects = new vector<JSONDataObject *>;
}

JSONArray:: ~JSONArray()
{
  _listOfDataObjects -> clear();
}

int JSONArray:: numJSONObjects()
{
  return _listOfDataObjects -> size();
}

void JSONArray:: parseJSONArray(fstream &stream)
{
  char cc[2], prev = ' ';
  cc[1] = '\0';


  if(! (stream >> cc[0]) || cc[0] != '[')
    {
      cout << " -- Expected a brace to start an object, found -> " << string(cc) << " <--." << endl;
      exit(1);
    }
  do{
    JSONDataObject *dItem = jsonObjectNode();
    dItem -> parseFromJSONstream(stream);
    _listOfDataObjects -> push_back(dItem);

    if(! (stream >> cc[0]))
      {
	cout << "--error in read. Expected a comma or a closed-brace." << endl;
	exit(1);
      }
    if(cc[0] != ']' && cc[0] != ',')
      {
	cout << "--Expected a brace to end an object or a command to seperate attributes , found --> " << string(cc) <<  " <--." << endl;
	exit(1);
      }
  }
  while(cc[0] != ']');
}



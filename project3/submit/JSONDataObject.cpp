#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "JSONDataObject.hpp"
#include "JSONDataItem.hpp"
#include "JSONArray.hpp"


using namespace std;

JSONDataObject:: JSONDataObject()
{
  _listOfDataItems = new vector<JSONDataItem*>();
}

JSONDataObject:: ~JSONDataObject()
{
  _listOfDataItems -> clear();
 }

void JSONDataObject:: parseFromJSONstream(fstream &stream)
{
  char cc;
  
  if(!(stream >> cc) || cc != '{')
    {
      cout << "--Expected a curled brace to start, found --> " << cc << " <--." << endl;
      exit(1);
    }
  stream.unget();
  stream >> cc;
  while(cc != '}')
    {
      JSONDataItem *dPair = new JSONDataItem;
      dPair -> parseJSONDataItem(stream);
      _listOfDataItems -> push_back(dPair);
      stream >> cc;
    }
  
}



string JSONDataObject:: valueForStringAttribute(string s)
{
  for(vector<JSONDataItem *>::iterator iter = _listOfDataItems -> begin(); iter != _listOfDataItems -> end(); ++iter)
    {
      if(s == (*iter) -> attribute())
	return (*iter) -> stringValue(); 
	
    }
  
	/*  for(int i = 0; i< _listOfDataItems -> size(); i++)
    {
      JSONDataItem *dItem = _listOfDataItems -> at(i);
      if(dItem -> attribute() == s)
	return dItem -> stringValue();
	}*/
    return "";
}

unsigned int JSONDataObject:: valueForIntegerAttribute(string s)
{
  for(vector<JSONDataItem *>::iterator iter = _listOfDataItems -> begin(); iter != _listOfDataItems -> end(); ++iter)
    {
      if(s == (*iter) -> attribute())
	return (*iter) -> integerValue();
    }
  return 0;
  /*  for(int i = 0; i < _listOfDataItems -> size(); i++)
    {
      JSONDataItem * dItem = _listOfDataItems -> at(i);
      if(dItem->isNumber() && dItem->attribute() == s)
	return dItem->integerValue();
	}*/
}

#ifndef DATAO_HPP
#define DATAO_HPP

#include <vector>
#include <fstream>
#include <string>
#include "JSONDataItem.hpp"

using namespace std;

class JSONDataObject
{
public:
  JSONDataObject();
  ~JSONDataObject();
  vector <JSONDataItem *> *listOfDataItems() const {return _listOfDataItems; }
  void parseFromJSONstream(fstream &stream);
  virtual void print(){}
  
  string valueForStringAttribute(string s);
  unsigned int valueForIntegerAttribute(string s);

private:
  vector <JSONDataItem *> *_listOfDataItems;

};

#endif

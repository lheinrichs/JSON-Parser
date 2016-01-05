#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include "JSONDataObject.hpp"

using namespace std;

class JSONArray
{
public: 
  JSONArray();
  ~JSONArray();
  vector <JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
  virtual JSONDataObject *jsonObjectNode() = 0;
  int numJSONObjects();
  void parseJSONArray(fstream &stream);
  virtual void print() {}

protected:
  vector<JSONDataObject *> *_listOfDataObjects;
};

#endif

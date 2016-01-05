#ifndef DATAI_HPP
#define DATAI_HPP
#include <string>

using namespace std;

class JSONDataItem
{
public:
  JSONDataItem();
  void parseJSONDataItem(fstream &stream);
  string attribute();
  int integerValue();
  string stringValue();
  bool isNumber();
  void print();

private:
  string _attribute, _svalue;
  int _ivalue;
  bool hasReadAnItem, _isNumber;

  string readQuotedString(fstream &stream);

};

#endif

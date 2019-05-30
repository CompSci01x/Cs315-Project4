
#ifndef JSONArray_hpp
#define JSONArray_hpp

#include <stdio.h>
#include <vector>
#include "JSONDataObject.hpp"

class JSONArray
{
public:
    JSONArray() {}
   // ~JSONArray();
    
    virtual JSONDataObject *jsonObjectNode() = 0;

    int numJSONObjects();
    void parseJSONArray(JSONTokenizer *tokenizer);
    
   // virtual void print();
    std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }

    
protected:
    std::vector<JSONDataObject *> *_listOfDataObjects = new std::vector<JSONDataObject *>;
    
};


#endif /* JSONArray_hpp */

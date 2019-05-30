//
//  JSONDataObject.hpp
//  Project 4
//
//  Created by Simple on 11/23/18.
//  Copyright © 2018 Simple. All rights reserved.
//

#ifndef JSONDataObject_hpp
#define JSONDataObject_hpp

#include <stdio.h>
#include <vector>

#include "Pair.hpp"
#include "JSONTokenizer.hpp"


class Pair;

class JSONDataObject
{
public:
    JSONDataObject() {}
   // virtual ~JSONDataObject();
    
    std::vector<Pair *> *listOfDataItems() { return _listOfDataItems; }
    
    void parseDataObject(JSONTokenizer *tokenizer);
    
 //   virtual void print();
    std::string valueForStringAttribute(std::string s);
    int valueForIntegerAttribute(std::string s);
    
private:
    std::vector<Pair *> *_listOfDataItems = new std::vector<Pair *>;
};


#endif /* JSONDataObject_hpp */

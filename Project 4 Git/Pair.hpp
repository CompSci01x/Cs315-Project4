

#ifndef Pair_hpp
#define Pair_hpp

#include <stdio.h>
#include <iostream>
#include "JSONTokenizer.hpp"
#include "JSONDataObject.hpp"

class Tokenizer;
class Pair {
    // represents a entity and its value:
    
public:
    Pair() {}
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, int);
    bool isNumber();  // is the datatype of the value of this entity integer?
    int numberValue();
    std::string stringValue();
    std::string attributeName();
    Pair * parsePair(JSONTokenizer *tokenizer);
    
private:
    std::string _attributeName, _attributeStringValue;
    int _attributeNumberValue;
    bool _isNumber;
    
};


#endif /* Pair_hpp */


#ifndef JSONTokenizer_hpp
#define JSONTokenizer_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "JSONToken.hpp"

using namespace std;

class JSONTokenizer
{
  
public:
    JSONTokenizer(std::string fileName) : inStream(fileName, std::ios::in) {}
    
    JSONToken getToken();
    bool charOfInterest(char );
    
    string assignAttributeString();
    int assignAttributeInt(char);
    string assignAttributeNull(char);
    
    
    
private:
    
    fstream inStream;
    
    
    
};


#endif /* JSONTokenizer_hpp */

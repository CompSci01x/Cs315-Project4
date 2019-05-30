
#ifndef JSONToken_hpp
#define JSONToken_hpp

#include <iostream>

using namespace std;

class JSONToken
{
  
public:
    JSONToken();
    
    bool &isOpenSquareBracket();
    bool &isClosedSquareBracket();
    
    
    bool &isOpenSquigglyBracket();
    bool &isClosedSquigglyBracket();
    
    
    bool &isColon();
    bool &isComma();
    
    bool &isAttributeString();
    bool &isAttributeInt();
    bool &isAttributeNull();
    
    
    bool &endOfFile();
    
    
    string attributeString();
    string attributeNull();
    int attributeInt();
    
    
    void makeNull(string);
    void makeString(string);
    void makeInt (int);
    void print();
    
    
    
private:
    bool _isOpenSquareBracket , _isClosedSquareBracket , _isOpenSquigglyBracket , _isClosedSquigglyBracket , _isColon , _isComma ,
    _isAttributeString , _isAttributeInt , _isAttributeNull , _eof;
    
    string _attributeString , _attributeNull;
    int _attributeInt;
    
};


#include <stdio.h>

#endif /* JSONToken_hpp */

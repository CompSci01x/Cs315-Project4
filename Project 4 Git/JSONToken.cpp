
#include <iostream>
#include <iomanip>
#include "JSONToken.hpp"

//**************************************************************
//
// Constructor
//
//**************************************************************
JSONToken::JSONToken()
{
    _isOpenSquareBracket = false;
    _isClosedSquareBracket = false;

    _isOpenSquigglyBracket = false;
    _isClosedSquigglyBracket = false;

    _isColon = false;
    _isComma  = false;
    
    _isAttributeString = false;
    _isAttributeInt = false;
    
    _isAttributeNull = false;
    
    _eof = false;
    
    _attributeNull = "";
    _attributeString = "";
     _attributeInt = 0;
}


///////////////////////////////////////////////////////////////

bool &JSONToken::isOpenSquareBracket()
{
    return _isOpenSquareBracket;
}

bool &JSONToken::isClosedSquareBracket()
{
    return _isClosedSquareBracket;
}


///////////////////////////////////////////////////////////////


bool &JSONToken::isOpenSquigglyBracket()
{
    return _isOpenSquigglyBracket;
}

bool &JSONToken::isClosedSquigglyBracket()
{
    return _isClosedSquigglyBracket;
}


///////////////////////////////////////////////////////////////

bool &JSONToken::isColon()
{
    return _isColon;
}

bool &JSONToken::isComma()
{
    return _isComma;
}


///////////////////////////////////////////////////////////////


bool &JSONToken::isAttributeNull()
{
    return _isAttributeNull;
}


bool &JSONToken::isAttributeString()
{
    return _isAttributeString;
}

bool &JSONToken::isAttributeInt()
{
    return _isAttributeInt;
}



///////////////////////////////////////////////////////////////


string JSONToken::attributeNull()
{
    return _attributeNull;
}

string JSONToken::attributeString()
{
    return _attributeString;
}

int JSONToken::attributeInt()
{
    return _attributeInt;
}


///////////////////////////////////////////////////////////////


void JSONToken::makeString(string s)
{
    _attributeString = s;
    _isAttributeString = true;
}

void JSONToken::makeInt (int x)
{
    _attributeInt = x;
    _isAttributeInt = true;
}

void JSONToken::makeNull (string n)
{
    _attributeNull = n;
    _isAttributeNull = true;
}

///////////////////////////////////////////////////////////////

bool &JSONToken::endOfFile()
{
    return _eof;
}


///////////////////////////////////////////////////////////////



//**************************************************************
//
// This function is only for checking if the Tokenizer is
//  working properly (otherwise it is not used).
//
//**************************************************************
void JSONToken::print()
{
    
    if (isOpenSquareBracket())
    {
        cout << "[" << endl;
    }
    
    else if (isClosedSquareBracket())
    {
        cout << "]" << endl;
    }
    
    else if (isOpenSquigglyBracket())
    {
        cout << "{" << endl;
    }
    
    else if (isClosedSquigglyBracket())
    {
        cout << "}" << endl;
    }
    
    else if (isColon())
    {
        cout << ":" << endl;
    }
    
    else if (isComma())
    {
        cout << "," << endl;
    }
    
    else if (isAttributeString() )
    {
        cout << attributeString() << endl;
    }
    
    else if (isAttributeNull() )
    {
        cout << attributeNull() << endl;
    }
    
    else if (isAttributeInt() )
    {
        cout << attributeInt() << endl;
    }
    else
    {
        std::cout << "Unknown Token\n";
    }
    
    
}




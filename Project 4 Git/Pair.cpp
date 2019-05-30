
#include "Pair.hpp"


//**************************************************************
//
// Constructor for string attributes
//
//**************************************************************

Pair::Pair(std::string attributeName, std::string attributeValue)
{
    _attributeName = attributeName;
    _attributeStringValue = attributeValue;
    
    _isNumber = false;
}


//**************************************************************
//
// Constructor for number (int) attributes
//
//**************************************************************

Pair::Pair(std::string attributeName, int attributeNumValue)
{
    _attributeName = attributeName;
    _attributeNumberValue = attributeNumValue;
    _isNumber = true;
}


//////////////////////////////////////////////////////////////////////

std::string Pair::stringValue()
{
    return _attributeStringValue;
    
}

//////////////////////////////////////////////////////////////////////

std::string Pair::attributeName()
{
    return _attributeName;
}

//////////////////////////////////////////////////////////////////////

bool Pair::isNumber()
{
    return _isNumber;
}

//////////////////////////////////////////////////////////////////////

int Pair::numberValue()
{
    return _attributeNumberValue;
}

//////////////////////////////////////////////////////////////////////


Pair * Pair::parsePair(JSONTokenizer *tokenizer)
{
    // get next token
    JSONToken token = tokenizer->getToken();
    
    JSONToken nxtToken = tokenizer->getToken();
 
    
    if (token.isAttributeString())
    {
        if ( nxtToken.isColon() )
        {
            nxtToken = tokenizer->getToken();
            
            if (nxtToken.isAttributeNull())
            {
                Pair *pair = new Pair(token.attributeString() , nxtToken.attributeNull() );
                return pair;
            }
            
            else if (nxtToken.isAttributeInt())
            {
                Pair *pair = new Pair(token.attributeString() , nxtToken.attributeInt());
                return pair;
            }
            else if (nxtToken.isAttributeString())
            {
                Pair *pair = new Pair(token.attributeString() , nxtToken.attributeString());
                return pair;
            }
            
            
        }
        
    }
    
    
    std::cout << "Error: Pair::parsePair(): Found Unknown Token" << std::endl;
    std::cout << "token: ";
    token.print();
    std::cout << "nxtToken: ";
    nxtToken.print();
    std::cout << "Terminating..." << std::endl;
    exit(1);
    
}

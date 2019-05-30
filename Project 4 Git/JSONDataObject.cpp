
#include "JSONDataObject.hpp"



void JSONDataObject::parseDataObject(JSONTokenizer *tokenizer)
{
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open squiggly brace.
    JSONToken token = tokenizer->getToken();
    
    if( ! token.isOpenSquigglyBracket() )
    {
        cout << "Error: JSONDataObject::parseDataObject: Expected an open brace, but found" << endl;
        token.print();
        cout << "Terminating..." << endl;
        exit(1);
    }
    
    do {
        
        Pair *pair = new Pair();
        pair = pair->parsePair(tokenizer);
       
        _listOfDataItems->push_back(pair);
        
        token = tokenizer->getToken();
        
        } while( token.isComma() );  // after having read a pair, we expect a comma
    
    
    // So, we didn't find a comma. Then, it must be a close squiggly brace.
    
    if( ! token.isClosedSquigglyBracket() )
    {
        cout << "Error: JSONDataObject::parseDataObject: Expected an close brace, but found" << endl;
        token.print();
        cout << "Terminating..." << endl;
        exit(1);
    }
    
}


std::string JSONDataObject::valueForStringAttribute(std::string attributeName)
{
        for (int x = 0; x < _listOfDataItems->size() ; x++)
        {
            if (_listOfDataItems->at(x)->attributeName() == attributeName)
                return _listOfDataItems->at(x)->stringValue();
        }
        
        return " ";
}

int JSONDataObject::valueForIntegerAttribute(std::string attributeName)
{
    for (int x = 0; x < _listOfDataItems->size() ; x++)
    {
        if (_listOfDataItems->at(x)->attributeName() == attributeName)
            return _listOfDataItems->at(x)->numberValue();
    }
    
    return 0;
}

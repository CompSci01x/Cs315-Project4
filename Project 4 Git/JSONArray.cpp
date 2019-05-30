

#include "JSONArray.hpp"

void JSONArray::parseJSONArray(JSONTokenizer *tokenizer)
{
    JSONToken token = tokenizer->getToken();
    
    if( ! token.isOpenSquareBracket() )
    {
          // write an error message and exit
        cout << "Error: JSONArray::parseJSONArray: Expected an open square brace, but found" << endl;
        token.print();
        cout << "Terminating..." << endl;
        exit(1);
    }
    
        
        do {
            JSONDataObject *dItem = jsonObjectNode();
            
            dItem->parseDataObject(tokenizer);
            _listOfDataObjects->push_back(dItem);
            
            token = tokenizer->getToken();
            
                if( ! token.isClosedSquareBracket() && ! token.isComma() )
                {
                // print an error message and exit
                cout << "Error: JSONArray::parseJSONArray: Found an unknown token:" << endl;
                token.print();
                cout << "Terminating..." << endl;
                exit(1);
                }
            
            } while( ! token.isClosedSquareBracket() );
    
}


#include "JSONTokenizer.hpp"


//**************************************************************
//
// Finds char of intrest
//
//**************************************************************
bool JSONTokenizer::charOfInterest(char c)
{
    
    if (c == '[')
    {
        return true;
    }
    
    else if (c == '{')
    {
        return true;
    }
    
    else if (c == '"' && inStream.peek() == '"')
    {
        return true;
    }
    
    else if (c == '"' )
    {
        return true;
    }
    else if ( isalnum(c) )
    {
        return true;
    }
    
    else if (c == ':')
    {
        return true;
    }
    
    else if (c == ',')
    {
        return true;
    }
    
    else if (c == '}')
    {
        return true;
    }
    
    else if (c == ']')
    {
        return true;
    }
    
    
    return false;
}


//**************************************************************
//
// Runs through the JSON file and gets Tokens
//
//**************************************************************
JSONToken JSONTokenizer::getToken()
{
    char c;
    
    while (inStream.get(c) && !charOfInterest(c))
    {
        
    }
 
    JSONToken token;
    
    if (inStream.eof())
    {
        token.endOfFile() = true;
        return token;
    }

    if (c == '[')
    {
        token.isOpenSquareBracket() = true;
        return token;
    }
    
    else if (c == '{')
    {
        token.isOpenSquigglyBracket() = true;
        return token;
    }
    
    else if (c == '"' && inStream.peek() == '"')
    {
        // to essentially skip the clossing "
        inStream.get(c);
        
        token.makeString("");
        return token;
    }
    
    else if (c == '"' )
    {
        
        token.makeString( assignAttributeString() );
        return token;
    }
    
    else if ( isalnum(c) )
    {
        
        if (c == 'n' && inStream.peek() == 'u')
        {
            token.makeNull( assignAttributeNull(c) );
            token.isAttributeNull() = true;
            return token;
        }
        
        if (isdigit(c))
        {
                token.makeInt( assignAttributeInt(c) );
                token.isAttributeInt() = true;
                return token;
            }
        
    }
    
    else if (c == '}')
    {
        token.isClosedSquigglyBracket() = true;
        return token;
    }
    
    else if (c == ']')
    {
        token.isClosedSquareBracket() = true;
        return token;
    }
    
    else if (c == ':')
    {
        token.isColon() = true;
        return token;
        
    }
    
    else if (c == ',')
    {
        token.isComma() = true;
        return token;
    }
    
    
    else
    {
        cout << "Unkown Token\n\n";
    }
    
    return token;
    
}


//**************************************************************
//
// Assigns the attribute string value
//
//**************************************************************
string JSONTokenizer::assignAttributeString()
{
    // stores a char read from input file
    char c;
    
    // will store the attribute string which could be either an attri name or attri string value
    string attributeString = "";
    
    do
    {
        inStream.get(c);
        
        if ( c == '\\' && inStream.peek() == '"' )
        {
                inStream.get(c);
            
                while (c != '\\' && inStream.peek() != '"')
                {
                    attributeString += c;
                    inStream.get(c);
                }
            
            if (c != '\\' && inStream.peek() == '"')
            {
                attributeString += c;
                inStream.get(c);
                return attributeString;
            }
            else if (c == '\\' && inStream.peek() == '"')
            {
                // right now c = (\) so get(c)
                // to get the double quotes (")
                inStream.get(c);
            }
        
        }
        else if (c == '\\' && isalnum(inStream.peek()))
        {
            while (c == '\\')
            {
                // right now c is the backslash char (\)
                // so get the next char to skip the char that follows immediately after the \ char
                inStream.get(c);
                
                // check if the next char is a backslash char (\)
                if (inStream.peek() != '\\')
                {
                    // if the next char is not a \ then clear c ( c = ' ' ) and break out of the loop
                    c = ' ';
                    break;
                }
              
                // otherwise get the next char which is the backslash char \ and run through the loop again
                inStream.get(c);
            }
        }
        
        attributeString += c;
        
    }while ( inStream.peek() != '"');
    
    // To get the closing " essentially skipping it
        inStream.get(c);
    
    return attributeString;
}


//**************************************************************
//
// Assigns the attribute number(int) value
//
//**************************************************************
int JSONTokenizer::assignAttributeInt(char c)
{
    // will temporarily store the int value as a string
    string temp = "";
    
    // store the current int (which is currently treated as a char) in temp
    temp+=c;
    
    // check if the next char is a digit
    if (isdigit(inStream.peek()))
    {
    // if so concatinate the int (which is currently treated as a char) onto temp and keep going until the next char is not an int
        do
        {
            inStream.get(c);
            temp+=c;
            
        }while(isdigit(inStream.peek() ) );
        
    }
    
    return std::stoi(temp);
}



//**************************************************************
//
// Assigns the the null value as a string
//
//**************************************************************
string JSONTokenizer::assignAttributeNull(char c)
{
    // will store the null attribute value as a "null" string
    string n = "";
    
    // adds the first char "n" to the string
    n += c;
    
    // keeps going until the string n contains "null"
    do
    {
        inStream.get(c);
        n += c;
        std::cout << n;
        
    }while (n != "null");
    
    return n;
}





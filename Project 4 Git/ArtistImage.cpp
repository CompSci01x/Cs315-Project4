
#include "ArtistImage.hpp"

unsigned    ArtistImage::width()
{
    if (cachedWidth)
        return _width;
    
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}


unsigned    ArtistImage::height()
{
    if (cachedHeight)
        return _height;
    
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}


unsigned    ArtistImage::artistID()
{
    if (cachedArtistID)
        return _artistID;
    
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}



std::string    ArtistImage::type()
{
    if (cachedType)
        return _type;
    
    cachedType = true;
    return _type = valueForStringAttribute("type");
}


std::string    ArtistImage::uri()
{
    if (cachedURi)
        return _uri;
    
    cachedURi = true;
    return _uri = valueForStringAttribute("uri");
}





std::string ArtistImage::htmlString(Pair *pair)
{
    std::string htmlString;
    
    htmlString = "<li><p>" + pair->attributeName() + ": ";
    
    if (pair->attributeName() == "width")
        htmlString += std::to_string(width());
    
    else if (pair->attributeName() == "height")
        htmlString += std::to_string(height());
    
    else if (pair->attributeName() == "artist_id")
        htmlString += std::to_string(artistID());
        
    else if (pair->attributeName() == "type")
        htmlString += type();
    
    else if (pair->attributeName() == "uri")
        htmlString += uri();
    
    
    else
    {
        std::cout << "Error in std::string ArtistImage::htmlString(Pair *)\nUnknown AttributeName.\nTerminating...\n";
        exit(1);
    }
    
    htmlString += "</p></li>";
    
    return htmlString;
    
}

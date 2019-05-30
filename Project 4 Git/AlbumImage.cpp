

#include "AlbumImage.hpp"

unsigned    AlbumImage::width()
{
    if (cachedWidth)
        return _width;
    
    cachedWidth = true;
    return _width = valueForIntegerAttribute("width");
}


unsigned    AlbumImage::height()
{
    if (cachedHeight)
        return _height;
    
    cachedHeight = true;
    return _height = valueForIntegerAttribute("height");
}


unsigned    AlbumImage::albumID()
{
    if (cachedAlbumID)
        return _albumID;
    
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}



std::string    AlbumImage::type()
{
    if (cachedType)
        return _type;
    
    cachedType = true;
    return _type = valueForStringAttribute("type");
}


std::string    AlbumImage::uri()
{
    if (cachedURi)
        return _uri;
    
    cachedURi = true;
    return _uri = valueForStringAttribute("uri");
}



std::string AlbumImage::htmlString(Pair *pair)
{
    std::string htmlString;
    
    htmlString = "<li><p>" + pair->attributeName() + ": ";
    
    if (pair->attributeName() == "width")
        htmlString += std::to_string(width());
    
    else if (pair->attributeName() == "height")
        htmlString += std::to_string(height());
    
    else if (pair->attributeName() == "album_id")
        htmlString += std::to_string(albumID());
    
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

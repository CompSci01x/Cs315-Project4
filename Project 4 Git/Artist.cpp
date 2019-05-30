
#include <stdio.h>
#include "Artist.hpp"

unsigned int Artist:: artistID()
{
    if( cachedArtistID )
        return _artistID;
    
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}


std::string Artist::profile()
{
    if( cachedProfile )
        return _profile;
    
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}


std::string Artist::artistName()
{
    if( cachedName )
        return _name;
    
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
    
}

std::string Artist::realName()
{
    if( cachedRealName )
        return _realName;
    
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}

std::string Artist::numImages()
{
    if( cachedNumImages )
        return _numImages;
    
    cachedNumImages = true;
    return _numImages = valueForStringAttribute("num_images");
    
}



std::string Artist::htmlString(Pair *pair)
{    
    std::string htmlString;
    
    htmlString = "<li><p>" + pair->attributeName() + ": ";
    
    if (pair->attributeName() == "artist_name")
        htmlString += artistName();
    
    else if (pair->attributeName() == "real_name")
        htmlString += realName();
    
    else if (pair->attributeName() == "artist_id")
    {
        htmlString += std::to_string(artistID());
    }
    
    else if (pair->attributeName() == "profile")
        htmlString += profile();
    
    else if (pair->attributeName() == "num_images")
    {
        htmlString += numImages();
    }
    
    
    else
    {
       std::cout << "Error in std::string Artist::htmlString(std::string attributeName)\nUnknown AttributeName.\nTerminating...\n";
        exit(1);
    }
    
    htmlString += "</p></li>";
    
    return htmlString;
    
}

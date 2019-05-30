
#include <stdio.h>
#include "Track.hpp"

unsigned int Track:: albumID()
{
    if( cachedAlbumID )
        return _albumID;
    
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
    
}

std::string Track:: artistName()
{
    
    if( cachedAritstName )
        return _artistName;
    
    cachedAritstName = true;
    return _artistName = valueForStringAttribute("artist_name");
    
}

std::string Track::title()
{
    
    if( cachedTitle )
        return _title;
    
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
}


std::string Track::albumName()
{
    if( cachedAlbumName )
        return _albumName;
    
    cachedAlbumName = true;
    return _albumName = valueForStringAttribute("album_name");
    
}


std::string Track::duration()
{
    if( cachedDuration )
        return _duration;
    
    cachedDuration = true;
    return _duration = valueForStringAttribute("duration");
}


std::string Track::position()
{
    if( cachedPosition )
        return _position;
    
    cachedPosition = true;
    return _position = valueForStringAttribute("position");

}




std::string Track::htmlString(Pair *pair)
{
    std::string htmlString;
    htmlString = "<li><p>" + pair->attributeName() + ": ";
    
    if (pair->attributeName() == "artist_name")
        htmlString += artistName();
    
    else if (pair->attributeName() == "title")
        htmlString += title();
    
    else if (pair->attributeName() == "album_name")
        htmlString += albumName();
    
    else if (pair->attributeName() == "album_id")
    {
        htmlString += std::to_string(albumID());
    }
    
    else if (pair->attributeName() == "duration")
        htmlString += duration();
    
    else if (pair->attributeName() == "position")
        htmlString += position();
    
    
    else
    {
        std::cout << "Error in std::string Track::htmlString(std::string attributeName)\nUnknown AttributeName.\nTerminating...\n";
        exit(1);
    }
    
    htmlString += "</p></li>";
    
    return htmlString;
    
}


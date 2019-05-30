
#include <stdio.h>
#include "Album.hpp"


unsigned int Album:: albumID()
{
    if( cachedAlbumID )
        return _albumID;
    
    cachedAlbumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
    
}

unsigned Album::artistID()
{
    if( cachedArtistID )
        return _artistID;
    
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");

}


unsigned int Album::numImages()
{
    if( cachedNumImages )
        return _numImages;
    
    cachedNumImages = true;
    return _numImages = valueForIntegerAttribute("num_images");
}

unsigned int Album:: numTracks()
{
    if( cachedNumTracks )
        return _numTracks;
    
    cachedNumTracks = true;
    return _numTracks = valueForIntegerAttribute("num_tracks");

}


std::string Album::year()
{
    if( cachedYear )
        return _year;
    
    cachedYear = true;
    return _year = valueForStringAttribute("year");

}

std::string Album::genres()
{
    if( cachedGenres )
        return _genres;
    
    cachedGenres = true;
    return _genres = valueForStringAttribute("genres");

}


std::string Album::title()
{
    if( cachedTitle )
        return _title;
    
    cachedTitle = true;
    return _title = valueForStringAttribute("title");
    
}




std::string Album::htmlString(Pair *pair)
{
    std::string htmlString;
    
    htmlString =  "<li><p>" + pair->attributeName() + ": ";
    
    if (pair->attributeName() == "album_id")
    {
        htmlString += std::to_string(albumID());
    }
    else if (pair->attributeName() == "artist_id")
    {
        htmlString += std::to_string(artistID());
    }
    
    else if (pair->attributeName() == "num_tracks")
    {
        htmlString += std::to_string(numTracks());
    }
    
    else if (pair->attributeName() == "year")
    {
        htmlString += year();
    }
    
    else if (pair->attributeName() == "genres")
        htmlString += genres();
    
    else if (pair->attributeName() == "num_images")
    {
        htmlString += std::to_string(numImages());
    }
    
    else if (pair->attributeName() == "title")
        htmlString += title();
    
    else
    {
        std::cout << "Error in std::string Album::htmlString(std::string attributeName)\nUnknown AttributeName.\nTerminating...\n";
        exit(1);
    }
    
    htmlString += "</p></li>";
    
    return htmlString;
    
}

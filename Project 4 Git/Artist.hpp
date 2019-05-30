
#ifndef Artist_hpp
#define Artist_hpp

#include<fstream>
#include<cstring>
#include <vector>

#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include "JSONDataObject.hpp"
#include "Albums.hpp"
#include "ArtistImage.hpp"

class Albums;

class Artist: public JSONDataObject
{
public:
    Artist(): cachedName(false), cachedRealName(false), cachedProfile(false), cachedNumImages(false), cachedArtistID(false) {}
   // ~Artist();
    
     unsigned    artistID();
    std::string profile();
    std::string artistName();
    std::string realName();
    std::string numImages();  // since it's a string in the JSON file
   
    

    
    // the following 4 function-prototypes are new to this project.
    
    void setAlbums(Albums *albums) { _albums = albums; }
    Albums *albums() { return _albums; }
    
    ArtistImage *&primaryImage()       { return _primaryImage;   }
    ArtistImage *&secondaryImage()     { return _secondaryImage; }

    
    void print();
    std::string htmlString(Pair *);
    
    
private:
    
    std::string _name, _realName, _profile, _numImages;
    unsigned _artistID;
    bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;
    
    // the following 3 variables are new to this project.
    ArtistImage *_primaryImage, *_secondaryImage;
    Albums *_albums; // albums is a JSONArray and thus has a vector< JSONDataObj * >
};

#endif /* Artist_hpp */


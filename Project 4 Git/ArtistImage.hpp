

#ifndef ArtistImage_hpp
#define ArtistImage_hpp

#include <stdio.h>
#include <vector>
#include<fstream>
#include<cstring>

#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include "JSONDataObject.hpp"

class ArtistImage: public JSONDataObject
{
public:
    ArtistImage(): cachedWidth(false), cachedHeight(false), cachedArtistID(false), cachedType(false), cachedURi(false) {}
  
    
    unsigned    width();
    unsigned    height();
    unsigned    artistID();
    std::string type();
    std::string uri();
    
    
    void print();
    std::string htmlString(Pair *);
    
    
private:
    std::string _type, _uri;
    unsigned _width, _height, _artistID;
    bool cachedWidth, cachedHeight, cachedArtistID, cachedType, cachedURi;

};


#endif /* ArtistImage_hpp */

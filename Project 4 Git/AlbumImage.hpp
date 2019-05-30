
#ifndef AlbumImage_hpp
#define AlbumImage_hpp

#include <stdio.h>


#include <stdio.h>
#include <vector>
#include<fstream>
#include<cstring>

#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include "JSONDataObject.hpp"

class AlbumImage: public JSONDataObject
{
public:
    AlbumImage(): cachedWidth(false), cachedHeight(false), cachedAlbumID(false), cachedType(false), cachedURi(false) {}
    
    unsigned    width();
    unsigned    height();
    unsigned    albumID();
    std::string type();
    std::string uri();
    
    
    void print();
    std::string htmlString(Pair *);
    
    
private:
    std::string _type, _uri;
    unsigned _width, _height, _albumID;
    bool cachedWidth, cachedHeight, cachedAlbumID, cachedType, cachedURi;
  
};

#endif /* AlbumImage_hpp */

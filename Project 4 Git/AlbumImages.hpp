

#ifndef AlbumImages_hpp
#define AlbumImages_hpp

#include <stdio.h>

#include "JSONArray.hpp"
#include "AlbumImage.hpp"
#include "JSONDataObject.hpp"

class AlbumImages: public JSONArray
{
public:
    AlbumImages() {}
    //  ~Artists();
    
    void loadAlbumImagesFromFile(std::string fileName);     // this will create an ArtistImages Entity []
    
    JSONDataObject *jsonObjectNode() { return new AlbumImage();  } // this creates an Artist Instance
    
    
    void createAlbumImagesHTMLFile(std::fstream &);
    void replaceWithHTMLList(std::fstream &);
    
    
    int numAlbumImages()    {return int(listOfAlbumImages()->size()); } // what does this do?
    
    
    std::string htmlString(); // ???
    
    AlbumImage* setPrimaryAlbumImageForAlbums(int);
    AlbumImage* setSecondaryAlbumImageForAlbums(int);
    
    
    std::vector<AlbumImage *> *listOfAlbumImages() { return (std::vector<AlbumImage *> *) _listOfDataObjects; }     // holds the ArtistImg Obj's {},{},{}
    
    void runAsserts();  // used for checking the integrity of this class.
};



#endif /* AlbumImages_hpp */

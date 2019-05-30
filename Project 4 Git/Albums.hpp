//
//  Albums.hpp
//  Project 4
//
//  Created by Simple on 11/23/18.
//  Copyright © 2018 Simple. All rights reserved.
//

#ifndef Albums_hpp
#define Albums_hpp

#include <stdio.h>
#include <vector>

#include "JSONArray.hpp"
#include "Album.hpp"
#include "JSONDataObject.hpp"
#include "AlbumImages.hpp"

class Albums: public JSONArray
{
public:
    Albums() {}
  //  ~Albums();
    
    int numAlbums()     {return int(listOfAlbums()->size());}
    void addAlbum(Album *album) {_listOfDataObjects->push_back(album);}
    Album *albumWithID(unsigned int aID);
    void loadAlbumsFromFile(std::string fileName);
    
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Album();  }
    
    
    Albums *albumsForArtistWithID(int artistID);
    
    
    void createAlbumHTMLFile(std::fstream &);
    void replaceWithHTMLList(std::fstream &);
    
        void setTracksForAlbums(Tracks *tracks);
    void setImagesForAlbums(AlbumImages *albumImages);

    
    std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.
};
#endif /* Albums_hpp */

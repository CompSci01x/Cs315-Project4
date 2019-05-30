//
//  ArtistImages.hpp
//  Project 4
//
//  Created by Simple on 11/23/18.
//  Copyright © 2018 Simple. All rights reserved.
//

#ifndef ArtistImages_hpp
#define ArtistImages_hpp

#include <stdio.h>

#include "JSONArray.hpp"
//#include "Artist.hpp"
#include "ArtistImage.hpp"
#include "JSONDataObject.hpp"

class ArtistImages: public JSONArray
{
public:
    ArtistImages() {}
    //  ~Artists();
    
    void loadArtistImagesFromFile(std::string fileName);     // this will create an ArtistImages Entity []
    
    JSONDataObject *jsonObjectNode() { return new ArtistImage();  } // this creates an ArtistImage Instance
    
    
    void createArtistImagesHTMLFile(std::fstream &);
    void replaceWithHTMLList(std::fstream &);
    
    
    int numArtistImages()   { return int(listOfArtistImages()->size()); }
    
        
    ArtistImage* setPrimaryArtistImageForArtists(int);
    ArtistImage* setSecondaryArtistImageForArtists(int);
    

    
    std::vector<ArtistImage *> *listOfArtistImages() { return (std::vector<ArtistImage *> *) _listOfDataObjects; }     // holds the ArtistImg Obj's {},{},{}
    
    void runAsserts();  // used for checking the integrity of this class.
};


#endif /* ArtistImages_hpp */

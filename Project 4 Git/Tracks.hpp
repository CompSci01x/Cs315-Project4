//
//  Tracks.hpp
//  Project 4
//
//  Created by Simple on 11/23/18.
//  Copyright © 2018 Simple. All rights reserved.
//

#ifndef Tracks_hpp
#define Tracks_hpp

#include <stdio.h>

#include "JSONArray.hpp"
#include "Track.hpp"
#include "JSONDataObject.hpp"

class Tracks: public JSONArray
{
public:
    Tracks() {}
  //  ~Tracks();
    
    int numTracks()     {return int(listOfTracks()->size());}
    
    void addTrack(Track *track)     {_listOfDataObjects->push_back(track);}
    Track *trackWithID(unsigned int aID);
    
    void loadTracksFromFile(std::string fileName);
    
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Track();  }
    
    
    Tracks *tracksForAlbumWithID(int albumID);
    void setTracksForAlbums(Tracks *tracks);

    
    void createTrackHTMLFile(std::fstream &);
    void replaceWithHTMLList(std::fstream &);
    
    
    std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.
};

#endif /* Tracks_hpp */

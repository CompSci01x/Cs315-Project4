
#ifndef Artists_hpp
#define Artists_hpp

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "JSONArray.hpp"
#include "Artist.hpp"
#include "JSONDataObject.hpp"
#include "ArtistImages.hpp"
#include "Album.hpp"
#include "Track.hpp"

class Artists: public JSONArray
{
public:
    Artists() {}
  //  ~Artists();
    
    void loadArtistsFromFile(std::string fileName);     // this will create an Artist Entity []
    //void loadArtistsFromFile ()
    
    JSONDataObject *jsonObjectNode() { return new Artist();  } // this creates an Artist Instance

    
    void createArtistHTMLFile(std::fstream &);
    void replaceWithHTMLList(std::fstream &);
    
    
    int numArtists()    {return int(listOfArtists()->size());}
    
    void addArtist(Artist *artist);     // what does this do?
    
    Artist *artistWithID(unsigned int aID);     // what does this do?
    
    
    std::string htmlString(); // ???
    
    
    
    void setAlbumsAndTracksForArtists(Albums * , Tracks *);
    void setArtistAndAlbumImages(ArtistImages *, AlbumImages *);
    
    void createMasterHTMLFile(std::fstream &);
    void replaceWithMasterHTMLList(std::fstream &);
    
    void createAlbumsSubDirectory();
  //  void createAlbumsHTMLFile(std::fstream &);

    
    
    void setAlbumsForArtists(Albums *albums);
    void setImagesForArtists(ArtistImages *);
    
    std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }     // holds the Artist Obj's {},{},{}
    
    void runAsserts();  // used for checking the integrity of this class.
};

#endif /* Artists_hpp */

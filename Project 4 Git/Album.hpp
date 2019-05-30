
#ifndef Album_hpp
#define Album_hpp

#include<fstream>
#include<cstring>
#include <vector>

#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include "JSONDataObject.hpp"
#include "Tracks.hpp"
#include "AlbumImage.hpp"

class Pair;

class Album: public JSONDataObject
{
public:
    Album(): cachedTitle(false), cachedGenres(false), cachedYear(false), cachedAlbumID(false), cachedArtistID(false), cachedNumImages(false), cachedNumTracks(false) {}
  //  ~Album();
    
    unsigned albumID();
    unsigned artistID();
    unsigned numImages();
    unsigned numTracks();
    std::string year();
    std::string title();
    std::string genres();
    
    void setTracks(Tracks *tracks) {_tracks = tracks;}
   // void setArtist(Artist *artist) {_artist = artist;}
   // Artist *artist() {return _artist;}
    Tracks *tracks()  { return _tracks; }

    AlbumImage *&primaryImage() { return _primaryAlbumImage;   }
    AlbumImage *&secondaryImage()  { return _secondaryAlbumImage; }

    void print();
    std::string htmlString(Pair *);



private:
    std::string _title, _genres, _year;
    unsigned _albumID , _artistID , _numImages , _numTracks;
    bool cachedTitle, cachedGenres, cachedYear, cachedAlbumID ,cachedArtistID , cachedNumImages, cachedNumTracks;
    
    // the following 3 variables are new to this project.
    
    AlbumImage *_primaryAlbumImage, *_secondaryAlbumImage;
    Tracks *_tracks;
   // Artist *_artist;
    
};


#endif /* Album_hpp */


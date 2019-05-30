#ifndef Track_hpp
#define Track_hpp

#include<fstream>
#include<cstring>
#include <vector>

#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include "JSONDataObject.hpp"

class Pair;
class JSONDataObject;

class Track: public JSONDataObject
{
    
public:
    Track(): cachedAlbumID(false), cachedAritstName(false), cachedTitle(false), cachedAlbumName(false), cachedDuration(false), cachedPosition(false) {}
  //  ~Track();
    
    unsigned int albumID();
    std::string artistName();
    std::string title();
    std::string albumName();
    std::string duration();
    std::string position();

    
    void print();
    std::string htmlString(Pair *);
    
private:
    std::string _artistName, _title, _albumName, _duration , _position;
    unsigned _albumID;
    bool cachedAlbumID, cachedAritstName , cachedTitle , cachedAlbumName, cachedDuration, cachedPosition;
    
};





#endif /* Track_hpp */

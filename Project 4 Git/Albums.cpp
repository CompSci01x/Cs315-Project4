

#include "Albums.hpp"
#include "Album.hpp"

void Albums::loadAlbumsFromFile(std::string albumsFileName)
{
    JSONTokenizer *tokenizer = new JSONTokenizer(albumsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}



void Albums::createAlbumHTMLFile(std::fstream &htmlTemplateFile)
{
    fstream HTMLFile ("Albums.html" , std::ios::out );
    
    std::string readLine;
    std::string marker = "<% albums %>";
    
    while (htmlTemplateFile)
    {
        // get a line from the template file
        getline(htmlTemplateFile , readLine);
        
        // check if its the marker if so replace it with HTML list otherwise add the line to "Album.html"
        if (readLine == marker)
            replaceWithHTMLList(HTMLFile);
        else
            HTMLFile << readLine << std::endl;
    }
    
    htmlTemplateFile.close();
    HTMLFile.close();
}


void Albums::replaceWithHTMLList(std::fstream &HTMLFile)
{
    HTMLFile << "<ol>" << std::endl;
    
    // outer loop goes through earch Album obj
    for (int x = 0; x < listOfAlbums()->size() ; x++)
    {
        HTMLFile <<  "<li><p>" << listOfAlbums()->at(x)->title() << "</p>" << std::endl;
        HTMLFile << "<ul>" << std::endl;
        
        // inner loop goes through the attribute pairs of the Album obj
        for (int y = 0 ; y < listOfAlbums()->at(x)->listOfDataItems()->size() ; y++)
        {
            // get an Album obj
            Album *albumIns = listOfAlbums()->at(x);
            
            // get a pair of attribute values from the Album obj
            Pair *pair = albumIns->listOfDataItems()->at(y);
            
            HTMLFile << albumIns->htmlString(pair) << std::endl;
            
        }
        
        HTMLFile << "</ul>" << std::endl;
        HTMLFile << "</li>" << std::endl;
        
    }
    
    HTMLFile << "</ol>" << std::endl;
}


Albums * Albums::albumsForArtistWithID(int artistID)
{
    Albums *albumsForArtist = new Albums();
    
    //search through Albums entity and will return a new Albums Entity which will store the albumsForArtistWithID
    for (int x = 0 ; x < numAlbums() ; x++)
    {
        if (listOfAlbums()->at(x)->artistID() == artistID)
            albumsForArtist->addAlbum(listOfAlbums()->at(x));
    }
    
    return albumsForArtist;
}



void Albums::setTracksForAlbums(Tracks *tracks)
{
    for (int x = 0; x < numAlbums(); x++)
    {
        int albumID = listOfAlbums()->at(x)->albumID();
        
        if (listOfAlbums()->at(x)->albumID() == albumID)
        listOfAlbums()->at(x)->setTracks(tracks->tracksForAlbumWithID(albumID));
    }
    
}


void Albums::setImagesForAlbums(AlbumImages *albumImages)
{
    for (int x = 0; x < numAlbums(); x++)
    {
        int albumID = listOfAlbums()->at(x)->albumID();
        listOfAlbums()->at(x)->primaryImage() = albumImages->setPrimaryAlbumImageForAlbums(albumID);
        listOfAlbums()->at(x)->secondaryImage() = albumImages->setSecondaryAlbumImageForAlbums(albumID);
    }
    
}

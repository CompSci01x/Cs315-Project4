
#include "Tracks.hpp"


void Tracks::loadTracksFromFile(std::string tracksFileName)
{
    JSONTokenizer *tokenizer = new JSONTokenizer(tracksFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}



void Tracks::createTrackHTMLFile(std::fstream &htmlTemplateFile)
{
    fstream HTMLFile ("Tracks.html" , std::ios::out );
    
    std::string readLine;
    std::string marker = "<% tracks %>";
    
    while (htmlTemplateFile)
    {
        // get a line from the template file
        getline(htmlTemplateFile , readLine);
        
        // check if its the marker if so replace it with HTML list otherwise add the line to "Track.html"
        if (readLine == marker)
            replaceWithHTMLList(HTMLFile);
        else
            HTMLFile << readLine << std::endl;
    }
    
    htmlTemplateFile.close();
    HTMLFile.close();
}


void Tracks::replaceWithHTMLList(std::fstream &HTMLFile)
{
    HTMLFile << "<ol>" << std::endl;
    
    // outer loop goes through earch Track obj
    for (int x = 0; x < listOfTracks()->size() ; x++)
    {
        HTMLFile <<  "<li><p>" << listOfTracks()->at(x)->title() << "</p>" << std::endl;
        HTMLFile << "<ul>" << std::endl;
        
        // inner loop goes through the attribute pairs of the Track obj
        for (int y = 0 ; y < listOfTracks()->at(x)->listOfDataItems()->size() ; y++)
        {
            // get an Track obj
            Track *trackIns = listOfTracks()->at(x);
            
            // get a pair of attribute values from the Track obj
            Pair *pair = trackIns->listOfDataItems()->at(y);
            
            HTMLFile << trackIns->htmlString(pair) << std::endl;
            
        }
        
        HTMLFile << "</ul>" << std::endl;
        HTMLFile << "</li>" << std::endl;
        
    }
    
    HTMLFile << "</ol>" << std::endl;
}

Tracks * Tracks::tracksForAlbumWithID(int albumID)
{
    Tracks *tracksForAlbum = new Tracks();

    //search through Tracks entity and will return a new Tracks Entity which will store the tracksForAlbumWithID
    for (int x = 0 ; x < numTracks() ; x++)
    {
        if (listOfTracks()->at(x)->albumID() == albumID)
            tracksForAlbum->addTrack(listOfTracks()->at(x));
    }

    return tracksForAlbum;
}

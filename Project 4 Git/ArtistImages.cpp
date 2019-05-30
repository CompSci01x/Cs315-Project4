

#include "ArtistImages.hpp"


void ArtistImages::loadArtistImagesFromFile(std::string artistsFileName)
{
    JSONTokenizer *tokenizer = new JSONTokenizer(artistsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}


void ArtistImages::createArtistImagesHTMLFile(std::fstream &htmlTemplateFile)
{
    fstream HTMLFile ("ArtistImages.html" , std::ios::out );
    
    std::string readLine;
    std::string marker = "<% artistImages %>";
    
    while (htmlTemplateFile)
    {
        // get a line from the template file
        getline(htmlTemplateFile , readLine);
        
        // check if its the marker if so replace it with HTML list otherwise add the line to "artist.html"
        if (readLine == marker)
            replaceWithHTMLList(HTMLFile);
        else
            HTMLFile << readLine << std::endl;
    }
    
    htmlTemplateFile.close();
    HTMLFile.close();
}


void ArtistImages::replaceWithHTMLList(std::fstream &HTMLFile)
{
    
    HTMLFile << "<style>" << std:: endl;
    HTMLFile << "h1 {color: red;}" << std::endl;
    HTMLFile << "h2 {color: green;}" << std::endl;
    HTMLFile << "h3 {color: blue}" << std::endl;
    HTMLFile << "html {width: 1000px;}\n img.image {float: left;}\n  div.clear { clear: both; }" << std::endl;
    HTMLFile << "</style>" << std::endl;

    
    HTMLFile << "<ol>" << std::endl;
    
    // outer loop goes through earch artist obj
    for (int x = 0; x < listOfArtistImages()->size() ; x++)
    {
        HTMLFile <<  "<li><p>" << listOfArtistImages()->at(x)->artistID() << "</p>" << std::endl;
        HTMLFile << "<ul>" << std::endl;
        
        
        // inner loop goes through the attribute pairs of the artist obj
        for (int y = 0 ; y < listOfArtistImages()->at(x)->listOfDataItems()->size() ; y++)
        {
            // get an artist obj
            ArtistImage *artistImgIns = listOfArtistImages()->at(x);
            
            // get a pair of attribute values from the artist obj
            Pair *pair = artistImgIns->listOfDataItems()->at(y);
            
            HTMLFile << artistImgIns->htmlString(pair) << std::endl;
            
        }
        
        ArtistImage *artistImgIns = listOfArtistImages()->at(x);

        HTMLFile << "<img class=\"image\"" << " width= " << artistImgIns->width()
        << " height= " << artistImgIns->height() << " src= " << "\"" << artistImgIns->uri() << "\"" << ">" << std::endl;


        HTMLFile << "<div class=\"clear\">&nbsp;</div>" << std::endl;

        
        HTMLFile << "</ul>" << std::endl;
        HTMLFile << "</li>" << std::endl;
        
    }
    
    HTMLFile << "</ol>" << std::endl;
}

ArtistImage * ArtistImages::setPrimaryArtistImageForArtists(int artistID)
{
 
    //search through ArtistImages entity and will return an ArtistImage
    for (int x = 0 ; x < numArtistImages() ; x++)
    {
        if (listOfArtistImages()->at(x)->artistID() == artistID && listOfArtistImages()->at(x)->type() == "primary")
            return listOfArtistImages()->at(x);
    }
    
    return nullptr;
}

ArtistImage* ArtistImages::setSecondaryArtistImageForArtists(int artistID)
{
    //search through ArtistImages entity and will return an ArtistImage
    for (int x = 0 ; x < numArtistImages() ; x++)
    {
        if (listOfArtistImages()->at(x)->artistID() == artistID && listOfArtistImages()->at(x)->type() == "secondary")
            return listOfArtistImages()->at(x);
    }
    
    return nullptr;
}


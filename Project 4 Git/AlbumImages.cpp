

#include "AlbumImages.hpp"

void AlbumImages::loadAlbumImagesFromFile(std::string AlbumsFileName)
{
    JSONTokenizer *tokenizer = new JSONTokenizer(AlbumsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}


void AlbumImages::createAlbumImagesHTMLFile(std::fstream &htmlTemplateFile)
{
    fstream HTMLFile ("AlbumImages.html" , std::ios::out );
    
    std::string readLine;
    std::string marker = "<% albumImages %>";
    
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


void AlbumImages::replaceWithHTMLList(std::fstream &HTMLFile)
{
    HTMLFile << "<style>" << std:: endl;
    HTMLFile << "h1 {color: red;}" << std::endl;
    HTMLFile << "h2 {color: green;}" << std::endl;
    HTMLFile << "h3 {color: blue}" << std::endl;
    HTMLFile << "html {width: 1000px;}\n img.image {float: left;}\n  div.clear { clear: both; }" << std::endl;
    HTMLFile << "</style>" << std::endl;
    
    
    HTMLFile << "<ol>" << std::endl;
    
    // outer loop goes through earch Album obj
    for (int x = 0; x < listOfAlbumImages()->size() ; x++)
    {
        HTMLFile <<  "<li><p>" << listOfAlbumImages()->at(x)->albumID() << "</p>" << std::endl;
        HTMLFile << "<ul>" << std::endl;
        
        // inner loop goes through the attribute pairs of the Album obj
        for (int y = 0 ; y < listOfAlbumImages()->at(x)->listOfDataItems()->size() ; y++)
        {
            // get an Album obj
            AlbumImage *albumImgIns = listOfAlbumImages()->at(x);
            
            // get a pair of attribute values from the Album obj
            Pair *pair = albumImgIns->listOfDataItems()->at(y);
            
            HTMLFile << albumImgIns->htmlString(pair) << std::endl;
            
        }
        
        AlbumImage *albumImgIns = listOfAlbumImages()->at(x);
        
        HTMLFile << "<img class=\"image\"" << " width= " << albumImgIns->width()
        << " height= " << albumImgIns->height() << " src= " << "\"" << albumImgIns->uri() << "\"" << ">" << std::endl;


        HTMLFile << "<div class=\"clear\">&nbsp;</div>" << std::endl;


        HTMLFile << "</ul>" << std::endl;
        HTMLFile << "</li>" << std::endl;
        
    }
    
    HTMLFile << "</ol>" << std::endl;
}


AlbumImage * AlbumImages::setPrimaryAlbumImageForAlbums(int albumID)
{
    
    //search through AlbumImages entity and will return an AlbumImage
    for (int x = 0 ; x < numAlbumImages() ; x++)
    {
        if (listOfAlbumImages()->at(x)->albumID() == albumID && listOfAlbumImages()->at(x)->type() == "primary")
            return listOfAlbumImages()->at(x);
    }
    
    return nullptr;
}

AlbumImage* AlbumImages::setSecondaryAlbumImageForAlbums(int albumID)
{
    //search through AlbumImages entity and will return an AlbumImage
    for (int x = 0 ; x < numAlbumImages() ; x++)
    {
        if (listOfAlbumImages()->at(x)->albumID() == albumID && listOfAlbumImages()->at(x)->type() == "secondary")
        return listOfAlbumImages()->at(x);
    }
    
    return nullptr;
}


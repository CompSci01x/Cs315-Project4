

#include "Artists.hpp"

void Artists::loadArtistsFromFile(std::string artistsFileName)
{
    JSONTokenizer *tokenizer = new JSONTokenizer(artistsFileName);
    parseJSONArray(tokenizer);
    delete tokenizer;
}


void Artists::createArtistHTMLFile(std::fstream &htmlTemplateFile)
{
        fstream HTMLFile ("Artists.html" , std::ios::out );
    
        std::string readLine;
    std::string marker = "<% artists %>";
    
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


void Artists::replaceWithHTMLList(std::fstream &HTMLFile)
{
        HTMLFile << "<ol>" << std::endl;
    
        // outer loop goes through earch artist obj
        for (int x = 0; x < numArtists() ; x++)
        {
            HTMLFile <<  "<li><p>" << listOfArtists()->at(x)->artistName() << "</p>" << std::endl;
            HTMLFile << "<ul>" << std::endl;
    
            // inner loop goes through the attribute pairs of the artist obj
            for (int y = 0 ; y < listOfArtists()->at(x)->listOfDataItems()->size() ; y++)
            {
                // get an artist obj
                Artist *artistIns = listOfArtists()->at(x);
    
                // get a pair of attribute values from the artist obj
                Pair *pair = artistIns->listOfDataItems()->at(y);
    
                HTMLFile << artistIns->htmlString(pair) << std::endl;
    
            }
    
            HTMLFile << "</ul>" << std::endl;
            HTMLFile << "</li>" << std::endl;
    
            // to delete and free the memory allocated for the artistAttributes vector ptr and it's Pair ptr's
          //  artistInstances.at(x).delPtrs();
        }
    
        HTMLFile << "</ol>" << std::endl;
}
//

void Artists::setAlbumsForArtists(Albums *albums)
{
    
    for (int x = 0; x < numArtists(); x++)
    {
        int artistID = listOfArtists()->at(x)->artistID();
        listOfArtists()->at(x)->setAlbums(albums->albumsForArtistWithID(artistID));
    }
    
}

void Artists::setImagesForArtists(ArtistImages *artistImages)
{
    for (int x = 0; x < numArtists(); x++)
    {
        int artistID = listOfArtists()->at(x)->artistID();
        listOfArtists()->at(x)->primaryImage() = artistImages->setPrimaryArtistImageForArtists(artistID);
        listOfArtists()->at(x)->secondaryImage() = artistImages->setSecondaryArtistImageForArtists(artistID);
    }
    
}


void Artists::setAlbumsAndTracksForArtists(Albums *albums , Tracks *tracks)
{
    setAlbumsForArtists(albums);

    for (int x = 0; x < numArtists(); x++)
        listOfArtists()->at(x)->albums()->setTracksForAlbums(tracks);
}

void Artists::setArtistAndAlbumImages(ArtistImages *artistImages, AlbumImages *albumImages)
{
    setImagesForArtists(artistImages);
    
    for (int x = 0; x < numArtists(); x++)
        listOfArtists()->at(x)->albums()->setImagesForAlbums(albumImages);
}




void Artists::createMasterHTMLFile(std::fstream &htmlTemplateFile)
{
    fstream HTMLFile ("MasterFile.html" , std::ios::out );
    
    std::string readLine;
    std::string marker = "<% MasterFile %>";
    
    while (htmlTemplateFile)
    {
        // get a line from the template file
        getline(htmlTemplateFile , readLine);
        
        // check if its the marker if so replace it with HTML list otherwise add the line to "artist.html"
        if (readLine == marker)
            replaceWithMasterHTMLList(HTMLFile);
        else
            HTMLFile << readLine << std::endl;
    }
    
    htmlTemplateFile.close();
    HTMLFile.close();
}



void Artists::replaceWithMasterHTMLList(std::fstream &HTMLFile)
{
    HTMLFile << "<style>" << std::endl;
    
    HTMLFile << "h1 {color: red;}" << std::endl;
    HTMLFile << "h2 {color: green;}" << std::endl;
    HTMLFile << "h3 {color: blue}" << std::endl;
    
    HTMLFile << "html {" << "\n" << "width: 1000px;" << "\n" << "}" << std::endl;
    
    HTMLFile << "img.image {" << "\n" << "float: left;" << "\n" << "}" << std::endl;
    
    HTMLFile << "table.albumInfo {" << "\n" << "margin: 20px 20px;" << "\n" << "float: right;" << "\n" << "}" << std::endl;
    
    HTMLFile << "td.aTitle {" << "\n" << "colspan: 2;" << "\n" << "font-family: serif;" << "\n" << "font-style: bold italic;" <<
    "\n" << "font-size: 2.0em;" << "\n" << "}" << std::endl;
    
    HTMLFile << " td.tagName {" << "\n" << "width: 150px;" << "\n" << " text-align: bottom;" << "\n" << "}" << std::endl;
    
    HTMLFile << " td.value {" << "\n" << "color: blue;" << "\n" << "   }" << std::endl;
    
    HTMLFile << "div.clear { clear: both; }" << std::endl;
    
    HTMLFile << "table.tracks td {" << "\n" << " border: collapse;" << "\n" << " border-top: 1px solid red;" << "\n" << "}" << std::endl;
    
    HTMLFile << "tr.tracks {" << "\n" << "border: 3px solid red;" << "\n" << "}" << std::endl;
    
    HTMLFile << "td.trackName {" << "\n" << "width: 350px;" << "\n" << "padding: 8px;" << "\n" << "}" << std::endl;
    
    HTMLFile << "</style>" << std::endl;

    HTMLFile << "<title>Artists</title>" << std::endl;
    
    HTMLFile << "</head>" << std::endl;
    
    HTMLFile << "<body>" << std:: endl;
    
    
     Pair *pair = new Pair();
    
    for (int x = 0; x < numArtists(); x++)
    {
        HTMLFile << "<h1> Artist </h1>" << std::endl;
       
        Artist *artist = listOfArtists()->at(x);
        
        HTMLFile << "<ol>" << std::endl;
        HTMLFile << "<h2>" << listOfArtists()->at(x)->artistName() << "</h2>" << std::endl;
        HTMLFile << "</ol>" << std::endl;
        
        if (listOfArtists()->at(x)->primaryImage() != nullptr)
        {
            HTMLFile << "<img class= " <<" \"image\" " << " width= " << listOfArtists()->at(x)->primaryImage()->width()
            << " height= " << listOfArtists()->at(x)->primaryImage()->height() << " src= " << "\"" <<listOfArtists()->at(x)->primaryImage()->uri() << "\"" << ">" << std::endl;

        }
        else if (listOfArtists()->at(x)->secondaryImage() != nullptr)
        {
            HTMLFile << "<img class= " <<" \"image\" " << " width= " << listOfArtists()->at(x)->secondaryImage()->width()
            << " height= " << listOfArtists()->at(x)->secondaryImage()->height() << " src= " << "\"" <<listOfArtists()->at(x)->secondaryImage()->uri() << "\"" << ">" << std::endl;
        }
            HTMLFile << "<ul>" << std::endl;
        
        
        for (int inner = 0; inner < artist->listOfDataItems()->size(); inner ++)
        {
            pair = artist->listOfDataItems()->at(inner);
            
            HTMLFile << artist->htmlString(pair) << std::endl;
        }
       
        HTMLFile << "<div class=\"clear\">&nbsp;</div>" << std::endl;
        
        
        for (int y = 0; y < artist->albums()->numAlbums(); y++)
        {
            HTMLFile << "<hr color=\"orange\">" << std::endl;
            
            HTMLFile << "<h1>" << "Album" << "</h1>" << std::endl;
            
            
            Albums *albums = artist->albums();
            Album *album = albums->listOfAlbums()->at(y);
            
            HTMLFile << "<ol>" << std::endl;
            HTMLFile << "<h2>" << albums->listOfAlbums()->at(y)->title() << "</h2>" << std::endl;
            HTMLFile << "</ol>" << std::endl;
            
            if (album->primaryImage() != nullptr)
            {
                HTMLFile << "<img class= " <<" \"image\" " << " width= " << album->primaryImage()->width()
                << " height= " << album->primaryImage()->height() << " src= " << "\"" <<album->primaryImage()->uri() << "\"" << ">" << std::endl;
                
            }
            else if (album->secondaryImage() != nullptr)
            {
                HTMLFile << "<img class= " <<" \"image\" " << " width= " << album->secondaryImage()->width()
                << " height= " << album->secondaryImage()->height() << " src= " << "\"" << album->secondaryImage()->uri() << "\"" << ">" << std::endl;
            }
            
            HTMLFile << "<ul>" << std::endl;

            
            for (int inner = 0; inner < album->listOfDataItems()->size(); inner ++)
            {
                pair = album->listOfDataItems()->at(inner);
                HTMLFile << album->htmlString(pair) << std::endl;
            }
            
            
            HTMLFile << "<div class=\"clear\">&nbsp;</div>" << std::endl;

            HTMLFile << "<h1>" << "Tracklist" << "</h1>" << std::endl;

            for (int z = 0; z < album->tracks()->numTracks(); z++)
            {
                
                Tracks *tracks = album->tracks();
                Track *track = tracks->listOfTracks()->at(z);
                
                 HTMLFile << "<ol>" << std::endl;
                HTMLFile << "<h3>" << track->title() << "</h3>" << std::endl;
                 HTMLFile << "</ol>" << std::endl;
                
                HTMLFile << "<ul>" << std::endl;
                
                for (int inner = 0; inner < track->listOfDataItems()->size(); inner++)
                {
                    pair = track->listOfDataItems()->at(inner);
                    HTMLFile << track->htmlString(pair) << std::endl;
                }
                
                
                HTMLFile << "</ul>" << std::endl;
                HTMLFile << "</li>" << std::endl;
            }
            
            HTMLFile << "</ul>" << std::endl;
            HTMLFile << "</li>" << std::endl;
            
        }
        
        HTMLFile << "</ul>" << std::endl;
        HTMLFile << "</li>" << std::endl;
    }
    
    
}


void Artists::createAlbumsSubDirectory()
{
    // create directory
   if (mkdir("AlbumsTracks", 0777) == -1 )
   {
       std::cout << "Error: Directory Already Exists\n";
       exit(1);
   }
   
    std::string nameOfFile;
    fstream HTMLFile;
    
    for (int x = 0; x < numArtists(); x++)
    {
        Albums *albums = listOfArtists()->at(x)->albums();
        
        std::string directoryName =  "AlbumsTracks/" + listOfArtists()->at(x)->artistName();
        
        
        if (mkdir(directoryName.c_str(), 0777) == -1 )
        {
            std::cout << "Error: Directory Already Exists\n";
            exit(1);
        }
        
        
        for (int y = 0; y < albums->numAlbums(); y++)
        {
            Album *album = albums->listOfAlbums()->at(y);
            
            nameOfFile = album->title();
            
            HTMLFile.open(directoryName + "/" + nameOfFile + ".html" ,std::ios::out);
            
            HTMLFile << "<!DOCTYPE html> \n<html> \n<head> \n<title>AlbumsTracks</title> \n</head> \n<body> " << std::endl;
            HTMLFile << "<style>" << std:: endl;
            HTMLFile << "h1 {color: red;}" << std::endl;
            HTMLFile << "h2 {color: green;}" << std::endl;
            HTMLFile << "h3 {color: blue}" << std::endl;
            HTMLFile << "html {width: 1000px;}\n img.image {float: left;}\n  div.clear { clear: both; }" << std::endl;
            HTMLFile << "</style>" << std::endl;
            
            
            HTMLFile << "<h1> Album </h1>" << std::endl;
            
            HTMLFile << "<ol>" << std::endl;
            HTMLFile << "<h2>" << albums->listOfAlbums()->at(y)->title() << "</h2>" << std::endl;
            HTMLFile << "</ol>" << std::endl;
            
            if (album->primaryImage() != nullptr)
            {
                HTMLFile << "<img class=\"image\""<< " width= " << album->primaryImage()->width()
                << " height= " << album->primaryImage()->height() << " src= " << "\"" <<album->primaryImage()->uri() << "\"" << ">" << std::endl;
                
            }
            else if (album->secondaryImage() != nullptr)
            {
                HTMLFile << "<img class=\"image\"" << " width= " << album->secondaryImage()->width()
                << " height= " << album->secondaryImage()->height() << " src= " << "\"" << album->secondaryImage()->uri() << "\"" << ">" << std::endl;
            }
            
            HTMLFile << "<ul>" << std::endl;
            
            
            for (int inner = 0; inner < int(album->listOfDataItems()->size()); inner++)
            {
                Pair *pair = album->listOfDataItems()->at(inner);
                HTMLFile << album->htmlString(pair) << std::endl;
            }
            
            HTMLFile << "<div class=\"clear\">&nbsp;</div>" << std::endl;

        
            Tracks *tracks = album->tracks();
            
            HTMLFile << "<ul>" << std::endl;
            
            HTMLFile << "<h1> Tracklist </h1>" << std::endl;
            
            for (int z = 0; z < tracks->numTracks(); z++)
            {
                Track *track = tracks->listOfTracks()->at(z);
                
                HTMLFile << "<ol>" << std::endl;
                HTMLFile << "<h3>" << track->title() << "</h3>" << std::endl;
                HTMLFile << "</ol>" << std::endl;
                
                HTMLFile << "<ul>" << std::endl;

                for (int inner = 0; inner < int(track->listOfDataItems()->size()); inner++)
                {
                    Pair *pair = track->listOfDataItems()->at(inner);
                    HTMLFile << track->htmlString(pair) << std::endl;
                }
                
                
                HTMLFile << "</ul>" << std::endl;
                HTMLFile << "</li>" << std:: endl;
            }
            
            
            HTMLFile << "</ul>" << std::endl;
            
            HTMLFile << "</body>\n </html>" << std::endl;
    
            HTMLFile.close();

        }


    }
    
    
}

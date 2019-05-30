
//***************************
//
// Class: CS-315
//
// Project 4
//
// Date: December 4th, 2018
//***************************

#include <iostream>
#include <fstream>

#include "Artists.hpp"
#include "Albums.hpp"
#include "Tracks.hpp"
#include "ArtistImages.hpp"
#include "AlbumImages.hpp"

int main (int argc, const char * argv[])
{
    
    if (argc != 12)
    {
        std::cout << "usage: " << argv[0] << " artists_human_readable.json artists_template.html albums_human_readable.json albums_template.html tracks_human_readable.json tracks_template.html artist_images_human_readable.json artistImages_template.html album_images_human_readable.json albumImages_template.html masterFile_template.html" << std::endl;
        exit(1);
    }
    
    
    std::fstream artisthtmlTemplateStream;
    artisthtmlTemplateStream.open(argv[2] , std::ios::in);
    
    
    if( ! artisthtmlTemplateStream.is_open())
    {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }
    
    
    Artists *artists = new Artists();
    artists->loadArtistsFromFile(argv[1]);
    artists->createArtistHTMLFile(artisthtmlTemplateStream);
    
    
/////////////////////////////////////////////////////////////////////////////////
    
    
    std::fstream albumhtmlTemplateStream;
    albumhtmlTemplateStream.open(argv[4] , std::ios::in);
    
    if( ! albumhtmlTemplateStream.is_open())
    {
        std::cout << "Unable top open " << argv[4] << ". Terminating...";
        exit(2);
    }
    

    Albums *albums = new Albums();
    albums->loadAlbumsFromFile(argv[3]);
    albums->createAlbumHTMLFile(albumhtmlTemplateStream);
    
    
/////////////////////////////////////////////////////////////////////////////////
    

    std::fstream trackhtmlTemplateStream;
    trackhtmlTemplateStream.open(argv[6] , std::ios::in);
    
    if( ! trackhtmlTemplateStream.is_open())
    {
        std::cout << "Unable top open " << argv[6] << ". Terminating...";
        exit(2);
    }
    
    
    Tracks *tracks = new Tracks();
    tracks->loadTracksFromFile(argv[5]);
    tracks->createTrackHTMLFile(trackhtmlTemplateStream);
    
    
/////////////////////////////////////////////////////////////////////////////////

    
    std::fstream artistImageHtmlTemplateStream;
    artistImageHtmlTemplateStream.open(argv[8] , std::ios::in);
    
    if( ! artistImageHtmlTemplateStream.is_open())
    {
        std::cout << "Unable top open " << argv[8] << ". Terminating...";
        exit(2);
    }
    
    ArtistImages *aImg = new ArtistImages();
    aImg->loadArtistImagesFromFile(argv[7]);
    aImg->createArtistImagesHTMLFile(artistImageHtmlTemplateStream);
    
    
/////////////////////////////////////////////////////////////////////////////////
    
   
    std::fstream albumImageHtmlTemplateStream;
    albumImageHtmlTemplateStream.open(argv[10] , std::ios::in);
    
    if( ! albumImageHtmlTemplateStream.is_open())
    {
        std::cout << "Unable top open " << argv[10] << ". Terminating...";
        exit(2);
    }
    
    AlbumImages *albImg = new AlbumImages();
    albImg->loadAlbumImagesFromFile(argv[9]);
    albImg->createAlbumImagesHTMLFile(albumImageHtmlTemplateStream);
    
    
/////////////////////////////////////////////////////////////////////////////////

    
    artists->setAlbumsAndTracksForArtists(albums, tracks);
    artists->setArtistAndAlbumImages(aImg, albImg);
    
    std::fstream masterFileHtmlTemplateStream;
    masterFileHtmlTemplateStream.open(argv[11] , std::ios::in);
    
    if( ! masterFileHtmlTemplateStream.is_open())
    {
        std::cout << "Unable top open " << argv[10] << ". Terminating...";
        exit(2);
    }
    
    artists->createMasterHTMLFile(masterFileHtmlTemplateStream);
    artists->createAlbumsSubDirectory();
    
    
    std::cout << "Program has run successfully\n";
    
    return 0;
    


    
}


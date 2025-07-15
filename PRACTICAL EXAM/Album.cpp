#include <iostream>
#include "Album.h"
#include <string>
using namespace std;

Album::Album(){
	title = "";
	artist = "";
	releaseYear = 0;
	trackCount = 0;
}

void Album::setTitle(string t){
	title = t;
}
void Album::setArtist(string a){
	artist = a;
}
void Album::setReleaseYear(int y){
	releaseYear = y;
}

void Album::setTrackCount(int c){
	trackCount = c;
}

void Album::displayAlbumInfo() const{
	cout << "Album Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Released: " << releaseYear << endl;
	cout << "Tracks: " << trackCount << endl;
}

bool Album::isClassic() const{
	if (releaseYear <= 2030){
		cout << "This is not a classic Album." << endl;
		return true;
	}else{
		return false;
	}
}

void Album::addTrack(){
	cout << "Adding a bonus track..." << endl;
	trackCount++;
}



#include <iostream>
#include "Album.h"
using namespace std;

int main(){
	Album A;
	A.setTitle("The Light");
	A.setArtist("BGYO");
	A.setReleaseYear(2021); 	
	A.setTrackCount(12);
	A.displayAlbumInfo();
	A.isClassic();
	A.addTrack();
	cout<< "Is updated"<<endl;
	A.displayAlbumInfo();
}



#ifndef ALBUM_H
#define ALBUM_H
#include <string>
using namespace std;
class Album{
	private:
		string title,artist;
		int yearRelease, trackCount;
		
	public:
		void setTitle();
		void setArtist();
		void setyearRelease();
		void settrackCount();
		void displayAlbumInfo();
		bool isClassic();
		void addTrack();
};

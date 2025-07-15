#ifndef ALBUM_H
#define ALBUM_H
#include <string>
using namespace std;

class Album{
	
	private:
		string title;
		string artist;
		int releaseYear;
		int trackCount;
		
	public:
		Album();  //Default Construct
		void setTitle(string);
		void setArtist(string);
		void setReleaseYear(int);
		void setTrackCount(int);
		void displayAlbumInfo() const;
		bool isClassic() const;
		void addTrack();
};

#endif



#include <iostream>

#include <string>


using namespace std;


class LinkedList {

private:

// Declare a structure for the list

struct ListNode {

string songname;

struct ListNode *next;

};


ListNode *head; // List head pointer


public:

// Constructor

LinkedList() : head(NULL) {}


// Destructor

~LinkedList();


// Linked list operations

void addSong(const string& song_name);

void deleteSong(const string& song_name);

bool findSong(const string& song_name) const;

void displayPlayList() const;

};


// Destructor to clean up all nodes

LinkedList::~LinkedList() {

ListNode *nodePtr = head;

while (nodePtr != NULL) {

ListNode *garbage = nodePtr;

nodePtr = nodePtr->next;

delete garbage;

}

}




void LinkedList::addSong(const string& song_name) {

//TODO
{
ListNode *newNode, *nodePtr;
newNode = new ListNode;
newNode->songname = song_name;
newNode->next = NULL;

if (!head)
head = newNode;
else 
{

nodePtr = head;

while (nodePtr->next)
nodePtr = nodePtr->next;

nodePtr->next = newNode;
} cout << "Song \""<< song_name << "\" has been added!" << endl<<endl;}
}


void LinkedList::deleteSong(const string& song_name) {

ListNode *nodePtr = head;

ListNode *previousNode = NULL;


if (!head) {

cout << "The playlist is empty!\n" << endl;

return;

}


if (head->songname == song_name) {

nodePtr = head->next;

delete head;

head = nodePtr;

cout << "Song \"" << song_name << "\" has been deleted!\n" << endl;

return;

}


while (nodePtr != NULL && nodePtr->songname != song_name) {

previousNode = nodePtr;

nodePtr = nodePtr->next;

}


if (nodePtr) {

previousNode->next = nodePtr->next;

delete nodePtr;

cout << "Song \"" << song_name << "\" has been deleted!\n" << endl;

} else {

cout << "Song \"" << song_name << "\" not found in the list!\n" << endl;

}

}


bool LinkedList::findSong(const string& song_name) const {

//TODO
ListNode *nodeptr = head;

while (nodeptr != NULL){
	if (nodeptr->songname == song_name) {
		return true;
	}
	nodeptr = nodeptr->next;
}
return false;

}


void LinkedList::displayPlayList() const {

//TODO
{
ListNode *nodePtr;
if (head==NULL)
cout << "The List is empty!" << endl;
else {
	cout << "The songs in the playlist are:"<<endl;
nodePtr = head;
while (nodePtr)
{

cout <<nodePtr->songname << endl;
nodePtr = nodePtr->next;
} cout<< endl;}
}

}


void displayMenu() {

cout<<"---- Playlist Menu ----\n";

cout << "1. Add Song\n";

cout << "2. Remove Song\n";

cout << "3. Display Playlist\n";

cout << "4. Find Song\n";

cout << "5. Exit\n";

}


int main() {

LinkedList playlist;

int choice;

string song_name;


do {

displayMenu();

cout << "Enter your choice: ";

cin >> choice;

cin.ignore(); // To ignore newline character after choice input


switch (choice) {

case 1:

cout << "Enter song name: ";

getline(cin, song_name);

playlist.addSong(song_name);

break;

case 2:

cout << "Enter song name to remove: ";

getline(cin, song_name);

playlist.deleteSong(song_name);

break;

case 3:

cout << "Playlist:\n";

playlist.displayPlayList();

break;

case 4:

cout << "Enter song name to find: ";

getline(cin, song_name);

if (playlist.findSong(song_name)) {

cout << "Song \"" << song_name << "\" found in the playlist.\n";

} else {

cout << "Song \"" << song_name << "\" not found in the playlist.\n";

}

break;

case 5:

cout << "Exiting...\n";

break;

default:

cout << "Invalid choice! Please try again.\n";

}

} while (choice != 5);


return 0;

}

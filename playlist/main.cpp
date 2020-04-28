#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;
void PrintMenu(string);

int main(){
	string playlistTitle;
	
	cout << "Enter playlist's title:" <<endl;
	getline(cin,playlistTitle);
	PrintMenu(playlistTitle);
	
	
	return 0;
}

void PrintMenu(string title){
	char option = 'z';
	Playlist myPlaylist;
	
	while(option != 'q'){
		cout<< title << " PLAYLIST MENU" <<endl;
		cout<< "a - Add song" << endl;
		cout<< "d - Remove song" <<endl;
		cout<< "c - Change position of song" <<endl;
		cout<< "s - Output songs by specific artist" <<endl;
		cout<< "t - Output total time of playlist (in seconds)" <<endl;
		cout<< "o - Output full playlist" << endl;
		cout<< "q - Quit" <<endl << endl;
		cout<< "Choose an option:";
		cin >> option;
		if(option=='a'){
			cout<< "ADD SONG" <<endl;
			myPlaylist.addSong();
			cout<< endl;
		}
		if(option=='d'){
			cout<< "REMOVE SONG" <<endl;			
			myPlaylist.removeSong();
			cout<< endl;
		}
		if(option=='c'){
			cout << "CHANGE POSITION OF SONG" <<endl;
			myPlaylist.changePostion();
			cout <<endl;
		}
		if(option=='s'){
			cout<< "OUTPUT SONG BY SPECIFIC ARTIST" <<endl;
			myPlaylist.specificArtist();
			cout<<endl;
		}
		if(option=='t'){
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" <<endl;
			cout <<"Total time: "<< myPlaylist.listTime() <<" seconds";
			cout<<endl;
		}
		if(option=='o'){
			cout<< title << " - OUTPUT FULL PLAYLIST" <<endl;
			myPlaylist.printList();
			cout<< endl;
		}
		if(option=='q'){
			cout<< "Bye!" <<endl;
		}
	}	
}

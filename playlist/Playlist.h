#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode{
	private:
		string uniqueID; //Initialized to "none" in default constructor
		string songName; //Initialized to "none" in default constructor
		string artistName; //Initialized to "none" in default constructor
		int songLength; //Initialized to 0 in default constructor
		PlaylistNode* nextNodePtr; //Initialized to 0 in default constructor
		
	public:
		//Default constructor
		PlaylistNode();
		
		//Parameterized constructor
		PlaylistNode(string, string, string, int);

		//Mutators
		void SetNext(PlaylistNode* );
		void InsertAfter(PlaylistNode* );
		
		//Accessors
		string GetID();
		string GetSongName();
		string GetArtistName();
		int GetSongLength();
		PlaylistNode* GetNext();
		void PrintPlaylistNode();
};

class Playlist{
	private:
		PlaylistNode* head;
		
	public:
		Playlist();

		void printList();
		void addSong();
		void removeSong();
		void changePostion();
		void specificArtist();
		int listTime();
		PlaylistNode* findLast();
		int listLength();
};
#endif

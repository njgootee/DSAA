#include "Playlist.h"

//Default constructor
PlaylistNode::PlaylistNode(){
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr =nullptr;
}

//Parameterized constructor
PlaylistNode::PlaylistNode(string id, string song, string artist, int length){
	uniqueID=id;
	songName = song;
	artistName = artist;
	songLength = length;
	nextNodePtr = nullptr;
}

//Mutators
void PlaylistNode::SetNext(PlaylistNode* next){
	nextNodePtr = next;
}
void PlaylistNode::InsertAfter(PlaylistNode* next){
	this->SetNext(next->GetNext());
	next->SetNext(this);
}

//Accessors
string PlaylistNode::GetID(){
	return uniqueID;
}
string PlaylistNode::GetSongName(){
	return songName;
}
string PlaylistNode::GetArtistName(){
	return artistName;
}
int PlaylistNode::GetSongLength(){
	return songLength;
}
PlaylistNode* PlaylistNode::GetNext(){
	return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode(){
	cout<< "Unique ID: " << GetID() <<endl;
	cout<< "Song Name: " << GetSongName() <<endl;
	cout<< "Artist Name: " << GetArtistName() <<endl;
	cout<< "Song Length (in seconds) : " << GetSongLength() <<endl;
}

//Playlist Class Functions
Playlist::Playlist(){
	head=nullptr;
}

int Playlist::listLength(){
	PlaylistNode* tmp = head;
	int count=0;
	
	while(tmp!=nullptr){
		++count;
		tmp = tmp->GetNext();
	}
	return count;
}

void Playlist::printList(){
	if(head == nullptr){
		cout<< "Playlist is empty." <<endl;
	}else{
		PlaylistNode* tmp =head;
		int count = 1;
		
		while(tmp!=nullptr){
			cout<< count << "." <<endl;
			tmp->PrintPlaylistNode();
			tmp=tmp->GetNext();
			count++;
		}
	}
}

PlaylistNode* Playlist::findLast(){
		PlaylistNode* tmp=head;
		while(tmp->GetNext()!=nullptr){
			tmp=tmp->GetNext();
		}
		return tmp;
}

void Playlist::addSong(){
	string id;
	string	song;
	string	artist;
	int	length;
	
	cout<< "Enter song's unique ID:" <<endl;
	cin>> id;
	cout<< "Enter song's name:" <<endl;
	cin>> song;
	cout<< "Enter artist's name:" <<endl;
	cin>> artist;
	cout<< "Enter song's length (in seconds):" <<endl;
	cin>> length;
	
	if(head == nullptr){
		head = new PlaylistNode(id, song, artist, length);
	}
	else{
		PlaylistNode* last = findLast();
		last->SetNext(new PlaylistNode(id, song, artist, length));
	}
}

void Playlist::removeSong(){
	PlaylistNode* tmp =head;
	PlaylistNode* prev = nullptr;
	string id;
	cout<<"Enter song's unique ID:" <<endl;
	cin>> id;
	
	while(tmp!=nullptr){
		if(tmp->GetID()==id){
			break;
		}
		prev = tmp;
		tmp = tmp->GetNext();
	}
	if(prev!=nullptr){
		prev->SetNext(tmp->GetNext());
		delete tmp;
	}else{
		head = tmp->GetNext();
		delete tmp;
	}
}

void Playlist::changePostion(){
	int curr;
	int neu;
	PlaylistNode* prev = nullptr;
	PlaylistNode* tmp = head;
	
	cout << "Enter song's current position:" <<endl;
	cin >> curr;
	cout << "Enter new position for song:" <<endl;
	cin >> neu;
	if(neu<0){
		neu=1;
	} else if(neu>listLength()){
		neu=listLength();
	}
	if(curr<0){
		curr=1;
	} else if(curr>listLength()){
		curr=listLength();
	}	

   for (int i = 1; i < curr; i++)
   {
       prev = tmp;
       tmp = tmp->GetNext();
   }

   if (tmp!=nullptr)
   {
       string changeName = tmp->GetSongName();

       if (prev == NULL)
       {
           head = tmp->GetNext();
       }else{
           prev->SetNext(tmp->GetNext());
       }
       PlaylistNode* tmp2 = tmp;
       prev = nullptr;
       tmp = head;
      
       for (int i = 1; i < neu; i++)
       {
           prev = tmp;
           tmp = tmp->GetNext();
       }
      
       if (prev == nullptr)
       {
           tmp2->SetNext(head);
           head = tmp2;
       }else{
           tmp2->InsertAfter(prev);
      }


       cout << "\"" << changeName << "\" moved to position " << neu << endl;

   }
}

void Playlist::specificArtist(){
	string name;
	
	cout << "Enter artist's name:" <<endl;
	cin >> name;
	cout << endl;
	
	PlaylistNode* tmp =head;
	int count = 1;
	
	while(tmp!=nullptr){
		if(tmp->GetArtistName()==name){
			cout<< count << "." <<endl;
			tmp->PrintPlaylistNode();
		}
		tmp=tmp->GetNext();
		count++;
	}
}

int Playlist::listTime(){
	int total=0;
	PlaylistNode* tmp =head;
	
	while(tmp!=nullptr){
		total+=tmp->GetSongLength();
		tmp=tmp->GetNext();
	}
	
	return total;
}


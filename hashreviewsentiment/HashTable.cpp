#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	this->size=s;
    hashTable = new list<WordEntry>[size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    //method 2
    return(s[0]+27*s[1]+729*s[2])%size;
    /*method 3, considers all characters
    int ret = 0;
    for(unsigned i=0; i<s.length(); i++){
        ret=ret+((s[s.length()-i-1]*(37^i))%size);
    }
    return ret;*/
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    //hash num of s
    int hashNum = computeHash(s);
    //if already in table
    if(contains(s)){
        //add new app
        list <WordEntry> :: iterator it;
        for(it=hashTable[hashNum].begin();it!=hashTable[hashNum].end();++it){
            if(it->getWord()==s){
                it->addNewAppearance(score);
            }
        }        
    }else{
        //new entry
        hashTable[hashNum].push_back(WordEntry(s,score));
    }
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    int hashNum=computeHash(s);
    //if found
    if(contains(s)){
        list <WordEntry> :: iterator it;
        for(it=hashTable[hashNum].begin();it!=hashTable[hashNum].end();++it){
            if(it->getWord()==s){
                return it->getAverage();
            }
        }        
    }
    //not found
    return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
    //compute hash of string
    int hashNum = computeHash(s);
    //setup iterator for list in array
    if(!hashTable[hashNum].empty()){
        list <WordEntry> :: iterator it;
        for(it=hashTable[hashNum].begin();it!=hashTable[hashNum].end();++it){
            if(it->getWord()==s){
                return true;
            }
        }
    }
    return false;
}


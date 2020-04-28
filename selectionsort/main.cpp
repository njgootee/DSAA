#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

//Passes in an index of type int and a vector of type T (T could be string, double or int). 
//The function returns the index of the min value starting from "index" to the end of the "vector".
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    unsigned mindex=index;
    
    for(unsigned i=index+1;i<vals.size();++i){
        if(vals.at(i)<vals.at(mindex)){
            mindex=i;
        }
    }
    return mindex;
}

//Passes in a vector of type T and sorts them based on the selection sort method. 
//This function should utilize the min_index function to find the index of the min value in the unsorted portion of the vector.
template<typename T>
void selection_sort(vector<T> &vals){
   unsigned i = 0;
   unsigned indexSmallest = 0;
   T temp;

   if(vals.size()==0){return;}
   
   for (i = 0; i < vals.size()-1; ++i) {
      indexSmallest=min_index(vals,i);

      temp = vals.at(i);
      vals.at(i) = vals.at(indexSmallest);
      vals.at(indexSmallest) = temp;
   }    
}

//Passes in a vector of type T (T could be string, double or int) and an index of type int. 
//The function returns the element located at the index of the vals.
template<typename T>
T getElement(vector<T> vals, int index){
    return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){
    //Part A
    cout <<"---PART_A---" <<endl;
    vector<int> ints{1,2,3,6,8,10,1234};
    vector<double> doubles{14.0,14.4,16.8,32.7,1.1,0.4,0.02,3245.0,12.4};
    vector<string> strings{"great","greater","greatest","aardvark","aaron","xylophone","giraffe"};
    
    cout <<"ints: ";
    for(unsigned i=0;i<ints.size();++i){
        cout<<ints.at(i) <<",";
    }
    cout <<endl;
    selection_sort(ints);
    cout<< "sorted ints: ";
    for(unsigned i=0;i<ints.size();++i){
        cout<<ints.at(i) <<",";
    }
    cout <<endl;

    cout <<"doubles: ";
    for(unsigned i=0;i<doubles.size();++i){
        cout<<doubles.at(i) <<",";
    }
    cout <<endl;
    selection_sort(doubles);
    cout<< "sorted doubles: ";
    for(unsigned i=0;i<doubles.size();++i){
        cout<<doubles.at(i) <<",";
    }
    cout <<endl;

    cout <<"strings: ";
    for(unsigned i=0;i<strings.size();++i){
        cout<<strings.at(i) <<",";
    }
    cout <<endl;
    selection_sort(strings);
    cout<< "sorted strings: ";
    for(unsigned i=0;i<strings.size();++i){
        cout<<strings.at(i) <<",";
    }
    cout <<endl;

    //Part B
    cout << "---PART_B---" <<endl;

    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;

    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try{
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch(const std::out_of_range& excpt){
            cout << "out of range exception occured" <<endl;
        }
    }

    return 0;
}
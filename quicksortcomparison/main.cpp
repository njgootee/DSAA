#include <iostream> // output
#include <ctime> //clock
#include<stdlib.h> //rand
using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
const int NUMBERS_SIZE = 50000;

//helper for qsmp
int midpointPartition(int numbers[],int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   // Pick middle element as pivot
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
      
      // Increment l while numbers[l] < pivot
      while (numbers[l] < pivot) {
         ++l;
      }
      
      // Decrement h while pivot < numbers[h]
      while (pivot < numbers[h]) {
         --h;
      }
      
      // If there are zero or one elements remaining,
      // all numbers are partitioned. Return h
      if (l >= h) {
         done = true;
      }
      else {
         // Swap numbers[l] and numbers[h],
         // update l and h
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   return h;
}
//this function sorts the given array in the range from i to k using quicksort method. 
//In this function, pivot is the midpoint element (numbers[(i+k)/2]). 
//(implementation of this function is given in section 21.5)
void Quicksort_midpoint(int numbers[], int i, int k){
   int j = 0;
   
   // Base case: If there are 1 or zero elements to sort,
   // partition is already sorted
   if (i >= k) {
      return;
   }
   
   // Partition the data within the array. Value j returned
   // from partitioning is location of last element in low partition.
   j = midpointPartition(numbers, i, k);
   
   // Recursively sort low partition (i to j) and
   // high partition (j + 1 to k)
   Quicksort_midpoint(numbers, i, j);
   Quicksort_midpoint(numbers, j + 1, k);
}

//helper function for qsme pivot fn
void Swap(int arr[], int left, int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

//qsme pivot fn
int MedianOfThree(int arr[], int left, int right){
    int mid = (left + right)/2;
    if(arr[right] < arr[left]){
        Swap(arr, left, right);
    }       
    if(arr[mid] < arr[left]){
        Swap(arr, mid, left);
    }
    if(arr[right] < arr[mid]){
        Swap(arr, right, mid);
    }
    return mid;
}

//qsme partition function
int medianPartition(int numbers[],int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   // Pick middle element as pivot
   midpoint = MedianOfThree(numbers,i,k);
   pivot = numbers[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
      
      // Increment l while numbers[l] < pivot
      while (numbers[l] < pivot) {
         ++l;
      }
      
      // Decrement h while pivot < numbers[h]
      while (pivot < numbers[h]) {
         --h;
      }
      
      // If there are zero or one elements remaining,
      // all numbers are partitioned. Return h
      if (l >= h) {
         done = true;
      }
      else {
         // Swap numbers[l] and numbers[h],
         // update l and h
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   return h;
}
//this function utilizes different pivot selection technique in quicksort algorithm. 
//The pivot is the median of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). 
void Quicksort_medianOfThree(int numbers[], int i, int k){
   int j = 0;
   
   // Base case: If there are 1 or zero elements to sort,
   // partition is already sorted
   if (i >= k) {
      return;
   }
   
   // Partition the data within the array. Value j returned
   // from partitioning is location of last element in low partition.
   j = medianPartition(numbers, i, k);
   
   // Recursively sort low partition (i to j) and
   // high partition (j + 1 to k)
   Quicksort_medianOfThree(numbers, i, j);
   Quicksort_medianOfThree(numbers, j + 1, k);    
}

//this function sorts the given array using InsertionSort method. 
void InsertionSort(int numbers[], int numbersSize){
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < numbersSize; ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
   }
}

//array generation
int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main(){
    //generate arrays

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1,arr2,arr3);

    //time QS1
    clock_t Start = clock();
    Quicksort_midpoint(arr1,0,NUMBERS_SIZE-1);
    clock_t End = clock();
    int eTimeQuick1 = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    //time QS2
    Start = clock();
    Quicksort_medianOfThree(arr2,0,NUMBERS_SIZE-1);
    End = clock();
    int eTimeQuick2 = (End - Start)/CLOCKS_PER_MS;

    //time IS
    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    int eTimeInsertion = (End - Start)/CLOCKS_PER_MS;

    //output
    cout<<"SORT TIMES (ms):"<<endl;
    cout << "Quick Sort (midpoint): " << eTimeQuick1 << endl;
    cout<< "Quick Sort (median of 3): " << eTimeQuick2 <<endl;
    cout<< "Insertion Sort: " << eTimeInsertion <<endl;

    return 0;
}
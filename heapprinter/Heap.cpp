#include "Heap.h"
#include <iostream>
/*Initializes an empty heap.*/
Heap::Heap(){
    numItems=0;
}

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue ( PrintJob* neuJob){
    if(IsFull()){
        cout << "Error: heap is full." <<endl;
        return;
    }

    numItems++;
    int i = numItems-1;
    arr[i] = neuJob;

    PrintJob* temp;
    while(i!=0){
        if(arr[parent(i)]->getPriority()<arr[i]->getPriority()){
            temp=arr[i];
            arr[i]=arr[parent(i)];
            arr[parent(i)]=temp;
        }
        i=parent(i);
    }
}

/*Removes the node with highest priority from the heap.  */
void Heap::dequeue(){
    if(numItems==0){
        cout << "Error: heap is empty." <<endl;
        return;
    }

    arr[0]=arr[numItems-1];
    numItems--;
    trickleDown(0);
}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest(){
    return arr[0];
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages*/
void Heap::print(){
    if(numItems==0){
        cout << "Error: heap is empty." <<endl;
        return;
    }    
    cout << "Priority: " << highest()->getPriority() << ", Job Number: " << highest()->getJobNumber() <<", Number of Pages: " << highest()->getPages() <<endl;
}

/*This function is called by dequeue function
to move the new root down the heap to the 
appropriate location.*/
void Heap::trickleDown(int loc){
    int l =left(loc);
    int r =right(loc);
    int largest = loc;
    PrintJob* temp;

    if(l<numItems-1 && arr[l]->getPriority()>arr[loc]->getPriority()){
        largest = l;
    }
    if(r<numItems-1 && arr[r]->getPriority()>arr[largest]->getPriority()){
        largest = r;
    }
    if(largest!=loc){
        temp=arr[loc];
        arr[loc]=arr[largest];
        arr[largest]=temp;
        trickleDown(largest);
    }
}

/* This function checks for full Heap */
bool Heap::IsFull(){
    if(numItems==MAX_HEAP_SIZE){
        return true;
    }
    else return false;
}
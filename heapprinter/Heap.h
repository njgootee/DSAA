#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  PrintJob* arr[MAX_HEAP_SIZE];
  int numItems;  //current number of items in heap

public:
  /*Initializes an empty heap.*/
  Heap();

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue ( PrintJob* );

  /*Removes the node with highest priority from the heap. */
  void dequeue ( );

  /*Returns the node with highest priority.*/
  PrintJob* highest ( );

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void print ( );

private:
  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void trickleDown(int);

  //private helper functions
  bool IsFull();

  int parent(int i){return (i-1)/2;}

  int left(int i){return (2*i+1);}

  int right(int i){return(2*i+2);}
};
#endif
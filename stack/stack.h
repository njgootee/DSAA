#ifndef __STACK_H
#define __STACK_H
#include <iostream>
#include <stdexcept>
using namespace std;
const int MAX_SIZE = 20;

template <class T>
class stack{
private:
    int size;
    T* data;

    //Private helper functions
    bool full(){
        if(size>=MAX_SIZE){
            return true;
        }else{
            return false;
        }
    }

public:
    //constructs empty stack
    stack(){
        size=0;
        data=new T[MAX_SIZE];
    }

    /*inserts a new element (val) of type T (T could be integer or string) into the data. 
    If the data array is full, this function should throw an overflow_error exception
    with error message "Called push on full stack." */
    void push(T val){
        if(full()){
            throw overflow_error("Called push on full stack.");
        }
        else{
            data[size]=val;
            size++;
        }
    }

    /*removes the last element from data. If the data array is empty, this function should throw an 
    outofrange exception with error message "Called pop on empty stack."*/
    void pop(){
        if(empty()){
            throw out_of_range("Called pop on empty stack.");
        }
        else{
            size--;
        }
    }

    /* returns the top element of stack (last inserted element). If stack is empty, this function 
    should throw an underflow_error exception with error message "Called top on empty stack."*/
    T top(){
        if(empty()){
            throw underflow_error("Called top on empty stack.");
        }
        return data[size-1];
    }

    /* returns true if the stack is empty otherwise it returns false.*/
    bool empty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
};
#endif
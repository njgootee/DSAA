#ifndef __NODE_H
#define __NODE_H
#include <string>
using namespace std;

class Node{
    public:
        Node(string);
        ~Node(){};
    private:
        Node* left;
        Node* right;
        string data;
        int height;
        friend class AVLTree;
};

#endif
#ifndef __AVLTREE_H
#define __AVLTREE_H
#include "Node.h"
using namespace std;
class AVLTree{
    public:
        AVLTree();
        //Insert an item to the binary search tree and perform rotation if necessary.
        void insert(const string &);
        // Return the balance factor of a given node.
        int balanceFactor(Node*);
        //Traverses and prints the tree in inorder notation. 
        //Prints the string followed by its balance factor in parentheses followed by a , and one space.
        void printBalanceFactors();
        //Generate dotty file and visualize the tree using dotty program. 
        void visualizeTree(const string &);
    private:
        //Implements four possible imbalance cases and update the parent of the given node
        Node* rotate(Node*, string);
        //Rotate the subtree to left at the given node and returns the new subroot.
        Node* rotateLeft(Node*);
        //Rotate the subtree to right at the given node and returns the new subroot.
        Node* rotateRight(Node*);

        void printBalanceFactors(Node *);

        void visualizeTree(ofstream &, Node *);

        Node* root;

        int maxInt(int, int);

        int height(Node*);

        Node* insertBST(Node*, const string &);

};
#endif
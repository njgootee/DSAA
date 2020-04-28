 #include "AVLTree.h"
 #include <iostream>
 #include <queue>
 #include <cstdlib>
 #include <fstream>
 using namespace std;

//return max of two height ints
int AVLTree::maxInt(int a, int b){
    return (a>b)? a: b;
}

//return height or zero for null node
int AVLTree::height(Node* temp){ 
    if(temp==0){
        return 0;
    }
    return temp->height;
}

//constructor
AVLTree::AVLTree(){
    root=0;
}

//insert as BST, update height then perform rotations if necessary
Node* AVLTree::insertBST(Node* temp, const string &s){
    if(temp==0){
        return new Node(s);
    }
    if(s<temp->data){
        temp->left=insertBST(temp->left,s);
    }else if (s>temp->data){
        temp->right = insertBST(temp->right, s);
    }
    else{
        return temp;
    }
    //Height update for rotation, balance factor
    temp->height=maxInt(height(temp->left), height(temp->right))+1;
    //Rotation
    return rotate(temp,s);
}

//Insert an item to the binary search tree and perform rotation if necessary.
void AVLTree::insert(const string &s){
    root=insertBST(root, s);
}

// Return the balance factor of a given node.
int AVLTree::balanceFactor(Node* node){
    if(node == 0){
        return 0;
    }
    return height(node->left) - height(node->right);
}
//Traverses and prints the tree in inorder notation. 
//Prints the string followed by its balance factor in parentheses followed by a , and one space.
void AVLTree::printBalanceFactors(){
    printBalanceFactors(root);
    cout << endl;
}

//Generate dotty file and visualize the tree using dotty program. 
void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

//Checks imbalance cases and updates the parent of the given node
Node* AVLTree::rotate(Node* temp, string s){
    int balance = balanceFactor(temp);
    //left left
    if (balance > 1 && s< temp->left->data){
        return rotateRight(temp);
    }
    // right right
    if(balance < -1 && s>temp->right->data){
        return rotateLeft(temp);
    }
    //left right
    if(balance > 1 && s>temp->left->data){
        temp->left = rotateLeft(temp->left);
        return rotateRight(temp);
    }
    //right left
    if(balance < -1 && s <temp->right->data){
        temp->right = rotateRight(temp->right);
        return rotateLeft(temp);
    }
    return temp;
}

//Rotate the subtree to left at the given node and returns the new subroot.
Node* AVLTree::rotateLeft(Node* root){
    Node* a = root->right;
    Node* b = a->left;

    //rotate
    a->left = root;
    root->right =b;

    //height update
    root->height= max(height(root->left), height(root->right))+1;
    a->height = max(height(a->left), height(a->right))+1;
    return a;
}
//Rotate the subtree to right at the given node and returns the new subroot.
Node* AVLTree::rotateRight(Node* root){
    Node* a = root->left;
    Node* b = a->right;

    //rotate
    a->right = root;
    root->left = b;

    //height update
    root->height=max(height(root->left), height(root->right))+1;
    a->height=max(height(a->left), height(a->right))+1;

    return a;
}

//recursive print
void AVLTree::printBalanceFactors(Node * temp){
    if(temp!=0){
        printBalanceFactors(temp->left);        
        cout<< temp->data << "(" <<balanceFactor(temp) <<")" << ", ";
        printBalanceFactors(temp->right);
    }
}

//Visualize Tree
void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}
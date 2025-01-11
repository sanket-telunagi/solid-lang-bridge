#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct Node{
    int val ;
    Node * left ;
    Node * right ;
} ;


void inorder (Node * root){
    if (root == NULL) return ;
    cout << root->val << endl ;
    inorder(root->left) ;
    inorder(root->right) ;
}

Node * newNode(int val) {
    Node * root = (Node *) malloc(sizeof(Node));
    root->val = val ;
    root->left = nullptr ;
    root->right = nullptr ;
    return root ;
}

class node {

    public :
    int val ;
    node * left = nullptr ;
    node * right = nullptr ;

    public :
    node (int v) {
        val = v ;
    }
};


/*

                        3
                       / \
                      /   \
                     /     \ 
                    /       \ 
                   /         \ 
                  5           6
                 /             \
        
                  
 
*/

int main()
{
    Node * root = newNode(3);
    
    root->left = newNode(5) ;
    root->left->left = newNode(6) ;
    root->left->right = newNode(2) ;
    root->left->right->left = newNode(7) ;
    root->left->right->right = newNode(4) ;

    root->right = newNode(1) ;
    root->right->left = newNode(0) ;
    root->right->right = newNode(8) ;

    // cout << root->val << endl ;


    // Node r ;
    // r.val = 2 ;
    // cout << r.val << endl ;
    inorder(root) ;

    // node n1 = node(10) ;
    // cout << n1.val << " " << n1.left << endl ;
    return 0 ;
}
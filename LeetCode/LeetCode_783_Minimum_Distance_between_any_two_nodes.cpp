#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct TreeNode {
    int val ;
    TreeNode * left ;
    TreeNode * right ;
    TreeNode(int x) : val(x) , left(NULL), right(NULL) {}
} ;

typedef TreeNode TreeNode ;

void traverse(TreeNode * root, vector<int> & nodes) {
    if (root == NULL) return ;
    traverse(root->left, nodes) ;
    nodes.push_back(root->val) ;
    traverse(root->right, nodes) ;
}

// int minDiffInBST(TreeNode* root) {
//     vector<int> nodes ;
//     traverse(root, nodes) ;
//     int ans = INT_MAX ;
//     for (int i = 0; i < nodes.size() - 1; i++)
//     {
//         ans = min(ans, nodes[i+1] - nodes[i]) ;
//     }
//     return ans ;
    
// }

/*
    The other way
*/

void inorder(TreeNode * root, TreeNode * prev, int & diff) {
    // perform inorder traversal
    if(root == nullptr) return ;

    // go left , get root, go right
    // left
    inorder(root->left, prev, diff) ;

    // root 
    if (prev != nullptr) {
        diff = min(diff, root->val - prev->val) ;
    }
    prev = root ;

    // right 
    inorder(root->right, prev, diff) ;
}

int minDiffInBST (TreeNode * root) {
    int diff = INT_MAX ;
    TreeNode * prev = NULL ;
    inorder(root, prev, diff) ;
    return diff ;
}


int main()
{
    TreeNode * root = new TreeNode(4) ;
    root->left = new TreeNode(2) ;
    root->left->left = new TreeNode(1) ;
    root->left->right = new TreeNode(3) ;
    root->right = new TreeNode(6) ;

    cout << minDiffInBST(root) ;
    return 0 ;
}
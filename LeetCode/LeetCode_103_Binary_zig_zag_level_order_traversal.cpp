/*
    Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
    (i.e., from left to right, then right to left for the next level and alternate between).
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct TreeNode {
    int val ;
    TreeNode * left ;
    TreeNode * right ;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef struct TreeNode TreeNode ;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res ;
    queue <TreeNode *> dq ;

    if (root != nullptr)
        dq.push(root) ;

    while (!dq.empty())
    {
        int n = dq.size() ;
        vector<int> level ;
        for (int i = 0; i < n; i++)
        {
            TreeNode * node = dq.front() ;
            dq.pop() ;
  
            level.push_back(node->val) ;
            if (node->left != nullptr) dq.push(node->left) ;
            if (node->right != nullptr) dq.push(node->right) ;
         
        }
       
        if(level.size() % 2 != 0) reverse(level.begin(),level.end()) ;
        res.push_back(level) ;
    }
    return res ;
}

int main()
{

    // Tree 1
    TreeNode * root ;
    root = new TreeNode(3) ;
    root->left = new TreeNode(9) ;
    root->right = new TreeNode(20) ;
    root->right->left = new TreeNode(15) ;
    root->right->right = new TreeNode(7) ;

    for(auto & it : zigzagLevelOrder(root)) {
        for(auto & i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}
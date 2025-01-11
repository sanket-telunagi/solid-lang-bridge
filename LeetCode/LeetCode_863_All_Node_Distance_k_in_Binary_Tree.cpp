#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct Node{
    int val ;
    Node * left ;
    Node * right ;
} ;

void inorder (Node * root, Node * par, unordered_map<int, vector<int>> & mp){
    if (root == NULL) return ;

    if (par != nullptr) {
        mp[par->val].push_back(root->val) ;
        mp[root->val].push_back(par->val) ;
    }

    inorder(root->left, root, mp) ;
    inorder(root->right, root, mp) ;

}

Node * newNode(int val) {
    Node * root = (Node *) malloc(sizeof(Node));
    root->val = val ;
    root->left = nullptr ;
    root->right = nullptr ;
    return root ;
}

int main()
{
    // Tree 1 
    Node * root = newNode(3);
    
    root->left = newNode(5) ;
    root->left->left = newNode(6) ;
    root->left->right = newNode(2) ;
    root->left->right->left = newNode(7) ;
    root->left->right->right = newNode(4) ;

    root->right = newNode(1) ;
    root->right->left = newNode(0) ;
    root->right->right = newNode(8) ;

    unordered_map<int, vector<int>> mp ;
    inorder(root, nullptr, mp) ;

    // Tree 2
    // Node * root = newNode(1) ;


    for (auto & it : mp) {
        cout << it.first << " : " ;
        for (auto i : it.second) {
            cout << i << ' ' ;
        }
        cout << endl ;
    }

    // problem input 
    int target , k ;
    cin >> target >> k ; 
    int vis[mp.size() + 1] = {0} ;
    int lev[mp.size() + 1] = {0} ;
    vector<int> res ;
    queue<int> q ;
    q.push(target) ;

    while (!q.empty()) {
        int v = q.front() ;
        q.pop() ;
        vis[v] = true ;
        for (int child : mp[v]) {
            if (!vis[child]) {

            q.push(child) ;
            lev[child] = lev[v] + 1;
            }
        }
       
    }

    while (!q.empty()) {
        cout << q.front() << " " ;
        q.pop() ;
    }

    for(int i = 0 ; i < mp.size() + 1; i++) {
        if (lev[i] == k) res.push_back(i) ;
        cout << lev[i] << " " ;
    }
    cout << endl ;

    for (auto it : res) {
        cout << it << " " ;
    }
    return 0 ;
}
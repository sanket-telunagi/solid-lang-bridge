/*
    In graph theory and computer science, the lowest common ancestor (LCA) 
    (also called least common ancestor) of two nodes v and w in a tree or 
    directed acyclic graph (DAG) T is the lowest (i.e. deepest) 
    node that has both v and w as descendants, where we define each node to 
    be a descendant of itself (so if v has a direct connection from w, w is the lowest common ancestor).
*/

#include<bits/stdc++.h>
#include <iostream>


using namespace std ;

void printV(vector<int> & V) {
    for(auto i : V) cout << i << " " ;
    cout << endl ;
}

void DFS(vector<vector<int>> & g, vector<int> & parents, int vertex, int par = -1) {
    parents[vertex] = par ;
    for(int & child : g[vertex]) {
        if (child == par) continue;
        DFS(g, parents, child, vertex) ;
    }
}

vector<int> Vpath(int node, vector<int> & parents) {
    vector <int> path;
    while (node != -1)
    {
        path.push_back(node) ;
        node = parents[node] ;
    }
    reverse(path.begin(), path.end()) ;
    return path ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> g(n+1) ;
    vector<int> parents(n+1, -1) ;

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2 ;
        cin >> v1 >> v2 ;
        g[v1].push_back(v2) ;
        g[v2].push_back(v1) ;
    }

    // calling DFS to store all parents
    DFS(g, parents, 1) ;



    int n1 , n2 ;
    cin >> n1 >> n2 ;
    vector<int> pn1 = Vpath(n1, parents), pn2 = Vpath(n2,parents) ;
  
    printV(pn1) ; printV(pn2) ;
    // finding lca
    int lca = -1 ;
    for (int i = 0; i < min(pn1.size(), pn2.size()); i++)
    {
        if (pn1[i] == pn2[i]) lca = pn1[i] ;
        else break;
    }
    cout << lca << endl ;
   
    return 0 ;
}
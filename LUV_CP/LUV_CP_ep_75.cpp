/*
    finding diameter of the tree 
    diameter : maximum didstance between any two nodes of the tree
*/

/*

    approach :
    run a dfs to find the node of maximum distance
    now the node with maximum distance will be one of the ends of the diameter
    so use that node to calculate the dfs
    and get the maximum diastance 
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void DFS(vector<vector<int>> & G, vector<int> & depth, int vertex , int pr = 0 ) {


    for (auto & child : G[vertex]) {

        if (child == pr) continue; 

        depth[child] = depth[vertex] + 1 ;

        DFS(G, depth, child, vertex) ;
    }
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> g(n + 1) ;
    for (int i = 0; i < n; i++)
    {
        int v1, v2 ;
        cin >> v1 >> v2 ;
        g[v1].push_back(v2) ;
        g[v2].push_back(v1) ;
    }
    vector<int> depth (n + 1,1) ;
    DFS(g, depth, 1) ; 

    int max_distance = -1 ;
    int max_distance_node ;
    for(int i =0 ; i < n ; i++) {
        if (depth[i] > max_distance) {
            max_distance = depth[i] ;
            max_distance_node = i ;
        }
        depth[i] = 0 ;
    }

    DFS(g, depth, max_distance_node) ;


    for(int i = 0 ; i < n ; i++) {
        if (depth[i] > max_distance) {
            max_distance = depth[i] ;
        }
    }
    cout << max_distance << endl ;
    return 0 ;
}
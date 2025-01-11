/*
    --- Program to calculate height and depth of each node

    Height : height of node is maximum distance of node in that subtree
    Depth  : maximum distance of node from root node 
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void printG(vector<vector<int>> & G) {
    int i = 0 ;
    for (auto & it : G) {
        cout << i << " : " ;
        for (auto & i : it ) {
            cout << i << " " ;
        }
        cout << endl ;
        i++ ;
    }
}

void cal_Depth_Hight_DFS(vector<vector<int>> & G, int * depth, int * height , int vertex, int par = 0) {
    // perform operation on vertex on entering the vertex

    for (auto & child : G[vertex]) {
        // Perform operation on entering the child
        if (child == par) continue;

        depth[child] = depth[vertex] + 1 ;

        cal_Depth_Hight_DFS(G, depth, height, child, vertex) ;

        // perform operation on leaving the child
        // height[vertex] = max(height[vertex], height[child] + 1) ;
        int temp = height[vertex] ;
        temp = max(temp, height[child] + 1) ;
        height[vertex] = max(height[vertex], temp) ;
    }

    // perform operation on vertex while leaving the vertex
}

void printArr(int * arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> g(n) ;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2 ;
        cin >> v1 >> v2 ;
        g[v1].push_back(v2) ;
        g[v2].push_back(v1) ;
    }

    int depth[n] = {0}, height[n] = {0} ;

    cal_Depth_Hight_DFS(g, depth, height, 0) ;

    for (int i = 0; i < n; i++)
    {
        cal_Depth_Hight_DFS(g, depth, height, i) ;
    }
    


    printArr(depth, n) ;
    printArr(height, n) ;
    
    return 0 ;
}
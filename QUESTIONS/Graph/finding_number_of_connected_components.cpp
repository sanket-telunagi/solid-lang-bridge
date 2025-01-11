#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void traverse(unordered_map<int, vector<int>> & mp, int i, int * vis) {
    vis[i] = 1 ;
    for (auto child : mp[i]) {
        if(vis[child]) continue ;
        traverse(mp, child, vis) ;
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.

    unordered_map<int, vector<int>> g ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (roads[i][j]) {
                g[i].push_back(j) ;
                g[j].push_back(i) ;
            }
        }
        
    }

    int ct = 0 ;
    int vis[n+1] = {0} ;

    for (int i = 0 ; i < n ; i++) {
        if (!vis[i]) {
            traverse(g, i, vis) ;
            ct++ ;
        }
    }
    
    return ct ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> mat(n, vector<int> (n,0)) ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j] ;
        }
        
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat[i][j] ;
    //     }
        
    // }

    cout << findNumOfProvinces(mat, n) ;
    
    return 0 ;
}
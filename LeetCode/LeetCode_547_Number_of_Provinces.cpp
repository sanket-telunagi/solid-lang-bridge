#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void dfs(int i , int * vis, unordered_map<int, vector<int>> & mp) {
    vis[i] = true ;

    for(int child : mp[i]) {
        if(vis[child]) continue;
        dfs(child, vis, mp) ;
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_map<int, vector<int>> mp ;
    int n = isConnected.size() ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j]) {
                mp[i].push_back(j) ;
                mp[j].push_back(i) ;
            }
        }
        
    }

    int vis[n] = {0} , ct = 0 ;

    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue; 
        dfs(i, vis, mp) ;
        ct++ ;
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

    cout << findCircleNum(mat) ;
    return 0 ;
}
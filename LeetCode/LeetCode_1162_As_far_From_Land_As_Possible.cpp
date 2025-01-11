/*
    Using multisource BFS
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size() ;
    deque<pair<int, int>> dq ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1) {
                dq.push_back({i,j});
            }
        }
        
    }

    int res = -1 ;
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}} ;
    while (dq.empty() != true) {
        pair<int,int> pos = dq.front() ;
        dq.pop_front() ;

        res = grid[pos.first][pos.second] ;
        for (auto & pr : directions) {
            pair<int,int> new_pos = {(pos.first + pr.first),(pos.second+ pr.second)} ;
            if ((min(new_pos.first, new_pos.second) >= 0) && (max(new_pos.first, new_pos.second) < n) && (grid[new_pos.first][new_pos.second] == 0)) {
                dq.push_back(new_pos) ;
                grid[new_pos.first][new_pos.second] = grid[pos.first][pos.second] + 1 ;
            } 
        }
    }
    
    if (res > 1) return res - 1;
    else return -1 ;
}


int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> grid(n, vector<int> (n, 0)) ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j] ;
        }
        
    }

    cout << maxDistance(grid) << endl ;
    
    return 0 ;
}
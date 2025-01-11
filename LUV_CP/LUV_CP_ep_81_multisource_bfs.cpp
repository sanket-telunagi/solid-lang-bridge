#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isValid(int i , int j, int n ,int m) {
    return i >= 0 and j >= 0 and i < m and j < n ;
}

int bfs(vector<vector<int>> & grid) {
    vector<pair<int,int>> movements = {
        {0,1}, {1, 0}, {-1, 0}, {0, -1}
    } ;

    int mx = 0 ;
    int m = grid.size(), 
        n = grid[0].size() ;
    bool vis [m][n] = {0} ;
    int lev[m][n] = {0} ;

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         mx = max(mx, grid[i][j]) ;
    //     }
        
    // }
    

    queue<pair<int,int>> q ;

    // push  pairs with maximum value 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2) {
                q.push({i,j}) ;
            }
        }
        
    }

    int res = INT_MIN ;
    int ct = 0 ;
    while (!q.empty())
    {
        int vx = q.front().first ;
        int vy = q.front().second ;
        q.pop() ;
        // if (grid[vx][vy] == 0 ) continue; 

        for (auto move : movements) {
            int next_x = move.first + vx ,
                next_y = move.second + vy ;

            if (!isValid(next_x, next_y, m, n)) continue;
            if(vis[next_x][next_y]) continue;
            if (grid[next_x][next_y] == 0) continue;

            q.push({next_x, next_y}) ;
            vis[next_x][next_y] = true ;
            grid[next_x][next_y] = 2 ;
            // lev[next_x][next_y] = lev[vx][vy] + 1 ;
            // res = max(res, lev[next_x][next_y]) ;
        }
        ct ++ ;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1) return -1 ;
        }
        
    }
    
    
    return ct ;

}

int orangesRotting(vector<vector<int>>& grid) {
    // return bfs(grid) ;
    int ROWS = grid.size(), 
        COLS = grid[0].size() ,
        fresh = 0 ;
    
    queue<pair<int,int>> q;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 2) q.push({i, j}) ;
            if (grid[i][j] == 1) fresh++ ;
        }
        
    }

    vector<pair<int,int>> movements = {
        {0,1}, {1, 0}, {-1, 0}, {0, -1}
    } ;

    int ct = 0 ;
    while (!q.empty() and fresh > 0)
    {
        // for dynamicaly changing size
        int s = q.size() ;
        for (int i = 0 ; i < s; i++) {
            pair<int,int> co = q.front() ;
            q.pop() ;
            for (auto move : movements) {
                int r = co.first + move.first ;
                int c = co.second + move.second ;

                // invalid positions 
                if (r < 0 || c < 0 || r >= ROWS || c >= COLS) continue; 

                if (grid[r][c] != 1) continue;
                q.push({r, c}) ;
                grid[r][c] = 2 ;
                fresh-- ; // decreament fresh oranges 

            }
        }
        ct ++ ;

    }
    
    return fresh != 0 ? -1 : ct ;
}

int main()
{
    int m, n ;
    cin >> m >> n  ;

    vector<vector<int>> grid(m, vector<int> (n, 0)) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j] ;
        }
        
    }

    cout << orangesRotting(grid) << endl ;
    

    return 0 ;
}
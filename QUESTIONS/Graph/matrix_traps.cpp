#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void dfs(int i, int j , vector<vector<bool>> & vis, vector<vector<int>> & matrix) {
    
    int ROWS = matrix.size() , 
        COLS = matrix[0].size() ;
    
    // return if invalid 


    // if (i < 0 || j < 0 || i >= ROWS || j >= COLS || matrix[i][j] == 1 || vis[i][j] == true) return ;

    // mark them visited 
    vis[i][j] = true ;

    // traverse with allowed movements 
    vector<pair<int,int>> movements = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    } ;

    for (auto & move : movements) {
        int nextX = i + move.first ,
            nextY = j + move.second ;
        if (nextX < 0 || nextY < 0 || nextX >= ROWS || nextY >= COLS || matrix[nextX][nextY] == 1 || vis[nextX][nextY] == true) continue ;
        dfs(nextX, nextY, vis, matrix) ;
        // vis[nextX][nextY] = true ;
    }


}

int matrixTraps(int N,int M,vector<vector<int>> &matrix)
{
    int ROWS = matrix.size() , 
        COLS = matrix[0].size() ;

        // cout << ROWS << " " << COLS << endl ;

    vector<vector<bool>> vis (ROWS, vector<bool> (COLS, false)) ;
    // taverse for all boarders

    for (int i = 0; i < ROWS; i++)
    {
        
        // if (matrix[i][0] == 1 or matrix[i][COLS-1] == 1) continue ;
        // cout << i << endl ;
        if (!vis[i][0] && matrix[i][0] != 1) {
            dfs(i, 0, vis, matrix) ;
        }

        if (!vis[i][COLS-1] && matrix[i][COLS - 1] != 1) {
            dfs(i, COLS - 1, vis, matrix) ;
        }

    }

    for (int i = 0; i < COLS; i++)
    {
        if (!vis[0][i] && matrix[0][i] != 1) {
            dfs(0, i, vis, matrix) ;
        }

        if (!vis[ROWS - 1][i] && matrix[ROWS - 1][i] != 1) {
            dfs(ROWS - 1, i, vis, matrix) ;
        }

    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (matrix[i][j] == 1) {
                vis[i][j] = true ;
            }
        }

    }

    // print matrix 

    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         cout << vis[i][j] << " " ;
    //     }
    //     cout << endl ;
        
    // }
    

    int ct = 0 ;
    // traverse except borders 
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (!vis[i][j] && matrix[i][j] != 1) {
                // cout << i << " " << j << " " << ++ct << endl ;
                ct++ ;
                vis[i][j] = true ;
            }
        }
        
    }
    
    return ct ;
    
}
       

int main()
{
    int m, n ;
    cin >> m >> n ;
    /*
        m : rows
        n : cols 
    */
    vector<vector<int>> grid(m, vector<int> (n, 0)) ;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j] ;
        }
        
    }

    cout << matrixTraps(m, n, grid) ;
    return 0 ;
}
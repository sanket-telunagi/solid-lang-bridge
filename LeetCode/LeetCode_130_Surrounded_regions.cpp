#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void dfs(int i, int j, vector<vector<bool>> & vis, vector<vector<char>> & board) {
    
    int ROWS = board.size(),
        COLS = board[0].size() ;
    
    vis[i][j] = true ;

    // traverse to all the children 
    vector<pair<int,int>> movements = {
        {0,1}, {0, -1}, {1, 0}, {-1, 0}
    } ;

    for (auto move : movements) {
        int nextX = i + move.first ,
            nextY = j + move.second ;

        // all teh invalid conditions 
        if (nextX < 0 || nextX >= ROWS || nextY < 0 || nextY >= COLS || vis[nextX][nextY] == true || board[i][j] == 'X') continue ;

        // start dfs 
        dfs(nextX, nextY, vis, board) ;
    }
}

void solve(vector<vector<char>>& board) {
    int ROWS = board.size(), 
        COLS = board[0].size() ;

    // vivited array 
    vector<vector<bool>> vis(ROWS, vector<bool>(COLS, 0)) ;

    // first get all the connected zeros from the zeros at the borders of the mat and mark vsited 
    for (int i = 0; i < COLS; i++)
    {
        // first row
        if ( !vis[0][i]) {
            dfs(0, i, vis, board) ;
        }

        // last row
        if (!vis[ROWS - 1][i]) {
            dfs(ROWS - 1, i, vis, board) ;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        // first COL
        if ( !vis[i][0]) {
            dfs(i, 0, vis, board) ;
        }

        // last COL
        if (!vis[i][COLS - 1]) {
            dfs(ROWS - 1, i, vis, board) ;
        }
    }
    
    // now rest of the elements with zeros mark as 'X'

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (!vis[i][j] and board[i][j] != 'X') {
                board[i][j] = 'X' ;
            }
        }
        
    }
    

    
}

int main()
{
    int m, n ;
    // m : ROWS
    // n : COLS
    cin >> m >> n ;
    vector<vector<char>> mat (m, vector<char> (n, '0')) ;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j] ;
        }
        
    }

    // print(mat)


    solve(mat) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}
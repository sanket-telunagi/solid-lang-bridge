#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void bfs(vector<vector<int>> & mat, vector<vector<int>> & resDist) {
    int ROWS = mat.size(), 
        COLS = mat[0].size() ;

    // use multisource bfs 
    bool vis[ROWS][COLS] ;

    // queue of co-ordinates and levels 
    queue<pair<pair<int,int>, int>> q ;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (mat[i][j] == 0) {
                q.push({{i,j}, 0}) ;
                // 1 at level zero 
                vis[i][j] = 1 ;
            } else {
                vis[i][j] = 0 ; // all other are unvisited 
            }
        }
        
    }

    // all allowed movements 
    vector<pair<int,int>> movements = {
        {0,1}, {0,-1}, {1, 0}, {-1, 0}
    } ;

    while (!q.empty()) {

        // take the current size of queue 
        int curr_size = q.size() ;

        // start bfs for there many times 
        // multisource bfs 
        for (int i = 0 ; i < curr_size; i++) {
            pair<int,int> position = q.front().first ;
            int curr_lev = q.front().second ;

            // pop the element
            q.pop() ;

            // save the resulatant distance 
            resDist[position.first][position.second] = curr_lev ;

            // now go for all the moves from current position 
            for(auto move : movements) {

                int nextX = move.first + position.first ;
                int nextY = move.second + position.second ;

                // invalid conditions 
                if (nextX < 0 || nextX >= ROWS || nextY < 0 || nextY >= COLS || vis[nextX][nextY]) continue ;

                q.push({
                    {nextX, nextY} ,
                    curr_lev + 1  // increament the level 
                }) ;

                vis[nextX][nextY] = true ;
            }
        }
    }
}

vector < vector < int > > updateMatrix(vector < vector < int >> & mat) {
    // Write your code here.
    int ROWS = mat.size(),
        COLS = mat[0].size() ;

    vector<vector<int>> resDist(ROWS, vector<int>(COLS, 0)) ;

    bfs(mat, resDist) ;
    return resDist ;
}

int main()
{
    {
        int n , m ;
        // m : rows 
        // n : cols

        cin >> m >> n ;

        vector<vector<int>> grid (m, vector<int> (n, 0)) ;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j] ;
            }
            
        }
        
        // print grid
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl ;
        // }

        for (auto it : updateMatrix(grid)) {
            for (auto i : it) {
                cout << i << " " ;
            }
            cout << endl ;
        }

    }
    return 0 ;
}
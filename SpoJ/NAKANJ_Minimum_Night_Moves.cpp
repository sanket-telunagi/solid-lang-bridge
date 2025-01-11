#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int getX(string & pos) {
    return pos[0] - 'a' ;
}

int getY(string & pos) {
    return pos[1] - '1' ;
}

bool isValid(int x , int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8 ;
}


int min_steps_BFS (string p1, string p2) {
    int sourseX = getX(p1) , sourseY = getY(p1) ;  // sourse coordinates
    int destX = getX(p2) , destY = getY(p2) ;      // destination coordinates

    // movements knight can do
    vector<pair<int,int>> movements = {
        {1,2}, {-1,2}, // up right left
        {1,-2}, {-1, -2}, // down right left
        {2,1} , {2,-1}, // right up down
        {-2,1}, {-2,-1} // left up down
    } ;

    // board with 
    //      level : steps to reach current box from sourse
    //      VIsited : to set the visited positions

    vector<vector<int>> level(8, vector<int> (8, -1)), visited(8, vector<int> (8,0)) ;

    // queue to BFS
    // cout << sourseX << " " << sourseY << endl ;
    queue<pair<int, int>> knight_pos ;
    knight_pos.push(make_pair(sourseX, sourseY)) ;
    // cout << knight_pos.front().first << knight_pos.front().second << endl ;
    visited[sourseX][sourseY] = 1 ;
    level[sourseX][sourseY] = 0 ;
    

    while (!knight_pos.empty())
    {
        pair<int, int> pos = knight_pos.front() ;
        knight_pos.pop() ;

        // movements will be its children
        for(auto & move : movements) {
            int next_x = pos.first + move.first , next_y = pos.second + move.second ;

            // if the next move is valid then only proceed
            if (!isValid(next_x, next_y)) continue ;

            if (!visited[next_x][next_y]) {
                knight_pos.push({next_x, next_y}) ;
                visited[next_x][next_y] = 1 ;
                level[next_x][next_y] = level[pos.first][pos.second] + 1;
            }

        }
        if (level[destX][destY] != -1) break;  // reached the desination return steps
    }
    return level[destX][destY] ;
}

int main()
{
    int t ; 
    cin >> t ;
    while (t--)
    {
        string p1, p2 ;
        cin >> p1 >> p2 ;
        // cout << p1 << " " << p2 << endl ;
        cout << min_steps_BFS(p1, p2) << endl  ;
    }
    
    return 0 ;
}
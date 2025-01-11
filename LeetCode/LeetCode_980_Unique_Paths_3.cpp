#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
const int N = 30 ;
bool visited[N][N] = {0};

// bool isValid(vector<vector<int>> & grid, pair<int, int> & start){
//     if (start.first < 0 || start.second < 0 || start.first >= grid.size() || start.second >= grid[0].size() || grid[start.first][start.second] == -1){
//         return false ;
//     }else {
//         return true ;
//     }
// }

bool isValid(pair<int,int>  pr, int & m ,  int & n, vector<vector<int>> & grid) {
    if((pr.first >=0 && pr.first < m) && (pr.second >= 0 && pr.second < n) && visited[pr.first][pr.second] != 1 && grid[pr.first][pr.second] == 0) {
        return true ;
    }else {
        return false ;
    }
}

void findPath(vector<vector<int>> & grid, vector<pair<int, int>> & path, vector<vector<pair<int,int>>> & paths ,pair<int, int>  start) {
    if (grid[start.first][start.second] == -1) return ;
    if (grid[start.first][start.second] == 2) {
        paths.push_back(path) ;
        return ;
    }
    int m = grid.size(), n = grid[0].size() ;
    if(isValid(start, m , n, grid)) {
        visited[start.first][start.second] = 1 ;
        // move up
        path.push_back(start) ;
        findPath(grid, path, paths, {start.first - 1, start.second}) ;
        path.pop_back() ;

        // move down 
        path.push_back(start) ;
        findPath(grid, path, paths, {start.first + 1, start.second}) ;
        path.pop_back() ;

        // Move left
        path.push_back(start) ;
        findPath(grid, path, paths, {start.first , start.second - 1}) ;
        path.pop_back() ;

        // move right 
        path.push_back(start) ;
        findPath(grid, path, paths, {start.first, start.second + 1}) ;
        path.pop_back() ;

        visited[start.first][start.second] = 0 ;
    }
}

void printPaths(vector<vector<pair<int,int>>> & paths) {
    for (auto & it : paths) {
        for(auto & i : it) {
            cout << "(" << i.first << ", " << i.second << "), " ;
        }
        cout << endl ;
    }
}

int main()
{
    int m ,n ;
    cin >> m >>  n ;
    pair<int, int> start ;
    vector<vector<int>> grid(m, vector<int> (n,0)) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j] ;
            if (grid[i][j] == 1) start = {i,j} ;
        }
        
    }

    vector<vector<pair<int,int>>> paths ;
    vector<pair<int, int>> path ;
    findPath(grid, path, paths, start) ;
    printPaths(paths) ;
    // for(auto it : grid) {
    //     for(int i : it) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }
    
    return 0 ;
}
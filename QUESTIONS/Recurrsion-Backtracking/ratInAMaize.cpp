#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

const int N = 30 ;
vector<string> paths ;
int grid[N][N] ;
bool visited[N][N] = {0};
bool isValid(pair<int,int>  pr, int & m ,  int & n) {
    if((pr.first >=0 && pr.first < m) && (pr.second >= 0 && pr.second < n) && visited[pr.first][pr.second] != 1 && grid[pr.first][pr.second] == 1) {
        return true ;
    }else {
        return false ;
    }
}

void findPath(pair<int,int>  pos, int m , int n, string & path) {
    if(pos.first == m - 1 && pos.second == n - 1){
        paths.push_back(path) ;
        return ;
    }

    if(isValid(pos, m , n)) {
        visited[pos.first][pos.second] = 1 ;
        // Move Down 
        path.push_back('D') ;
        findPath( {pos.first + 1, pos.second}, m, n, path) ;
        path.pop_back() ;

        // Move Left 
        path.push_back('L') ;
        findPath({pos.first, pos.second - 1}, m, n, path) ;
        path.pop_back() ;
        // Move Right 
        path.push_back('R') ;
        findPath({pos.first, pos.second + 1}, m, n, path) ;
        path.pop_back() ;
        // Move up 
        path.push_back('U') ;
        findPath({pos.first -1 , pos.second}, m, n, path) ;
        path.pop_back() ;
        visited[pos.first][pos.second] = 0 ;
    }
}

int main()
{
    int m , n ;
    cin >> m >> n ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j] ;
        }
        
    }

    pair<int,int> pos = {0,0} ;
    string path = "" ;
    findPath(pos, m , n , path) ;

    for(auto i : paths) {
        cout << i << endl ;
    }
    
    return 0 ;
}
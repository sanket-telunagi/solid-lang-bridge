#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dfs(int i, int j, vector<vector<int>> & grid) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1) return 0 ;
    if (i == grid.size() - 1 && j == grid[0].size() - 1) return 1 ;

    vector<pair<int,int>> movements = {
        {0,1}, // go right
        {1, 0} // go down
    } ;

    // only allowed to go right or down else it will form the infinite loop 

    int ways = 0 ;

    for (auto move : movements) {
        ways += dfs(i + move.first , j + move.second, grid) ;
    }

    return ways ;


}

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    return dfs(0, 0, grid) ;
}

int main()
{
    int m, n ;
    cin >> m >> n ;
    vector<vector<int>> grid (m, vector<int> (n, 0)) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j] ;
        }
        
    }
    cout << uniquePathsWithObstacles(grid) << endl ;
    return 0 ;
}
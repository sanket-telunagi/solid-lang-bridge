/*
    Given a m x n matrix return the longest increasing path 
    in matrix 
    From each cell you can either move up, down, right, left
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


// int DFS(int i , int j,vector<vector<int>> & matrix,int initial) {
//     int m = matrix.size() ;
//     int n = matrix[0].size() ;

//     if ( i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] <= initial)  return 0;

//     int maxlength = 0 ;

    
//         // cout << initial << " " ;
//         maxlength = max({
//         // Go up
//         DFS(i , j-1, matrix, initial) ,

//         // Go down
//         DFS(i , j+1, matrix, initial) ,

//         DFS(i+1 , j, matrix, initial) ,

//         DFS(i-1 , j, matrix, initial) }) ;
//         // cout << endl ;
    
//         return maxlength + 1 ;

// }

// int longestIncreasingPath(vector<vector<int>> & matrix) {
//     // int ct = 0 ;
//     int ans = 0 ;
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         int len ;
//         for (int j = 0; j < matrix[i].size(); j++)
//         {
//              ;
//             ans = max(ans, DFS(i,j,matrix, 0)) ;
//         }
  
//     }
    
//     return ans ;
// }

// int main()
// {
//     int n , m ;
//     cin >> n >> m ;
//     vector<vector<int>> matrix ;
//     for (int i = 0; i < m; i++)
//     {
//         vector<int> temp ;
//         for (int j = 0; j < n; j++)
//         {
//             int x ;
//             cin >> x ;
//             temp.push_back(x) ;
//         }
//         matrix.push_back(temp) ;
//     }
//     cout << longestIncreasingPath(matrix) ;
//     return 0 ;
// }

#include <iostream>
#include <algorithm>

const int N = 10;

int matrix[N][N] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

int findLongestPath(int matrix[][N], int x, int y, int prev)
{
    // base case: if the current position is out of bounds or the value of the element at the current position is not greater than prev, return 0
    if (x < 0 || y < 0 || x >= N || y >= N || matrix[x][y] <= prev)
        return 0;

    int maxLength = 0;
    // try moving to the left, right, up, and down positions
    maxLength = std::max({findLongestPath(matrix, x - 1, y, matrix[x][y]),
                          findLongestPath(matrix, x + 1, y, matrix[x][y]),
                          findLongestPath(matrix, x, y - 1, matrix[x][y]),
                          findLongestPath(matrix, x, y + 1, matrix[x][y])});

    return maxLength + 1;
}

int main()
{
    int maxLength = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            maxLength = std::max(maxLength, findLongestPath(matrix, i, j, INT_MIN));
        }
    }
    std::cout << maxLength << std::endl;
    return 0;
}

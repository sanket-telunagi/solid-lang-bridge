#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int perimeter =  0 ;



void DFS(int i , int j, vector<vector<int>> & matrix, vector<vector<bool>> & visited) {
    int m = matrix.size() ;
    int n = matrix[0].size() ;

    if ( i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] != 1) {
        return ;
    }
    if (matrix[i][j] && visited[i][j] != 0) {
        visited[i][j] = true ;
      
        // cout << initial << " " ;

        // Go up
        DFS(i , j-1, matrix, visited) ;

        // Go down
        DFS(i , j+1, matrix, visited) ;

        // Go right
        DFS(i+1 , j, matrix, visited) ;

        // Go left
        DFS(i-1 , j, matrix, visited) ;
        // cout << endl ;
    }

}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> matrix ;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp ;
        for (int j = 0; j < n; j++)
        {
            int x ;
            cin >> x ;
            temp.push_back(x) ;
        }
        matrix.push_back(temp) ;
    }
    vector<vector<bool>> visited(m, vector<bool>(m,0)) ;

    int perimeter = 0 ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (( i-1 < 0 ) | (i + 1 >= m)) {
                perimeter += 1 ;
            }
            if ( ((j-1) < 0) | (j + 1 >= n)) {
                perimeter += 1 ;
            }
            if (i-1 > 0 && j - 1 > 0 && i+1 < m && i+1 < n) {
                int up = matrix[i][j-1] ;
                int down = matrix[i][j+1] ;
                int left = matrix[i-1][j] ;
                int right = matrix[i+1][j] ;
                if((left | right | up | down) == 0) {
                    perimeter += 4 ;
                }
                else if ((left ^ right ^ up ^ down) == 0) {
                    perimeter += 2 ;
                }
                else if ((left + right + up + down) == 1) {
                    perimeter += 3 ;
                }
                else if ((left + right + up + down) == 3) {
                    perimeter += 1 ;
                }
            }
        }
        
    }
    cout << perimeter ;

    return 0 ;
}
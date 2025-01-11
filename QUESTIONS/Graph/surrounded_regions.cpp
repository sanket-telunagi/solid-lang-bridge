#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void dfs () {

}

void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here   
}

int main()
{
    int m, n ;
    cin >> m >> n ;
    /*
        m : ROWS,
        n : COLS
    */

    char** mat ;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> (*(mat + i) + j) ;
        }
        
    }
    

    // /*Print the matrix*/
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout <<  mat[i][j]  << " ";
    //     }
    //     cout << endl ;
    // }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<  *(*(mat + i) + j) ;
        }
        
    }
    

    return 0 ;
}
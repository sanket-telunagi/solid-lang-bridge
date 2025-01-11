#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long int MissingNo(vector<vector<int> >& matrix) {
    pair<int,int> null ;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if(matrix[i][j] == 0){
                null.first = i ;
                null.second = j ;
            }
        }
        
    }
    
}


int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j] ;
        }
        
    }
    cout << MissingNo(matrix) ;
    return 0 ;
}
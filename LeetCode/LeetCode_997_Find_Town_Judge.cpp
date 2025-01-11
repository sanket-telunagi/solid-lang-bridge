#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int findJudge(int n, vector<vector<int>>& trust) {
        
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> trust (n, vector<int> (2)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> trust[i][0] >> trust[i][1] ;
    }
    cout << findJudge(n, trust) << endl ;
    

    return 0 ;
}
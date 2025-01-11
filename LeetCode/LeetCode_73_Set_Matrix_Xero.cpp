#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void setZeroes(vector<vector<int>>& matrix) {
        
}

int main()
{
    int m, n ;
    cin >> m >> n ;
    vector<vector<int>> nums(m, vector<int> (n,0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j] ;
        }
        
    }
    setZeroes(nums) ;

    for (auto & it : nums) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


void intToDigits(vector<int> & nums, long long num) {
    while (num > 0) {
        nums.push_back(num%10) ;
        num /= 10 ;
    }
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res = {{1}};
    if (numRows == 0) return {{}} ;

    if (numRows == 2) return {{1}, {1,1}} ;

    else if (numRows > 2) {
        int ct = 2;
        res.push_back({1,1}) ;
        for(int i = ct ; i < numRows; i++) {
            vector<int> temp ;
            temp.push_back(1) ;
            for (int j = 0 ; j < res[i-1].size() - 1; j++) {
                int num = res[i-1][j] + res[i-1][j+1] ;
                // cout << num << endl ;
                temp.push_back(num) ;
            } 
            temp.push_back(1) ;
            res.push_back(temp) ;
            // cout << res.size() << endl ;
        }
    }
    
    return res ;
}

int main()
{
    int n ;
    cin >> n ;

    vector<vector<int>> ans = generate(n) ;

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}
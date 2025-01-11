#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool cmp(vector<int> & a, vector<int> & b) {
    return a[1] < b[1] ;
}

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp) ; // sorting is important 

    // following a greedy approach 
    int ct = 0, curr_val = INT_MIN ;
    for (auto & it : pairs) {
        if (curr_val < it[0]) {
            ct++ ;
            curr_val = it[1] ;

        }
    }

    return ct ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> nums(n, vector<int> (2, 0)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1] ;
    }

    // for (auto & it : nums) cout << it[0] << " " << it[1] << endl ;
    cout << findLongestChain(nums) << endl ;
    
    return 0 ;
}
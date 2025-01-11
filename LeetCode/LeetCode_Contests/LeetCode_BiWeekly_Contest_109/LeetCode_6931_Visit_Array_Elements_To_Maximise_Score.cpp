#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

map<pair<int, bool>, long long> mp ;

long long  solve(long long  i, bool Parity, vector<int> & nums, long long  x) {
    // goes out of indices, return 
    if (i >= nums.size()) return 0 ;

    if (mp.find({i, Parity}) != mp.end()) return mp[{i, Parity}] ;

    // not take the current index but as the parity is switch 
    long long  temp1 = 0, temp2 = 0 ;
    if (nums[i] % 2 != Parity) // parity changed
        temp1 = nums[i] + solve(i + 1, !Parity, nums, x) - x;

    // taken but check if parity
    if (nums[i] % 2 == Parity)
        temp2 += nums[i] ;
    temp2 += solve(i+1, Parity, nums, x) ;

    return mp[{i, Parity}] =  max(temp1, temp2) ;
}

long long  maxScore(vector<int> & nums, long long  x) {
    bool parity = 0 ; // even parity
    if (nums[0] % 2 != 0) parity = 1 ; // start with odd parity
    // always start with 0 index
    long long  ans = nums[0] + solve(1, parity, nums, x) ;
    return ans ;
}


int main()
{
    long long  n , x;
    cin >> n >> x;
    vector<int> nums(n) ;
    for (long long  i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << maxScore(nums, x) << endl ;
    return 0 ;
}
#include <bits/stdc++.h>
#include <iostream>

/*
    Q : Find the minimum cost to reach nth stone if a frog can jump either (i+1)th or (i+2)th stone initially at start
*/

int frog_jump(int idx, vector<int> & nums) {
    int cost = INT_MAX ;

    cost = min(cost, frog_jump(idx-1, nums) + abs(nums[idx] - nums[idx - 1])) ;

    if (idx - 2 > 0) cost = min(cost, frog_jump(idx-2, nums) + abs(nums[idx] - nums[idx - 2])) ;
}

using namespace std ;
int main() {
    int n;
    cin >> n ;
    vector<int> nums (n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << frog_jump(3, nums) ;
    
    return 0 ;
}
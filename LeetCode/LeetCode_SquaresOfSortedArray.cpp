#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    set<int> temp ;
    for (int i : nums) {
        temp.insert(i*i) ;
    }
    vector<int> ans ;
    for(auto & it : temp) {
        ans.push_back(it) ;
    }
    return ans ;
}

int main() {
    
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i =0 ; i < n ; i++) {
        cin >> nums[i] ;
    }

    vector<int> ans ;
    ans = sortedSquares(nums) ;
    for (int i : ans) {
        cout << i << " " ;
    }

    return 0 ;
}
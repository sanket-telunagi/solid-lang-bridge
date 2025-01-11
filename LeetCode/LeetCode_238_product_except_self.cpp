#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> productExceptSelf(vector<int>& nums) {
    long long prod = 1 ;
    bool hasZero = false ;
    bool allZero = false ;
    int ct = 0 ;
    for (auto it : nums) {
        if (it == 0) {
            hasZero = true ;
            ct++ ;
            continue ;
        }
        prod *= it ;
    }


    // if there are more than 1 zeros whole product becomes zero 
    if (ct > 1) {
        allZero = true ;
    }

    int prod_0 = 0 ;
    int n = nums.size() ;
    vector<int> res(n) ;
    for (int i = 0; i < n; i++)
    {
        if (allZero) {
            res[i] = 0 ;
            continue ;
        }
        if (nums[i] == 0) {
            res[i] = prod ;
            continue ;
        }
        if (hasZero) {
            res[i] = 0 ;
            continue ;
        }
        res[i] = prod / nums[i] ;
    }
    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    
    for (auto it : productExceptSelf(nums)) {
        cout << it << " " ;
    }

    return 0 ;
}
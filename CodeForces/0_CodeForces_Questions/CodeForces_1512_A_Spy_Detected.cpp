#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int getIndex(int num, vector<int> & nums) {
    int idx = 0 ;
    int i = 0 ;
    for (auto it : nums) {
        if (it == num) idx = i ;
        i++ ;
    }
    return idx + 1 ;
}

int main()
{
    int t;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        int num = 0 ;
        unordered_map<int,int> mp ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            mp[nums[i]]++  ;
        }

        for (auto & it : mp) {
            if (it.second == 1) {
                num = it.first ;
            }
        }

        cout << getIndex(num, nums) << endl ;
        
    }
    return 0 ;
}
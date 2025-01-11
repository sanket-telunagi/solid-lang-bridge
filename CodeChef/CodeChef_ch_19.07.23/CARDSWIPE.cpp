#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        int arr[n+1]  ;
        memset(arr, 0, sizeof(arr)) ;
        for (int i = 0; i < n; i++)
        {
            cin >>  nums[i] ;
            
        }
        int ct = 0 ;
        unordered_set<int> s ;
        int res = 0 ;
        for (auto it : nums) {
            if (s.find(it) != s.end()) {
                s.erase(s.find(it)) ;
            } else {
                s.insert(it) ;
            }
            res = max(res,(int) s.size()) ;
        }

        for (auto it : arr) {
            // cout << it << " " ;
            if (it != 0) ct++ ;
        }

        cout << res << endl ;
        
        
    }
    return 0 ;
}
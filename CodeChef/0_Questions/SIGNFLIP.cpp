#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , k ;
        cin >> n >>  k ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        int sum = 0 ;
        sort(nums.begin(), nums.end()) ;
        if ( k == 0 ) {
            for (auto it : nums) {
                if (it <= 0) continue; 
                sum += it ;
            }
        } else {
            for (int i = 0; i < n; i++)
            {
                if (k == 0) break;
                if (nums[i] < 0) {
                    nums[i] *= -1 ;
                    k-- ;
                }
            }
            sort (nums.begin(), nums.end()) ;
            // for (auto it : nums) cout << it << " " ;
            for (auto it : nums) {
                if (it <= 0) continue; 
                sum += it ;
            }
        }
        
        cout << sum << endl ;
        
    }
    return 0 ;
}
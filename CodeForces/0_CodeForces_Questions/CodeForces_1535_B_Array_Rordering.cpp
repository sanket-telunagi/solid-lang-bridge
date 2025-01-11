#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool cmp(int x, int y) {
    return x % 2 < y % 2 ; // take even first 
}

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        sort (nums.begin(), nums.end(), cmp) ;
        int ans = 0 ;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans += __gcd(nums[i], nums[j] * 2) > 1 ;
            }
            
        }
        cout << ans << endl ;
        
    }
    
    return 0 ;
}
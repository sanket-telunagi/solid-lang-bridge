#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp [100001] ;

int lis (int idx, vector<int> & nums) {
    if (dp[idx] != -1) return dp[idx] ;



    int ct = 1 ;

    for (int j = 0; j < idx; j++)
    {
        if (nums[j] < nums[idx]) {
            ct = max(ct, lis(j, nums) + 1) ;
        }
    }

    return dp[idx] = ct ;
}

bool increasingTriplet(vector<int>& nums) {
    bool res = false ;

    int j = 0 , k = 0;
    int n = nums.size() ;
    
    if (n <= 2) return false ;

    for (int i = 0; i < n - 2; i++)
    {
        if (nums[i] >= nums[i + 1]) continue;
        
        for (j = i + 1; j < n - 1; j++)
        {
            if (nums[j] <= nums[i]) continue ;
            // cout << nums[j] << endl ;
            for (k = j + 1; k < n; k++)
            {
                if (nums[k] <= nums[j] ) continue ;
                // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl ;
                // if (k + 1 < n)
                if (nums[k] > nums[j]) return true ;
                else continue ;
            }
            if (nums[j] >= nums[j+1]) continue; 

            // j = k - 1;
            
        }

        // i = j - 1; // later i ++ ;
        
        
    }
    // memset(dp, -1, sizeof(dp)) ;

    // // return false ;
    // int n = nums.size() ;
    // int ans = 0 ;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = max(ans, lis(i, nums)) ;
    // }

    // // cout << ans << endl ;

    // if (ans >= 3) return true ;
    
    return false ;
    
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

    cout << increasingTriplet(nums) << endl ;
    
    return 0 ;
}
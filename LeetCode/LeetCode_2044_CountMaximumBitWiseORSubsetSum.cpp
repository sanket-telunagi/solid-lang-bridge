#include<bits/stdc++.h>
#include <iostream>
using namespace std ;



int countMaxOrSubsets(vector<int>& nums) {
    
    int ans = 0 ;
    int sub_ct = (1 << nums.size()) ;
    for (int  mask = 0; mask < sub_ct; mask++)
    {
        int temp = 0 ;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((mask & (1<<i)) != 0){
                temp ^= nums[i] ;
              
            } 
        }
        ans = max(ans, temp) ;
        cout << ans << " " << temp << endl;
    }
    return ans ;
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

    cout << countMaxOrSubsets(nums) ;
    
    return 0 ;
}
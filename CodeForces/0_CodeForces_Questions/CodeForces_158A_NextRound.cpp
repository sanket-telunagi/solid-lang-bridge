#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
   {
        int  t, k;
        cin >> t >> k ;
        vector<int> nums(t) ;
        for (int i = 0; i < t; i++)
        {
            cin >> nums[i] ;
        }

        // sort(nums.begin(), nums.end()) ;
        int temp = nums[k-1] ;
        int ct = 0 ;
        for (auto num : nums) {
            if (temp == 0) {
                if (num > temp) ct++ ;
            }
            else if (num >= temp) ct++ ;
        }
        cout << ct << endl ;
    }
    return 0 ;
}
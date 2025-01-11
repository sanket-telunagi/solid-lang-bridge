#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t;
    vector<int> nums(t) ;
    for (int i = 0; i < t; i++)
    {
        cin >> nums[i] ;
    }

    // let's use dutch national flag algorithm 
    int lo = 0 , hi = lo + 1 ;
    while (lo < t && hi < t) {
        if (nums[lo] >= 0 ) {
            lo++ ;
            hi ++ ;
        }
        else 
        {
            while (nums[hi] < 0 && hi < t) {
                hi++ ;
            }
            cout << nums[lo] << " " << nums[hi] << endl ;
            swap(nums[lo], nums[hi]) ;

        }
        
        
        
    }

    for (int it : nums) cout << it << " " ;
    return 0 ;
}
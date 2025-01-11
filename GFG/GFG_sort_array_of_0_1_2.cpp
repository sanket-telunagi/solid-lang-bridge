#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    vector<int> hsh(3) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
        switch (nums[i]) {
            case 0 : hsh[0]++ ;
            case 1 : hsh[1]++ ;
            case 2 : hsh[2]++ ;
        }
    }

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (nums[i] > nums[j]) {
    //             swap(nums[i], nums[j]) ;
    //         }
    //     }
        
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (i < hsh[0]) nums[i] = 0 ;
    //     else if ( i < hsh[1]) nums[i] = 1 ;
    //     else nums[i] = 2 ;
    // }

    // dutch nationanl flag algorithm

    /*
        low : all elements below low are 0
        high: all elements above high are 2
    */

    int lo = 0 , mid = 0 , hi = n - 1 ;

    while (mid <= hi) {
        switch(nums[mid]) {
            case 0 :
                swap(nums[lo++], nums[mid++]) ;
                break ;
            case 1 :
                mid++ ;
                break ;
            case 2 :
                swap(nums[mid], nums[hi--]) ;
                break ;
        }
    }
    

    for (int it : nums) cout << it << " " ;
    
    
    return 0 ;
}
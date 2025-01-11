#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int missingnumber(vector<int> & nums) {
    int n = nums.size() ;

    // int sum = n * (n + 1) / 2 ;

    // int total = accumulate(nums.begin(), nums.end(), 0) ;

    // return sum - total ;


    /*
        eg 1 : 

            3 0 1

            x = 0 

                x = x ^ 3 ^ 1
                x = x ^ 0 ^ 2
                x = x ^ 1 ^ 3

            hence at last the x becomes 2
    
    */
    int x = 0 ;

    for (int i = 0; i < n; i++)
    {
        x ^= nums[i] ^ (i + 1) ; // xoring same elements are 0 
    }
    
    return x ;
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

    cout << missingnumber(nums) << endl ;
    
    return 0 ;
}
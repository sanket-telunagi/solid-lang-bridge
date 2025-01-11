#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    for (int i = 0; i < n-1; i++) swap(nums[n - 1 - i], nums[n - 1 - (i+1)]) ;
    
    

    for(int it : nums) cout << it << " " ;
    
    return 0 ;
}
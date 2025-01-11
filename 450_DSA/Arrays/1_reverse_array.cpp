#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    int temp = n ;
    vector<int> nums(n) ;
    while(temp) {
        cin >> nums[n - temp--] ;
       
    }
    for (int i = 0; i < n / 2 ; i++)
    {
        // cout << nums[i] << " " << nums[n - i - 1] << endl ;
        swap(nums[i], nums[n - i - 1]) ;
        // cout << nums[i] << " " << nums[n - i - 1] << endl ;

    }
    for(int it : nums) {
        cout << it << " " ;
    }
    
    return 0 ;
}
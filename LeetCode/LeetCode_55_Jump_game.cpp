#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool helper(int index, vector<int> nums) {
    if (index >= nums.size()) return true ;

    // we jumped fro current index 

}

bool canJump (vector<int> & nums) {
    int mxJump = 0 ,n = nums.size() ;
    for (int i = 0; i < n; )
    {
        if (i >= n) return false ;
        
    }
    
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

    cout << canJump(nums) << endl ;
    
    return 0 ;
}
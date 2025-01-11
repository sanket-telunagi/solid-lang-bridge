#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int xorOperation(int n, int start) {
    vector<int> nums ;
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(start + 2 * i) ;
        ans ^= nums[i] ;
    }
    return ans ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    cout << xorOperation(n,k) ;
    return 0 ;
}
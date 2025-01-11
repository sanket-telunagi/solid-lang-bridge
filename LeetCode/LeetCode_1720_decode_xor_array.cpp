#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> decode(vector<int>& encoded, int first) {
    int n = encoded.size() ;
    vector<int> decoded ;
    decoded.push_back(first) ;
    for (int i = 1; i < n+1; i++)
    {
        decoded.push_back(encoded[i-1] ^ decoded[i-1]) ;
    }
    return decoded ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums, ans ;
    for (int i = 0; i < n; i++)
    {
        int x ;
        cin >> x ;
        nums.push_back(x) ;
    }
    int first ;
    cin >> first ;
    ans = decode(nums,first) ;
    for(auto it : ans) {
        cout << it << " " ;
    }
    
    
    return 0 ;
}
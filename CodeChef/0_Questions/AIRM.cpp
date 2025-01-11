#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


bool cmp (pair<int,int> & p1 , pair<int,int> & p2) {
    return p1.second < p2.first ;
}
int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        // vector<int> nums(2 * n) ;
        // for (int i = 0; i < 2 *n; i++)
        // {
        //     cin >> nums[i] ;
        // }

        // vector<pair<int,int>> planes ;
        // for (int i = 0; i < n; i++)
        // {
        //     planes.push_back({nums[i], nums[i+n]}) ;
        // }
        
        // sort(planes.begin(), planes.end()) ;

        // for (auto & it : planes)
        // {
        //     cout << it.first << " " << it.second << endl ;
        // }
        
        /*
            answer is nothing but the frequency of most frequent element 
        */
       unordered_map<int,int> mp ;
       int ct = 1 ;
        for (int i = 0; i < 2 * n; i++)
        {
            int x ;
            cin >> x ;
            mp[x]++ ;
            ct = max(ct, mp[x]) ;
        }
        cout << ct << endl ;
        
    }
    return 0 ;
}
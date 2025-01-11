#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        int l = 0 , r = 0 ;
        int hsh [8] = {0} ; // track the count 
        int ct = 0 ;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 7) {
                if (hsh[nums[i]] == 0) {
                    hsh[nums[i]] ++ ;
                    ct++ ;
                }
            }
            if (ct == 7) break ;
            r++ ;
        }

        cout << r + 1 << endl ;
        
        
    }
    return 0 ;
}
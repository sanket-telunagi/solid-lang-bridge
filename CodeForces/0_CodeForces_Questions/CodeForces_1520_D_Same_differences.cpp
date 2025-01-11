#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
int  main()
{
    long long  t ;
    cin >>t ;
    while (t-- > 0) {
        long long  n ;
        cin >> n ;
        vector<long long > nums(n) ;
        unordered_map<long long ,long long > mp ;
        long long  res = 0 ;
        for (long long  i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            nums[i] -= i ;
            res += mp[nums[i]] ;
            mp[nums[i]] ++ ;
        }

        long long  ct = 0  ;

        // for (long long  i = 0 ; i < n - 1 ; i++) {
        //     for (long long  j = i + 1; j < n ; j++) {
        //         if (nums[j] - nums[i] == j - i) ct++ ;
        //     }
        // }
        
        cout << res << endl ;
    }
    return 0 ;
}
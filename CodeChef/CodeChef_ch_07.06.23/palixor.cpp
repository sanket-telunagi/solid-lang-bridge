#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPal(long long int num) {
    bool res = true ;
    // vector<int> digits ;
    // while (num > 0) {
    //     digits.push_back(num % 10) ;
    //     num /= 10 ;
    // }
    // int n = digits.size() ;
    // // if number is with even number of digits and is divisibel by 11 it is definately palindrom 
  
    //     for (int i = 0 ; i < n / 2 ; i++) {
    //         if (digits[i] != digits[n - i - 1]) {
    //             res = false ;
    //         }
    //     }

    long long temp = num , rev = 0 ;
    while (temp > 0) {
        int digit = temp % 10 ;
        rev = rev * 10 + digit ;
        temp /= 10 ;
    }
    if (rev != num) res = false ;
   
    return res ;
}

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<long long int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        int ct = 0 ;
        /*
        // TLE
        for (int i = 0 ; i < n ; i++) {
            long long int res = nums[i] ;
            for (int j = i + 1 ; j < n; j++)
            {
       
                res ^= nums[j] ;
                if (isPal(res)) {
                    // cout << nums[i] << " " << nums[j] << endl ;
                    ct++ ;
                }
                res = nums[i] ;
            }
            
        }
        */
        sort(nums.begin(), nums.end()) ;
        
        cout << ct + n << endl ;
        
    }
    return 0 ;
}
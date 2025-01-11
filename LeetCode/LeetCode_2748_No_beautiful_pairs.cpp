#include<bits/stdc++.h>
#include <iostream>

using namespace std ;

// bool hsh[N + 1] ;

bool isPrime(int num) {
    if (num <= 1) return false ;
    bool res = true ;
    for (int i = 2; i  < num; i++)
    {
        if (num % i == 0) res = false ;
    }
    return res ;
}

bool coprime (int num1, int num2) {
    return (__gcd(num1, num2) == 1) ;
}

int fdig(int fnum) {
    int res = 0 ;
    while (fnum > 0) {
        res = fnum % 10 ;
        fnum /= 10 ;
    }
    return res ;
}

int ldig(int lnum) {
    return lnum % 10 ;
}

int countBeautifulPairs(vector<int>& nums) {
    int ct = 0 ;
    int n = nums.size() ;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (coprime(fdig(nums[i]), ldig(nums[j]))) {
                ct++ ;
                // std :: cout << nums[i] << " " << nums[j] << endl ;
            }
        }
        
    }

    // int primes = 0 ;
    int res = 0 ;

    res = ct ;
    // for (auto it : nums) {
    //     std :: cout << it << " " <<  isPrime(it) << endl ;
    //     // if (isPrime(it)) primes++ ;
    // }

    // while (primes--) {
    //     res += (--n) ;
    // }




    
    return res ;
}

int main()
{
    int n ;
    std :: cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> nums[i] ;
    }

    std :: cout << countBeautifulPairs(nums) << endl ;
    
    return 0 ;
}
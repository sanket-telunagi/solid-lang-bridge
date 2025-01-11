#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<vector<int>> findPrimePairs(int n) {
    vector<vector<int>> res ;
    multiset<int> primes ;
    vector<int> isPrime(n+1, 1); // all primes initially 
    isPrime[0] = isPrime[1] = 0 ; // 0 and 1 are not prime 

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i]) {
            primes.insert(i) ;
            for (int j = 2 * i; j <= n; j += i)
            {
                isPrime[j] = false ;
            }  
        }
    }

    // for(auto & it : primes) {
    //     cout << it << " " ;
    // }

    // two sum problem
    unordered_map<int, int> mp ;

    set<pair<int, int>> hsh ;
    for (auto & it : primes) {
        int cpt = n - it ;
        if (primes.find(cpt) != primes.end() && hsh.find({it, cpt}) == hsh.end() && hsh.find({cpt, it}) == hsh.end()) {
            hsh.insert({it, cpt}) ;
            res.push_back({it, cpt}) ;
        }
    }
    
    
    return res;
}

int main()
{
    int n ;
    cin >> n ;
    for(auto & it : findPrimePairs(n)) {
        for (auto & i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}
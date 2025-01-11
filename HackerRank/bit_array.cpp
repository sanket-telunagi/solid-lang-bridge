#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    const int N = 1e6 ;
    unordered_map<int,int> mp ;
    int n,s , p, q ;
    cin >> n >> s >> p >> q ;
    vector<int> arr ;
    arr.push_back(s % (1 << 30)) ;
    for (int i = 1; i <= n - 1; i++) {
        int num = (arr[i-1] * p + q)%(1 << 30) ;
        arr.push_back(num) ;
      
    }
    int ct = 0 ;
    for(auto i : arr){
        mp[i] ++ ;
    }
    for(auto & pr : mp){
        if (pr.second == 1){
            ct ++ ;
        }
    }
    
    cout << ct ;
    return 0;
}
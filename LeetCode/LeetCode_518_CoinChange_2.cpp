#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

unordered_map<string, int> mp ;

int solve(int curr_demonition, int curr_amount, vector<int> & coins) {
    if (curr_amount == 0) return 1 ;
    if (curr_demonition < 0) return 0 ;
    string key = to_string(curr_amount) + "$" + to_string(curr_amount) ;
    if (mp.find(key) != mp.end()) return mp[key] ;

    long long ways = 0 ;
    for (int amo = 0; amo <= curr_amount; amo += coins[curr_demonition])
    {
        ways += solve(curr_demonition -1, curr_amount - amo, coins )  ;
    }
    return mp[key] = ways ;
}

int change(int amount, vector<int>& coins) {
    return solve(coins.size() - 1, amount, coins) ;
}

int main()
{
    int n, amount ;
    cin >> n >> amount ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << change(amount, nums) << endl ;
    
    return 0 ;
}
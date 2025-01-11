#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*

    You are given a 0-indexed integer array nums representing the initial positions of some marbles. 
    You are also given two 0-indexed integer arrays moveFrom and moveTo of equal length.

    Throughout moveFrom.length steps, you will change the positions of the marbles. 
    On the ith step, you will move all marbles at position moveFrom[i] to position moveTo[i].

    After completing all the steps, return the sorted list of occupied positions.

    Notes:

        We call a position occupied if there is at least one marble in that position.
        There may be multiple marbles in a single position.
*/

vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        
    map<int, int> mp ;
    for(auto i : nums) {
        mp[i] ++ ;
    }
    int m = moveFrom.size() ;
    for (int i = 0; i < m; i++)
    {
        if (moveFrom[i] == moveTo[i]) continue ;
        mp[moveTo[i]] += mp[moveFrom[i]] ;
        mp[moveFrom[i]] = 0 ;
    }
    vector<int> res ;
    for(auto & it : mp) {
        if (it.second != 0) {
            res.push_back(it.first) ;
        }
    } 
    return res ;
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<int> nums(n), moveFrom(m), moveTo(m) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> moveFrom[i] ;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> moveTo[i];
    }
    
    for (auto i : relocateMarbles(nums, moveFrom, moveTo)) cout << i << " " ;
    
    
    return 0 ;
}
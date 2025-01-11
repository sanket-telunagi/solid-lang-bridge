#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// int numRescueBoats(vector<int>& people, int limit, int cur = 0, int idx = 0) {
//     if (cur == limit or idx == people.size()) return 1 ;
//     return min(numRescueBoats(people,limit, 0,idx + 1) + 1, numRescueBoats(people, limit, abs(limit- people[idx]),idx+1) + 1) ;
// }

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end()) ;
    int res = 0 , l = 0 , r = people.size()-1, rem = 0 ;
    while(l <= r) {
        rem = limit - people[r] ;
        r -- ;
        res ++ ;
        if (l <= r && rem >= people[l]) l++ ;
    }
    return res ;
}

int main()
{
    int n , l;
    cin >> n >> l ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << numRescueBoats(nums, l) << endl ;
    return 0 ;
}
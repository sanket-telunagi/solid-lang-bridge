#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool can_ship(vector<int> & weights, int days, int cap) {
    int ships = 1 , curr_cap = cap ;
    for (auto & wt : weights) {
        if (curr_cap - wt < 0) {
            ships++ ;
            curr_cap = cap ;
        }
        curr_cap -= wt ;
    }
    return ships <= days ;
}

int shipWithinDays(vector<int>& weights, int days) {
    int l = *max_element(weights.begin(), weights.end()) , r = accumulate(weights.begin(), weights.end(), 0);
    int res = r , cap = 0 ;

    while (l <= r) {
        cap = l + (r - l) / 2;
        if (can_ship(weights, days, cap)) {
            res = min(res, cap) ;
            r = cap - 1;
        }else {
            l = cap + 1 ;
        }
    }
    return res ;
}

int main()
{
    int n , days ;
    cin >> n >> days ;

    vector<int> wights(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> wights[i] ;
    }
    
    cout << shipWithinDays(wights, days) << endl ;

    return 0 ;
}
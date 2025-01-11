#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool canEat(vector<int> & piles, int h, int k) {
    float ct = 0 ;
    // ceil function works with float value 
    for(auto & banana : piles) {
        ct += float ;
    }
    return ct <= h ;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int s = 1, e = *max_element(piles.begin(), piles.end()) ,res ,  mid ;
    while(s <= e) {
        mid = s + (e - s) / 2 ;
        if(canEat(piles, h, mid)) {
            res = mid ;
            e = mid-1;
        }else {
            s = mid + 1;
        }
    }
    return res ;
}

int main()
{
    int n , h;
    cin >> n >> h;
    vector<int> piles(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i] ;
    }
    cout << minEatingSpeed(piles, h) << endl ;
    return 0 ;
}
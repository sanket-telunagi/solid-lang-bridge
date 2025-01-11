#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

bool cmp(pair<int, int> & p1, pair<int, int> & p2) {
  
    // if (p1.first == p2.first) {
    //     return p1.second <= p2.second ;
    // }
    // return p1.first < p2.first ;

    return (p1.first + p1.second < p2.first + p2.second) ;

}

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int>> sums ;

    for (int i = 0; i < k; i++) {
        for (int j = 0 ; j < k; j++) {
            if (i < nums1.size() && j < nums2.size()) {
                sums.push_back({nums1[i], nums2[j]}) ;
            }
        }
    }
    sort(sums.begin(), sums.end(), cmp) ;

    // for(auto & it : sums) {
    //     cout << it.first << " " << it.second << endl ;
    // }

    vector<vector<int>> res ;
    for (int i = 0 ; i < k ; i++){
        if (i < sums.size()) {
            res.push_back({sums[i].first, sums[i].second}) ;
        
        }
    }

    return res ;
}

int main() {
    int n1, n2 , k ;
    cin >> n1 >> n2 >> k ;
    vector<int> nums1(n1), nums2(n2) ;

    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i] ;
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i] ;
    }

    for(auto & it : kSmallestPairs(nums1, nums2, k)) {
        cout << it[0] << ' ' << it[1] << endl ;
    } 
    
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector <int> sortedArray(vector<int> & a, vector<int> & b) {
    vector<int> nums ;
    int x = min(a.size(), b.size()) ,
        p1 = 0,
        p2 = 0,
        n = a.size(), 
        m = b.size();

    while (p1 < n && p2 < m) {
        // cout << a[p1] << " " << b[p2] << endl ;
        if (a[p1] == b[p2] ) 
        {
            
            nums.push_back(a[p1]) ;
            p1++ ;
            p2++ ;
        } 
        else if (a[p1] < b[p2]) {
            if (nums.size() == 0 || nums.back() != b[p2])
                nums.push_back(a[p1]) ;
            p1++ ;
        }
        // if (a[p1] > b[p2]) 
        else {
            if (nums.size() == 0 || nums.back() != a[p1])
                nums.push_back(b[p2]) ;
            p2++ ;
        }
    }

    while (p1 < n) {
        nums.push_back(a[p1]) ;
        p1++ ;
    }

    while (p2 < m) {
        nums.push_back(b[p2]) ;
        p2++ ;
    }
    return nums ;
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<int> nums1(n), nums2(m) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i] ;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i] ;
    }
    
    for (auto it : sortedArray(nums1, nums2) ) {
        cout << it << " " ;
    }
    
    return 0 ;
}
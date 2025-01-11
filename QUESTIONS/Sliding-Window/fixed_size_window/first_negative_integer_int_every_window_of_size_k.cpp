#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void printQ(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;
}

void printV(vector<int> & vec) {
    for(int it : vec) cout << it << " " ;
    cout << endl ;
}

vector<int> first_negative_int(vector<int> & nums, int k) {
    int n = nums.size() ;
    int l =0 ;
    vector<int> res ;
    queue<int> q ;
    for(int r = 0 ;  r < n ; r++) {
        while (r - l + 1 < k)
        {
            if (nums[r] < 0) q.push(nums[r]) ;
            // printQ(q) ;
            r++ ;
        }
        // printQ(q);
        
        
        if (nums[r] < 0) q.push(nums[r]) ;
        // printV(res) ;
        if (r - l + 1 == k) res.push_back(q.front()) ;
        if(nums[l] < 0) q.pop() ;
        l++ ;
    }
    return res ;
}

int main() {
    int n, k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    for(int it : first_negative_int(nums, k)) cout << it << " " ;
    
    return 0 ;
}
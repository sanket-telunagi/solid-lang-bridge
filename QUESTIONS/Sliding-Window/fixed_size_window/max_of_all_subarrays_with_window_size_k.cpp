#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> max_window_element_brute(vector<int> & nums, int k) {
    // breute force

    vector<int> ans ;

    int n = nums.size() ;
    for (int i = 0; i < n-k+1; i++)
    {
        int res = INT_MIN ;
        for (int j = i; j < i + k; j++)
        {
            res = max(res, nums[j]) ;

        }
        ans.push_back(res) ;
    }
    return ans ;
}

void printq(queue<int> & q) {
    while (!q.empty())
    {
        cout<< q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;
}

void printW (vector<int> & nums, int l, int r) {
    for (int i = l; i <= r; i++)
    {
        cout << nums[i] << " " ;
    }
    cout << endl ;
    
}

vector<int> max_window_element(vector<int> & nums, int k) {
    vector<int> ans ;
    deque<int> q ;
    int l = 0, n = nums.size() ;

    int r = 0 ;
    for (r = 0;  r < n; r++)
    {
        // calculations 
        // printq(q) ;
        if(r - l + 1 < k) {
            while (!q.empty() && q.back() < nums[r]) q.pop_back() ;
            q.push_back(nums[r]) ;
            r++ ;
        }
        while (!q.empty() && (q.back() < nums[r])) q.pop_back() ;
        q.push_back(nums[r]) ;

        // removing the previous calculations and collecting answer 
        // when window size is reached 

        if (r - l + 1 == k) {
            // printW(nums, l, r) ;
            // printq(q);
            ans.push_back(q.front()) ;
            if (q.front() == nums[l]) q.pop_front() ;
            l++ ;
        
        }        
      
    }
    return ans ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    for(int it : max_window_element(nums, k)) {
        cout << it << " " ;
    }
    
    return 0 ;
}
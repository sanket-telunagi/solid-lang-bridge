#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n , k;
    cin >> n >> k;
    vector<int> nums(n) ;
    int temp = n ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    

    // use stack to store the sorted elements 
    // stack<int> stk ;
    // stk.push(nums[0]) ;
    // queue<int> q ;
    // for (int it = 1; it < temp; it++)
    // {
    //     while (stk.top() > nums[it] && !stk.empty()) {
    //         int num = stk.top() ;
    //         stk.pop() ;
    //         q.push(num) ;
    //     }
    //     while(!q.empty()) {
    //         stk.push(q.front()) ;
    //         q.pop() ;
    //     }

    //     stk.push(nums[it]) ;
    // }
    // while (!stk.empty()) {
    //     cout << stk.top() << " " ;
    //     stk.pop() ;
    // }

    sort(nums.begin(), nums.end()) ;

    cout << nums[k - 1] << endl ;
    return 0 ;
}
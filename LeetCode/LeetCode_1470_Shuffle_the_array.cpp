#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void printV(vector<int> ans) ;

vector<int> shuffle(vector<int>& nums, int n) {
    for (int i = 0; i < n -1 ; i++)
    {
        if ( i == 0 ) {
            swap(nums[n-1], nums[n]) ;
        }else {
            swap(nums[n - i], nums[n - i - 1]) ;
            swap(nums[n + i], nums[n + i - 1]) ;
        }
        printV(nums) ;
    }
    return nums ;
}

void printV(vector<int> ans) {
    for (int i : ans) cout << i << " " ;
    cout << endl ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(2*n) ;
    for (int i = 0; i < 2*n; i++) cin >> nums[i] ;
    printV(shuffle(nums,n)) ;
    return 0 ;
}
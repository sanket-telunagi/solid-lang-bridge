#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> rearrangeArray(vector<int> & nums) {
    int posIndex = -2 , negIndex = -1 , n = nums.size();
    vector<int> res(n, 0) ;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0) {
            res[posIndex += 2] = nums[i] ; // inc every alternate number

        } else {
            res[negIndex += 2] = nums[i] ;
        }
    }
    return res ;
}


int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    for (int it : rearrangeArray(nums)) {
        cout << it << " " ;
    } 
    cout << endl ;
    
    return 0 ;
}
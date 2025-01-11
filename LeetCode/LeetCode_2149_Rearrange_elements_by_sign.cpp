#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> positives , negatives , res ;
    for (int it : nums) {
        if (it >= 0) positives.push_back(it) ;
        else negatives.push_back(it) ;
    }
    int n = nums.size() ,
        p = 0,
        pn = 0;
    for(int i = 0 ; i < n ; i++) {
        if (i % 2 == 0){ res.push_back(positives[p++]) ;}
        else res.push_back(negatives[pn++]) ;
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
    for (auto it : rearrangeArray(nums)) {
        cout << it << " " ;
    }
    return 0 ;
}
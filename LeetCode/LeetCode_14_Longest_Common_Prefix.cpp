#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string longestCommonPrefix(vector<string>& strs) {
    long long mn = INT_MAX ;
    string temp = "" ;
    for (auto it : strs) {
        {
            if ((long long ) it.size() < mn) {
                mn = it.size() ;
                temp = it ;
            }
        }
    }

    string res = "" ;

    for (int i = 0; i < mn; i++)
    {
        bool f = true ;
        char ch = temp[i] ;
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[j][i] != ch) {
                f = false ;
                break;
            }
        }
        if (!f) {
            break;
        }

        res.push_back(ch) ;
        
    }
    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<string> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << longestCommonPrefix(nums) ;
    return 0 ;
}
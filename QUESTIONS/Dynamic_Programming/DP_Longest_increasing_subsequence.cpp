#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int Longest_increasing_subsequence(vector<int> & nums) {
    int table[nums.size() + 1][nums.size() + 1] ;

    for (int i = 0; i < nums.size() + 1; i++)
    {
        for (int j = 0; j < nums.size() + 1; j++)
        {
            if(i == 0 || j == 0) {
                table[i][j] = 0 ;
            }
        }

    }

    for (int i = 1; i < nums.size() + 1; i++)
    {
        for (int j = 1; j < nums.size() + 1; j++)
        {
            // if (i == 0 || j == 0) table[i][j] == 0 ;
            if (nums[i-1] > nums[j-1]) {
                table[i][j] = table[i][j-1] + 1 ;
            } else {
                table[i][j] = 0 ;
            }
        }
        
    }
    for (int i = 0; i < nums.size() + 1; i++)
    {
        for (int j = 0; j < nums.size() + 1; j++)
        {
            cout << table[i][j] << " " ;
        }
        cout << endl ;
    }

    int n = nums.size() ;
    return table[n][n] ;
    
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
    cout << Longest_increasing_subsequence(nums) ;
    return 0 ;
}
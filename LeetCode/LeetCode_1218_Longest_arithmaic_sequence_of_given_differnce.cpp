#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int longestSubsequence(vector<int>& arr, int difference) {
    // works but TLE :  O(n^2)
    // int res = 0 ;
    // int ct = 0 , n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     int num = arr[i] + difference ;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] == num) {
    //             ct++ ;
    //             num = arr[j] + difference ;
    //         }
    //     }
    //     res = max(res, ct  + 1) ;
    //     ct = 0 ;
        
    // }

    /*
        While going to right keep track of the numbers visited 
        As Look for the number with the diff less than the current number visited before 
        if there exists the number add one to the subsequence 
    */
    int res = 0 ,
        n = arr.size();
    unordered_map<int,int> mp ;

    for (int i = 0; i < n; i++)
    {
        int tempnum = arr[i] - difference ; // previous number is less by the factor of diff
        // if its not present set its ct to 1
        if (mp.find(tempnum) == mp.end()) mp[arr[i]] = 1 ;

        // get the ct of last num and add 1 to it 
        else mp[arr[i]] = 1 + mp[tempnum] ;
        res = max(res, mp[arr[i]]) ;
    }
    



    return res ;
    
}

int main()
{
    int n, diff ;
    cin >> n >> diff ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << longestSubsequence(nums, diff) << endl ;
    
    
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// to find the elemnt in the array 
int toFind (int left , int num, vector<int> & nums) {
    int right = nums.size() ,
        mid = 0 ;
    int idx = -1 ;

    while (left <= right) {
        mid = left + (right - left) / 2 ;
        if (nums[mid] == num) return mid ;
        else if (nums[mid] < num) {
            left = mid + 1 ;
        } else {
            right = mid - 1 ;
        }
    }

    return idx ;
}

unordered_map<string, bool> mp ;

unordered_map<int, int> hsh ;

bool solve (int index, int k , vector<int> & nums) {
    // if (index >= nums.size() or k > nums.back()) return false ;
    if (index == (nums.size() - 1)) return true ;
    // cout << "in" << endl ;

    string key = to_string(index) + "&" + to_string(k) ;
    if (mp.find(key) != mp.end()) return mp[key] ;

    bool ans = false ;

    vector<int> possibilities = {-1, 0, +1} ;
    for (auto possibility : possibilities) {
        int temp = k + possibility ;
        // if (temp > 0) {
        //     int idx = toFind(index, nums[index] + temp, nums) ;
        //     if (idx != -1) {
        //         ans |= solve(idx , temp, nums) ;
        //     }
        // }

        if (temp > 0 && hsh.find(nums[index] + temp) != hsh.end()) {
            ans |= solve(hsh[nums[index] + temp], temp, nums) ;
        }
    }

    return mp[key] = ans ;
}

bool canCross(vector<int>& stones) {
    int i = 0 ;
    for (auto it : stones) {
        hsh[it] = i++ ;
    }
    return solve (0, 0, stones) ;
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

    // cout << toFind(9, 3, nums) << endl ;
    cout << canCross(nums) << endl ;
    
    return 0 ;
}
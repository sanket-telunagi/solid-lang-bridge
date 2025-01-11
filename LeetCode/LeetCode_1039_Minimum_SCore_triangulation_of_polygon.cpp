#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    You have a convex n-sided polygon where each vertex has an integer value. 
    You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
    You will triangulate the polygon into n - 2 triangles. 
    For each triangle, the value of that triangle is the product of the values of its vertices, 
    and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

    Return the smallest possible total score that you can achieve with some triangulation of the polygon.
*/

/*
    Solution :
        Problem is of MCM 

        5 steps :
            1 : Choose i and j :
                - i should start with 0 
                - j should be n - 2
            
            2 : Find BC 
                - i >= j return 0 

            3 : Move k
                after each 3 steps 
            
            4 : calculation of answer from temp
                score = nums[i] * nums[k] * nums[j]
                total score = sigma(score)
*/

unordered_map<string, int> mp ;

int MCM(int i, int j , vector<int> & nums) {
    if (i >= j) return 0 ;

    string key = to_string(i) + " " + to_string(j) ;
    if(mp.find(key) != mp.end()) return mp[key] ;
    // ans 
    int ans = INT_MAX;

    for (int k = i; k < j; k ++)
    {
        int left = MCM(i, k, nums) ;
        int right = MCM(k + 1, j, nums) ;
        int score = left + right + (nums[i-1] * nums[k] * nums[j] * 1LL) ;
        ans = min(ans, score);
    }
    return mp[key] = ans ;
} 

int minScoreTriangulation(vector<int>& values) {
    return MCM(1, values.size()- 1, values) ;
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
    cout << 'A' + 0 << 'Z' + 0 <<  'a' + 0 << 'z' + 0 << endl ;
    cout << minScoreTriangulation(nums) << endl ;
    
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


int sLargest(vector<int> & nums) {
    int largest = -1 ,
        sLargest = -1 ,
        n = nums.size() ;

    for (auto it : nums) {
        if (it > largest) {
            sLargest = largest ;
            largest = it ;
        }
        else if (it > sLargest && it != largest) {
            sLargest = it ;
        }
    }

    return sLargest ;
}
int sSmallest(vector<int> & nums) {
    int smallest = INT_MAX ,
        sSmallest = -1 ,
        n = nums.size() ;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < smallest) {
            sSmallest = smallest ;
            smallest = nums[i] ;
        }
        else if (nums[i] < sSmallest && nums[i] != smallest) {
            sSmallest = nums[i] ;
        }
    }
    return sSmallest == INT_MAX ? -1 : sSmallest ;
}

vector<int> solve(vector<int> & nums) {
    int n = nums.size() ;
    return {sLargest(nums), sSmallest(nums)} ;
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
    vector<int> res = solve(nums) ;
    cout << res[0] << " " << res [1] << endl ;
    return 0 ;
}
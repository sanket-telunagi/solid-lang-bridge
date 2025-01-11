#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Every time for k groups k -1 partitions will be made 
    teh adjucent elements of each partion and first and last elements are 
    added in the retsult 
    so we just have to find the sum of each adjecent element in the array 
    sort it 
    and take first k - 1 groups for minimum sum 
    take last k -1 terms for maximum sum 
    retrun thedifference of the minimum and maximum sum 

*/

long long putMarbles(vector<int>& weights, int k) {
    long long mn_sum = 0 , mx_sum = 0 ;
    vector<long long> wt ;
    int n = weights.size() ;
    for (int i = 0; i < n-1; i++)
    {
        long long sum = weights[i] + weights[i+1] ;
        wt.push_back(sum) ;
    }

    // sort the array 
    sort(wt.begin(), wt.end()) ;
    

    // we have to take the first and last element by default 
    for (int i = 0; i < k -1; i++)
    {
        mn_sum += wt[i] ;
        mx_sum += wt[n - 2 - i] ;
    }
    
    return mx_sum - mn_sum ;
    
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << putMarbles(nums, k) ;
    
    return 0 ;
}
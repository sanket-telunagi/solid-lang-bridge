#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


bool isPossible(vector<int>& dist, double hour, int speed) {
    int n = dist.size() ;
    double time = 0.0 ;

    for (int  i = 0; i < n - 1; i++)
    {
        time += (dist[i]/ speed) ;

        if (dist[i] % speed != 0) time++ ;
    }
    // cout << time << endl ;

    time += double(dist[n-1])  / speed ;
    return time <= hour ;
    
}

int minSpeedOnTime(vector<int>& dist, double hour) {
    

    int mn = 1 , mx = 1e7 ;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2 ;

        if (isPossible(dist, hour, mid)) {
            mx = mid ;
        

        } else {
            mn = mid + 1 ;
        
        }
    }
    
    return mn > int(1e7 + 1)? -1 : mn ;

}

int main()
{
    int n ;
    float h ;
    cin >> n >> h ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << minSpeedOnTime(nums, h) << endl ;
    return 0 ;
}
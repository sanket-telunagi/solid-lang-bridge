#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int M = 1e9 + 7 ;
int dp [110][210] ;

int fun(int start, int fuel, int finish, vector<int> & locations) {
    // if fuel negatives return 
    if (fuel < 0) return 0 ;

    // memoisation 
    if (dp[start][fuel] != -1) return dp[start][fuel] ;

    int count = 0 ;

    // if we reached the destination  
    if (start == finish) count ++ ;

    // look for other paths
    int n = locations.size() ;
    for (int i = 0; i < n; i++)
    {
        if ( i == start) continue ; // if its the starting point then jump

        int fuel_lost = abs(locations[start] - locations[i]) ;
        count += fun(i, fuel - fuel_lost, finish, locations) ;

        // mod the count 
        count = count % M ;
    }

    return dp[start][fuel] = count ;
    
}

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    memset(dp, -1, sizeof(dp)) ;

    int res = fun (start, fuel, finish, locations) ;
    return res ;
}

int main()
{
    int n , start, finish, fuel;
    std :: cin >> n >> start >> finish >> fuel ;

    vector<int> locations(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> locations[i] ;
    }
    
    std :: cout << countRoutes(locations, start, finish, fuel) << endl ;
    return 0 ;
}
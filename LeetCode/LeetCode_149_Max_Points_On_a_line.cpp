#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int maxPoints(vector<vector<int>>& points) {
    // if there exists only one point
    int n = points.size() ;
    if (n <= 1) {
        return n ;
    }else {
        map<pair<int,int>,int> mp ;
        int ans = -1 ;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (abs(points[j][0]- points[i][0]) > 0) {

                    int slope = abs((points[j][1] - points[i][1]) / (points[j][0]- points[i][0])) ;
                    mp[{points[i][0],points[i][1]}] ++ ;
                    cout << points[j][0] << " " << points[j][1] << endl ;
                    
                }else if(abs(points[j][0]- points[i][0]) == 0) {
                    mp[{0,0}]++ ; 
                }
            }  
            cout << endl ;
        }
        for (auto & pr : mp) {
            ans = max(ans, pr.second) ;
        }
        return ans ;
    }
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> points (n,vector<int>(2)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1] ;
        // cout << points[i][0]<< " " << points[i][1] << endl ;;
    }
    cout << maxPoints(points) << endl ;
    return 0 ;
}
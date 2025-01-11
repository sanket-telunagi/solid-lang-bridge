#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// int findMinArrowShots(vector<vector<int>>& points) {
//     // keep track of bursted arrows
//     vector<bool> bursted(points.size(), 0) ;
//     int ct = 0 ;
//     for (int i = 0; i < points.size(); i++)
//     {
//         int temp = points[i][0] ;
//         if (bursted[i]) continue ;
//         for (int j = 0; j < points.size(); j++)
//         {
//             if(bursted[j] == 0) {
//                 if (((points[i][0] >= points[j][0]) && (points[i][0] <= points[j][1])) || ((points[i][1] >= points[j][0]) && (points[i][0] <= points[j][1]))){
//                     bursted[j] = 1 ;   
//                 }
//             }else {
//                 continue ;
//             }
//         }
//         ct++ ;
//     }
//     return ct ;
// }

// int findMinArrowShots(vector<vector<int>> & points) {

//     int ct = 0;
//     int index = 0 ;

//     sort(points.begin(),points.end()) ;

//     for (int i = 0; i < points.size(); i++)
//     {
//         if (ct == 0 || points[i][0] > points[index][1]) {
//             ct++ ;
//             index = i ;
//         }
//     }
//     // for (auto & it : points) {
//     //     cout << it[0] << " " << it[1] << endl ;
//     // }
//     return ct ;
// }

// int findMinArrowShots(vector<vector<int>>& points) {
//     sort (points.begin(), points.end()) ;
//     if (points.size() == 1) {
//         return 1 ;
//     }
//     int ct = 1 ;
//     int curr_max = points[0][1] ;
//     for (int i = 1; i < points.size(); i++)
//     {
//         if (points[i][0] > curr_max) {
//             ct ++ ;
//             curr_max = points[i][1] ;
//         }
//     }
//     return ct ;
// }

// int findMinArrowShots(vector<vector<int>>& points) {
//     sort (points.begin(), points.end()) ;
    
//     int pt = 0 , ct = 0 , i = 0, a = points[0][0], b = points[0][1];

//     while (i < points.size()) {
//         while (i < points.size() && ((points[i][0] <= b )&& (points[i][0] >= 1)))
//         {
//             a = max(a,points[i][0]) ;
//             b = min(b,points[i][1]) ;
//             i++ ;
//         }
//         ct ++ ;
//         if (i == points.size() ) break ;
//         a = points[i][0] ;
//         b = points[i][1] ;
//     }
//     return ct ;
// }

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) {
        return 0 ;
    }else if (points.size() == 1) {
        return 1 ;
    }

    sort (points.begin(), points.end()) ;
    
    int ct = 1 , s = points[0][0] , e = points[0][1];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > e) {
            ct++ ;
            s = points[i][0] ;
            e = points[i][1] ;
        }else {
            s = max(points[i][0], s) ;
            e = min(points[i][1], e) ;
        }
    }
    return ct ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> points(n,vector<int>(2,0)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1] ;
    }

    // for (auto & it : points) {
    //     cout << it[0] << " " << it[1] << endl ;
    // }

    cout << findMinArrowShots(points) ;
    
    return 0 ;
}
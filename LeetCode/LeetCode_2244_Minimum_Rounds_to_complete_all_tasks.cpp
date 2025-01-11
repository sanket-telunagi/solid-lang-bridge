#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// int minimumRounds(vector<int>& tasks) {
//     int hi = 0, lo = 0 ;
//     sort(tasks.begin(),tasks.end()) ;
//     int ans = 0 ;
//     int temp = 0 ;
//     unordered_map<int,int> occur ;
//     for (int i = 0; i < tasks.size(); i++)
//     {
//         occur[tasks[i]] ++ ;
//         if(tasks[lo] != tasks[hi]) {
//             lo = hi ;
//         }else {
//             hi++ ;
//             // cout << hi << " ";
//             temp++ ;
//         }

//         if(temp == 3) {
//             ans++ ;
//             temp = 0 ;
//         }
//         else if(temp == 2) {
//             ans++ ;
//             temp = 0 ;
//         }
//     }
//     for (auto & pr : occur) {
//         if(pr.second <= 1) {
//             return -1 ;
//         }
//     }

//     return ans ;
// }

int minimumRounds(vector<int> & tasks) {
    int ans = 0 ;

    unordered_map<int, int> occur ;
    for(int & i : tasks) {
        occur[i]++ ;
    }

    for (auto & pr : occur) {
        if (pr.second <= 1) return -1 ;
        if (pr.second % 3 == 0){
            ans+= (pr.second / 3) ;
        }else if (pr.second % 3 == 2 && pr.second == 2){
            ans++ ;
        }else {
            ans += (pr.second / 3) +  1 ;
        }
    }
    
    return ans ;
}

int main()
{
    int n ; 
    cin >> n ;
    vector<int> tasks(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i] ;
    }

    cout << minimumRounds(tasks) ;
    
    return 0 ;
}
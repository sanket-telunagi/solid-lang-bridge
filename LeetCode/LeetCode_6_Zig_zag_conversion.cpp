#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// string convert(string s, int numRows) {
//     vector <string> levels (numRows) ;
//     int i = 0 ;
//     int level = 0;
//     int l = s.length() / numRows ;
//     // cout << l << endl ;
//     int ct = 0 ;
//     while(i < l-1)
//     {
//         while (level < numRows)
//         {
//             levels[level++].push_back(s[ct]) ;
//             // cout << level++ << " ";
//             ct++ ;
//         }
//         --level ;
//         while (level > 0)
//         {
//             levels[--level].push_back(s[ct]) ;
//             // cout << --level << " " ;
//             ct++ ;
//         }
//         level++ ;
//         i++ ;
//     }
  
//     // cout << level ;
//     levels[level].push_back(s[ct]) ;
//     ct++ ;
  
   
 
//     // cout << endl  << ct ;
    
//     string ans = "" ;
//     for(auto & st : levels) {
      
//         ans += st ;
//     }
    
//     return ans ;
// }


    string convert(string s, int numRows) {
        int n = s.size();

        if(numRows == 1 || n == 1) return s;

        vector<string> rows(min(numRows, n));
        int cur = 0, down = 0;
        for(char c: s) {
            rows[cur].push_back(c);
            if(cur == 0 || cur == numRows-1) down ^= 1;
            cur += down ? 1 : -1;
        }

        string ans = "";
        for(string & st: rows) ans += st;
        return ans;
    }


int main()
{
    string s; 
    int n ;
    cin >> s >> n ;
    cout << convert(s,n) ;
    return 0 ;
}
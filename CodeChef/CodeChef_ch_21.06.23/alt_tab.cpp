#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;

    unordered_map<string, int> hsh ;
    deque<string> dq ;

    while (t--) {
        string s ;
        cin >> s ;
        dq.push_front(s) ;
        hsh[s]++ ;
    }
    string res = "" ;
    // for(auto & it : hsh) {
    //     cout << it.first << " " << it.second << endl ;
    // }
    while(!dq.empty()) {
        string s = dq.back() ;
        // cout << s << endl ;
        if (hsh[s] == 1) {
            // cout << *s.end() << endl ;
            res.push_back(s[s.length() - 2]);
            
            res.push_back(s[s.length() - 1]) ;
            
        } else {
            hsh[s]-- ;
        }
        dq.pop_back() ;
    }
    
    for (int i = 0; i < res.length() / 2; i++)
    {
        swap(res[res.length() - i - 1], res[i]) ;
    }
    
    for (int i = 0; i < res.length() - 1; i+= 2)
    {
        swap(res[i], res[i+1]) ;
    }
    

    cout << res << endl ;
    return 0 ;
}
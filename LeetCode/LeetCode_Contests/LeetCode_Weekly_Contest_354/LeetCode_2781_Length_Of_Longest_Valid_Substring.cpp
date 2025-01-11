#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int longestValidSubstring(string word, vector<string>& forbidden) {
    // int n = word.length() ;
    // unordered_map<string, int> mp ;
    // for(auto & it : forbidden) mp[it]++ ;

    // int l = 0 , r = 0 , res = 0  ;

    // for (int i = 0; i < n; i++)
    // {
    //     string temp = word.substr(l, r - l + 1) ;
    //     cout << temp << endl ;
    //     if (mp.find(temp) != mp.end()) {
    //         while (mp.find(temp) != mp.end()) {
    //             l++ ;
                
    //             temp = word.substr(l, r - l + 1) ;
    //             cout << temp << endl ;
    //         }
    //     }
    //     res = max(res, r - l + 1) ;
    //     r++ ;
    // }

    // return res ;

    int n = word.length() , 
        r = n - 1 ,
        l = r ,
        res = 0 ;
    /*
        Require sol : 
            TC : O(n) / O(nlog(n))
        
        Use the constraint :
            forbidden[i].length <= 10
    */

    unordered_set<string> st ;
    for (auto & it : forbidden) st.insert(it) ;
    for (l = n - 1; l >= 0; l--)
    {
        for (int k = l; k <= min(l + 10, r); k++)
        {
            string temp = word.substr(l, k - l + 1) ;
            if (st.find(temp) != st.end()) {
                r = k - 1 ;
                break;
            }
        }
        res = max(res, r - l + 1) ;
    }
    return res ;
}

int main()
{
    string s ;
    cin >> s ;
    int n ;
    cin >> n ;
    vector<string> forbidden(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> forbidden[i] ;
    }
    cout << longestValidSubstring(s, forbidden) << endl ;
    return 0 ;
}
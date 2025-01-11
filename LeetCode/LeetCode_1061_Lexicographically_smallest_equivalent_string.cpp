#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// char minimum(unordered_set<char> & temp) {
//     char ans = '{' ;
//     for (auto it : temp) {
//         ans = min(ans,it) ;
//     }
//     return ans ;
// }

// // [m,p], [a,o], [k,r,s], [e,i].
// // [h,w], [d,e,o], [l,r].
// // [a,o,e,r,s,c], [l,p], [g,t] and [d,m]

// string smallestEquivalentString(string s1, string s2, string baseStr) {
//     string ans ;

//     unordered_map<char,vector<char>> mp ;

//     return ans ;
// }



void setHsh(char a, char val, char * hsh)
{
    while (hsh[a - 'a'] != a)
    {
        char temp = hsh[a - 'a'];
        hsh[a - 'a'] = val;
        a = temp;
    }
    hsh[a - 'a'] = val;
}
string smallestEquivalentString(string s1, string s2, string baseStr)
{
    char hsh [26];
    for (int i = 0; i < 26; i++)
    {
        hsh[i] = 'a' + i;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        
        while (hsh[s1[i] - 'a'] != s1[i])
        {
            s1[i] = hsh[s1[i] - 'a'];
        }
        char p1 = s1[i] ;

        while (hsh[s2[i] - 'a'] != s2[i])
        {
            s2[i] = hsh[s2[i] - 'a'];
        }
        char p2 = s2[i] ;

        p1 < p2 ? setHsh(s2[i], p1, hsh) : setHsh(s1[i], p2, hsh) ; 
    }
    string ans = baseStr;
    for (int i = 0; i < baseStr.size(); i++)
    {
        while (hsh[baseStr[i] - 'a'] != baseStr[i])
        {
            baseStr[i] = hsh[baseStr[i] - 'a'];
        }
        ans[i] = baseStr[i] ;
    }
    return ans;
}

int main()
{
    string s1, s2, baseStr;
    cin >> s1 >> s2 >> baseStr;
    cout << smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}

// create map
// unordered_map<char,unordered_set<char>> mp ;
// for (int i = 0; i < s1.length(); i++)
// {
//     mp[s1[i]].insert(s1[i]) ;
//     mp[s1[i]].insert(s2[i]) ;
//     mp[s2[i]].insert(s2[i]) ;
//     mp[s2[i]].insert(s1[i]) ;
// }

// // create minimum algorithm

// // for (auto & pr : mp) {
// //     cout << pr.first << " : " ;
// //     for (auto & i : pr.second) {
// //         cout << i << " " ;
// //     }
// //     cout << endl ;
// // }
// unordered_map<char,char> final ;
// for (auto & pr : mp) {
//     final[pr.first] = (char)minimum(pr.second) ;
// }

// string ans = "" ;
// for (int i = 0; i < baseStr.length(); i++)
// {
//     ans.push_back(final[baseStr[i]]) ;
//     // cout << ans ;
// }
// for (int i = 0; i < ans.length(); i++)
// {
//     ans[i] = final[ans[i]] ;
//     // cout << ans ;
// }

// for (auto & pr : final ) {
//     cout << pr.first << " " << pr.second << endl ;
// }

// unordered_map<char,char> final_match ;

// for(auto & pr : mp) {
//     final_match[pr.first] = min(min(mp[pr.first]), min(mp[pr.first])) ;

// }

// for (int i = 0; i < baseStr.length(); i++)
// {
//     ans.push_back(min(mp[baseStr[i]], mp[mp[baseStr[i]]])) ;
// }

// for (int i = 0; i < s1.length(); i++)
// {
//     if (mp[s1[i]] == 0) {
//         mp[s1[i]] = s2[i] ;
//     }
//     if (mp[s2[i]] == 0) {
//         mp[s2[i]] = s1[i] ;
//     }
//     mp[s1[i]] = min(mp[s1[i]],mp[s2[i]]) ;
//     mp[s2[i]] = min(mp[s2[i]],mp[s1[i]]) ;
// }

// for (int i = 0; i < s1.length(); i++)
// {

// }

// for (auto & it : mp) {
//     // mp[it.first] = min(mp[it.first],mp[mp[it.first]]) ;
//     // char temp = it.first ;
//     for(auto & tp : it.second) {
//         cout << tp <<" " ;
//     }
//     cout << endl ;
// }

// for (auto & it : mp) {
//    cout << it.first << " : " << it.second << endl ;

// }
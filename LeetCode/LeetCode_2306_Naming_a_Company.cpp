#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long distinctNames (vector<string> & ideas) {
    long long ans = 0 ;

    unordered_map<char, string> mp ;
    for (int i = 0; i < ideas.size(); i++)
    {
        mp[ideas[i][0]] = ideas[i].substr(1,ideas[i].length()) ;
    }
    
    for (auto & ch1 : mp) {
        for (auto & ch2 : mp) {
            if (ch1.first == ch2.first) continue;;

            int intersect = 0 ;
            for(auto & ch : mp[ch1.first]) {
                if (mp.find(ch2.first) != mp.end()) intersect ++;
            }
            int d1 = mp[ch1.first].length() - intersect ;
            int d2 = mp[ch2.first].length() - intersect ;
            ans = d1 * d2 ;
        }
    }


    return ans ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<string> ideas(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> ideas[i] ;
    }
    cout << distinctNames(ideas) << endl  ;
    return 0 ;
}
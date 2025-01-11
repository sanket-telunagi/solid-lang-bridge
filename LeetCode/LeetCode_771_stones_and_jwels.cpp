#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

 int numJewelsInStones(string jewels, string stones) {
        set<char> jewels_hsh;
        for(char & i : jewels ) {
            jewels_hsh.insert(i) ;
        }
        int ct = 0 ;
        for (auto & i : stones) {
            if (jewels_hsh.find(i) != jewels_hsh.end()) {
                ct++ ;
            }
        }
        return ct ;
    }

int main()
{
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    cout << numJewelsInStones(s1,s2) ;
    return 0 ;
}
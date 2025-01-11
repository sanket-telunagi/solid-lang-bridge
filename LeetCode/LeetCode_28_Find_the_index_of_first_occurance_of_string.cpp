#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void printDQ (deque<char> & dq) {
    for (auto & ch : dq) {
        cout << ch << " " ;
    }
    cout << endl ;
}

int strStr(string haystack, string needle) {
    int ans = -1 ;
    deque<char> hay, nee ;
    for (auto & i : needle) nee.push_back(i) ;


    int s = 0, e = 0 ;
    int i = 0 ;
    while(e <= haystack.length()) {
        // create first window
        while (e <= needle.size() - 1) {
            hay.push_back(haystack[e++]) ;
        }
        printDQ(hay) ;
        // check window 
        if(hay == nee) return ans = s;
        hay.pop_front() ;
        hay.push_back(haystack[e++]) ;
        s++ ;

    }
    return ans ;
}

int main()
{
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    cout << strStr(s1,s2) ;
    return 0 ;
}
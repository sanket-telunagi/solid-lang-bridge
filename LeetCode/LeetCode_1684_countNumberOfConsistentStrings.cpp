#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int countConsistentStrings(string allowed, vector<string>& words) {
    int consistent = 0 ;
    for (int i = 0; i < allowed.length(); i++)
    {
        
    }
    
}

int main()
{
    int n ;
    cin >> n ;
    string allowed ;
    cin >> allowed ;
    vector<string> words ;
    for (int i = 0; i < n; i++)
    {
        string s ;
        cin >> s ;
        words.push_back(s) ;
    }
    countConsistentStrings(allowed, words) ;
    return 0 ;
}
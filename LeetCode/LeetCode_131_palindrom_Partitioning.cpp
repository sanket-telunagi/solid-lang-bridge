#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPal(string & s) {
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i]) return false ;
    }
    return true ; 
}

void sub_string(string & s , vector<string> & sol, vector<vector<string>> & ans, int index = 0) {
    if (index >= s.length()) {
        if (sol.size() != 0 ) ans.push_back(sol) ;
        return ;
    }

    for (int i = index; i < s.length(); i++)
    {
        string temp = s.substr(index, i + 1 - index) ;
        if (isPal(temp)) {
            sol.push_back(temp) ;
            sub_string(s,sol,ans, i + 1) ;
            sol.pop_back() ;
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans ;
    vector<string> empty ;
    sub_string(s, empty, ans) ;
    return ans ;
}

int main()
{
    string s  ;
    cin >> s ;
    for(auto & it : partition(s)) {
        for(auto & i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}
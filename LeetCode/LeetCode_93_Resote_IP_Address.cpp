#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool valid(const string& s, int start, int length) {
    return length == 1 || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
}

vector<string> ans ;

void helper(const string& s, int start, vector<int>& dots) {
    const int rmLen = s.length() - start;
    const int rmInt = 4 - dots.size();
    if (rmLen > rmInt * 3 || rmLen < rmInt) {
        return;
    }
    if (dots.size() == 3) {
        if (valid(s, start, rmLen)) {
            string temp;
            int last = 0;
            for (int dot : dots) {
                temp.append(s.substr(last, dot));
                last += dot;
                temp.append(".");
            }
            temp.append(s.substr(start));
            ans.push_back(temp);
        }
        return;
    }
    for (int i = 1; i <= 3 && i <= rmLen; ++i) {
        dots.push_back(i);
        if (valid(s, start, i)) {
            helper(s, start + i, dots);
        }
        dots.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<int> empty ;
    helper(s,0,empty) ;
    return ans ;
}

int main()
{
    string s ;
    cin >> s ;
    for(auto i : restoreIpAddresses(s)) {
        cout << i << endl ;
    }
    return 0 ;
}
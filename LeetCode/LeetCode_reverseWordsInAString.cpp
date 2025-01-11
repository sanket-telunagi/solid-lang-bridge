/*
    Given a string s,
    reverse the order of characters in each word within a
    sentence while still preserving whitespace and initial word order.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string reverseWords(string & s)
{
    string & ans = s;
    int start = 0, end = ans.length() - 1;
    for (int i = 0; i < ans.length(); i++)
    {
        if (ans[i] == ' ') {
            end = i ;
            for (int j = start; j < end/2; j++)
            {
                swap(ans[start],ans[end]) ;
            }
            start = i + 1;
        }
    }
    return ans ;
}

int main()
{
    string s, ans;
    getline(cin , s);
    ans = reverseWords(s);
    cout << s << endl;
    return 0;
}
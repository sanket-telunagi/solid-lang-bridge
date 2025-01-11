#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void reverseString(vector<char> &s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(s[i], s[s.size() - 1 - i]);
    }
}
int main()
{
    int n ;
    cin >> n ;
    vector<char> s(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] ;
    }
    reverseString(s) ;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " " ;
    }
    
    return 0;
}
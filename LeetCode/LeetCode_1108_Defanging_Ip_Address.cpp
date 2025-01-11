#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string defangIPaddr(string address) {
    string ans ;
    for (int i = 0; i < address.length(); i++)
    {
        if (address[i] == '.') {
            ans.push_back('[') ;
            ans.push_back('.') ;
            ans.push_back(']') ;
            continue ;
        } else {
            ans.push_back(address[i]) ;
        }
    }
    return ans ;
}

int main()
{
    string s ;
    cin >> s ;
    cout << defangIPaddr(s) ;
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void permute(string & str, int index = 0) {
    if (index >= str.length()) {
        cout << str << endl ;
        return ;
    }

    for (int i = index; i < str.length(); i++)
    {
        swap(str[i], str[index]) ;
        permute(str, index + 1) ;
        swap(str[i], str[index]) ;
    }
}

int main()
{
    string s ;
    cin >> s;
    permute(s) ;
    return 0 ;
}
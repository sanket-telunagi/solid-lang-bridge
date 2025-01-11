#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ; 
    cin >> t ;
    while (t--)
    {
        string num ; 
        cin >> num ;
        int res = 0 ;
        for (int i = 0; i < num.length(); i++)
        {
            res = (res * 10 + (num[i] - '0')) % 20;   
        }
        cout <<  res << endl ;
        
    }
    
    return 0 ;
}
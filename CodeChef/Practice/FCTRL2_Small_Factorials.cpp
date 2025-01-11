#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    vector<unsigned long long> facto ;
    facto.push_back(1) ;
    for (unsigned long long i = 1; i <= 100; i++)
    {
        facto.push_back(i * facto[i-1]) ;
    }
    for( auto i : facto) {
        cout << i << endl ;
    }
    return 0 ;
}
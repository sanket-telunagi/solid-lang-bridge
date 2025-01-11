#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin  >> t;
    while (t--)

    {int w1, w2, x1, x2 , M ;
    cin >> w1 >> w2 >> x1 >> x2 >> M ;
    int inc = w2 - w1 ;
    int mx_inc = M * x2 , mn_inc = M*x1 ;

    if (inc >= mn_inc && inc <= mx_inc) cout << 1 << endl ;
    else cout << 0 << endl ;}
    return 0 ;
}
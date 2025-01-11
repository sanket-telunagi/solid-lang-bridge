#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;

        unordered_map<int,int> mp1, mp2 ;
        /*
            PLink : https://www.codechef.com/LP1TO205/problems/POLIN
            The problem reduces to finding the distinct y cordinates 
            and distinct x coordinates 
            the sum of them is the answer
        */
        for (int i = 0; i < n; i++)
        {
            int x, y ;
            cin >> x >> y ;
            mp1[x]++ ;
            mp2[y]++;
        }

        cout << mp1.size() + mp2.size() <<endl ;
        
    }
    
    return 0 ;
}
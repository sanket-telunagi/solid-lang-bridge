#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int captureForts(vector<int>& forts) {
    int start = 0 , end = 0 ;
    if (forts[start] == 0 || forts[start] == -1) {
        return 0 ;
    }
    int ans = -1 ;
    for (int i = 0; i < forts.size(); i++)
    {
        end++ ;
        if (forts[i] == -1 || forts[i] == 1) {
            start = end ;
        }
        ans = max(ans,(end - start) - 1) ;
    }
    return ans + 1 ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> forts(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> forts[i] ;
    }
    cout << captureForts(forts) ;
    return 0 ;
}
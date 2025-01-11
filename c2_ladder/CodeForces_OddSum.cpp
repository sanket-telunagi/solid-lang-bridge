#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n ;
        cin >> n ;
        int cnt = 0;
        multiset<int> v ;
        unordered_map<int,int> m  ;
        for (int i = 0; i < 2*n; i++)
        {
            int x ;
            cin >> x ;
            v.insert(x);
        }
        
        
       
        if (cnt == n)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}
// Next greatest element of each element in array 

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> NGE(vector<int> &v) {
    stack <int> stk ; // indices
    vector <int> nge(v.size()) ; // vector which stores next greater element 
    for (int i = 0; i < v.size(); i++)
    {
        while (!stk.empty() && v[i] > v[stk.top()])  // stk empty and found nge
        {
            nge[stk.top()] = i ;
            stk.pop() ;
        }
        stk.push(i) ; // pushing indices
    }
    while (!stk.empty()) // -1 for rest of the elements
    {
        nge[stk.top()] = -1 ;
        stk.pop() ;
    }
    return nge ;
}

int main() {
    int n ;
    cin >> n ;
    vector<int> v ;

    while (n--)
    {
        int x ;
        cin >> x;
        v.push_back(x) ;
    }

    vector<int> nge = NGE(v) ;  // array contains indices of nge's

    for (int i = 0; i < nge.size(); i++)
    {
        cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl ;
    }
    
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isSorted(string & temp) {
    for(int i = 0 ; i < temp.length()-1 ; i++){
        if(temp[i] > temp[i+1]) {
            return false ;
        }
    }
    return true ;
}

int minDeletionSize(vector<string>& strs) {
    int ans = 0 ;
    for (int i = 0; i < strs[0].size(); i++)
    {

        string temp = "" ;
        for (int j = 0; j < strs.size(); j++)
        {
            temp.push_back(strs[j][i]) ;
        }
        if(!isSorted(temp)) {
            ans++ ;
        } 
    }
    return ans ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<string> names(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> names[i] ;
    }

    cout << minDeletionSize(names) ;
    return 0 ;
}
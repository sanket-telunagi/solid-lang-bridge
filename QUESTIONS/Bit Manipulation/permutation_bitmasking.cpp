/*
    generating permutation - 
    0 0 
    0 1
    1 0
    1 1

    0 0 1
    0 1 0
    0 1 1
    1 0 0
    1 0 1
    1 1 0
    
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<string> ans ;

void genPer(string & s,vector<string> & ans, int i = 0) 
{
    if(i >= s.length()) {
        ans.push_back(s) ;
        return ;}

  
    for (int index = i; index < s.length(); index++)
    {
        swap(s[index],s[i]) ;
        genPer(s,ans,i+1) ;
        swap(s[index],s[i]) ;
    }
    
}


int main()
{
    string s ;
    cin >> s ;
    int k = 0 ;
    int n = s.length() ;

    // vector<string> ans ;
    // for (int mask = 1; mask <= per_ct; mask++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         if((mask & (1 << i)) != 0 ) {
    //             swap(s[i],s[k]) ;
    //             cout << s << endl ;
    //             swap(s[i],s[k]) ;
    //             k++ ;
    //         }
    //     }
        
    // }
    vector<string> ans ;
    genPer(s,ans) ;
    
    for(auto it : ans) {
        cout << it << endl ;
    }
    

    return 0 ;
}
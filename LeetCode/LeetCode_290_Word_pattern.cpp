#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// bool wordPattern(string pattern , string s) {
//     stringstream stream (s) ;
//     string token ;
//     unordered_map<char, int> s_map ;
//     unordered_map<string, int> pattern_map ;

//     for (int i = 0; i < s.length(); i++)
//     {
//         getline(stream , token, ' ') ;
//         if(pattern_map[token] != s_map[pattern[i]]) return false ;
//         else pattern_map[token] = s_map[pattern[i]] = i + 1 ;
//     }
//     if(getline(stream , token, ' ')) return false ;
//     return true ;
// }

// bool wordPattern(string pattern, string s) {        
//         stringstream ss(s);
//         string token;
        
//         unordered_map<char,int>m;
//         unordered_map<string,int>m2;
//         for(int i=0;i<pattern.size(); i++)
//         {
//             getline(ss,token,' ');
//             if(m2[token] != m[pattern[i]])
//                 return false;
//             m2[token] = m[pattern[i]] = i+1;
//         }
//         if(getline(ss,token,' '))
//             return false;
//         return true;
//     }

bool wordPattern(string pattern, string s) {    
        
        
        stringstream stream(s);
        string token;
        
        unordered_map<char,string>s_map;
        unordered_map<string,char>pattern_map;

        for(int i = 0 ; i < pattern.size() ; i++)
        {
            getline(stream,token,' ');

            if(pattern_map.count(token) && pattern_map[token] != pattern[i]) return false;
            
            if(s_map.count(pattern[i]))
            {
                if(s_map[pattern[i]] == token) continue;
                else return false;
            }
            else
            {
                s_map[pattern[i]] = token;
                pattern_map[token] = pattern[i];
            }
        }
        if(getline(stream,token,' ')) return false;
        return true;
}


int main()
{
    string s , pattern ;
    cin >> pattern ;
    getline(cin , s) ;
    cout << s ;
    cout << wordPattern (pattern , s) ;
    return 0 ;
}
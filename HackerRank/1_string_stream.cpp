#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int string2int(string s) {
    int num = 0 ;
    int i = s.length() - 1 ;
    int factor = 1 ;
    while (i >= 0) {
        
        char digit = s[i] ;
        if (digit == '-') break;
        num = num + (factor * (digit - '0')) ;
        i-- ;
        factor *= 10 ;
    }
    if(s[0] == '-') return -1*num ;
    return num ;
}

vector<int> parseInts(string str) {
	// Complete this function
    string temp = "";
    vector<int> ans ;
    // for (int i = 0; i < str.length(); i++) {
    //     if(str[i] != ',') {
    //         temp.push_back(str[i]) ;
            
    //     }  
    //     if(str[i] == ',' | i == str.length() - 1 ) {
    //         ans.push_back(string2int(temp)) ;
    //         temp = "" ;
    //     }
    // }
    int ct = 0 ;
    for(auto i : str) {
        if(i == ',') ct++ ;
    }
    ct++ ;
    int i = 0 ;
    while (ct--)
    {
        while (str[i] != ',')
        {
            
            temp.push_back(str[i]) ;
            i++ ;
            if (i == str.length()) break ;
        }
        ans.push_back(string2int(temp)) ;
        if (i == str.length()) break ;
        i++ ;
        temp = "" ;
        
    }
    
    return ans ;
}

// vector<string> parseInts(string str) {
//     // Complete this function
//     string temp = "";
//     vector<string> ans ;
//     // for (int i = 0; i < str.length(); i++) {
//     //     if(str[i] != ',') {
//     //         temp.push_back(str[i]) ;
            
//     //     }  
//     //     if(str[i] == ',' | i == str.length() - 1 ) {
//     //         ans.push_back(string2int(temp)) ;
//     //         temp = "" ;
//     //     }
//     // }
//     int ct = 0 ;
//     for(auto i : str) {
//         if(i == ',') ct++ ;
//     }
//     ct++ ;
//     int i = 0 ;
//     while (ct--)
//     {
//         while (str[i] != ',')
//         {
            
//             temp.push_back(str[i]) ;
//             i++ ;
//             if (i == str.length()) break ;
//         }
//         ans.push_back(temp) ;
//         if (i == str.length()) break ;
//         i++ ;
//         temp = "" ;
        
//     }
    
//     return ans ;
// }

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    // cout << string2int(str) ;
    return 0;
}
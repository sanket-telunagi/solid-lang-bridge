#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


int largestVariance(string s) {
    // minimum variance will be 0
    int ans = 0 ;

    // get frequency of each character 
    unordered_map<char, int> mp ;
    for (auto & it : s) {
        mp[it] ++ ;
    }

    // for each pait of characters 26 * 26 pairs

    for (int i = 'a'; i <= 'z'; i++)
    {
        for (int j = 'a'; j <= 'z'; j++)
        {
            // in case of absence of characters or single occurance of the characters the answer will be zero 

            if (i == j || mp[i] == 0 || mp[j] == 0) continue;

            // now time to check the occurance of pair in the string 
            // in sorted as well as reverse manner 
            int l = 2 ;
            while (l--) {
                int ct1 = 0 , ct2 = 0 ;
                // use kadanes algorithm to find maximum sum subarray 
                for (auto & ch : s) {
                    ct1 += (ch == i) ;
                    ct2 += (ch == j) ;

                    if (ct1 - ct2 < 0) {
                        ct1 = ct2 = 0 ;
                        // make both zero 
                    }

                    if (ct1 > 0 && ct2 > 0)  ans = max(ans, ct1 - ct2) ;
                }
            }
            
            reverse(s.begin(), s.end()) ;

        }
        
    }
    
    return ans ;
}

int main()
{
    string s ;
    cin >> s ;
    cout << largestVariance(s) << endl ;
    return 0 ;
}
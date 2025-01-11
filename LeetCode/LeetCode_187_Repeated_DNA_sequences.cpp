#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

    For example, "ACGAATTCCG" is a DNA sequence.
    When studying DNA, it is useful to identify repeated sequences within the DNA.
    Given a string s that represents a DNA sequence, 
    return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
    You may return the answer in any order.

    ans : 
        from the question it is clear that we have to find the subbstring of window size "k" which occured the most times

        window size is 10
        k = 10 
*/

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> str ;
    int l = 0 , r = 0, n = s.length() ;
    unordered_map<string, int> mp ;
    int k = 10 ;
    r = 9 ;
    mp[s.substr(l, 10)] ++ ;

    for (r = 10; r < n ;r++) {
        l++ ;
        string temp = s.substr(l,10) ;
        mp[temp]++ ;
        // cout << temp << endl ;;
    }

    for (auto & pr : mp) {
        if (pr.second > 1) {
            str.push_back(pr.first) ;
        }
    }
    return str ;
}

int main()
{
    string dna ;
    cin >> dna ;

    for (string & it :  findRepeatedDnaSequences(dna)) {
        cout << it << endl ;
    }
    return 0 ;
}
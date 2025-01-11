#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// bool isAlienSorted(vector<string>& words, string order) {
//     unordered_map<char, int> mp ;
//     int i = 1 ;
//     for (char & ch : order) mp[ch] = i++ ;
//     for (int word = 0; word < words.size() - 1; word++)
//     {
//         for (int ch = 0 ; ch < words[word].length() ; ch++) {
//             if (mp[words[word][ch]] > mp[words[word+1][ch]]) {
//                 return false ;
//             }
//         }
//     }
//     return true ;
// }

bool cmp(unordered_map<char, int> &mp, string &s1, string &s2)
{
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
    {
        if (mp[s1[i]] > mp[s2[i]])
            return false;
        if (mp[s1[i]] == mp[s2[i]])
            continue;
        return true;
    }

    if (s1.size() > s2.size())
        return false;
    return true;
}
bool isAlienSorted(vector<string> &words, string order)
{
    unordered_map<char, int> mp;

    int i = 0;
    for(int i = 0 ;i<order.size();i++){
             mp[order[i]] = i ; 
         }

    for (int i = 1; i < words.size(); i++)
    {
        if (cmp(mp, words[i-1], words[i]))
            continue;
        return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string order;
    cin >> order;
    cout << isAlienSorted(words, order);

    return 0;
}
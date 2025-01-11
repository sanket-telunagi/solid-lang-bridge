#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> smallestSufficientTeam(vector<string> & req_skills, vector<vector<string>> & people) {
    int n = req_skills.size() ;

    unordered_map<int, vector<int>> mp ;

    mp.reserve(1 << n) ;

    mp[0] = {} ;

    unordered_map<string, int> skill_hash ;

    for (int i = 0; i < n; i++)
    {
        skill_hash[req_skills[i]] = i ;
    }
    
    for (int i = 0; i < people.size(); i++)
    {
        
        int ct = 0 ;

        for (auto & ski : people[i]) {
            ct |= 1 << skill_hash[ski] ;
        }

        for (auto & it : mp) {
            int combination = it.first | ct ;

            if (mp.find(combination) == mp.end() || mp[combination].size() > 1 + mp[it.first].size()) {
                mp[combination] = it.second ;
                mp[combination].push_back(i) ;
            }
        }
    }
    
    return mp[(1 << n) - 1] ;
}

int main()
{
    int n ;;
    cin >> n ;
    vector<string> req_skills (n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> req_skills[i] ;
    }

    int n_people ;
    cin >> n_people ;
    vector<vector<string>> people ;
    for (int i = 0; i < n_people; i++)
    {
        int size ;
        cin >> size ;
        vector<string> temp(size) ;
        for (int j = 0; j < size; j++)
        {
            cin >> temp[j] ;
        }
        
    }
    for (auto it : smallestSufficientTeam(req_skills, people)) {
        cout << it << " " ;
    }
    
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool cmp (vector<int> & v1, vector<int> & v2) {
    return v1[1] <= v2[0] ;
}

unordered_map<string, int> mp ;

int find_next(int target, vector<vector<int>> & events) {
    int lo = 0 , hi = events.size() ;
    int mid  = 0 ;

    while (lo < hi)
    {
        mid = (lo + hi) / 2 ;

        if (events[mid][0] <= target) {
            lo = mid + 1 ;
        } else {
            hi = mid ;
        }
    }
    return lo ;
}

int solve (int index , int k, vector<vector<int>> & events) {

    if (k == 0 || index == events.size()) {
        return 0 ;
    };

    string key = to_string(index) + " " + to_string(k) ;

    if (mp.find(key) != mp.end()) return mp[key] ;

    int target = events[index][1] ;
    int next_event_index  = find_next(target, events) ;

    int ans = INT_MIN ;

    // current index not selected 
    int temp1 = solve(index + 1, k , events) ;
    
    // current event selected 
    int temp2 = solve(next_event_index, k - 1, events) + events[index][2] ;
    mp[key] = max(temp1, temp2) ;
    return mp[key] ;
}

int maxValue(vector<vector<int>>& events, int k) {
    // sort the events 
    sort(events.begin(), events.end(), cmp) ;
    // for  (auto & it : events) {
    //     cout << it[0] << " " << it[1] << " " << it[2] << endl ;
    // }

    int res = 0 ,
        n = events.size();

    // for (int i = 0; i < n; i++)
    // {
    //     int temp = events[i][2] ; // value 
    //     int t = k - 1;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (t == 0) break;
    //         if (events[j][0] > events[i][1]) {
    //             t-- ;
    //             temp += events[j][2] ;
    //         }
    //     }

    //     res = max(res, temp) ;
        
    // }
    

    return solve(0, k, events);
}

int main()
{
    int n, k ;
    cin >> n >> k;
    vector<vector<int>> events ;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(3) ;
        for (int j = 0; j < 3; j++)
        {
            cin >> temp[j] ;
        }
        events.push_back(temp) ;
    }

    // cout << find_next(3, events) << endl;
    // 
    cout << maxValue(events, k) << endl;
    return 0 ;
}
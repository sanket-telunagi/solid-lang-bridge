/*
    You are given an array of non-overlapping intervals intervals where 
    intervals[i] = [starti, endi] represent the start and the end of the ith interval and 
    intervals is sorted in ascending order by starti. You are also given an interval 
    newInterval = [start, end] that represents the start and end of another interval.

    Insert newInterval into intervals such that intervals is still sorted in ascending 
    order by starti and intervals still does not have any overlapping intervals 
    (merge overlapping intervals if necessary).

    Return intervals after the insertion.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0) {
        return {newInterval} ;
    }
    vector<vector<int>> ans ;
    vector<int> buffer (2,0) ;
    bool interval_consumed = 0 ;
    for (auto & it : intervals) {
        if (it[1] < newInterval[0]) {
            ans.push_back(it) ;
            continue ;
        } 
        else if (it[0] > newInterval[1]) {
            ans.push_back(it) ;
            continue;
        }
        else {
            interval_consumed = 1 ;
            if (buffer[0] == 0 && buffer[1] == 0) {
                buffer[0] = min(it[0], newInterval[0]) ;
                buffer[1] = max(it[1], newInterval[1]) ;
            }else {
                
                buffer[0] = min({buffer[0] ,it[0], newInterval[0]}) ;
                buffer[1] = max({buffer[1], it[1], newInterval[1]}) ;
            }
        
        }
    }

    if (buffer[1] != 0) ans.push_back(buffer) ;

    sort(ans.begin(), ans.end()) ;

    // if (ans[ans.size() - 1][1] < newInterval[0]) ans.push_back(newInterval) ;
    // else if (ans[0][0] > newInterval[1]) ans.push_back(newInterval) ;
    if (!interval_consumed) 
        for (auto & it : ans) {
            if (it[0] > newInterval[1]) {
                ans.push_back(newInterval) ;
                break;
            }
            else if (it[1] < newInterval[0]) {
                ans.push_back(newInterval) ;
                break ;
            }
        }

    sort (ans.begin(), ans.end()) ;
    return ans ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> intervals(n, vector<int> (2)) ;
    vector<int> newInterval(2) ;

    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1] ;
    }
    cin >> newInterval[0] >> newInterval[1] ;

    for (auto & it : insert(intervals, newInterval)) {
        for(auto & i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}





/*

    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]

    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/
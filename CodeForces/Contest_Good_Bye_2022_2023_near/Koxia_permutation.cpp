#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void genPer(vector<int> &nums, vector<vector<int>> &ans, int i = 0)
{
    if (i >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int index = i; index < nums.size(); index++)
    {
        swap(nums[i], nums[index]);
        genPer(nums, ans, i + 1);
        swap(nums[i], nums[index]);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        vector<vector<int>> ans;
        vector<int> c;
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
        }
        genPer(nums, ans);
        // for(auto it : ans) {
        //     for(auto i : it) {
        //         cout << i << " " ;
        //     }
        //     cout << endl ;
        // }
        for (auto it : ans)
        {
            int maximum = INT_MIN;
            for (int i = 0; i < n - k; i++)
            {
                maximum = max(maximum, *max_element(it.begin(), it.end()));
            }
            c.push_back(maximum);
        }

        pair<int, vector<int>> pr;
        pr.first = 0;
        int minimum = INT_MAX;
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     minimum = min(minimum, c[i]);
        //     pr.first = ;
        // }
        sort(c.begin(),c.end()) ;
        // for (auto i : ans[pr.fisrt])
        // {
        //     cout << i << " ";
        // }
        cout << endl ;
    }
    return 0;
}
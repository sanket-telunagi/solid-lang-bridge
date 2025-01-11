#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i : nums)
    {
        ans ^= i;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << singleNumber(v);
    return 0;
}
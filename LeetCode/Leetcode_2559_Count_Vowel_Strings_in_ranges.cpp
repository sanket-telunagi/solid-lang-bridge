#include <bits/stdc++.h>
using namespace std;

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    vector<int> ans(queries.size());
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    vector<int> pre(words.size());
    int sum = 0;
    for (int i = 0; i < words.size(); i++)
    {
        string curr = words[i];
        if (vowels.count(curr[0]) &&
            vowels.count(curr[curr.size() - 1]))
        {
            sum++;
        }
        pre[i] = sum;
    }

    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> currentQuery = queries[i];
        ans[i] =
            pre[currentQuery[1]] -
            (currentQuery[0] == 0 ? 0 : pre[currentQuery[0] - 1]);
    }

    return ans;
}

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int strings, query ;
        cin >> strings >> query;
        vector<string> words(strings);
        for (int i = 0; i < strings; i++)
        {
            cin >> words[i];
        }
        vector<vector<int>> queries;
        for (int i = 0; i < query; i++)
        {
            vector<int> val(2,0) ;
            cin >> val[0] >> val[1];
            queries.push_back(val);
        }
        
        for (int ch : vowelStrings(words, queries)) {
            cout << ch << " ";
        }
        cout << endl ;
        
    }
    
    return 0;
}
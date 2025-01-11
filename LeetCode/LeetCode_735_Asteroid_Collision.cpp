#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size(),
        ct = n,
        l = ct;
    while (l--)
    {
        
    }
    
    for (int i = n - 1; i >= 1; i--)
    {
        if (asteroids[i] < 0 && asteroids[i - 1] > 0)
        {

            if ((abs(asteroids[i]) == abs(asteroids[i - 1])))
            {
                asteroids[i] = asteroids[i - 1] = 0;
                ct -= 2;
            }
            if ((asteroids[i] > 0 && asteroids[i - 1] < 0) || (asteroids[i] < 0 && asteroids[i - 1] > 0))
            {
                if ((abs(asteroids[i]) > abs(asteroids[i - 1])))
                {
                    asteroids[i - 1] = asteroids[i];
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                }
                ct--;
            }
        }
    }
    // cout << ct << endl ;
    // for (auto it : asteroids) {
    //     cout << it << " " ;
    // }
    cout << endl ;
    vector<int> res1;
    for (auto it : asteroids)
    {
        if (it != 0)
        res1.push_back(it) ;
    }
    n = res1.size() ;
    asteroids = res1 ;
    for (auto it : asteroids) {
        cout << it << " " ;
    }
    cout << endl ;
    for (int i = n - 1; i >= 1; i--)
    {
        if (asteroids[i] < 0 && asteroids[i - 1] > 0)
        {

            if ((abs(asteroids[i]) == abs(asteroids[i - 1])))
            {
                asteroids[i] = asteroids[i - 1] = 0;
                ct -= 2;
            }
            if ((asteroids[i] > 0 && asteroids[i - 1] < 0) || (asteroids[i] < 0 && asteroids[i - 1] > 0))
            {
                if ((abs(asteroids[i]) > abs(asteroids[i - 1])))
                {
                    asteroids[i - 1] = asteroids[i];
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                }
                ct--;
            }
        }
    }

    vector<int> res2;
    for (auto it : asteroids)
    {
        if (it != 0)
        res2.push_back(it) ;
    }
    n = res2.size() ;
    asteroids = res2 ;
    for (auto it : asteroids) {
        cout << it << " " ;
    }
    cout << endl ;
    for (int i = n - 1; i >= 1; i--)
    {
        if (asteroids[i] < 0 && asteroids[i - 1] > 0)
        {

            if ((abs(asteroids[i]) == abs(asteroids[i - 1])))
            {
                asteroids[i] = asteroids[i - 1] = 0;
                ct -= 2;
            }
            if ((asteroids[i] > 0 && asteroids[i - 1] < 0) || (asteroids[i] < 0 && asteroids[i - 1] > 0))
            {
                if ((abs(asteroids[i]) > abs(asteroids[i - 1])))
                {
                    asteroids[i - 1] = asteroids[i];
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                }
                ct--;
            }
        }
    }


    vector<int> res3;
    for (auto it : asteroids)
    {
        if (it != 0)
        res3.push_back(it) ;
    }
    n = res3.size() ;
    asteroids = res3 ;
    for (auto it : asteroids) {
        cout << it << " " ;
    }
    cout << endl ;
    for (int i = n - 1; i >= 1; i--)
    {
        if (asteroids[i] < 0 && asteroids[i - 1] > 0)
        {

            if ((abs(asteroids[i]) == abs(asteroids[i - 1])))
            {
                asteroids[i] = asteroids[i - 1] = 0;
                ct -= 2;
            }
            if ((asteroids[i] > 0 && asteroids[i - 1] < 0) || (asteroids[i] < 0 && asteroids[i - 1] > 0))
            {
                if ((abs(asteroids[i]) > abs(asteroids[i - 1])))
                {
                    asteroids[i - 1] = asteroids[i];
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                }
                ct--;
            }
        }
    }

    vector<int> res4;
    for (auto it : asteroids)
    {
        if (it != 0)
        res4.push_back(it) ;
    }
    n = res4.size() ;
    asteroids = res4 ;
    for (auto it : asteroids) {
        cout << it << " " ;
    }
    cout << endl ;
    for (int i = n - 1; i >= 1; i--)
    {
        if (asteroids[i] < 0 && asteroids[i - 1] > 0)
        {

            if ((abs(asteroids[i]) == abs(asteroids[i - 1])))
            {
                asteroids[i] = asteroids[i - 1] = 0;
                ct -= 2;
            }
            if ((asteroids[i] > 0 && asteroids[i - 1] < 0) || (asteroids[i] < 0 && asteroids[i - 1] > 0))
            {
                if ((abs(asteroids[i]) > abs(asteroids[i - 1])))
                {
                    asteroids[i - 1] = asteroids[i];
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                }
                ct--;
            }
        }
    }

    vector<int> res5;
    for (auto it : asteroids)
    {
        if (it != 0)
        res5.push_back(it) ;
    }
    n = res5.size() ;
    asteroids = res5 ;
    for (auto it : asteroids) {
        cout << it << " " ;
    }
    cout << endl ;
    for (int i = n - 1; i >= 1; i--)
    {
        if (asteroids[i] < 0 && asteroids[i - 1] > 0)
        {

            if ((abs(asteroids[i]) == abs(asteroids[i - 1])))
            {
                asteroids[i] = asteroids[i - 1] = 0;
                ct -= 2;
            }
            if ((asteroids[i] > 0 && asteroids[i - 1] < 0) || (asteroids[i] < 0 && asteroids[i - 1] > 0))
            {
                if ((abs(asteroids[i]) > abs(asteroids[i - 1])))
                {
                    asteroids[i - 1] = asteroids[i];
                    asteroids[i] = 0;
                }
                else
                {
                    asteroids[i] = 0;
                }
                ct--;
            }
        }
    }

    vector<int> res;
    for (auto it : asteroids)
    {
        if (it != 0)
        res.push_back(it) ;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (auto it : asteroidCollision(nums))
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
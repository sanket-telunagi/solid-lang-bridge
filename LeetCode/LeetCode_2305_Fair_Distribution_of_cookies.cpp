#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isEnough(vector<int> & cookies, int k , int mid) {
    int cookie = 0 ,
        n = cookies.size();
    for (int i = 0; i < n; i++)
    {
        if (cookie + cookies[i] <= mid) {
            cookie += cookies[i] ;
            cout << cookie << " " << k << " " << mid << endl;
        } else {
            k-- ; // cookies given to one student 

            // if studunts ended or the number of cookies greater than given cookies 
            if (k == 0 || cookies[i] > mid) return false ;

            cookie = cookies[i] ;
        }
    }
    
    return true ;
}

int distributeCookies1(vector<int>& cookies, int k) {
    int n = cookies.size() ;
    
    // problem is same as book allocation problem
    sort (cookies.begin(), cookies.end()) ;
    
    for (auto it : cookies) cout << it << " " ;
    cout << endl ;

    int lo = 0 ,
        hi = accumulate(cookies.begin(), cookies.end(), 0) ,
        res = 0 ,
        mid = 0 ;

    // amswer lies between lo and hi 
    while (hi - lo > 1) {
        mid = lo + (hi - lo) / 2 ;
        if (isEnough(cookies, k, mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo < hi ? lo : hi ;
}

// bool isPossible(int mid, int k , vector<int> & nums) {
//     int cookies = 0,
//         n = nums.size() ;

//     for (int i = 0; i < n; i++)
//     {
     
//         if (nums[i] > mid) return false ;

//         if (cookies + nums[i] > mid) {
//             k-- ;
//             cookies = nums[i] ;
//             if (k == 0) return false ;
//         }
//         cookies += nums[i] ;
//     }

//     return true ;
    
// }

int backTrack(int index, vector<int> & kids, vector<int> & nums) {
    int res = INT_MAX ;
    if (index >= nums.size()) {
        res = min(res, *max_element(kids.begin(), kids.end())) ; // get the minimum unfaireness
        return res ;
    }

    for (int i = 0; i < kids.size(); i++)
    {
        kids[i] += nums[index] ;
        res = min(res, backTrack(index + 1, kids, nums)) ;
        kids[i] -= nums[index] ;
    }
    

    return res ;
}

int distributeCookies (vector<int> & nums, int k) {
    int n = nums.size() ;
    vector<int> kids(k, 0) ; // create total number of kids 
    return backTrack(0, kids, nums) ;

}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << distributeCookies(nums, k) << endl ;
    
    return 0 ;
}
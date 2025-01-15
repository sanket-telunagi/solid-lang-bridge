#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; 
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums1(n), nums2(n);
        for (int i = 0 ; i < n ; i++) {
            int num ;
            cin >> num ;
            nums1[i] = (num);
        }
        // for (int num : nums1) cout << num << " ";
        
        for (int i = 0 ; i < n ; i++) {
            int num ;
            cin >> num ;
            nums2[i] = (num);
        }
        unordered_map<int,int> m ;
        int res = 0 ;
        for (int i = 0 ; i < n ; i++) {
            for (int j = nums1[i] ; j < nums2[i]; j++) {
                m[j]++ ;
                res = max(res, m[j]);
                // cout << track[j] << " ";
            }
        }
        cout << res << endl ;
    }
}

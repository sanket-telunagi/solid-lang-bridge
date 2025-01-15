# include<bits/stdc++.h>
using namespace std; 
int main () {
    int t; 
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector<int> nums1, nums2 ;
        for (int i = 0; i < n; i++)
        {
            int num ;
            cin >> num ;
            nums1.push_back(num) ;
        }
        for (int i = 0; i < n; i++)
        {
            int num ;
            cin >> num ;
            nums2.push_back(num) ;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int count = 0, nums1Counter = 0, nums2Counter = 0 ;
        while (nums1Counter < n && nums2Counter < n)
        {

            while (nums1[nums1Counter] <= nums2[nums2Counter])
            {
                count ++ ;
                nums1Counter++ ;
                if (count == 6) {
                    
                }
            }
            
        }
        
    }
    
}
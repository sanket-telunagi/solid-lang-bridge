#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , p ;
        cin >> n >> p ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        sort(nums.begin(), nums.end()) ;
        int i = 0 , ct = 0 ,
            isDis = false ;;

            /*
                Suppose k=3 and a[i] is 7. If we do k>=a[i]/2, it will return true as since the values are integers, 
                a[i]/2 = 3 and not 3.5 as it should. 
                Hence, we add 1 to a[i] before dividing so that we get 4 in the above example and it returns false.
            */
        for (int i = 0; i < n; i++)
        {
            if ( p - nums[i] >= 0) {
                p -= nums[i] ;
                ct++ ;
            } else {
                if (p - ((nums[i] + 1) / 2) >= 0) {
                    p -= nums[i] / 2 ;
                    ct++ ;
                    break ;
                }
            }
        }
        
        
        cout << ct << endl ;
    }
    return 0 ;
}
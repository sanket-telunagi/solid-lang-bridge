#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// void print(vector<long long int> & arr) {
//     for(long long int i = 0 ; i < arr.size() ; i++) {
//         cout << arr[i] << " " ;

//     }
//     cout << endl ;
// }

int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        long long int n , m ;
        cin >> n >> m ;
        vector<long long int> N(n), M(m) ;
        for (long long int i = 0; i < n; i++)
        {
            cin >> N[i] ;
        }
        for (long long int i = 0; i < m; i++)
        {
            cin >> M[i] ;
        }

        for (int i = 0; i < m; i++)
        {
            if(n == 1 && m == 1) {
                N[i] = M[i] ;
                break;
            }
            auto mini = min_element(N.begin(),N.end()) ;

            auto maxi = max_element(M.begin(),M.end()) ;

            if (*mini < *maxi){
                replace(N.begin(),N.end(),*mini,*maxi) ;
                M.erase(maxi) ;
            }
        }
        
        long long int sum = 0 ;
        for(long long int i = 0 ; i < n ; i++) {
            sum += N[i] ;

        }

        cout << sum << endl ;
        
        
    }
    return 0 ;
}
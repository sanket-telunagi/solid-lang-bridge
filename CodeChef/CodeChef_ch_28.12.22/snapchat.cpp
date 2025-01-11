#include<vector>
#include <iostream>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        int A[n], B[n] ;

        for (int i = 0; i < n; i++)
        {
            cin >> A[i] ;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i] ;
        }
        int ct = 0 ;
        int ans = 0 ;
        for (int i = 0; i < n; i++)
        {
            if (A[i] < 1 | B[i] < 1) {
                ans = max(ans,ct) ;
                ct = 0 ;
                continue ;
            }
            ct++ ;
        }
        cout << (ans|0) << endl ;
        
    }
    return 0 ;
}
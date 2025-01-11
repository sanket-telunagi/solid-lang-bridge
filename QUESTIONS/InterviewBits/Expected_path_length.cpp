#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

// int power(int base, int exponent) {
//     int result = 1;
//     while (exponent > 0) {
//         if (exponent % 2 == 1) {
//             result = (long long) result * base % mod;
//         }
//         base = (long long) base * base % mod;
//         exponent /= 2;
//     }
//     return result;
// }



// int main() {
//     int a;
//     cin >> a;

//     int ans = 0;
//     int power = [] (int base, int exponent){
//             int result = 1;
//             while (exponent > 0) {
//                 if (exponent % 2 == 1) {
//                     result = (long long) result * base % mod;
//                 }
//                 base = (long long) base * base % mod;
//                 exponent /= 2;
//             }
//             return result;
//     } ;

//     for (int i = 2; i <= a; i++) {
//         ans = (ans + power(i, mod - 2)) % mod;
//     }

//     cout << ans << endl;
//     return 0;
// }



int main() {
    int a;
    cin >> a;

    auto power = [&](int base, int exponent) {
        int result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (long long) result * base % mod;
            }
            base = (long long) base * base % mod;
            exponent /= 2;
        }
        return result;
    };

    int ans = 0;
    for (int i = 2; i <= a; i++) {
        ans = (ans + power(i, mod - 2)) % mod;
    }

    cout << ans << endl;
    return 0;
}


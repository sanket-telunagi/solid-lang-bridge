#include <bits/stdc++.h>
#include <iostream>
using namespace std ;


// pair<int,vector<pair<int,int>>> solve (vector<int> & arr) {
//     int swaps = 0 ;
//     pair<int,vector<pair<int,int>>> ans ;
//     vector<pair<int,int>> swap_indices ;
//     for (int i = 0 ; i < arr.size() /2 ; i++) {
//         if (arr[i] == 1) {
//             for(int j = arr.size() - 1; j >= arr.size()/2 ; j--) {
//                 if (arr[j] == 0) {
//                     swap(arr[i],arr[j]) ;
//                     cout << "swaps : " << arr[i] << " " << arr[j] << endl ;
//                     swaps++ ;
//                     swap_indices.push_back({i,j}) ;
//                 }
//             }
//         }
//     }
//     ans.first = swaps ;
//     ans.second = swap_indices ;
//     return ans ;
// }

void print(vector <int> & arr) {
    for (auto i : arr) {
        cout << i << " " ;
    }
    cout << endl ;
}

pair<int,vector<pair<int,int>>> solve (vector<int> & arr) {
    int swaps = 0 ;
    pair<int,vector<pair<int,int>>> ans ;
    vector<pair<int,int>> swap_indices ;
    for (int i = 0 ; i < arr.size() /2 ; i++) {
        if (arr[i] == 1) {
            for(int j = arr.size()/2; j < arr.size() - 1; j++) {
                if (arr[j] == 0 && arr[i] == 1) {
                    swap(arr[i],arr[j]) ;
                    swaps++ ;
                    swap_indices.push_back({i,j}) ;
                }
            }
        }
    }
    ans.first = swaps ;
    ans.second = swap_indices ;
    return ans ;
}

int main() {
    int n ; cin >> n ;
    vector<int> arr(n) ;
    
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    pair<int,vector<pair<int,int>>> ans ;
    ans = solve(arr) ;
    
    cout << ans.first << endl ;
    for (int i = ans.first-1 ; i >= 0; i--) {
        cout << ans.second[i].first << " " << ans.second[i].second << endl;
    }
    return 0 ;
}
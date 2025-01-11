#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// void permutaion(vector<int> & A,int B,int & ans, int index = 0) {
    
//     if (index == A.size()) {
//         return ;
//     }
//     int aesthetic_value = 0;

//   // Compute the aesthetic value
//     for (int i = 0; i < A.size() - B; i++) {
//         aesthetic_value += abs(A[i] - A[i + B]);
//     }
//     ans = min(ans,aesthetic_value) ;
//     for (int i = index; i < A.size(); i++)
//     {
//         swap(A[i],A[index]) ;
//         permutaion(A,B,ans,index + 1) ;
//         swap(A[i],A[index]) ;
//     }
// }

// Function to compute the minimum aesthetic value for any permutation of array A
long long minAestheticValue(vector<int>& A, int B) {
    long long ans = INT64_MAX;
    // permutaion(A,B,aesthetic_value) ;
    auto permutation = [& ans, & A, & B] (auto & self, int index = 0) {
        if (index == A.size()) {
            return ;
        }
        long long aesthetic_value = 0;

    // Compute the aesthetic value
        for (int i = 0; i < A.size() - B; i++) {
            aesthetic_value += abs(A[i] - A[i + B]);
        }
        ans = min(ans,aesthetic_value) ;
        for (int i = index; i < A.size(); i++)
        {
            swap(A[i],A[index]) ;
            permutation(permutation,index + 1) ;
            swap(A[i],A[index]) ;
        }
    } ;

    permutation(permutation, A, B , ans) ;
    return ans;
}

int main() {
  // Example usage
  int B, N;
  cin >> N >> B ;
//   vector<int> A = {1, 3, 5, 7, 9};
vector<int> A(N) ;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] ;
    }
    
  cout << minAestheticValue(A, B) << endl;

  return 0;
}

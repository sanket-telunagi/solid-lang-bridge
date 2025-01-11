#include <stdio.h>

void permutaion(int * A, int n1,int B,int * ans, int index) {
    
    if (index == n1) {
        return ;
    }
    long long int aesthetic_value = 0;

  // Compute the aesthetic value
    for (int i = 0; i < n1 - B; i++) {
        aesthetic_value += abs(A[i] - A[i + B]);
    }
    *ans = min(*ans,aesthetic_value) ;
    for (int i = index; i < n1; i++)
    {
        swap(A[i],A[index]) ;
        permutaion(A,n1,B,ans,index + 1) ;
        swap(A[i],A[index]) ;
    }
}

// Function to compute the minimum aesthetic value for any permutation of array A
int minAestheticValue(int * A,int n1, int B) {
    long long aesthetic_value = __INT_MAX__;
    permutaion(A,n1,B,aesthetic_value,0) ;
    return aesthetic_value;
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


int main()
{
    
    return 0 ;
}
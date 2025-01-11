#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minimumSum(int n, int k) {
    /*
        Rverse the problem 
        find all the pairs in range of [1, k] that sum to 'k'
        and now take only minimum alament from these pairs
        as the the pairs are repeated chose only half of the len 
    */

    multiset<int> notInsert ;

    for (int i = 1; i < k; i++)
    {
        for (int j = i+ 1; j <= k; j++)
        {
            if (i + j == k) notInsert.insert(max(i,j)) ; // find all the elemnts that should no be inserted 
            // take maximum elemnt as we need the sum minimum 
            
        }
    }

    int sum = 0 , it = 0 , i = 0;
    while (it != n)
    {
        i++ ;
        if (notInsert.find(i) != notInsert.end()) continue; // if it is not choosable continue 
        // cout << i << endl ; // see the elements 
        sum += i ;
        it ++ ; // we need n elements in teh array 
    }
    

    return sum ;

}

int main()
{
    int n , k ;
    cin >> n >> k ;
    cout << minimumSum(n, k) << endl ;
    return 0 ;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int kThSmallest (vector<int> & nums, int k) {
    /*
        1 : Sorting array 

            - sort array and fint the kth elemnt from start 

        2 : using maxHeap 
            - use maxHeap 
            - create maxHeap of first k elemnts only 
            - now for rest of the elements, enqeue the element to root if its less than the root node
            - pop the first element 
            - do this till the end and 
            - at last the top elemnt will be the result 
    */

    // use priority queue
    // deafult is the maxHeap

    priority_queue<int> maxHeap ;

    for (int i = 0; i < k; i++)
    {
        maxHeap.push(nums[i]) ;
    }

    for (int i = k ; i < nums.size(); i++) {
        if (nums[i] < maxHeap.top()) {
            maxHeap.push(nums[i]) ;
            maxHeap.pop() ;
        }
    }


    return maxHeap.top() ;
    
    
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << kThSmallest(nums, k) << endl ;
    
    return 0 ;
}
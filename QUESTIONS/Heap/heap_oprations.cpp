#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// creating heap datastructure 
class Heap {
    // creating heap with one base indexing 
    int nums[100] ;  // implementing heap with array 
    int size ; // keep tract of current hep size 

    public : 
    // call constructor to initialize the size 
    Heap () {
        size = 0 ;
        
    }

    // Print heap 
    void printHeap () {
        for (int i = 1 ; i <= size ; i++) {
            cout << nums[i] << " " ;
        }
        cout << endl ;
    }


    // inserting data in heap
    void insertNode (int num) {
        /*
            Algo : 
                1. insert data at the end of the heap 
                2. Now take the data to its right position 
                    - Compare the new node to ists parent 
                    - if its greater than parent swap the position 
                    - change the node 
                    - repaet the procesure 
        */

        size += 1 ;  // new data 
        nums[size] = num ; // insert node to the last position 
        int nodeIndex = size ;
        int parentIndex  ; // parent index for CBT

        while (nodeIndex > 1) {
            parentIndex = nodeIndex / 2 ;

            // check for condition 
            if (nums[parentIndex] < nums[nodeIndex]) {
                swap(nums[parentIndex], nums[nodeIndex]) ;
                
                // now node at its parent position 
                nodeIndex = parentIndex ;
            } 
            
            else return ;  // inserted node is at the right position 
            
        }

    }


    // deleting the node 
    int deleteNode () {
        /*
            Algo : 
            - for deleting the node we always refer to deleting the root node of CBT 
            - swap the root with the last node 
            - delete the last node 
            - node propagate the the swapped node to its correct position 
            - return the deleted node 
        */

        int returnNode = nums[1]; // the returning node // 1 based indexing 

        int rootIndex = 1 ; 
        int lastNode = size ;

        swap(nums[rootIndex], nums[lastNode]) ;

        // delete the node 
        size-- ;
        while (rootIndex < size) { // propaget till the last node 

            int leftIndex = 2*rootIndex, 
                rightIndex = 2*rootIndex + 1 ;

            if (leftIndex <= size && nums[leftIndex] > nums[rootIndex]) {
                swap(nums[leftIndex], nums[rootIndex]) ;
                rootIndex = leftIndex ;
            }

            else if (rightIndex <= size && nums[rightIndex] > nums[rootIndex]) {
                swap(nums[rootIndex], nums[rightIndex]) ;
                rootIndex = rightIndex ;
            }

            else break ;
        }

        return returnNode ; // return the deleted node 
    }

};

// heapify algorithm 
void Heapify(int * nums, int size, int index) {
    /*
        Heapify algorithm : 
        - it is an algorithm to create the heap from current node to the last node 
        - it creates the heap for the node after the provided starting node 
        
        Algo : 
        - start with the current node 
        - check for the right and left part if any part is smaller than the node swap it 
        - continue the above steps 

        // for a single node there is node need to heapify 

        - for a CBT (1 indexed)
            - root index = i 
            - left Child = 2 * i
            - right Child = 2 * i + 1 
            - parent index = i / 2 
            - leaf nodes = from  ( (n / 2) + 1) --> n  n : size of the tree    

        - for a CBT (0 indexed)
            - root index = i 
            - left Child = 2 * i + 1
            - right Child = 2 * i + 2 
            - parent = floor((n-1)/2)
            - leaf nodes = from ((n-1) + 1) --> n    n : size of tree 


        - TC : log(n)

        - Condition for the minHeap with be reversed 

    */

    int rootIndex = index ;
    while (rootIndex < size) {
        int leftIndex = 2 * rootIndex ,
            rightIndex = 2 * rootIndex + 1 ;
        
        if (leftIndex <= size && nums[leftIndex] > nums[rootIndex]) {
            swap(nums[rootIndex], nums[leftIndex]) ;
            rootIndex = leftIndex ;
        }

        else if (rightIndex <= size && nums[rightIndex] > nums[rootIndex]) {
            swap(nums[rootIndex], nums[rightIndex]) ;
            rootIndex = rightIndex;
        }

        else break ;
    }
}

void Heapify(vector<int> & nums, int size, int index) {
    // 0 based maxHeap
    int rootIndex = index ;
    while (rootIndex < size) {
        int leftIndex = 2 * rootIndex + 1 ,
            rightIndex = 2 * rootIndex + 2;
        
        if (leftIndex < size && nums[leftIndex] > nums[rootIndex]) {
            swap(nums[rootIndex], nums[leftIndex]) ;
            rootIndex = leftIndex ;
        }

        else if (rightIndex < size && nums[rightIndex] > nums[rootIndex]) {
            swap(nums[rootIndex], nums[rightIndex]) ;
            rootIndex = rightIndex;
        }

        else break ;
    }
}


void heapSort(vector<int> & nums) {
    // sort array with heaps 
    /*
        TC : O(n*log(n))

        Algo : 

            - create maxHeap from the given array 
            - aswap the larget elemnt (first value) with the last element
            - now apply heapify on the same node 
            - repeat till the last
        
        TC : O(n * log(n))

    */
    int n = nums.size() ;

    
    
    while (n > 1) {
        swap(nums[0], nums[n-1]) ;
        n-- ;

        Heapify(nums, n, 0) ;
    }
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    // create object 
    Heap heap ;

    // create heap 
    for (auto it : nums) {
        heap.insertNode(it) ;
        // heap.printHeap() ;
    }

    // printHeap 
    heap.printHeap() ;


    // delete the node in heap 
    cout << heap.deleteNode() << endl ;

    heap.printHeap() ;


    for (auto it : nums) cout << it << " " ;
    cout << endl ;

    // dont need to go for the leaf nodes 
    int startNode = 0 , endNode = (n - 1) / 2 ;
    // start always reverse 
    for (int i = endNode ; i >= startNode; i--) {
        Heapify(nums, n, i) ;
    }

    for (auto it : nums) cout << it << " " ;
    cout << endl ;


    heapSort(nums) ;
    for (auto it : nums) cout << it << " " ;
    cout << endl ;


    
    return 0 ;
}
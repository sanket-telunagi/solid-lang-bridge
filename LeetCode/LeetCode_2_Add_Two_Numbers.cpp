#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct ListNode {
    int val ;
    ListNode * next ;
    ListNode (int x) {
        val = x ;
        next = nullptr ;
    }
} ;

int getNumber(ListNode * root) {
    if (!root) return 0 ;
    return root->val + getNumber(root->next) * 10 ;
}

ListNode * to_LinkedList (int x) {
    
}

int main()
{
    // 2 -> 4 -> 3
    ListNode * l1 ;
    l1 = new ListNode(2) ;
    l1->next = new ListNode(4) ;
    l1->next->next = new ListNode(3) ;

    // 5 -> 6 -> 4 
    ListNode * l2 ;
    l2 = new ListNode(5) ;
    l2->next = new ListNode(6) ;
    l2->next->next = new ListNode(4) ;

    
    int n1 = getNumber(l1) , 
        n2 = getNumber(l2) ;

    
    return 0 ;
}
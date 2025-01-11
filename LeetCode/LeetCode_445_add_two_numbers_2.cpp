#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct ListNode {
    int val ;
    ListNode * next ;
    
} ;

ListNode * newNode (int x) {
    ListNode * root = (ListNode *) malloc(sizeof(ListNode)) ;
    root->val = x ;
    root->next = nullptr ;
    return root ;
}

void add(ListNode * l1, ListNode * l2, ListNode * sum, int & carry) {
    // if (l1 == nullptr) {
    //     return ;
    // }
    // add(l1->next, l2, sum, carry) ;

    // int val1 = 0, val2 = 0 ;
    // if (l1) {
    //     val1 = l1->val ;
    // }
    if (l1 == nullptr && l2 == nullptr) {
        return ;
    }
    add(l1->next, l2->next, sum->next, carry) ;

    int addition = l1->val + l2->val + carry ;
    carry = addition / 10 ;
    addition %= 10 ;
    sum->val = addition ;
}

int getLength(ListNode * root) {
    if (!root) return 0 ;
    return 1 + getLength(root->next) ;
}

int main()
{
    // 7 -> 2 -> 4 -> 3
    // ListNode * l1 , * l3 = l1 ;
    ListNode * l1 ;
    l1 = newNode(7) ;
    l1->next = newNode(2) ;
    l1->next->next = newNode(4) ;
    l1->next->next->next = newNode(3) ;
    cout << getLength(l1) << endl ;

    // 5 -> 6 -> 4 ;
    ListNode * l2 ;
    l2 = newNode(5) ;
    l2->next = newNode(6) ;
    l2->next->next = newNode(4) ;
    cout << getLength(l2) << endl ;

    int diff = getLength(l1) - getLength(l2) ;
    
    ListNode * sum ;
    ListNode * temp ;
    if (diff >= 0) {
        temp = l1 ;
        while (diff--) {
            temp = temp->next ;
        }

        

    } else {
        temp = l2 ;
        while (diff++) {
            temp = temp->next ;
        }
    }

    ListNode * l3 = l2  ;
    ListNode * res ;

    while (l3 != nullptr)
    {
        cout << l3->val << " " ;
        l3 = l3->next ;
    }
    
    return 0 ;
}
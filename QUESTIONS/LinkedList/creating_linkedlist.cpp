#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct ListNode {
    int val ;
    ListNode * next ;
};

ListNode * newNode (int x) {
    ListNode * root = (ListNode *) malloc(sizeof(ListNode)) ;
    root->val = x ;
    root->next = nullptr ;
    return root ;
}

ListNode * revList(ListNode * head) {
    ListNode * prev = nullptr, * after = nullptr;

    while (head) {
        after = head->next ;
        head->next = prev ;
        prev = head ;
        head = after ;
    }

    // head = prev ;
    return prev ;
}

void printList(ListNode * head) {
    while (head)
    {
        cout << head->val << " " ;
        head = head->next ;
    }
    cout << endl ;
}

int main()
{
    ListNode * l1 ;
    l1 = newNode(7) ;
    l1->next = newNode(2) ;
    l1->next->next = newNode(4) ;
    l1->next->next->next = newNode(3) ;

    cout << "Original : " << endl;
    ListNode * org = l1 ;
    printList(org) ;
    
    revList(l1) ;
    printList(l1) ;
    return 0 ;
}
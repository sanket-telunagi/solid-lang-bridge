#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node() : next(nullptr) {}

    // constructor to initialize the node with given value
    Node(int n) : val(n),
                  next(nullptr) {}
};

int main()
{
    /*
    node is always a pointer

    */
    Node *root = new Node(4);
    cout << root->val << endl;

    return 0;
}

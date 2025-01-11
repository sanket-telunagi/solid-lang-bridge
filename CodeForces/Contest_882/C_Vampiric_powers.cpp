// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 8

// A Trie Node
struct Node
{
	int value; 
	Node *arr[2];
};


Node *newNode()
{
	Node *temp = new Node;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void insert(Node *root, int pre_xor)
{
	Node *temp = root;


	for (int i=INT_SIZE-1; i>=0; i--)
	{

		bool val = pre_xor & (1<<i);

		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	temp->value = pre_xor;
}
int find(Node *root, int pre_xor)
{
	Node *temp = root;
	for (int i=INT_SIZE-1; i>=0; i--)
	{
	
		bool val = pre_xor & (1<<i);


		if (temp->arr[1-val]!=NULL)
			temp = temp->arr[1-val];

	
		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	return pre_xor^(temp->value);
}

int maxSubarrayXOR(int arr[], int n)
{
	Node *root = newNode();
	insert(root, 0);

	int result = INT_MIN, pre_xor =0;

	for (int i=0; i<n; i++)
	{
		pre_xor = pre_xor^arr[i];
		insert(root, pre_xor);


		result = max(result, find(root, pre_xor));
	}
	return result;
}

int main()
{
	int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        int arr[n] ;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i] ;
        }
        
	    cout << maxSubarrayXOR(arr, n) << endl ;
    }
	return 0;
}

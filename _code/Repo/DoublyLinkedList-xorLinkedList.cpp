
#include <stdint.h>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* npx; 
};
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
void insert(struct Node **head_ref, int data);
void printList (struct Node *head);
// Driver program to test above functions
int main ()
{

    #ifndef ONLINE_JUDGE
	    freopen("../input.txt", "r", stdin);
	    freopen("../output.txt", "w", stdout);
    #else
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        struct Node *head = NULL;
        int n, tmp;
        cin>>n;
        while(n--)
        {
            cin>>tmp;
            insert(&head, tmp);
        }
        printList (head);
        cout<<"\n";
    }
	return (0);
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of linked list is as
struct Node
{
	int data;
	struct Node* npx; 
};
Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers 
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/
// function should insert the data to the front of the list
void insert(struct Node **head_ref, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    
    if (*head_ref != NULL) {
        (*head_ref)->npx = XOR((*head_ref)->npx, newNode);
        newNode->npx = *head_ref;

        // cout << "head_ref npx of " << (*head_ref)->data << " = " << (*head_ref)->npx << "\n";
    } else {
        newNode->npx = newNode;
    }

    // cout << "newNode npx of " << (newNode)->data << " = " << (newNode)->npx << "\n";

    // cout << " >>> newNode " << newNode->data << " (" << newNode << ")" << endl;
    
    *head_ref = newNode;
}
// function should prints the contents of doubly linked list
// first in forward direction and then in backward direction
// you should print a next line after printing in forward direction
void printList (struct Node *head)
{
    Node *prev = NULL, *start = head, *temp;
    
    do {

    	if (prev == head)
    		cout << endl;

        cout << head->data << " ";

        if (prev == NULL)
        	temp = head->npx;
        else
        	temp = XOR(head->npx, prev);	

        // cout << "--" << head << endl;
        // break;
        
        prev = head;
        head = temp;
        
    } while (head != start);

    cout << head->data;
}

#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};
//Position this line where user code will be pasted.
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

struct Node *sortDoubly(struct Node *head);
// Driver program
int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #else
    #endif


    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}


Node *findMid(Node *h) {

	cout << "findMid" << endl;

    if (h == NULL || h->next == NULL)
        return h;
    
    Node *f = h->next;
    while (f->next != NULL && f->next->next != NULL) {
        h = h->next;
        f = f->next->next;
    }
    
    return h;
}

Node *merge(Node *a, Node *b) {
    
    cout << "merge" << endl;

    if (a == NULL)
        return b;
        
    if (b == NULL)
        return a;
        
    Node *res = NULL;
    
    if (a->data <= b->data) {
        res = a;
        res->next = merge(a->next, b);
    } else {
        res = b;
        res->next = merge(a, b->next);
    }

    if (res->next != NULL)
        res->next->prev = res;
        
    return res;
}

struct Node *sortDoubly(struct Node *head)
{
	cout << "sortDoubly" << endl;

	if (head == NULL || head->next == NULL)
	    return head;
	    
	Node *mid = findMid(head);
	Node *next_of_mid = mid->next;
	mid->next = NULL;
	
	Node *sorted_first = sortDoubly(head);
	Node *sorted_second = sortDoubly(next_of_mid);

	Node *merged = merge(sorted_first, sorted_second);
	merged->prev = NULL;
	
	return merged;
}
